//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
  int sockfd, newsockfd, portno, clilen, bytes_received;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[MAX_DATA_SIZE];
  char *file_name;
  FILE *fp;
  int file_size;
  time_t start_time, end_time;
  double elapsed_time;
  int bytes_sent = 0;

  printf("Internet Speed Test Application\n");

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error creating socket\n");
    exit(1);
  }

  portno = SERVER_PORT;

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error connecting to server\n");
    exit(1);
  }

  printf("Connected to server\n");

  clilen = sizeof(cli_addr);
  getpeername(sockfd, (struct sockaddr *)&cli_addr, &clilen);
  printf("Client IP address: %s\n", inet_ntoa(cli_addr.sin_addr));
  printf("Client port number: %d\n", ntohs(cli_addr.sin_port));

  if (send(sockfd, "START_TEST", strlen("START_TEST"), 0) < 0) {
    printf("Error sending data to server\n");
    exit(1);
  }

  bytes_sent += strlen("START_TEST");

  if (recv(sockfd, buffer, MAX_DATA_SIZE, 0) < 0) {
    printf("Error receiving data from server\n");
    exit(1);
  }

  file_name = strtok(buffer, "\n");
  fp = fopen(file_name, "rb");
  if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }

  fseek(fp, 0, SEEK_END);
  file_size = ftell(fp);
  rewind(fp);

  start_time = time(NULL);

  while (fread(buffer, sizeof(char), MAX_DATA_SIZE, fp) > 0) {
    bytes_sent += send(sockfd, buffer, MAX_DATA_SIZE, 0);
  }

  end_time = time(NULL);
  elapsed_time = difftime(end_time, start_time);

  printf("File size: %d bytes\n", file_size);
  printf("Bytes sent: %d\n", bytes_sent);
  printf("Elapsed time: %.2f seconds\n", elapsed_time);
  printf("Speed: %.2f bytes/second\n", (double)bytes_sent / elapsed_time);

  fclose(fp);
  close(sockfd);

  return 0;
}