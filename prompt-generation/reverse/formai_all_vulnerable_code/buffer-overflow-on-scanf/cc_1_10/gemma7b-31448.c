//Gemma-7B DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
  int sockfd, port, len;
  char buf[1024], msg[1024], server[256];

  //Ephemeral socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(25));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  //Get server address
  printf("Enter server address: ");
  scanf("%s", server);

  //Connect to server
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(25);
  serv_addr.sin_addr.s_addr = inet_addr(server);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  //Send email message
  printf("Enter your message: ");
  scanf("%s", msg);

  len = strlen(msg) + 1;
  if (send(sockfd, msg, len, 0) < 0) {
    perror("Error sending message");
    exit(1);
  }

  //Receive server response
  len = recv(sockfd, buf, 1024, 0);
  if (len > 0) {
    printf("Server response: %s", buf);
  } else {
    perror("Error receiving response");
    exit(1);
  }

  //Close socket
  close(sockfd);

  return 0;
}