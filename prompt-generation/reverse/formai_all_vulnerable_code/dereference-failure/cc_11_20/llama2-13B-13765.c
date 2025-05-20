//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE_MIN 1024
#define PORT_RANGE_MAX 65535

int main(int argc, char *argv[]) {
  // Check for invalid usage
  if (argc < 3) {
    printf("Usage: %s <target_ip> <port_range>\n", argv[0]);
    return 1;
  }

  // Parse command-line arguments
  char *target_ip = argv[1];
  int port_range = atoi(argv[2]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Set the target IP address and port range
  struct sockaddr_in target;
  target.sin_family = AF_INET;
  target.sin_port = htons(port_range);
  inet_pton(AF_INET, target_ip, &target.sin_addr);

  // Connect to the target host
  if (connect(sock, (struct sockaddr *)&target, sizeof(target)) < 0) {
    perror("connect");
    close(sock);
    return 1;
  }

  // Scan for open ports
  for (int i = PORT_RANGE_MIN; i <= PORT_RANGE_MAX; i++) {
    struct sockaddr_in port;
    port.sin_family = AF_INET;
    port.sin_port = htons(i);
    inet_pton(AF_INET, target_ip, &port.sin_addr);

    // Send a SYN packet to the target port
    int packet_len = send(sock, "ABC", 3, 0);
    if (packet_len < 0) {
      perror("send");
      continue;
    }

    // Receive a SYN-ACK packet back
    char buffer[1024];
    ssize_t len = recv(sock, buffer, 1024, 0);
    if (len < 0) {
      perror("recv");
      continue;
    }

    // Check if the port is open
    if (len == 13 && buffer[0] == 'A' && buffer[1] == 'B' && buffer[2] == 'C') {
      printf("Port %d is open on %s\n", i, target_ip);
    }
  }

  // Close the socket
  close(sock);

  return 0;
}