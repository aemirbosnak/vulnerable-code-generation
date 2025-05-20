//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 80
#define HOST "www.google.com"
#define NUM_ITERATIONS 10
#define BUFF_SIZE 1024

int main(int argc, char** argv) {
  int sockfd, ret;
  struct sockaddr_in serv_addr;
  char buff[BUFF_SIZE];
  struct timeval start, end;
  double time_taken;
  int i;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Set up the server address
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_addr.s_addr = inet_addr(HOST);

  // Connect to the server
  ret = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
  if (ret < 0) {
    perror("connect");
    close(sockfd);
    return -1;
  }

  // Send a request to the server
  strcpy(buff, "HEAD / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");
  ret = send(sockfd, buff, strlen(buff), 0);
  if (ret < 0) {
    perror("send");
    close(sockfd);
    return -1;
  }

  // Receive the response from the server
  memset(buff, 0, BUFF_SIZE);
  ret = recv(sockfd, buff, BUFF_SIZE, 0);
  if (ret < 0) {
    perror("recv");
    close(sockfd);
    return -1;
  }

  // Get the current time
  gettimeofday(&start, NULL);

  // Send and receive data for NUM_ITERATIONS times
  for (i = 0; i < NUM_ITERATIONS; i++) {
    memset(buff, 0, BUFF_SIZE);
    strcpy(buff, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");
    ret = send(sockfd, buff, strlen(buff), 0);
    if (ret < 0) {
      perror("send");
      close(sockfd);
      return -1;
    }

    memset(buff, 0, BUFF_SIZE);
    ret = recv(sockfd, buff, BUFF_SIZE, 0);
    if (ret < 0) {
      perror("recv");
      close(sockfd);
      return -1;
    }
  }

  // Get the current time
  gettimeofday(&end, NULL);

  // Calculate the time taken for the data transfer
  time_taken = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;

  // Calculate the average speed
  double avg_speed = (double)(NUM_ITERATIONS * BUFF_SIZE) / time_taken;

  // Print the results
  printf("Average speed: %.2f KB/s\n", avg_speed / 1024);

  // Close the socket
  close(sockfd);

  return 0;
}