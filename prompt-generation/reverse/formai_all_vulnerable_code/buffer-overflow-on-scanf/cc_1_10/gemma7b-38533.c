//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_PINGS 5

int main() {
  int sockfd, i, port = 53000;
  char hostname[256];
  struct sockaddr_in serv_addr;
  int ping_count = 0;
  FILE *fp;

  // Open a file for logging
  fp = fopen("ping_log.txt", "w");

  // Loop to get the hostname from the user
  printf("Enter the hostname: ");
  scanf("%s", hostname);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));

  // Bind the socket to a port
  serv_addr.sin_port = htons(port);
  bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

  // Send and receive pings
  for (i = 0; i < MAX_PINGS; i++) {
    // Send a ping message
    sendto(sockfd, "PING", 5, 0, (struct sockaddr *)hostname, sizeof(hostname));

    // Receive a ping response
    char resp[256];
    recvfrom(sockfd, resp, 256, 0, (struct sockaddr *)hostname, NULL);

    // Log the ping response
    fprintf(fp, "Ping %d: %s\n", ping_count, resp);

    // Increment the ping count
    ping_count++;
  }

  // Close the file
  fclose(fp);

  // Print the ping results
  printf("Ping results:\n");
  fp = fopen("ping_log.txt", "r");
  char line[256];
  while (fgets(line, 256, fp) != NULL) {
    printf("%s", line);
  }
  fclose(fp);

  return 0;
}