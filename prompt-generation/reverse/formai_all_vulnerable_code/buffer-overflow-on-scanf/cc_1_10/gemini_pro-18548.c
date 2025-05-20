//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: medieval
// Hark! A Network Ping Test in Medieval Tongue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

struct sockaddr_in sock_addr;
struct timeval tv_start, tv_end;
char *host_addr;
int sock, timeout = 1000, recv_len;
char buffer[1024];

int main() {
  // Greeting, fair user!
  printf("Welcome, noble user! Let us embark on a network ping test.\n");

  // Query the host address
  printf("Enter the host address thou wishest to test, good sir: ");
  scanf("%s", host_addr);

  // Create a socket, a window into the network
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) {
    perror("Socket creation failed, alas!");
    exit(1);
  }

  // Prepare the address of the host
  memset(&sock_addr, 0, sizeof(sock_addr));
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_addr.s_addr = inet_addr(host_addr);
  sock_addr.sin_port = htons(80);

  // Send a missive to the host
  int bytes_sent = sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *) &sock_addr, sizeof(sock_addr));
  if (bytes_sent < 0) {
    perror("Message sending failed, woe is me!");
    exit(1);
  }

  // Record the time of departure
  gettimeofday(&tv_start, NULL);

  // Await a reply from the host
  recv_len = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
  if (recv_len < 0) {
    perror("No reply received, alas!");
    exit(1);
  }

  // Record the time of arrival
  gettimeofday(&tv_end, NULL);

  // Calculate the time elapsed
  double time_elapsed = (double) (tv_end.tv_sec - tv_start.tv_sec) + (double) (tv_end.tv_usec - tv_start.tv_usec) / 1000000;

  // Display the results
  printf("Hark! The message reached its destination in %f seconds.\n", time_elapsed);

  // Close the socket, our window into the network
  close(sock);

  // Bid farewell
  printf("May good fortune be with thee, valiant user!\n");

  return 0;
}