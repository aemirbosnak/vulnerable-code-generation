//FormAI DATASET v1.0 Category: Port Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

void clear(void) {
  while (getchar() != '\n');
}

int main() {
  char ipAddress[20];
  int startPort;
  int endPort;
  int i, j;
  int scanFlag = 1;

  // Getting the IP Address
  printf("Enter the IP address of the target: ");
  fgets(ipAddress, 20, stdin);
  strtok(ipAddress, "\n");
  printf("Target: %s\n", ipAddress);

  // Getting the range of ports to scan
  printf("Enter the starting port: ");
  scanf("%d", &startPort);
  clear();
  printf("Enter the ending port: ");
  scanf("%d", &endPort);
  clear();

  printf("Scanning ports %d to %d...\n", startPort, endPort);

  // Declaring the socket and socket address for the target
  int sock;
  struct sockaddr_in target;

  // Creating the socket
  if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
    printf("Error creating socket...\n");
    exit(1);
  }

  // Preparing the target address
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = inet_addr(ipAddress);

  // Scanning each port in the range
  for (i = startPort; i <= endPort; i++) {
    // Preparing the target address
    target.sin_port = htons(i);

    // Connecting to the target
    if (connect(sock, (struct sockaddr *) &target, sizeof(target)) == 0) {
      printf("Port %d is open.\n", i);
      close(sock);
      sock = socket(PF_INET, SOCK_STREAM, 0);
    }
  }

  printf("Scan completed.\n");

  return 0;
}