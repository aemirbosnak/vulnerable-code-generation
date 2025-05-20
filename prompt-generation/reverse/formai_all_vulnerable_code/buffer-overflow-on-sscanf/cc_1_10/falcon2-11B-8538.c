//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
  if (argc!= 2) {
    printf("Usage: %s <target IP address>\n", argv[0]);
    return 1;
  }

  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char sendbuf[1000];
  char recvbuf[1000];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket failed");
    return 1;
  }

  // Convert the IP address to binary form
  struct in_addr ipaddr;
  sscanf(argv[1], "%d.%d.%d.%d", &ipaddr.s_addr, &ipaddr.s_addr, &ipaddr.s_addr, &ipaddr.s_addr);

  // Create an address struct and fill in the IP address and port number
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = ipaddr.s_addr;
  serv_addr.sin_port = htons(atoi(argv[2]));

  // Connect to the server
  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect failed");
    return 1;
  }

  // Send the message to the server
  sprintf(sendbuf, "Hello, world!");
  send(sockfd, sendbuf, strlen(sendbuf), 0);

  // Receive the response from the server
  recv(sockfd, recvbuf, sizeof(recvbuf), 0);
  printf("Received: %s\n", recvbuf);

  // Close the socket
  close(sockfd);

  return 0;
}