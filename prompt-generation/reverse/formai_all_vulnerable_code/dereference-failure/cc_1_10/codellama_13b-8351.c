//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main() {
  int sockfd, n;
  char recvBuff[1024];
  char *hello = "Hello from client";
  struct sockaddr_in serv_addr;
  struct hostent *server;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("\n Error : Could not create socket \n");
    return 1;
  }

  server = gethostbyname("smtp.gmail.com");
  if (server == NULL) {
    printf("\n Error : Could not find host\n");
    return 1;
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(25);
  serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("\n Error : Connect Failed \n");
    return 1;
  }

  n = write(sockfd, hello, strlen(hello));
  if (n < 0) {
    printf("\n Error : Write failed\n");
    return 1;
  }

  n = read(sockfd, recvBuff, 1024);
  if (n < 0) {
    printf("\n Error : Read failed\n");
    return 1;
  }

  printf("Server Response: %s\n", recvBuff);

  close(sockfd);
  return 0;
}