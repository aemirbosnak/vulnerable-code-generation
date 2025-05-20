//Gemma-7B DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
  int sockfd;
  struct sockaddr_in servaddr;
  char buf[1024];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(25));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Connect to the server
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(587);
  servaddr.sin_addr.s_addr = inet_addr("localhost");
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send email
  printf("Enter your email address: ");
  scanf("%s", buf);
  write(sockfd, buf, strlen(buf) + 1);

  printf("Enter the subject: ");
  scanf("%s", buf);
  write(sockfd, buf, strlen(buf) + 1);

  printf("Enter the message: ");
  scanf("%s", buf);
  write(sockfd, buf, strlen(buf) + 1);

  // Receive confirmation
  read(sockfd, buf, 1024);
  printf("%s", buf);

  // Close the socket
  close(sockfd);

  return 0;
}