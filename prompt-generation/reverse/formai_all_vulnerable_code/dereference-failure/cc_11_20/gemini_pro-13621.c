//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25

int main() {
  // Let's connect to the SMTP server with a big smile!
  struct sockaddr_in server_addr;
  socklen_t server_addr_len = sizeof(server_addr);
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Find the server's address. (We're just sending a message to localhost.)
  struct hostent *server = gethostbyname("localhost");
  if (server == NULL) {
    fprintf(stderr, "gethostbyname error\n");
    return EXIT_FAILURE;
  }

  // Set up the server address.
  memset(&server_addr, 0, server_addr_len);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SMTP_PORT);
  memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&server_addr, server_addr_len) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Get the server's welcome message.
  char buffer[256];
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send HELO.
  if (send(sockfd, "HELO localhost\r\n", 15, 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Get the server's response.
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send MAIL FROM.
  if (send(sockfd, "MAIL FROM: <sender@localhost>\r\n", 30, 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Get the server's response.
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send RCPT TO.
  if (send(sockfd, "RCPT TO: <recipient@localhost>\r\n", 30, 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Get the server's response.
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send DATA.
  if (send(sockfd, "DATA\r\n", 6, 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Get the server's response.
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send the email body.
  if (send(sockfd, "Subject: Happy Birthday!\r\n\r\nDear recipient,\r\n\nI hope this email finds you well. I'm writing to wish you a happy birthday! I hope you have a wonderful day filled with joy and laughter. Best wishes,\n\nSender", 170, 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Send the period to indicate the end of the email body.
  if (send(sockfd, ".\r\n", 3, 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Get the server's response.
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send QUIT.
  if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}