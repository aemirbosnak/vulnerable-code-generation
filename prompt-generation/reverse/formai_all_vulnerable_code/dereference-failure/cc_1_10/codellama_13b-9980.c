//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
// Inquisitive C Network Ping Test Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PING_DATA_SIZE 32
#define PING_TIMEOUT 2

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <host>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  char *ping_data = "Hello, World!";

  // Create a raw socket
  int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // Set the timeout for the socket
  struct timeval timeout;
  timeout.tv_sec = PING_TIMEOUT;
  timeout.tv_usec = 0;
  if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
    perror("setsockopt() failed");
    return 1;
  }

  // Get the host IP address
  struct hostent *he = gethostbyname(host);
  if (he == NULL) {
    herror("gethostbyname() failed");
    return 1;
  }

  // Send the ping request
  struct sockaddr_in dest_addr;
  dest_addr.sin_family = AF_INET;
  dest_addr.sin_port = 0;
  dest_addr.sin_addr = *((struct in_addr *)he->h_addr);
  if (sendto(sock, ping_data, PING_DATA_SIZE, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
    perror("sendto() failed");
    return 1;
  }

  // Receive the ping response
  char buf[PING_DATA_SIZE];
  struct sockaddr_in source_addr;
  socklen_t source_addr_len = sizeof(source_addr);
  if (recvfrom(sock, buf, PING_DATA_SIZE, 0, (struct sockaddr *)&source_addr, &source_addr_len) < 0) {
    perror("recvfrom() failed");
    return 1;
  }

  // Print the ping result
  printf("Ping successful!\n");
  printf("Host: %s\n", inet_ntoa(source_addr.sin_addr));
  printf("Time: %f\n", (double)PING_TIMEOUT);

  // Close the socket
  close(sock);

  return 0;
}