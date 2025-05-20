#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  char buffer[1024];
  int len = 0;

  // Listen for packets on port 80
  int sockfd = socket(AF_INET, SOCK_RAW, htons(80));
  bind(sockfd, NULL, 0);

  // Receive packet data
  while (1) {
    len = recvfrom(sockfd, buffer, 1024, NULL, NULL, NULL);
    if (len > 0) {
      // Print packet data
      printf("Received packet of size %d bytes:\n", len);
      printf("Data: ");
      for (int i = 0; i < len; i++) {
        printf("%02x ", (int)buffer[i]);
      }
      printf("\n");
    }
  }

  return 0;
}
