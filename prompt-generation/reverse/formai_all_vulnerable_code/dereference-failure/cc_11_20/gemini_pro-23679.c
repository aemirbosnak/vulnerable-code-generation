//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

// A weak attempt at Claude Shannon's style
// The program is a simple FTP client that can connect to a server, list directory contents, and download files.

int main(int argc, char **argv) {
  // Argument check
  if(argc != 3) {
    fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parsing server information
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid server IP address\n");
    return EXIT_FAILURE;
  }

  // Creating a socket
  int sockfd;
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connecting to the server
  if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Main loop
  while(1) {
    // Displaying prompt
    printf("ftp> ");

    // Getting command from user
    char command[1024];
    fgets(command, sizeof(command), stdin);

    // Parsing command
    char *token = strtok(command, " ");
    if(token == NULL) {
      continue;
    }

    // Handling commands
    if(strcmp(token, "ls") == 0) {
      // Listing directory contents
      send(sockfd, "LIST", strlen("LIST"), 0);
      char buffer[1024];
      int nbytes;
      while((nbytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
      }
      if(nbytes < 0) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
      }
    } else if(strcmp(token, "get") == 0) {
      // Downloading a file
      char filename[1024];
      strcpy(filename, strtok(NULL, " "));
      send(sockfd, "GET", strlen("GET"), 0);
      send(sockfd, filename, strlen(filename), 0);
      char buffer[1024];
      int nbytes;
      FILE *fp = fopen(filename, "w");
      while((nbytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, nbytes, 1, fp);
      }
      fclose(fp);
      if(nbytes < 0) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
      }
      printf("File downloaded\n");
    } else if(strcmp(token, "quit") == 0) {
      // Quitting
      send(sockfd, "QUIT", strlen("QUIT"), 0);
      close(sockfd);
      return EXIT_SUCCESS;
    } else {
      // Unknown command
      printf("Unknown command\n");
    }
  }

  return EXIT_SUCCESS;
}