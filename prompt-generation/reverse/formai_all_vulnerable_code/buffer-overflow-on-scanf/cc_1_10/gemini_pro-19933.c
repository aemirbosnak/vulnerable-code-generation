//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the maximum number of open ports to report
#define MAX_OPEN_PORTS 10

// Define the port range to scan
#define START_PORT 1
#define END_PORT 65535

// Create a function to scan a single port
int scan_port(char *host, int port) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Set the socket timeout
  struct timeval timeout;
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
    perror("setsockopt");
    close(sockfd);
    return -1;
  }

  // Connect to the host
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(host);
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    close(sockfd);
    return 0;
  }

  // Close the socket
  close(sockfd);

  // Return 1 if the port is open
  return 1;
}

// Create a function to scan a range of ports
int scan_ports(char *host, int start_port, int end_port) {
  // Initialize the number of open ports
  int num_open_ports = 0;

  // Iterate over the range of ports
  for (int port = start_port; port <= end_port; port++) {
    // Scan the port
    int is_open = scan_port(host, port);

    // Increment the number of open ports if the port is open
    if (is_open) {
      num_open_ports++;
    }
  }

  // Return the number of open ports
  return num_open_ports;
}

// Create a function to print the results of the port scan
void print_results(char *host, int num_open_ports) {
  // Print the host
  printf("Host: %s\n", host);

  // Print the number of open ports
  printf("Number of open ports: %d\n", num_open_ports);

  // Print the open ports
  if (num_open_ports > 0) {
    printf("Open ports: ");
    for (int port = START_PORT; port <= END_PORT; port++) {
      int is_open = scan_port(host, port);
      if (is_open) {
        printf("%d ", port);
      }
    }
    printf("\n");
  }
}

// Create a function to get the hostname from the user
char *get_hostname() {
  // Declare a variable to store the hostname
  char *hostname;

  // Get the hostname from the user
  printf("Enter the hostname: ");
  scanf("%s", hostname);

  // Return the hostname
  return hostname;
}

// Create a function to get the port range from the user
void get_port_range(int *start_port, int *end_port) {
  // Get the start port from the user
  printf("Enter the start port: ");
  scanf("%d", start_port);

  // Get the end port from the user
  printf("Enter the end port: ");
  scanf("%d", end_port);
}

// Create a function to main
int main() {
  // Get the hostname from the user
  char *host = get_hostname();

  // Get the port range from the user
  int start_port, end_port;
  get_port_range(&start_port, &end_port);

  // Scan the ports
  int num_open_ports = scan_ports(host, start_port, end_port);

  // Print the results of the port scan
  print_results(host, num_open_ports);

  // Return 0
  return 0;
}