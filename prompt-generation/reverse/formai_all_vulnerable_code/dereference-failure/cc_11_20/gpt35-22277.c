//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_SIZE 4096

int main(int argc, char **argv) {
  int sockfd, bytes_recv, bytes_sent;
  char buffer[MAX_SIZE];
  struct sockaddr_in server_address;
  struct hostent *server;
  int portno = 143; // IMAP default port number
  char username[MAX_SIZE];
  char password[MAX_SIZE];

  if (argc < 2) {
    fprintf(stderr, "Usage: %s servername [portno]\n", argv[0]);
    exit(0);
  }

  if (argc > 2) {
    portno = atoi(argv[2]);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Couldn't create socket");
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Couldn't resolve host name");
    exit(1);
  }

  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(portno);
  memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Couldn't connect to server");
    exit(1);
  }

  bytes_recv = recv(sockfd, buffer, MAX_SIZE, 0);
  if (bytes_recv < 0) {
    perror("Couldn't receive data from server");
    exit(1);
  }

  // Send login request
  printf("Enter username: ");
  fgets(username, MAX_SIZE, stdin);
  printf("Enter password: ");
  fgets(password, MAX_SIZE, stdin);

  sprintf(buffer, "LOGIN %s %s\r\n", username, password);
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent < 0) {
    perror("Couldn't send data to server");
    exit(1);
  }

  bytes_recv = recv(sockfd, buffer, MAX_SIZE, 0);
  buffer[bytes_recv] = '\0';

  if (strncmp(buffer, "* OK", 4) != 0) {
    printf("Login failed: %s", buffer);
    exit(1);
  }

  printf("Logged in successfully\n");

  // Send select request
  sprintf(buffer, "SELECT INBOX\r\n");
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent < 0) {
    perror("Couldn't send data to server");
    exit(1);
  }

  bytes_recv = recv(sockfd, buffer, MAX_SIZE, 0);
  buffer[bytes_recv] = '\0';

  if (strncmp(buffer, "* OK", 4) != 0) {
    printf("Select failed: %s", buffer);
    exit(1);
  }

  printf("Inbox selected\n");

  // Send list request
  sprintf(buffer, "LIST \"\" *\r\n");
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent < 0) {
    perror("Couldn't send data to server");
    exit(1);
  }

  bytes_recv = recv(sockfd, buffer, MAX_SIZE, 0);
  buffer[bytes_recv] = '\0';

  if (strncmp(buffer, "* OK", 4) != 0) {
    printf("List failed: %s", buffer);
    exit(1);
  }

  printf("List of mailboxes:\n%s\n", buffer);

  // Close connection
  sprintf(buffer, "LOGOUT\r\n");
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent < 0) {
    perror("Couldn't send data to server");
    exit(1);
  }

  bytes_recv = recv(sockfd, buffer, MAX_SIZE, 0);
  buffer[bytes_recv] = '\0';

  if (strncmp(buffer, "* BYE", 5) != 0) {
    printf("Logout failed: %s", buffer);
    exit(1);
  }

  printf("Logged out successfully\n");

  close(sockfd);

  return 0;
}