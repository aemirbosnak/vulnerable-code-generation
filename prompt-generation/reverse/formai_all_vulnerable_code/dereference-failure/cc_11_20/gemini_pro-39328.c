//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MSG_LEN 1024

int main(int argc, char** argv) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <server> <port> <username>\n", argv[0]);
    return 1;
  }

  char* server = argv[1];
  int port = atoi(argv[2]);
  char* username = argv[3];

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  struct hostent* host = gethostbyname(server);
  if (host == NULL) {
    fprintf(stderr, "Could not resolve hostname %s\n", server);
    return 1;
  }
  memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Could not create socket");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("Could not connect to server");
    return 1;
  }

  char* login_msg = "USER ";
  char* login_end = "\r\n";
  char* login = malloc(strlen(login_msg) + strlen(username) + strlen(login_end));
  strcpy(login, login_msg);
  strcat(login, username);
  strcat(login, login_end);

  if (send(sockfd, login, strlen(login), 0) < 0) {
    perror("Could not send login message");
    return 1;
  }

  char* recv_buf = malloc(MAX_MSG_LEN);
  if (recv(sockfd, recv_buf, MAX_MSG_LEN, 0) < 0) {
    perror("Could not receive login response");
    return 1;
  }

  if (strncmp(recv_buf, "+OK", 3) != 0) {
    fprintf(stderr, "Invalid login response: %s\n", recv_buf);
    return 1;
  }

  printf("Logged in as %s\n", username);

  while (1) {
    printf("> ");
    char* input = malloc(MAX_MSG_LEN);
    fgets(input, MAX_MSG_LEN, stdin);

    if (input[0] == '.') {
      if (strcmp(input, ".quit\n") == 0) {
        break;
      } else {
        printf("Invalid command\n");
        continue;
      }
    }

    if (send(sockfd, input, strlen(input), 0) < 0) {
      perror("Could not send message");
      return 1;
    }

    if (recv(sockfd, recv_buf, MAX_MSG_LEN, 0) < 0) {
      perror("Could not receive message");
      return 1;
    }

    printf("%s\n", recv_buf);
  }

  close(sockfd);
  return 0;
}