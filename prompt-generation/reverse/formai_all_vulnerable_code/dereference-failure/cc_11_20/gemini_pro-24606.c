//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

void handle_error(const char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  // Check if the user provided enough arguments.
  if (argc < 5) {
    printf("Usage: %s <server_address> <server_port> <from_email> <to_email>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Parse the server address and port.
  char *server_address = argv[1];
  int server_port = atoi(argv[2]);

  // Parse the email addresses.
  char *from_email = argv[3];
  char *to_email = argv[4];

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    handle_error("socket");
  }

  // Connect to the server.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(server_address);
  server_addr.sin_port = htons(server_port);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    handle_error("connect");
  }

  // Send the HELO command.
  char helo_cmd[MAX_LINE];
  sprintf(helo_cmd, "HELO %s\n", "localhost");

  if (send(sockfd, helo_cmd, strlen(helo_cmd), 0) == -1) {
    handle_error("send");
  }

  // Receive the server's response.
  char server_response[MAX_LINE];
  if (recv(sockfd, server_response, MAX_LINE, 0) == -1) {
    handle_error("recv");
  }

  // Check if the server's response is valid.
  if (strncmp(server_response, "250", 3) != 0) {
    printf("Error: Invalid server response: %s", server_response);
    exit(EXIT_FAILURE);
  }

  // Send the MAIL FROM command.
  char mail_from_cmd[MAX_LINE];
  sprintf(mail_from_cmd, "MAIL FROM: <%s>\n", from_email);

  if (send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0) == -1) {
    handle_error("send");
  }

  // Receive the server's response.
  if (recv(sockfd, server_response, MAX_LINE, 0) == -1) {
    handle_error("recv");
  }

  // Check if the server's response is valid.
  if (strncmp(server_response, "250", 3) != 0) {
    printf("Error: Invalid server response: %s", server_response);
    exit(EXIT_FAILURE);
  }

  // Send the RCPT TO command.
  char rcpt_to_cmd[MAX_LINE];
  sprintf(rcpt_to_cmd, "RCPT TO: <%s>\n", to_email);

  if (send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) == -1) {
    handle_error("send");
  }

  // Receive the server's response.
  if (recv(sockfd, server_response, MAX_LINE, 0) == -1) {
    handle_error("recv");
  }

  // Check if the server's response is valid.
  if (strncmp(server_response, "250", 3) != 0) {
    printf("Error: Invalid server response: %s", server_response);
    exit(EXIT_FAILURE);
  }

  // Send the DATA command.
  char data_cmd[] = "DATA\n";

  if (send(sockfd, data_cmd, strlen(data_cmd), 0) == -1) {
    handle_error("send");
  }

  // Receive the server's response.
  if (recv(sockfd, server_response, MAX_LINE, 0) == -1) {
    handle_error("recv");
  }

  // Check if the server's response is valid.
  if (strncmp(server_response, "354", 3) != 0) {
    printf("Error: Invalid server response: %s", server_response);
    exit(EXIT_FAILURE);
  }

  // Send the email body.
  char email_body[] = "Hello world!\n"
                       "This is an email sent from a C program.\n"
                       "It's a bit silly, but it works!\n";

  if (send(sockfd, email_body, strlen(email_body), 0) == -1) {
    handle_error("send");
  }

  // Send the dot character to indicate the end of the email body.
  char dot_char[] = ".\n";

  if (send(sockfd, dot_char, strlen(dot_char), 0) == -1) {
    handle_error("send");
  }

  // Receive the server's response.
  if (recv(sockfd, server_response, MAX_LINE, 0) == -1) {
    handle_error("recv");
  }

  // Check if the server's response is valid.
  if (strncmp(server_response, "250", 3) != 0) {
    printf("Error: Invalid server response: %s", server_response);
    exit(EXIT_FAILURE);
  }

  // Send the QUIT command.
  char quit_cmd[] = "QUIT\n";

  if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1) {
    handle_error("send");
  }

  // Receive the server's response.
  if (recv(sockfd, server_response, MAX_LINE, 0) == -1) {
    handle_error("recv");
  }

  // Check if the server's response is valid.
  if (strncmp(server_response, "221", 3) != 0) {
    printf("Error: Invalid server response: %s", server_response);
    exit(EXIT_FAILURE);
  }

  // Close the socket.
  close(sockfd);

  printf("Email sent successfully!\n");

  return 0;
}