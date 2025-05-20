//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Establish connection to the server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket creation failed");
    return EXIT_FAILURE;
  }

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connection failed");
    return EXIT_FAILURE;
  }

  // Send authentication credentials
  char buf[1024];
  sprintf(buf, "USER %s\r\n", "your_username");
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, sizeof(buf), 0);

  sprintf(buf, "PASS %s\r\n", "your_password");
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, sizeof(buf), 0);

  // Retrieve message headers
  sprintf(buf, "LIST\r\n");
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, sizeof(buf), 0);

  // Parse and display message headers
  char *msgNum;
  char *msgSize;
  while (sscanf(buf, "+OK %s %s\r\n", msgNum, msgSize) == 2) {
    printf("Message %s: %s bytes\n", msgNum, msgSize);
  }

  // Retrieve specific message
  sprintf(buf, "RETR %s\r\n", "message_number");
  send(sockfd, buf, strlen(buf), 0);

  // Parse and display message body
  char *messageBody;
  while ((messageBody = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
    printf("%s", messageBody);
  }

  // Close connection
  close(sockfd);

  return EXIT_SUCCESS;
}