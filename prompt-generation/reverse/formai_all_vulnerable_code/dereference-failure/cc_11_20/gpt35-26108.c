//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <pop_server_address> <pop_server_port>\n", argv[0]);
    exit(1);
  }

  // Create a socket to connect to the POP3 server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Could not create socket");
    exit(1);
  }

  // Get server hostname and port number
  char *server_address = argv[1];
  int server_port = atoi(argv[2]);

  // Resolve server hostname to IP address
  struct hostent *server = gethostbyname(server_address);
  if (server == NULL) {
    perror("Error resolving hostname");
    exit(1);
  }

  // Connect to server
  struct sockaddr_in server_addr;
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(server_port);
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("Could not connect to server");
    exit(1);
  }

  // Read server response
  char buffer[BUFFER_SIZE];
  bzero(buffer, sizeof(buffer));
  int n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  printf("%s", buffer);

  // Send USER command to server
  printf("Username: ");
  bzero(buffer, sizeof(buffer));
  fgets(buffer, sizeof(buffer), stdin);
  char user_command[BUFFER_SIZE];
  sprintf(user_command, "USER %s", buffer);
  n = write(sockfd, user_command, strlen(user_command));
  if (n < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Read server response
  bzero(buffer, sizeof(buffer));
  n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  printf("%s", buffer);

  // Send PASS command to server
  printf("Password: ");
  bzero(buffer, sizeof(buffer));
  fgets(buffer, sizeof(buffer), stdin);
  char pass_command[BUFFER_SIZE];
  sprintf(pass_command, "PASS %s", buffer);
  n = write(sockfd, pass_command, strlen(pass_command));
  if (n < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Read server response
  bzero(buffer, sizeof(buffer));
  n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  printf("%s", buffer);

  // Send LIST command to server
  char list_command[] = "LIST\n";
  n = write(sockfd, list_command, strlen(list_command));
  if (n < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Read server response
  bzero(buffer, sizeof(buffer));
  n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  printf("%s", buffer);

  // Send RETR command to server
  printf("Enter message number to retrieve: ");
  bzero(buffer, sizeof(buffer));
  fgets(buffer, sizeof(buffer), stdin);
  char retr_command[BUFFER_SIZE];
  sprintf(retr_command, "RETR %s", buffer);
  n = write(sockfd, retr_command, strlen(retr_command));
  if (n < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Read server response
  bzero(buffer, sizeof(buffer));
  while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
    printf("%s", buffer);
    bzero(buffer, sizeof(buffer));
  }
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }

  // Close socket
  close(sockfd);
  return 0;
}