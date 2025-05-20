//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Welcome message
void welcome() {
  printf("\n************************************************************************************\n");
  printf(" _____           _                                  _____  _   _      _   _   _ \n");
  printf("|  __ \         | |                                |  __ \| | | |    | | | | | |\n");
  printf("| |__) |__ _  ___| |_ ___ _ __   __ _  ___  _ __   | |  | | | | |    | | | | | |\n");
  printf("|  _  // _` |/ __| __/ _ \\ '_ \\ / _` |/ _ \\| '_ \\  | |  | | | | |    | | | | | |\n");
  printf("| | \\ \\ (_| | (__| ||  __/ | | | (_| | (_) | | | | | |__| | |_| |    |_| |_| |_|\n");
  printf("|_|  \\_\\__,_|\\___|\\__\\___|_| |_|\\__,_|\\___/|_| |_| |_____/ \\___/      (_) (_) (_)\n");
  printf("************************************************************************************\n\n");
}

// Main function
int main() {
  // Welcome the user
  welcome();

  // Get the hostname and port number from the user
  char hostname[100];
  int port;
  printf("Enter the hostname of the FTP server: ");
  scanf("%s", hostname);
  printf("Enter the port number of the FTP server: ");
  scanf("%d", &port);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Connect to the FTP server
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    return 1;
  }
  memcpy(&servaddr.sin_addr, host->h_addr_list[0], host->h_length);
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return 1;
  }

  // Login to the FTP server
  char username[100];
  char password[100];
  printf("Enter your username: ");
  scanf("%s", username);
  printf("Enter your password: ");
  scanf("%s", password);
  char buffer[100];
  sprintf(buffer, "USER %s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return 1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    return 1;
  }
  printf("%s", buffer);
  sprintf(buffer, "PASS %s\r\n", password);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return 1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    return 1;
  }
  printf("%s", buffer);

  // List the files in the current directory
  if (send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) == -1) {
    perror("send");
    return 1;
  }
  while (1) {
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
      perror("recv");
      return 1;
    }
    if (strcmp(buffer, "226 Transfer complete.\r\n") == 0) {
      break;
    }
    printf("%s", buffer);
  }

  // Download a file
  char filename[100];
  printf("Enter the name of the file you want to download: ");
  scanf("%s", filename);
  sprintf(buffer, "RETR %s\r\n", filename);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return 1;
  }
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }
  while (1) {
    if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
      perror("recv");
      return 1;
    }
    if (strcmp(buffer, "226 Transfer complete.\r\n") == 0) {
      break;
    }
    fprintf(fp, "%s", buffer);
  }
  fclose(fp);

  // Close the connection to the FTP server
  close(sockfd);

  return 0;
}