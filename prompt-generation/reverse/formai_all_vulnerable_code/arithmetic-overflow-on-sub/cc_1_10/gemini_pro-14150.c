//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

// Macros for network quality of service (QoS)
#define TOS_DEFAULT 0
#define TOS_LOW_DELAY 16
#define TOS_THROUGHPUT 8
#define TOS_RELIABLE 4

// Function to set the network QoS for a socket
int set_qos(int sockfd, int tos) {
  int qos = tos;
  if (setsockopt(sockfd, IPPROTO_IP, IP_TOS, &qos, sizeof(qos)) == -1) {
    return -1;
  }
  return 0;
}

// Function to monitor the network QoS
void monitor_qos(int sockfd) {
  struct timeval start, end;
  int bytes_sent, bytes_received;
  int qos;
  socklen_t qos_len = sizeof(qos);

  // Get the current QoS settings
  if (getsockopt(sockfd, IPPROTO_IP, IP_TOS, &qos, &qos_len) == -1) {
    perror("getsockopt");
    exit(EXIT_FAILURE);
  }

  // Start the timer
  gettimeofday(&start, NULL);

  // Send and receive data
  bytes_sent = send(sockfd, "Hello world", 12, 0);
  bytes_received = recv(sockfd, "Hello world", 12, 0);

  // Stop the timer
  gettimeofday(&end, NULL);

  // Calculate the elapsed time and throughput
  double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
  double throughput = (bytes_sent + bytes_received) / elapsed_time;

  // Print the results
  printf("QoS: %d\n", qos);
  printf("Elapsed time: %.2f ms\n", elapsed_time);
  printf("Throughput: %.2f bps\n", throughput);
}

int main() {
  int sockfd;
  struct sockaddr_in servaddr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the network QoS
  if (set_qos(sockfd, TOS_LOW_DELAY) == -1) {
    perror("set_qos");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(8080);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Monitor the network QoS
  monitor_qos(sockfd);

  // Close the socket
  close(sockfd);

  return 0;
}