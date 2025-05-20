//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[256];
  printf("Enter the IP address of the FTP server: ");
  scanf("%s", buffer);
  server = gethostbyname(buffer);
  if (server == NULL) {
    fprintf(stderr, "Error: no such host\n");
    exit(0);
  }

  portno = 21;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: could not create socket\n");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: could not connect to server\n");
    exit(0);
  }

  printf("Connected to FTP server\n");

  while (1) {
    printf("Enter FTP command: ");
    scanf("%s", buffer);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
      fprintf(stderr, "Error: could not write to socket\n");
      exit(0);
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
      fprintf(stderr, "Error: could not read from socket\n");
      exit(0);
    }

    printf("%s\n", buffer);
  }

  close(sockfd);
  return 0;
}