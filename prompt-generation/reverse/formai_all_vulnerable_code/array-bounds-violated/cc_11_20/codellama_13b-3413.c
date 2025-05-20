//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_BUF 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <host> <username>\n", argv[0]);
    return 1;
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(POP3_PORT);
  server.sin_addr.s_addr = inet_addr(argv[1]);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect");
    return 1;
  }

  char buf[MAX_BUF];
  int n;

  // Send username and password
  n = snprintf(buf, MAX_BUF, "%s\r\n", argv[2]);
  if (send(sock, buf, n, 0) < 0) {
    perror("send");
    return 1;
  }

  // Read response
  n = recv(sock, buf, MAX_BUF, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }
  buf[n] = '\0';

  // Parse response
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Error: %s\n", buf);
    return 1;
  }

  // Send LIST command
  n = snprintf(buf, MAX_BUF, "LIST\r\n");
  if (send(sock, buf, n, 0) < 0) {
    perror("send");
    return 1;
  }

  // Read response
  n = recv(sock, buf, MAX_BUF, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }
  buf[n] = '\0';

  // Parse response
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Error: %s\n", buf);
    return 1;
  }

  // Read number of messages
  n = recv(sock, buf, MAX_BUF, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }
  buf[n] = '\0';

  // Parse number of messages
  int num_messages = atoi(buf);
  if (num_messages == 0) {
    printf("No messages\n");
    return 0;
  }

  // Read message sizes
  for (int i = 0; i < num_messages; i++) {
    n = recv(sock, buf, MAX_BUF, 0);
    if (n < 0) {
      perror("recv");
      return 1;
    }
    buf[n] = '\0';

    // Parse message size
    int message_size = atoi(buf);
    if (message_size == 0) {
      printf("Invalid message size\n");
      return 1;
    }

    // Read message
    n = recv(sock, buf, MAX_BUF, 0);
    if (n < 0) {
      perror("recv");
      return 1;
    }
    buf[n] = '\0';

    // Parse message
    char *message = buf;
    printf("Message %d: %s\n", i + 1, message);
  }

  // Send QUIT command
  n = snprintf(buf, MAX_BUF, "QUIT\r\n");
  if (send(sock, buf, n, 0) < 0) {
    perror("send");
    return 1;
  }

  // Read response
  n = recv(sock, buf, MAX_BUF, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }
  buf[n] = '\0';

  // Parse response
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Error: %s\n", buf);
    return 1;
  }

  close(sock);

  return 0;
}