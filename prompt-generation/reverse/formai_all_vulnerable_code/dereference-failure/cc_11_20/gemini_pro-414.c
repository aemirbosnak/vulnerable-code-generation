//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 4096
#define PORT 8080

int main() {
  int s, c, r;
  struct sockaddr_in sa, ca;
  char buf[BUFSIZE];
  char* target_host;
  int target_port;

  // Initialize the server socket
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s == -1) {
    perror("socket");
    exit(1);
  }

  // Set the server socket options
  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_addr.s_addr = htonl(INADDR_ANY);
  sa.sin_port = htons(PORT);

  if (bind(s, (struct sockaddr*)&sa, sizeof(sa)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(s, 5) == -1) {
    perror("listen");
    exit(1);
  }

  // Accept incoming connections
  while (1) {
    c = sizeof(ca);
    c = accept(s, (struct sockaddr*)&ca, &c);
    if (c == -1) {
      perror("accept");
      continue;
    }

    // Read the request from the client
    r = recv(c, buf, BUFSIZE, 0);
    if (r == -1) {
      perror("recv");
      close(c);
      continue;
    }

    // Parse the request
    target_host = strtok(buf, " :\r\n");
    target_port = atoi(strtok(NULL, " :\r\n"));
    if (target_host == NULL || target_port == 0) {
      close(c);
      continue;
    }

    // Connect to the target host
    int t = socket(AF_INET, SOCK_STREAM, 0);
    if (t == -1) {
      perror("socket");
      close(c);
      continue;
    }

    struct sockaddr_in ta;
    memset(&ta, 0, sizeof(ta));
    ta.sin_family = AF_INET;
    ta.sin_addr.s_addr = inet_addr(target_host);
    ta.sin_port = htons(target_port);

    if (connect(t, (struct sockaddr*)&ta, sizeof(ta)) == -1) {
      perror("connect");
      close(t);
      close(c);
      continue;
    }

    // Forward the request to the target host
    send(t, buf, r, 0);

    // Receive the response from the target host
    while ((r = recv(t, buf, BUFSIZE, 0)) > 0) {
      send(c, buf, r, 0);
    }

    // Close the connections
    close(t);
    close(c);
  }

  close(s);
  return 0;
}