//Code Llama-13B DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
// internet_speed_test.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUF_SIZE];

  if (argc < 3) {
    fprintf(stderr, "usage %s hostname port\n", argv[0]);
    exit(0);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket failed");
    exit(1);
  }

  // Look up the IP address of the server
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }

  // Connect to the server
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
  serv_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Send a test file to the server
  FILE *fp;
  fp = fopen("testfile.txt", "r");
  if (fp == NULL) {
    perror("fopen failed");
    exit(1);
  }

  while ((n = fread(buffer, 1, BUF_SIZE, fp)) > 0) {
    write(sockfd, buffer, n);
  }

  // Close the file and socket
  fclose(fp);
  close(sockfd);

  return 0;
}