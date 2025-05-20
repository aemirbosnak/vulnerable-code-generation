//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAXSIZE 1024

/* Send HTTP request to server */
void send_http_request(int sock, char *host, char *path) {
  char buffer[MAXSIZE];
  sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
  send(sock, buffer, strlen(buffer), 0);
}

/* Receive HTTP response from server */
void receive_http_response(int sock) {
  char buffer[MAXSIZE];
  int n;
  while ((n = recv(sock, buffer, MAXSIZE-1, 0)) > 0) {
    buffer[n] = '\0';
    printf("%s", buffer);
  }
}

int main(int argc, char **argv) {
  int sock, port;
  char *host, *path;
  struct sockaddr_in server;
  struct hostent *hp;

  if (argc != 3) {
    printf("Usage: %s <host> <path>\n", argv[0]);
    return 1;
  }

  host = argv[1];
  path = argv[2];
  port = 80;

  /* Create socket */
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Failed to create socket");
    return 1;
  }

  /* Resolve hostname to IP address */
  if ((hp = gethostbyname(host)) == NULL) {
    perror("Failed to resolve hostname");
    return 1;
  }

  /* Fill in server details */
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = *((unsigned long*)hp->h_addr);
  server.sin_port = htons(port);

  /* Connect to server */
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Failed to connect");
    return 1;
  }

  /* Send HTTP request to server */
  send_http_request(sock, host, path);

  /* Receive HTTP response from server */
  receive_http_response(sock);

  /* Close socket */
  close(sock);

  return 0;
}