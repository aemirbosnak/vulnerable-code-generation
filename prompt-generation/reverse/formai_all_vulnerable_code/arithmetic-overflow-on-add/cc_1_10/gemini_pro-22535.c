//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char** argv)
{
  // Let's get excited about pinging!
  printf("\nPrepare for ping-tastic greatness!\n");

  // Who are we pinging?
  if (argc < 2)
  {
    printf("Hola! You need to give me an IP address or hostname to ping.\n");
    return -1;
  }
  char* hostname = argv[1];

  // Create a socket to send packets
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0)
  {
    printf("Oops! Couldn't create a socket. Maybe try again?");
    return -1;
  }

  // Set up the ping packet
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(33434);
  if (inet_aton(hostname, &addr.sin_addr) == 0)
  {
    printf("Hmm, that doesn't look like a valid IP address. Please try again!");
    return -1;
  }

  char* buffer = "Ping!";
  int len = strlen(buffer);

  // Time to ping!
  struct timeval start, end;

  int num_pings = 4;
  int received = 0;
  for (int i = 0; i < num_pings; i++)
  {
    // Send the ping packet
    gettimeofday(&start, NULL);
    int sent = sendto(sockfd, buffer, len, 0, (struct sockaddr*)&addr, sizeof(addr));
    if (sent < 0)
    {
      printf("Uh-oh, there was a problem sending the ping packet.");
      return -1;
    }

    // Wait for a response
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    int result = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
    if (result == -1)
    {
      printf("Whoops! There was a problem waiting for the response.");
      return -1;
    }

    // Did we get a response?
    if (result > 0)
    {
      // Get the response
      socklen_t addr_len = sizeof(addr);
      char recvbuffer[1024];
      int n = recvfrom(sockfd, recvbuffer, 1024, 0, (struct sockaddr*)&addr, &addr_len);
      if (n < 0)
      {
        printf("Oops! There was a problem receiving the response.");
        return -1;
      }

      // Check if the response is what we expected
      if (strcmp(recvbuffer, "Ping!") != 0)
      {
        printf("Hmm, that's not the response we were expecting. Weird.");
        return -1;
      }

      gettimeofday(&end, NULL);
      double time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
      printf("Ping %d: %lf ms\n", i + 1, time);
      received++;
    }
    else
    {
      printf("No response received for ping %d.\n", i + 1);
    }
  }

  // Yay! We're done pinging
  printf("\nPinging complete! We received %d out of %d pings.\n", received, num_pings);
  close(sockfd);
  return 0;
}