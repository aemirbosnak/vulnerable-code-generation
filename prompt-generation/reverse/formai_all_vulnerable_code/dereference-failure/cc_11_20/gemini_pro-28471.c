//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define BUFSIZE 4096

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <port> <destination>\n", argv[0]);
    return 1;
  }

  // Create a TCP socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Bind the socket to the specified port
  struct sockaddr_in sockaddr;
  memset(&sockaddr, 0, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  sockaddr.sin_port = htons(atoi(argv[1]));

  if (bind(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) == -1) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    return 1;
  }

  while (1) {
    // Accept an incoming connection
    struct sockaddr_in client_sockaddr;
    socklen_t client_sockaddr_size = sizeof(client_sockaddr);
    int clientfd = accept(sockfd, (struct sockaddr*)&client_sockaddr, &client_sockaddr_size);
    if (clientfd == -1) {
      perror("accept");
      continue;
    }

    // Get the destination host and port
    char* destination = argv[2];
    char* host;
    char* port;
    if (strchr(destination, ':') != NULL) {
      host = strtok(destination, ":");
      port = strtok(NULL, ":");
    } else {
      host = destination;
      port = "80";
    }

    // Create a TCP socket to the destination
    int remotefd = socket(AF_INET, SOCK_STREAM, 0);
    if (remotefd == -1) {
      perror("socket");
      close(clientfd);
      continue;
    }

    // Connect to the destination
    struct sockaddr_in remote_sockaddr;
    memset(&remote_sockaddr, 0, sizeof(remote_sockaddr));
    remote_sockaddr.sin_family = AF_INET;
    remote_sockaddr.sin_addr.s_addr = inet_addr(host);
    remote_sockaddr.sin_port = htons(atoi(port));

    if (connect(remotefd, (struct sockaddr*)&remote_sockaddr, sizeof(remote_sockaddr)) == -1) {
      perror("connect");
      close(clientfd);
      close(remotefd);
      continue;
    }

    // Proxy the data between the client and the destination
    char buf[BUFSIZE];
    while (1) {
      // Read data from the client
      int n = read(clientfd, buf, BUFSIZE);
      if (n == -1) {
        perror("read");
        break;
      } else if (n == 0) {
        break;
      }

      // Write the data to the destination
      int m = write(remotefd, buf, n);
      if (m == -1) {
        perror("write");
        break;
      }
    }

    // Close the connections
    close(clientfd);
    close(remotefd);
  }

  // Close the listening socket
  close(sockfd);

  return 0;
}