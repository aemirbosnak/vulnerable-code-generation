//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: brave
// Brave Network Topology Mapper
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_HOSTS 100
#define MAX_HOSTNAME_LEN 256
#define MAX_PORT 65535
#define MAX_PACKET_SIZE 1024

typedef struct {
  int port;
  char hostname[MAX_HOSTNAME_LEN];
  char ip_addr[INET_ADDRSTRLEN];
} host_info_t;

typedef struct {
  int host_count;
  host_info_t hosts[MAX_HOSTS];
} network_topology_t;

void get_network_topology(network_topology_t *topology) {
  int i, j, k, sockfd, n, recvlen;
  char buffer[MAX_PACKET_SIZE];
  struct sockaddr_in servaddr, cliaddr;
  struct hostent *hostinfo;
  socklen_t clilen;

  // Create a UDP socket
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    exit(1);
  }

  // Initialize the server address structure
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(MAX_PORT);

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind failed");
    exit(1);
  }

  // Set the socket to non-blocking mode
  if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0) {
    perror("fcntl failed");
    exit(1);
  }

  // Set the timeout for the recvfrom function
  struct timeval tv;
  tv.tv_sec = 1;
  tv.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0) {
    perror("setsockopt failed");
    exit(1);
  }

  // Start the main loop
  for (i = 0; i < MAX_HOSTS; i++) {
    // Set the timeout for the recvfrom function
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0) {
      perror("setsockopt failed");
      exit(1);
    }

    // Receive the packet from the network
    clilen = sizeof(cliaddr);
    if ((recvlen = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&cliaddr, &clilen)) < 0) {
      // Check if the error is due to timeout
      if (errno == EAGAIN || errno == EWOULDBLOCK) {
        // No packet received, continue to the next iteration
        continue;
      } else {
        perror("recvfrom failed");
        exit(1);
      }
    }

    // Get the hostname and IP address of the sender
    hostinfo = gethostbyaddr((char *)&cliaddr.sin_addr, sizeof(cliaddr.sin_addr), cliaddr.sin_family);
    if (hostinfo == NULL) {
      perror("gethostbyaddr failed");
      exit(1);
    }

    // Get the port number of the sender
    int port = ntohs(cliaddr.sin_port);

    // Add the sender's information to the topology
    topology->hosts[i].port = port;
    strcpy(topology->hosts[i].hostname, hostinfo->h_name);
    strcpy(topology->hosts[i].ip_addr, inet_ntoa(cliaddr.sin_addr));
  }

  // Close the socket
  close(sockfd);
}

int main() {
  network_topology_t topology;
  get_network_topology(&topology);
  printf("Network Topology:\n");
  for (int i = 0; i < topology.host_count; i++) {
    printf("%s (%s:%d)\n", topology.hosts[i].hostname, topology.hosts[i].ip_addr, topology.hosts[i].port);
  }
  return 0;
}