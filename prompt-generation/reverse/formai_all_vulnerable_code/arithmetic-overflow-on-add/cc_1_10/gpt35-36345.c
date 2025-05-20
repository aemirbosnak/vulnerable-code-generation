//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024 // buffer size for receiving data

int main(int argc, char *argv[]) {
  
  if (argc != 2) { // verify if the program is called with the correct argument
    fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));

  // set up the server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_port = htons(8080);

  // create a socket
  int server_sock = socket(PF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("socket");
    return 1;
  }

  // connect to the server
  int err = connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (err < 0) {
    perror("connect");
    return 1;
  }

  // continuously monitor the QoS of the network
  while (1) {
    char buffer[BUFFER_SIZE];
    // receive data from the server
    ssize_t recv_size = recv(server_sock, buffer, BUFFER_SIZE, MSG_WAITALL);
    if (recv_size < 0) {
      perror("recv");
      break;
    } else if (recv_size == 0) {
      fprintf(stderr, "Connection closed by server.\n");
      break;
    }
    // analyze the received data and calculate the QoS
    int num_received_packets = recv_size / sizeof(int);
    int sum = 0;
    for (int i = 0; i < num_received_packets; i++) {
      int packet = *(int *)(buffer + i * sizeof(int));
      sum += packet;
    }
    double qos = sum / (double)num_received_packets;
    printf("Current QoS: %.2f\n", qos);
    sleep(1); // wait for 1 second to simulate periodic monitoring
  }

  // close the connection and socket
  close(server_sock);
  return 0;
}