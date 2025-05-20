//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

int main(void) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct timeval start, end;
  char buffer[1];
  char *server_ip = "129.187.0.1"; // Change this to the server IP address

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5000); // Change this to the server port number
  inet_pton(AF_INET, server_ip, &serv_addr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  gettimeofday(&start, NULL);

  for (int i = 0; i < 10; i++) {
    send(sockfd, buffer, 1, 0);
    recv(sockfd, buffer, 1, 0);
  }

  gettimeofday(&end, NULL);

  close(sockfd);

  printf("Time taken for 10 packets: %ld microseconds\n",
         (end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec) / 10);

  // The following lines are the puzzling part, where we calculate the internet speed
  // based on the time taken for 10 packets and the packet size (which is assumed to be 1 byte)
  int packet_size = 1;
  double bytes_sent = 10 * packet_size;
  double time_taken = (end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec) / 10.0;
  double internet_speed = bytes_sent / time_taken / 1024 / 1024; // Convert bytes to megabytes

  printf("Internet speed: %.2f Mbps\n", internet_speed);

  return 0;
}