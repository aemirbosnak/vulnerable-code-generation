//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[256];
  char command[256];
  char filename[256];

  printf("Enter the FTP server IP address: ");
  scanf("%s", buffer);
  server = gethostbyname(buffer);

  if (server == NULL) {
    fprintf(stderr, "Error: unable to resolve host %s\n", buffer);
    exit(1);
  }

  portno = 21;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    fprintf(stderr, "Error: unable to create socket\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: unable to connect to server\n");
    exit(1);
  }

  printf("Connected to FTP server %s on port %d\n", buffer, portno);

  while (1) {
    printf("Enter FTP command (or quit to exit): ");
    scanf("%s", command);

    if (strcmp(command, "quit") == 0) {
      break;
    } else if (strcmp(command, "ls") == 0) {
      write(sockfd, "LIST\r\n", 6);
      bzero(buffer, 256);
      read(sockfd, buffer, 255);
      printf("%s", buffer);
    } else if (strcmp(command, "get") == 0) {
      printf("Enter filename to download: ");
      scanf("%s", filename);
      write(sockfd, "RETR ", 5);
      write(sockfd, filename, strlen(filename));
      write(sockfd, "\r\n", 2);
      bzero(buffer, 256);
      read(sockfd, buffer, 255);
      printf("%s", buffer);
      FILE *fp = fopen(filename, "wb");
      bzero(buffer, 256);
      while (read(sockfd, buffer, 255) > 0) {
        fwrite(buffer, 1, strlen(buffer), fp);
        bzero(buffer, 256);
      }
      fclose(fp);
    } else if (strcmp(command, "put") == 0) {
      printf("Enter filename to upload: ");
      scanf("%s", filename);
      FILE *fp = fopen(filename, "rb");
      if (fp == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        continue;
      }
      write(sockfd, "STOR ", 5);
      write(sockfd, filename, strlen(filename));
      write(sockfd, "\r\n", 2);
      bzero(buffer, 256);
      read(sockfd, buffer, 255);
      printf("%s", buffer);
      while (fread(buffer, 1, 255, fp) > 0) {
        write(sockfd, buffer, strlen(buffer));
        bzero(buffer, 256);
      }
      fclose(fp);
    } else {
      printf("Invalid FTP command\n");
    }
  }

  close(sockfd);

  return 0;
}