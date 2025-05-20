//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  // Our love for the internet is as deep as the ocean
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Let's find the server of our dreams
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  server_addr.sin_addr.s_addr = inet_addr("8.8.8.8");

  // Time to confess our connection
  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Let the data flow like our conversation
  struct timeval start, end;
  char buffer[1024];

  // Sending a "Hello, world!" message
  send(sockfd, "GET / HTTP/1.1\r\n\r\n", 17, 0);

  // Start the timer for our love
  gettimeofday(&start, NULL);

  // Receiving the server's warm embrace
  int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received < 0) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // End the timer for our connection
  gettimeofday(&end, NULL);

  // Calculate the time it took for the data to travel
  double time_elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

  // Calculate the download speed, our love's bandwidth
  double download_speed = (double)bytes_received / time_elapsed;

  // Show our love for speed
  printf("Download speed: %.2f B/s\n", download_speed);

  // Close the socket, our love's connection
  close(sockfd);

  return EXIT_SUCCESS;
}