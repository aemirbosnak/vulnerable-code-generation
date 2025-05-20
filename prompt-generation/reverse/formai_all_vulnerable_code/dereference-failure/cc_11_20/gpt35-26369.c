//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  struct hostent *he;
  struct in_addr **addr_list;

  if ((he = gethostbyname(argv[1])) == NULL) {
    perror("Could not resolve hostname");
    exit(EXIT_FAILURE);
  }

  addr_list = (struct in_addr **)he->h_addr_list;
  printf("IP Address for %s:\n", argv[1]);
  for (int i = 0; addr_list[i] != NULL; i++) {
    printf("%s\n", inet_ntoa(*addr_list[i]));
  }

  int sockfd, bytes, sent, received, total;
  char message[BUFFER_SIZE], response[BUFFER_SIZE];

  snprintf(message, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);

  struct sockaddr_in server_address = { 0 };
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr = *((struct in_addr *)he->h_addr);

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Could not create socket");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Could not connect to server");
    exit(EXIT_FAILURE);
  }

  total = strlen(message);
  sent = 0;
  do {
    bytes = write(sockfd, message + sent, total - sent);
    if (bytes < 0) {
      perror("Could not send message");
      exit(EXIT_FAILURE);
    }
    if (bytes == 0) {
      break;
    }
    sent += bytes;
  } while (sent < total);

  memset(response, 0, sizeof(response));
  total = BUFFER_SIZE - 1;
  received = 0;
  do {
    bytes = read(sockfd, response + received, total - received);
    if (bytes < 0) {
      perror("Could not receive response");
      exit(EXIT_FAILURE);
    }
    if (bytes == 0) {
      break;
    }
    received += bytes;
  } while (received < total);

  if (received == total) {
    perror("Could not receive entire response");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", response);

  close(sockfd);

  return 0;
}