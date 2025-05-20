//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  char buffer[2048];

  printf("What port do you want to connect to?\n");
  scanf("%d", &portno);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    printf("Error creating socket!\n");
    return -1;
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error connecting to server!\n");
    return -1;
  }

  printf("Connected to server!\n");

  while (1) {
    printf("Enter message to send:\n");
    fgets(buffer, 2048, stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    if (strcmp(buffer, "quit\n") == 0) {
      break;
    }

    memset(buffer, 0, 2048);
    recv(sockfd, buffer, 2048, 0);
    printf("Server: %s\n", buffer);
  }

  close(sockfd);
  printf("Connection closed.\n");

  return 0;
}