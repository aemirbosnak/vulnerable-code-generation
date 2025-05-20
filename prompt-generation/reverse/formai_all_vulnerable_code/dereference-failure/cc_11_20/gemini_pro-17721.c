//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: excited
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define SMTP_PORT 25
#define MAX_LINE 1024

int main() {
  // Get the hostname and port number to connect to.
  char hostname[MAX_LINE];
  int port;
  printf("Yay! Let's send an email!\n");
  printf("Give me the hostname of the SMTP server: ");
  scanf("%s", hostname);
  printf("And the port number (default 25): ");
  scanf("%d", &port);
  if (port == 0) {
    port = SMTP_PORT;
  }

  // Initialize a socket to the SMTP server.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Ooops! I couldn't create a socket!");
    exit(EXIT_FAILURE);
  }
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("Ooh noes! I couldn't find the host!");
    exit(EXIT_FAILURE);
  }
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);

  // Connect to the SMTP server.
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    perror("Uh-oh! I couldn't connect to the server!");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's greeting.
  char greeting[MAX_LINE];
  if (recv(sockfd, greeting, MAX_LINE, 0) == -1) {
    perror("Whoops! I couldn't read the greeting!");
    exit(EXIT_FAILURE);
  }
  printf("The SMTP server says: %s", greeting);

  // Send the HELO command.
  char helo_cmd[MAX_LINE];
  sprintf(helo_cmd, "HELO %s\r\n", hostname);
  if (send(sockfd, helo_cmd, strlen(helo_cmd), 0) == -1) {
    perror("D'oh! I couldn't send the HELO command!");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's response.
  char response[MAX_LINE];
  if (recv(sockfd, response, MAX_LINE, 0) == -1) {
    perror("Darn it! I couldn't read the response!");
    exit(EXIT_FAILURE);
  }
  printf("The SMTP server says: %s", response);

  // Send the MAIL FROM command.
  char mail_from_cmd[MAX_LINE];
  printf("Who's the lucky sender, my friend? Let's write: MAIL FROM: ");
  char sender[MAX_LINE];
  scanf("%s", sender);
  sprintf(mail_from_cmd, "MAIL FROM:<%s>\r\n", sender);
  if (send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0) == -1) {
    perror("Oh, no! I couldn't send the MAIL FROM command!");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's response.
  if (recv(sockfd, response, MAX_LINE, 0) == -1) {
    perror("Aww, man! I couldn't read the response!");
    exit(EXIT_FAILURE);
  }
  printf("The SMTP server says: %s", response);

  // Send the RCPT TO command.
  char rcpt_to_cmd[MAX_LINE];
  printf("Alright, who's the lucky recipient? We'll write: RCPT TO: ");
  char recipient[MAX_LINE];
  scanf("%s", recipient);
  sprintf(rcpt_to_cmd, "RCPT TO:<%s>\r\n", recipient);
  if (send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) == -1) {
    perror("Oops! I couldn't send the RCPT TO command!");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's response.
  if (recv(sockfd, response, MAX_LINE, 0) == -1) {
    perror("Blast it! I couldn't read the response!");
    exit(EXIT_FAILURE);
  }
  printf("The SMTP server says: %s", response);

  // Send the DATA command.
  char data_cmd[] = "DATA\r\n";
  if (send(sockfd, data_cmd, strlen(data_cmd), 0) == -1) {
    perror("Aw, snap! I couldn't send the DATA command!");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's response.
  if (recv(sockfd, response, MAX_LINE, 0) == -1) {
    perror("Yikes! I couldn't read the response!");
    exit(EXIT_FAILURE);
  }
  printf("The SMTP server says: %s", response);

  // Send the email body.
  printf("Now, let's write the email! Type away, my friend! (Type a '.' on a new line to finish)\n");
  char email_body[MAX_LINE];
  char line[MAX_LINE];
  while (true) {
    fgets(line, MAX_LINE, stdin);
    if (strcmp(line, ".\n") == 0) {
      break;
    }
    strcat(email_body, line);
  }
  if (send(sockfd, email_body, strlen(email_body), 0) == -1) {
    perror("Doh! I couldn't send the email body!");
    exit(EXIT_FAILURE);
  }

  // Send the termination command.
  char termination_cmd[] = "\r\n.\r\n";
  if (send(sockfd, termination_cmd, strlen(termination_cmd), 0) == -1) {
    perror("Oops! I couldn't send the termination command!");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's response.
  if (recv(sockfd, response, MAX_LINE, 0) == -1) {
    perror("Drat! I couldn't read the response!");
    exit(EXIT_FAILURE);
  }
  printf("The SMTP server says: %s", response);

  // Close the socket.
  close(sockfd);

  printf("Ta-da! Your email has been sent! Yay you!");
  return 0;
}