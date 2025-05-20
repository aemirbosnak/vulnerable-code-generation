//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, port;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUFFER_SIZE];
  char command[BUFFER_SIZE];
  char filename[BUFFER_SIZE];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  port = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error getting host by name\n");
    exit(EXIT_FAILURE);
  }

  memset((char *)&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
  serv_addr.sin_port = htons(port);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    exit(EXIT_FAILURE);
  }

  printf("Connected to server\n");

  while (1) {
    printf("Enter command: ");
    fgets(command, BUFFER_SIZE, stdin);

    if (strlen(command) > 0) {
      command[strlen(command) - 1] = '\0';  // Remove newline character
    }

    if (strcmp(command, "QUIT") == 0) {
      break;
    } else if (strcmp(command, "GET") == 0) {
      printf("Enter filename: ");
      fgets(filename, BUFFER_SIZE, stdin);
      filename[strlen(filename) - 1] = '\0';  // Remove newline character

      sprintf(buffer, "GET %s\n", filename);
      send(sockfd, buffer, strlen(buffer), 0);

      memset(buffer, 0, BUFFER_SIZE);
      recv(sockfd, buffer, BUFFER_SIZE, 0);

      if (strcmp(buffer, "File not found") == 0) {
        printf("File not found on server\n");
      } else {
        FILE *fp = fopen(filename, "w");
        if (fp == NULL) {
          perror("Error opening file");
          exit(EXIT_FAILURE);
        }

        while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
          fwrite(buffer, 1, strlen(buffer), fp);
        }

        fclose(fp);
        printf("File downloaded\n");
      }
    } else if (strcmp(command, "PUT") == 0) {
      printf("Enter filename: ");
      fgets(filename, BUFFER_SIZE, stdin);
      filename[strlen(filename) - 1] = '\0';  // Remove newline character

      sprintf(buffer, "PUT %s\n", filename);
      send(sockfd, buffer, strlen(buffer), 0);

      FILE *fp = fopen(filename, "r");
      if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
      }

      while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        send(sockfd, buffer, strlen(buffer), 0);
      }

      fclose(fp);
      printf("File uploaded\n");
    } else {
      printf("Invalid command\n");
    }
  }

  close(sockfd);

  return 0;
}