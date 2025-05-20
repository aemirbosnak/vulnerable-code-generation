//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: excited
// Unique C Port Scanner example program in an excited style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 100
#define MAX_HOSTS 100

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <host> <port1>-<port2>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  char *port_range = argv[2];
  char *port_str;
  char *delim = "-";

  // Split the port range into two ports
  port_str = strtok(port_range, delim);
  int port1 = atoi(port_str);
  port_str = strtok(NULL, delim);
  int port2 = atoi(port_str);

  // Initialize the socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("Failed to create socket\n");
    return 1;
  }

  // Set the port and address
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port1);
  addr.sin_addr.s_addr = inet_addr(host);

  // Loop through all the ports
  for (int port = port1; port <= port2; port++) {
    // Set the current port
    addr.sin_port = htons(port);

    // Attempt to connect to the port
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
      printf("Port %d is open\n", port);
    } else {
      printf("Port %d is closed\n", port);
    }
  }

  // Close the socket
  close(sock);
  return 0;
}