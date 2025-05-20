//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

#define MAX_SITES 10
#define MAX_SITE_LEN 100

int sites[MAX_SITES][MAX_SITE_LEN];
int num_sites;

int sockfd;
struct sockaddr_in servaddr;

void free_sockets() {
  close(sockfd);
}

void sigint_handler(int sig) {
  free_sockets();
  exit(0);
}

int main() {
  // Read the sites from a file
  FILE *f = fopen("sites.txt", "r");
  if (f == NULL) {
    perror("fopen");
    return 1;
  }
  num_sites = 0;
  while (fgets(sites[num_sites], MAX_SITE_LEN, f) != NULL) {
    // Remove the newline character from the site
    sites[num_sites][strlen(sites[num_sites]) - 1] = '\0';
    num_sites++;
  }
  fclose(f);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Set up the server address
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(80);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return 1;
  }

  // Register the signal handler
  signal(SIGINT, sigint_handler);

  // Main loop
  while (1) {
    // Check each site
    for (int i = 0; i < num_sites; i++) {
      // Send the HTTP request
      char request[MAX_SITE_LEN + 100];
      sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", sites[i], sites[i]);
      if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return 1;
      }

      // Receive the HTTP response
      char response[1024];
      int n = recv(sockfd, response, 1024, 0);
      if (n == -1) {
        perror("recv");
        return 1;
      }

      // Check the status code
      char status_code[4];
      strncpy(status_code, response + 9, 3);
      status_code[3] = '\0';
      int code = atoi(status_code);

      // Print the status code
      printf("%s: ", sites[i]);
      if (code == 200) {
        printf("OK\n");
      } else {
        printf("DOWN (%d)\n", code);
      }
    }

    // Sleep for 1 minute
    sleep(60);
  }

  // Free the sockets
  free_sockets();

  return 0;
}