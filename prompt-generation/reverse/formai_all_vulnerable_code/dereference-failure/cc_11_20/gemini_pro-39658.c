//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define SMTP_PORT 25
#define SMTP_HOST "smtp.example.com"

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <recipient>\n", argv[0]);
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct hostent *he = gethostbyname(SMTP_HOST);
  if (he == NULL) {
    fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
    return EXIT_FAILURE;
  }

  memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SMTP_PORT);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  char buffer[1024];
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  fprintf(stderr, "%s\n", buffer);

  snprintf(buffer, sizeof(buffer), "HELO %s\r\n", SMTP_HOST);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  fprintf(stderr, "%s\n", buffer);

  snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", argv[0]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  fprintf(stderr, "%s\n", buffer);

  snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", argv[1]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  fprintf(stderr, "%s\n", buffer);

  snprintf(buffer, sizeof(buffer), "DATA\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  fprintf(stderr, "%s\n", buffer);

  snprintf(buffer, sizeof(buffer), "Subject: Test email\r\n\r\nThis is a test email.\r\n\r\n.");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  fprintf(stderr, "%s\n", buffer);

  snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  fprintf(stderr, "%s\n", buffer);

  close(sockfd);
  return EXIT_SUCCESS;
}