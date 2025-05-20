//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 8080
#define MSS 1460
#define WINDOW_SIZE 5

int main() {
  int sockfd, newsockfd, opt = 1;
  struct sockaddr_in serv_addr, cli_addr;
  int addrlen = sizeof(serv_addr);
  char buffer[MSS];
  char filename[100];
  int n, rcv_window_size, cwnd_size;

  // Creating socket file descriptor
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Forcefully attaching socket to the port 8080
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // Forcefully attaching socket to the port 8080
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Now server is ready to listen and verify
  if (listen(sockfd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Accept the data packet from client and verify
  if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&addrlen)) < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }
  
  printf("TCP Server is now Ready for data transmission...\n");
  
  // File Name Receiving from Client
  n = recv(newsockfd, filename, 100, 0);
  filename[n] = '\0';

  // Open the requested file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error in reading file");
    return 1;
  }

  // Send window size to the client
  rcv_window_size = WINDOW_SIZE;
  send(newsockfd, &rcv_window_size, sizeof(rcv_window_size), 0);
  cwnd_size = MSS;

  // Slow Start Algorithm
  int ssthresh = MSS;
  int cwnd = MSS;

  while (1) {
    // Check if the congestion window is full
    if (cwnd >= cwnd_size) {
      // Send the data as per the window size
      while (cwnd >= MSS && (n = fread(buffer, sizeof(char), MSS, fp)) > 0) {
        send(newsockfd, buffer, n, 0);
        cwnd -= n;
      }
    }

    // Receive acknowledgement from the client
    int ack;
    recv(newsockfd, &ack, sizeof(ack), 0);

    // Update the congestion window
    if (ack == 1) {
      cwnd += MSS;
      if (cwnd > ssthresh) {
        cwnd_size += MSS;
      }
    } else {
      ssthresh = cwnd / 2;
      cwnd_size = ssthresh;
    }

    // If file transfer is complete
    if (n <= 0) {
      break;
    }
  }

  printf("File transfer complete\n");

  // Closing the socket file descriptor
  close(sockfd);
  close(newsockfd);
  fclose(fp);

  return 0;
}