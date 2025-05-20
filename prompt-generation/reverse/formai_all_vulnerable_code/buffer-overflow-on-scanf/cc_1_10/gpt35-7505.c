//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(){
  int socket_fd, in_port, out_port;
  char buffer[BUFFER_SIZE];

  // Prompt user for input ports
  printf("Enter input port number: ");
  scanf("%d", &in_port);
  printf("Enter output port number: ");
  scanf("%d", &out_port);

  // Create socket for packet monitoring
  socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
  if(socket_fd < 0){
    perror("Error creating socket");
    exit(1);
  }

  // Configure socket to listen on input port
  struct sockaddr_in saddr_in;
  saddr_in.sin_family = AF_INET;
  saddr_in.sin_port = htons(in_port);
  saddr_in.sin_addr.s_addr = INADDR_ANY;
  if(bind(socket_fd, (struct sockaddr *) &saddr_in, sizeof(saddr_in)) < 0){
    perror("Error binding socket");
    exit(1);
  }

  // Configure socket to send to output port
  struct sockaddr_in saddr_out;
  saddr_out.sin_family = AF_INET;
  saddr_out.sin_port = htons(out_port);
  inet_pton(AF_INET, "127.0.0.1", &saddr_out.sin_addr);
  
  // Start monitoring packets
  printf("Monitoring incoming packets on port %d. Sending to port %d...\n", in_port, out_port);
  while(1){
    // Receive packet
    int recv_bytes = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if(recv_bytes < 0){
      perror("Error receiving packet.");
      continue;
    }
    
    // Send packet to output port
    int send_bytes = sendto(socket_fd, buffer, recv_bytes, 0, (struct sockaddr *) &saddr_out, sizeof(saddr_out));
    if(send_bytes < 0){
      perror("Error sending packet.");
      continue;
    }
    
    printf("Packet received and sent successfully.\n");
  }

  return 0;
}