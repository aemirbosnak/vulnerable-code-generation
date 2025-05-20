//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
/*
 * Building a SMTP Client example program in an artistic style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in server;
  char buf[BUFSIZE];
  char *ptr;
  char *host;
  char *port;

  // Parse command line arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  host = argv[1];
  port = argv[2];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket()");
    exit(EXIT_FAILURE);
  }

  // Set up the server address
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(port));
  if (inet_pton(AF_INET, host, &server.sin_addr) <= 0) {
    perror("inet_pton()");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect()");
    exit(EXIT_FAILURE);
  }

  // Send the message to the server
  ptr = buf;
  sprintf(ptr, "HELO %s\r\n", host);
  ptr += strlen(ptr);
  sprintf(ptr, "MAIL FROM: <artistic-smtp-client@example.com>\r\n");
  ptr += strlen(ptr);
  sprintf(ptr, "RCPT TO: <artistic-smtp-client@example.com>\r\n");
  ptr += strlen(ptr);
  sprintf(ptr, "DATA\r\n");
  ptr += strlen(ptr);
  sprintf(ptr, "Subject: Artistic SMTP Client\r\n");
  ptr += strlen(ptr);
  sprintf(ptr, "From: Artistic SMTP Client <artistic-smtp-client@example.com>\r\n");
  ptr += strlen(ptr);
  sprintf(ptr, "To: Artistic SMTP Client <artistic-smtp-client@example.com>\r\n");
  ptr += strlen(ptr);
  sprintf(ptr, "\r\n");
  ptr += strlen(ptr);
  sprintf(ptr, "Hello, world!\r\n");
  ptr += strlen(ptr);
  sprintf(ptr, ".\r\n");
  ptr += strlen(ptr);
  sprintf(ptr, "QUIT\r\n");
  ptr += strlen(ptr);

  if (send(sockfd, buf, ptr - buf, 0) < 0) {
    perror("send()");
    exit(EXIT_FAILURE);
  }

  // Close the socket
  close(sockfd);

  return 0;
}