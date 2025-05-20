//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

// A relic from the old world, a POP3 client cobbled together from the remnants of the internet.
int main(int argc, char *argv[]) {

  if (argc < 3) {
    printf("Usage: %s <server> <port>\n", argv[0]);
    return 1;
  }

  // Reach out to the POP3 server, a beacon of hope in the digital wasteland.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    printf("Could not resolve server hostname\n");
    return 1;
  }
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  // Establish a connection, a lifeline to the past.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Could not create socket\n");
    return 1;
  }
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Could not connect to server\n");
    return 1;
  }

  // Greet the server, a faint echo of protocol amidst the chaos.
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    printf("Could not receive greeting from server\n");
    return 1;
  }
  printf("%s", buffer);

  // A user and password, remnants of a forgotten identity.
  char username[100];
  char password[100];
  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  scanf("%s", password);

  // Attempt to authenticate, a desperate plea for access to the trove of knowledge.
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "USER %s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    printf("Could not send username to server\n");
    return 1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    printf("Could not receive response from server\n");
    return 1;
  }
  printf("%s", buffer);

  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "PASS %s\r\n", password);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    printf("Could not send password to server\n");
    return 1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    printf("Could not receive response from server\n");
    return 1;
  }
  printf("%s", buffer);

  // List the messages, a glimmer of hope in the darkness.
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "LIST\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    printf("Could not send LIST command to server\n");
    return 1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    printf("Could not receive response from server\n");
    return 1;
  }
  printf("%s", buffer);

  // Retrieve the first message, a beacon of clarity amidst the static.
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "RETR 1\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    printf("Could not send RETR command to server\n");
    return 1;
  }
  while (1) {
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
      printf("Could not receive message from server\n");
      return 1;
    }
    if (strcmp(buffer, ".\r\n") == 0) {
      break;
    }
    printf("%s", buffer);
  }

  // Terminate the connection, a fleeting moment of closure in the wasteland.
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    printf("Could not send QUIT command to server\n");
    return 1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    printf("Could not receive response from server\n");
    return 1;
  }
  printf("%s", buffer);

  close(sockfd);
  return 0;
}