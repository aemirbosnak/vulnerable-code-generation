//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server> <username> [<password>]\n", argv[0]);
    return 1;
  }

  char *server = argv[1];
  char *username = argv[2];
  char *password = argc >= 4 ? argv[3] : NULL;

  struct hostent *host = gethostbyname(server);
  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve hostname '%s'\n", server);
    return 1;
  }

  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_port = htons(POP3_PORT);
  memcpy(&address.sin_addr, host->h_addr, host->h_length);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error: could not create socket");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) == -1) {
    perror("Error: could not connect to server");
    return 1;
  }

  char buffer[1024];

  // Receive the greeting from the server
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("Error: could not receive greeting from server");
    return 1;
  }

  printf("%s", buffer);

  // Send the username
  snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("Error: could not send username to server");
    return 1;
  }

  // Receive the response from the server
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("Error: could not receive response from server");
    return 1;
  }

  printf("%s", buffer);

  // Send the password
  if (password != NULL) {
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
      perror("Error: could not send password to server");
      return 1;
    }
  }

  // Receive the response from the server
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("Error: could not receive response from server");
    return 1;
  }

  printf("%s", buffer);

  // Send the QUIT command
  snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("Error: could not send QUIT command to server");
    return 1;
  }

  // Receive the response from the server
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("Error: could not receive response from server");
    return 1;
  }

  printf("%s", buffer);

  // Close the socket
  if (close(sockfd) == -1) {
    perror("Error: could not close socket");
    return 1;
  }

  return 0;
}