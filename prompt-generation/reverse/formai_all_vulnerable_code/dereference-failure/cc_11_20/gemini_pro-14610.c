//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// The main function
int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments
  if (argc < 3) {
    printf("Usage: %s <server> <port>\n", argv[0]);
    return 1;
  }

  // Get the server address and port number
  char *server = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 2;
  }

  // Resolve the server address
  struct hostent *host = gethostbyname(server);
  if (host == NULL) {
    perror("gethostbyname");
    return 3;
  }

  // Create a sockaddr_in structure
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  memcpy(&addr.sin_addr, host->h_addr, host->h_length);

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return 4;
  }

  // Send the USER command
  char *user = "USER username\r\n";
  if (send(sock, user, strlen(user), 0) == -1) {
    perror("send");
    return 5;
  }

  // Receive the server response
  char buf[1024];
  if (recv(sock, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 6;
  }

  // Check if the server response is OK
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Error: %s\n", buf);
    return 7;
  }

  // Send the PASS command
  char *pass = "PASS password\r\n";
  if (send(sock, pass, strlen(pass), 0) == -1) {
    perror("send");
    return 8;
  }

  // Receive the server response
  if (recv(sock, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 9;
  }

  // Check if the server response is OK
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Error: %s\n", buf);
    return 10;
  }

  // Send the LIST command
  char *list = "LIST\r\n";
  if (send(sock, list, strlen(list), 0) == -1) {
    perror("send");
    return 11;
  }

  // Receive the server response
  while (1) {
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
      perror("recv");
      return 12;
    }

    if (strncmp(buf, ".", 1) == 0) {
      break;
    }

    printf("%s", buf);
  }

  // Send the QUIT command
  char *quit = "QUIT\r\n";
  if (send(sock, quit, strlen(quit), 0) == -1) {
    perror("send");
    return 13;
  }

  // Close the socket
  close(sock);

  return 0;
}