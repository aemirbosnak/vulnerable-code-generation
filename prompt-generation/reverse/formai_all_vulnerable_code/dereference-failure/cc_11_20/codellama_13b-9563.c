//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: high level of detail
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #include <sys/socket.h>
  #include <sys/types.h>

  #define BUFSIZE 1024

  int main(int argc, char *argv[]) {
      int sockfd;
      struct sockaddr_in server_addr;
      char *server_name = "smtp.gmail.com";
      char *message = "Subject: Hello from C\n\nThis is a test message from C.\n";
      char buf[BUFSIZE];

      if (argc != 3) {
          fprintf(stderr, "Usage: %s <to_address> <from_address>\n", argv[0]);
          return 1;
      }

      // Create a socket
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd < 0) {
          perror("socket() failed");
          return 1;
      }

      // Initialize the server address
      memset(&server_addr, 0, sizeof(server_addr));
      server_addr.sin_family = AF_INET;
      server_addr.sin_port = htons(25);
      if (inet_pton(AF_INET, server_name, &server_addr.sin_addr) <= 0) {
          perror("inet_pton() failed");
          return 1;
      }

      // Connect to the server
      if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
          perror("connect() failed");
          return 1;
      }

      // Send the HELO command
      if (send(sockfd, "HELO\r\n", strlen("HELO\r\n"), 0) < 0) {
          perror("send() failed");
          return 1;
      }

      // Send the MAIL command
      if (send(sockfd, "MAIL FROM:<", strlen("MAIL FROM:<"), 0) < 0) {
          perror("send() failed");
          return 1;
      }
      if (send(sockfd, argv[2], strlen(argv[2]), 0) < 0) {
          perror("send() failed");
          return 1;
      }
      if (send(sockfd, ">\r\n", strlen(">\r\n"), 0) < 0) {
          perror("send() failed");
          return 1;
      }

      // Send the RCPT command
      if (send(sockfd, "RCPT TO:<", strlen("RCPT TO:<"), 0) < 0) {
          perror("send() failed");
          return 1;
      }
      if (send(sockfd, argv[1], strlen(argv[1]), 0) < 0) {
          perror("send() failed");
          return 1;
      }
      if (send(sockfd, ">\r\n", strlen(">\r\n"), 0) < 0) {
          perror("send() failed");
          return 1;
      }

      // Send the DATA command
      if (send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
          perror("send() failed");
          return 1;
      }

      // Send the message
      if (send(sockfd, message, strlen(message), 0) < 0) {
          perror("send() failed");
          return 1;
      }

      // Send the final dot
      if (send(sockfd, ".\r\n", strlen(".\r\n"), 0) < 0) {
          perror("send() failed");
          return 1;
      }

      // Send the QUIT command
      if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
          perror("send() failed");
          return 1;
      }

      // Close the socket
      close(sockfd);

      return 0;
  }