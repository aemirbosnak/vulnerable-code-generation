//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main()
{
  // Variables
  int sockfd, port;
  struct sockaddr_in serv_addr;
  char buf[BUF_SIZE];
  char command[BUF_SIZE];
  char filename[BUF_SIZE];

  // Get the server IP and port
  printf("Enter the server IP address: ");
  scanf("%s", buf);
  printf("Enter the server port: ");
  scanf("%d", &port);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Set up the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, buf, &serv_addr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(1);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Send a welcome message
  strcpy(buf, "Hello FTP server!");
  send(sockfd, buf, strlen(buf), 0);

  // Main loop
  while (1) {
    // Get the command
    printf("Enter a command (LIST, RETR, STOR, QUIT): ");
    scanf("%s", command);

    // Execute the command
    if (strcmp(command, "LIST") == 0) {
      // Send the LIST command
      strcpy(buf, "LIST");
      send(sockfd, buf, strlen(buf), 0);

      // Receive the list of files
      while (recv(sockfd, buf, BUF_SIZE, 0) > 0) {
        printf("%s", buf);
      }
    } else if (strcmp(command, "RETR") == 0) {
      // Get the filename
      printf("Enter the filename to retrieve: ");
      scanf("%s", filename);

      // Send the RETR command
      strcpy(buf, "RETR ");
      strcat(buf, filename);
      send(sockfd, buf, strlen(buf), 0);

      // Receive the file
      FILE *fp = fopen(filename, "wb");
      if (fp == NULL) {
        perror("fopen");
        exit(1);
      }
      while (recv(sockfd, buf, BUF_SIZE, 0) > 0) {
        fwrite(buf, 1, strlen(buf), fp);
      }
      fclose(fp);
    } else if (strcmp(command, "STOR") == 0) {
      // Get the filename
      printf("Enter the filename to store: ");
      scanf("%s", filename);

      // Send the STOR command
      strcpy(buf, "STOR ");
      strcat(buf, filename);
      send(sockfd, buf, strlen(buf), 0);

      // Send the file
      FILE *fp = fopen(filename, "rb");
      if (fp == NULL) {
        perror("fopen");
        exit(1);
      }
      while (fread(buf, 1, BUF_SIZE, fp) > 0) {
        send(sockfd, buf, strlen(buf), 0);
      }
      fclose(fp);
    } else if (strcmp(command, "QUIT") == 0) {
      // Send the QUIT command
      strcpy(buf, "QUIT");
      send(sockfd, buf, strlen(buf), 0);

      // Close the socket
      close(sockfd);

      // Exit the program
      exit(0);
    } else {
      printf("Invalid command!\n");
    }
  }

  return 0;
}