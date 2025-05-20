//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

// Define the port range to scan
#define START_PORT 1
#define END_PORT 65535

// Define the timeout for each port scan
#define TIMEOUT 1

// Define the maximum number of concurrent connections
#define MAX_CONNECTIONS 100

// Main function
int main(int argc, char *argv[]) {
  // Check if the user provided an IP address
  if (argc != 2) {
    printf("Usage: %s <ip address>\n", argv[0]);
    exit(1);
  }

  // Get the IP address of the target host
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    printf("Invalid IP address: %s\n", argv[1]);
    exit(1);
  }

  // Create an array of file descriptors for the sockets
  int sockets[MAX_CONNECTIONS];

  // Create a socket for each port
  for (int i = START_PORT; i <= END_PORT; i++) {
    // Create a socket
    sockets[i] = socket(AF_INET, SOCK_STREAM, 0);
    if (sockets[i] == -1) {
      printf("Could not create socket: %s\n", strerror(errno));
      exit(1);
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockets[i], SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
      printf("Could not set socket timeout: %s\n", strerror(errno));
      exit(1);
    }

    // Connect to the target host
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(i);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockets[i], (struct sockaddr *)&addr, sizeof(addr)) == -1) {
      // Ignore errors for closed ports
      if (errno == ETIMEDOUT) {
        close(sockets[i]);
        sockets[i] = -1;
      } else {
        printf("Could not connect to port %d: %s\n", i, strerror(errno));
      }
    }
  }

  // Print the list of open ports
  for (int i = START_PORT; i <= END_PORT; i++) {
    if (sockets[i] != -1) {
      printf("Port %d is open\n", i);
    }
  }

  // Close the sockets
  for (int i = START_PORT; i <= END_PORT; i++) {
    if (sockets[i] != -1) {
      close(sockets[i]);
    }
  }

  return 0;
}