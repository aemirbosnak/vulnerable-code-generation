//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[BUFFERSIZE];

  if (argc != 3) {
    fprintf(stderr,"Usage: %s <server_address> <port>\n", argv[0]);
    return 1;
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    return 1;
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr,"Error: no such host\n");
    return 1;
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    return 1;
  }

  printf("Connected to FTP server.\n");

  while (1) {
    printf("> ");

    bzero(buffer, BUFFERSIZE);
    fgets(buffer, BUFFERSIZE-1, stdin);

    if (strstr(buffer, "get") != NULL) {
      char *filename = strtok(buffer, " ");
      filename = strtok(NULL, " ");
      filename[strlen(filename)-1] = 0;

      printf("Getting file: %s\n", filename);

      // Send get command to server
      char get_command[BUFFERSIZE];
      sprintf(get_command, "get %s\n", filename);
      n = write(sockfd, get_command, strlen(get_command));
      if (n < 0) {
        perror("Error writing to socket");
        break;
      }

      // Open file for writing
      FILE *file = fopen(filename, "wb");
      if (file == NULL) {
        perror("Error opening file");
        break;
      }

      // Receive file data from server and write to file
      while (1) {
        bzero(buffer, BUFFERSIZE);
        n = read(sockfd, buffer, BUFFERSIZE-1);
        if (n < 0) {
          perror("Error reading from socket");
          break;
        } else if (n == 0) {
          break;
        } else {
          fwrite(buffer, sizeof(char), n, file);
        }
      }

      fclose(file);
      printf("File transfer complete!\n");
    } else if (strstr(buffer, "quit") != NULL) {
      // Send quit command to server and exit program
      n = write(sockfd, "quit\n", strlen("quit\n"));
      if (n < 0) {
        perror("Error writing to socket");
      }
      break;
    } else {
      // Invalid command
      printf("Invalid command.\n");
    }
  }

  close(sockfd);
  printf("Disconnected from FTP server.\n");

  return 0;
}