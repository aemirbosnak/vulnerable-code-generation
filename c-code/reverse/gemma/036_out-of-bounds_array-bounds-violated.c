#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main() {
  int startPort, endPort, port, connfd, err;
  char buffer[1024];

  printf("Enter the starting port: ");
  scanf("%d", &startPort);

  printf("Enter the ending port: ");
  scanf("%d", &endPort);

  for (port = startPort; port <= endPort; port++) {
    connfd = -1;
    err = 0;

    // Attempt to connect to the port
    if ((connfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
      err = 1;
    } else {
      // Connect to the port
      if (connect(connfd, NULL, 0) == -1) {
        err = 1;
      } else {
        // Send a message to the port
        write(connfd, "Hello, world!", 13);

        // Receive a message from the port
        read(connfd, buffer, 1024);

        // Close the connection
        close(connfd);
      }
    }

    if (err) {
      printf("Error connecting to port %d\n", port);
    } else {
      printf("Port %d is open and responded with: %s\n", port, buffer);
    }
  }

  return 0;
}
