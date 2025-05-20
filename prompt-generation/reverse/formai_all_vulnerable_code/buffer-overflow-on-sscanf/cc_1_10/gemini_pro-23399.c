//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
    return 1;
  }

  char *hostname = argv[1];
  char *username = argv[2];

  // Create a socket for the POP3 connection.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Connect to the POP3 server.
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(POP3_PORT);
  addr.sin_addr.s_addr = inet_addr(hostname);
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Receive the welcome message from the server.
  char buf[1024];
  int n = recv(sockfd, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return 1;
  }

  // Send the username to the server.
  sprintf(buf, "USER %s\r\n", username);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return 1;
  }

  // Receive the response from the server.
  n = recv(sockfd, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return 1;
  }

  // Send the password to the server.
  char *password = getpass("Password: ");
  sprintf(buf, "PASS %s\r\n", password);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return 1;
  }

  // Receive the response from the server.
  n = recv(sockfd, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return 1;
  }

  // Get the number of messages on the server.
  int num_messages;
  sscanf(buf, "+OK %d messages", &num_messages);

  // Get the size of the first message.
  long message_size;
  sscanf(buf, "+OK %*d %ld octets", &message_size);

  // Retrieve the first message.
  char *message = malloc(message_size);
  n = recv(sockfd, message, message_size, 0);
  if (n == -1) {
    perror("recv");
    return 1;
  }

  // Print the message to the console.
  printf("%s\n", message);

  // Close the socket.
  close(sockfd);

  return 0;
}