//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#define MAX_PACKET_SIZE 4096

void qos_monitor(int socket_fd) {
  struct sockaddr_in server_addr;
  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

  if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("[ERROR] Failed to connect to server: %s\n", strerror(errno));
    return;
  }

  char buffer[MAX_PACKET_SIZE];
  memset(buffer, 0, MAX_PACKET_SIZE);
  int bytes_sent = send(socket_fd, buffer, MAX_PACKET_SIZE, 0);
  if (bytes_sent < 0) {
    printf("[ERROR] Failed to send packet to server: %s\n", strerror(errno));
    return;
  }

  printf("[INFO] Packet sent successfully\n");

  char response_buffer[MAX_PACKET_SIZE];
  int bytes_recv = recv(socket_fd, response_buffer, MAX_PACKET_SIZE, 0);
  if (bytes_recv < 0) {
    printf("[ERROR] Failed to receive response from server: %s\n", strerror(errno));
    return;
  }

  printf("[INFO] Response received successfully\n");

  // analyze response_time
  struct timespec before, after;
  clock_gettime(CLOCK_REALTIME, &before);
  printf("[DEBUG] Before time: %ld\n", before.tv_nsec);
  // this could be replaced with actual response processing
  sleep(1);
  clock_gettime(CLOCK_REALTIME, &after);
  printf("[DEBUG] After time: %ld\n", after.tv_nsec);

  if (after.tv_sec - before.tv_sec > 0) {
    printf("[ERROR] Response took longer than 1 second\n");
  } else {
    if (after.tv_nsec - before.tv_nsec > 500000000) {
      printf("[WARNING] Response took longer than 500 milliseconds\n");
    } else {
      printf("[INFO] Response time within normal range\n");
    }
  }
}

int main() {
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    printf("[ERROR] Failed to create socket: %s\n", strerror(errno));
    return -1;
  }

  qos_monitor(socket_fd);

  close(socket_fd);

  return 0;
}