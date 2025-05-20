//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <regex.h>

#define MAX_BUFF 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the hostname and port number from the command line.
  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a socket for the connection.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Get the IP address of the hostname.
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "gethostbyname: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Create a sockaddr_in structure.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr = *(struct in_addr *)host->h_addr;

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the LOGIN command.
  char *login_command = "LOGIN username password\n";
  if (send(sockfd, login_command, strlen(login_command), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the server.
  char buffer[MAX_BUFF];
  int nbytes = recv(sockfd, buffer, MAX_BUFF - 1, 0);
  if (nbytes < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  buffer[nbytes] = '\0';

  // Check if the login was successful.
  if (strstr(buffer, "+OK LOGIN successful") == NULL) {
    fprintf(stderr, "Login failed: %s\n", buffer);
    return EXIT_FAILURE;
  }

  // Send the LIST command.
  char *list_command = "LIST \"\"\n";
  if (send(sockfd, list_command, strlen(list_command), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the server.
  memset(buffer, 0, sizeof(buffer));
  nbytes = recv(sockfd, buffer, MAX_BUFF - 1, 0);
  if (nbytes < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  buffer[nbytes] = '\0';

  // Parse the response and print the list of mailboxes.
  regex_t regex;
  regcomp(&regex, "^\\* LIST \\((\\d+)\\) \"(.*)\"\n", REG_EXTENDED);

  regmatch_t matches[3];
  int match_count = 0;
  char *start_ptr = buffer;
  while ((match_count = regexec(&regex, start_ptr, 3, matches, 0)) == 0) {
    char *mailbox_name = strndup(start_ptr + matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so);
    printf("%s\n", mailbox_name);

    start_ptr += matches[0].rm_eo;
    free(mailbox_name);
  }

  regfree(&regex);

  // Send the QUIT command.
  char *quit_command = "QUIT\n";
  if (send(sockfd, quit_command, strlen(quit_command), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}