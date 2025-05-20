//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define INTERVAL 1 // sampling interval in seconds

struct timespec timespec_diff(struct timespec start, struct timespec end) {
  struct timespec diff;
  if (end.tv_nsec < start.tv_nsec) {
    diff.tv_sec = end.tv_sec - start.tv_sec - 1;
    diff.tv_nsec = end.tv_nsec + 1000000000 - start.tv_nsec;
  } else {
    diff.tv_sec = end.tv_sec - start.tv_sec;
    diff.tv_nsec = end.tv_nsec - start.tv_nsec;
  }
  return diff;
}

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
    exit(1);
  }
  const char *ip = argv[1];
  const char *port = argv[2];

  // create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    error("socket");
  }

  // create address struct
  struct addrinfo hints;
  struct addrinfo *result;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET; // IPv4
  hints.ai_socktype = SOCK_STREAM; // TCP
  int s = getaddrinfo(ip, port, &hints, &result);
  if (s != 0) {
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(s));
    exit(1);
  }

  // connect to server
  int res = connect(sockfd, result->ai_addr, result->ai_addrlen);
  if (res == -1) {
    error("connect");
  }

  // set socket to non-blocking mode
  int flags = fcntl(sockfd, F_GETFL, 0);
  if (flags == -1) {
    error("fcntl F_GETFL");
  }
  res = fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
  if (res == -1) {
    error("fcntl F_SETFL O_NONBLOCK");
  }

  // initialize variables
  char buffer[BUFFER_SIZE];
  struct timespec start_time, end_time;
  int bytes_sent = 0, bytes_received = 0;
  int packets_sent = 0, packets_received = 0;
  int send_errors = 0, recv_errors = 0;

  // start monitoring loop
  while (1) {
    // reset start time and clear buffer
    clock_gettime(CLOCK_REALTIME, &start_time);
    memset(buffer, 0, sizeof(buffer));

    // send a packet
    int n = send(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1 && errno == EAGAIN) { // socket is non-blocking
      send_errors++;
    } else if (n == -1) {
      error("send");
    } else {
      bytes_sent += n;
      packets_sent++;
    }

    // receive a packet
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1 && errno == EAGAIN) { // socket is non-blocking
      recv_errors++;
    } else if (n == -1) {
      error("recv");
    } else {
      bytes_received += n;
      packets_received++;
    }

    // calculate and print metrics
    clock_gettime(CLOCK_REALTIME, &end_time);
    struct timespec diff = timespec_diff(start_time, end_time);
    if (diff.tv_sec >= INTERVAL) {
      double send_rate = (double) bytes_sent / (double) diff.tv_sec;
      double recv_rate = (double) bytes_received / (double) diff.tv_sec;
      double send_loss = 1.0 - (double) packets_received / (double) packets_sent;
      double recv_loss = 1.0 - (double) packets_sent / (double) packets_received;
      printf("Send Rate: %.2f bytes/sec, Recv Rate: %.2f bytes/sec, Send Loss: %.2f%%, Recv Loss: %.2f%%\n",
             send_rate, recv_rate, send_loss * 100.0, recv_loss * 100.0);
      printf("Send Errors: %d, Recv Errors: %d\n", send_errors, recv_errors);
      bytes_sent = 0;
      bytes_received = 0;
      packets_sent = 0;
      packets_received = 0;
      send_errors = 0;
      recv_errors = 0;
    }

    // wait for INTERVAL seconds
    struct timespec wait_time = {INTERVAL, 0};
    nanosleep(&wait_time, NULL);
  }

  // close socket
  close(sockfd);

  return 0;
}