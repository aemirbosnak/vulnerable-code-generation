//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
  int sockfd, newsockfd, portno, n;
  struct sockaddr_in serv_addr, cli_addr, serv_addr_udp;
  char buffer[256];

  // Create TCP socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening TCP socket");
    exit(1);
  }

  // Create UDP socket
  int udp_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (udp_sockfd < 0) {
    perror("ERROR opening UDP socket");
    exit(1);
  }

  // Get port number from user
  printf("Enter port number: ");
  scanf("%d", &portno);

  // Set up TCP server address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  // Set up UDP server address
  bzero((char *) &serv_addr_udp, sizeof(serv_addr_udp));
  serv_addr_udp.sin_family = AF_INET;
  serv_addr_udp.sin_addr.s_addr = INADDR_ANY;
  serv_addr_udp.sin_port = htons(portno);

  // Bind TCP socket to address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on TCP binding");
    exit(1);
  }

  // Bind UDP socket to address
  if (bind(udp_sockfd, (struct sockaddr *) &serv_addr_udp, sizeof(serv_addr_udp)) < 0) {
    perror("ERROR on UDP binding");
    exit(1);
  }

  // Listen on TCP socket
  listen(sockfd, 5);

  while (1) {
    // Accept TCP connection
    socklen_t clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("ERROR on TCP accept");
      exit(1);
    }

    // Receive data from TCP client
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
      perror("ERROR reading from TCP client");
      exit(1);
    }

    // Send data to UDP client
    sendto(udp_sockfd, buffer, n, 0, (struct sockaddr *) &cli_addr, clilen);

    // Close TCP connection
    close(newsockfd);
  }

  // Close TCP socket
  close(sockfd);

  // Close UDP socket
  close(udp_sockfd);

  return 0;
}