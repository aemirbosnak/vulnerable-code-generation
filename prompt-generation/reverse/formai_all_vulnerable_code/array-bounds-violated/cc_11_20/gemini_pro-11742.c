//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 587

const char *WELCOME_MSG = "220";
const char *HELO_MSG = "HELO %s\r\n";
const char *MAIL_FROM_MSG = "MAIL FROM: <%s>\r\n";
const char *RCPT_TO_MSG = "RCPT TO: <%s>\r\n";
const char *DATA_MSG = "DATA\r\n";
const char *MSG_END_MSG = ".";
const char *QUIT_MSG = "QUIT\r\n";

int main(int argc, char *argv[]) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <server_ip> <from_email> <to_email>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *server_ip = argv[1];
  char *from_email = argv[2];
  char *to_email = argv[3];

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  char buffer[4096];
  int len;

  while ((len = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
    buffer[len] = '\0';
    if (strncmp(buffer, WELCOME_MSG, strlen(WELCOME_MSG)) == 0) {
      printf("Received welcome message: %s\n", buffer);

      sprintf(buffer, HELO_MSG, "myhostname");
      send(sockfd, buffer, strlen(buffer), 0);
      printf("Sent HELO message: %s\n", buffer);
    } else if (strncmp(buffer, "250", 3) == 0) {
      printf("Received OK message: %s\n", buffer);

      sprintf(buffer, MAIL_FROM_MSG, from_email);
      send(sockfd, buffer, strlen(buffer), 0);
      printf("Sent MAIL FROM message: %s\n", buffer);
    } else if (strncmp(buffer, "250", 3) == 0) {
      printf("Received OK message: %s\n", buffer);

      sprintf(buffer, RCPT_TO_MSG, to_email);
      send(sockfd, buffer, strlen(buffer), 0);
      printf("Sent RCPT TO message: %s\n", buffer);
    } else if (strncmp(buffer, "250", 3) == 0) {
      printf("Received OK message: %s\n", buffer);

      send(sockfd, DATA_MSG, strlen(DATA_MSG), 0);
      printf("Sent DATA message: %s\n", DATA_MSG);
    } else if (strncmp(buffer, "354", 3) == 0) {
      printf("Received start mail input message: %s\n", buffer);

      char *subject = "This is a test email subject";
      char *body = "This is a test email body";

      sprintf(buffer, "%s\r\nFrom: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n",
            "MIME-Version: 1.0",
            from_email,
            to_email,
            subject,
            body);
      send(sockfd, buffer, strlen(buffer), 0);

      send(sockfd, MSG_END_MSG, strlen(MSG_END_MSG), 0);
      printf("Sent email message: %s\n", buffer);
    } else if (strncmp(buffer, "250", 3) == 0) {
      printf("Received OK message: %s\n", buffer);

      send(sockfd, QUIT_MSG, strlen(QUIT_MSG), 0);
      printf("Sent QUIT message: %s\n", QUIT_MSG);
    } else {
      fprintf(stderr, "Received error: %s\n", buffer);
      return EXIT_FAILURE;
    }
  }

  if (len == 0) {
    printf("Connection closed by server\n");
  } else if (len < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  close(sockfd);
  return EXIT_SUCCESS;
}