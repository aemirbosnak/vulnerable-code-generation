//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>
#include <stdbool.h>

#define BUFSIZE 1024

// Global variables
int trueFlag = 1;
int falseFlag = 0;
int sock, returnValue, addrLength;
int recvFromSize;
struct sockaddr_in clientAddress;
char buffer[BUFSIZE];
unsigned int qualityOfService = 0;

// Function to calculate Quality of Service
void calculateQualityOfService() {
  double rtt; // Round Trip Time (in ms)
  struct timeval currentTime, recvTime; // Variables to store send and receive TS
  long int sec, usec; // Variables to calculate microseconds

  gettimeofday(&currentTime, NULL); // Get current time
  sec = currentTime.tv_sec;
  usec = currentTime.tv_usec;

  // Send request to server
  sendto(sock, buffer, BUFSIZE, falseFlag, (struct sockaddr *)&clientAddress, addrLength);

  // Receive response from server
  recvFromSize = recvfrom(sock, buffer, BUFSIZE, falseFlag, (struct sockaddr *)&clientAddress, &addrLength);
  gettimeofday(&recvTime, NULL); // Get receive time
  sec = recvTime.tv_sec - sec;
  usec = recvTime.tv_usec - usec;

  rtt = (sec * 1000) + (usec / 1000.0); // Calculate Round Trip Time
  qualityOfService = (unsigned int)(BUFSIZE / rtt); // Calculate Quality of Service
}

int main(int argc, char *argv[]) {
  char *serverIP;
  struct hostent *server;
  int serverPort;

  // Check if IP Address and Port Number are provided
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <Server IP> <Server Port>\n", argv[0]);
    exit(1);
  }
  serverIP = argv[1];
  serverPort = atoi(argv[2]);

  // Create UDP socket
  sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sock < 0) {
    perror("Error in creating socket.");
    exit(1);
  }

  // Set socket options for Quality of Service
  setsockopt(sock, SOL_SOCKET, SO_PRIORITY, &qualityOfService, sizeof(qualityOfService));

  // Get server name
  server = gethostbyname(serverIP);
  if (server == NULL) {
    fprintf(stderr,"Error: No such host.\n");
    exit(1);
  }

  // Set server address structure
  struct sockaddr_in serverAddress;
  memset(&serverAddress, 0, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  bcopy(server->h_addr, &(serverAddress.sin_addr.s_addr), server->h_length);
  serverAddress.sin_port = htons(serverPort);

  // Set client address structure
  memset(&clientAddress, 0, sizeof(clientAddress));
  clientAddress.sin_family = AF_INET;
  clientAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  clientAddress.sin_port = htons(0);

  // Bind socket to client address
  returnValue = bind(sock, (struct sockaddr *)&clientAddress, sizeof(clientAddress));
  if (returnValue < 0) {
    perror("Error in binding client socket.");
    exit(1);
  }

  // Set server address length
  addrLength = sizeof(serverAddress);

  // Run Quality of Service Monitor for 10 seconds
  int i = 0;
  for(i = 0; i < 10; i++) {
    calculateQualityOfService();
    printf("Quality of Service: %u\n", qualityOfService);
    sleep(1);
  }

  // Close socket
  close(sock);
  return 0;
}