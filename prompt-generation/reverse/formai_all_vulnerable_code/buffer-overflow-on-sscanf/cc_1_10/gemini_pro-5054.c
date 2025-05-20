//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Ah, the enchanting realm of port scanning!
// Behold, a mystical voyage through the ethereal domains of interconnected devices.

int main(int argc, char* argv[]) {
  // Let's gather the secrets of our quest:
  if (argc < 3) {
    printf("Usage: %s [target IP] [port range]\n", argv[0]);
    exit(1);
  }

  // Decode the mystical IP address:
  struct sockaddr_in target;
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = inet_addr(argv[1]);

  // Unveil the range of portals we shall seek:
  int minPort, maxPort;
  sscanf(argv[2], "%d-%d", &minPort, &maxPort);

  // Summon the ethereal socket:
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket creation failed");
    exit(2);
  }

  // As we journey through each portal, we shall bow to the wise oracle of connect():
  for (int port = minPort; port <= maxPort; port++) {
    target.sin_port = htons(port);

    // Attempt to establish a mystical connection:
    if (connect(sockfd, (struct sockaddr*)&target, sizeof(target)) == 0) {
      printf("Port %d: Open\n", port);
    }
    else {
      printf("Port %d: Closed\n", port);
    }
  }

  // As our quest ends, we bid farewell to the ethereal realms:
  close(sockfd);
  return 0;
}