//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define IMAP_PORT 143

void read_response(int sockfd, char* response, int buffer_size);
int get_status_code(char* response);

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s username@hostname\n", argv[0]);
    return 1;
  }

  char* hostname = strchr(argv[1], '@') + 1;
  char* username = strndup(argv[1], strlen(argv[1]) - strlen(hostname) - 1);

  // Connect to the IMAP server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error opening socket\n");
    return 1;
  }

  struct hostent* server = gethostbyname(hostname);
  if (server == NULL) {
    printf("Error resolving hostname\n");
    return 1;
  }

  struct sockaddr_in serv_addr = { 0 };
  serv_addr.sin_family = AF_INET;
  bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(IMAP_PORT);

  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error connecting to server\n");
    return 1;
  }

  // Authenticate with username and password

  // Send LOGIN command to server
  char* login_cmd = malloc(strlen(username) + 30);
  sprintf(login_cmd, "LOGIN %s *", username);

  char response[1024];
  read_response(sockfd, response, sizeof(response));

  // Send username
  char* username_cmd = malloc(strlen(username) + 10);
  sprintf(username_cmd, "%s\r\n", username);

  send(sockfd, username_cmd, strlen(username_cmd), 0);
  read_response(sockfd, response, sizeof(response));

  // Send password
  char password[1024];
  printf("Password: ");
  fgets(password, 1024, stdin);

  char* password_cmd = malloc(strlen(password) + 10);
  password[strlen(password)-1] = '\0'; // Remove newline character
  sprintf(password_cmd, "%s\r\n", password);

  send(sockfd, password_cmd, strlen(password_cmd), 0);

  read_response(sockfd, response, sizeof(response));

  // Check if login was successful
  int status_code = get_status_code(response);
  if (status_code != 2) {
    printf("Login failed: %s", response);
    return 1;
  }

  free(login_cmd);
  free(username);
  free(username_cmd);
  free(password_cmd);

  printf("Logged in successfully!\n");

  // Recursive function to continue reading commands from input stream
  char buffer[1024];
  while (1) {
    printf("> ");
    fgets(buffer, 1024, stdin);

    if (strcmp(buffer, "exit\n") == 0) {
      break;
    }

    // Remove newline character from buffer
    buffer[strlen(buffer)-1] = '\0';

    // Send command to server
    send(sockfd, buffer, strlen(buffer), 0);

    // Read response from server
    read_response(sockfd, response, sizeof(response));

    // Print response
    printf("%s", response);
  }

  // Send LOGOUT command to server
  send(sockfd, "LOGOUT\r\n", 9, 0);

  read_response(sockfd, response, sizeof(response));
  close(sockfd);

  return 0;
}

void read_response(int sockfd, char* response, int buffer_size) {
  int offset = 0;

  while (1) {
    int bytes_received = recv(sockfd, response + offset, buffer_size - offset, 0);

    if (bytes_received == -1) {
      printf("Error receiving data from server\n");
      break;
    }

    offset += bytes_received;

    if (response[offset - 2] == '\r' && response[offset - 1] == '\n') {
      break;
    }

    if (offset >= buffer_size) {
      printf("Response too large for buffer\n");
      break;
    }
  }

  response[offset] = '\0';
}

int get_status_code(char* response) {
  char code[4] = { 0 };
  strncpy(code, response, 3);
  return atoi(code);
}