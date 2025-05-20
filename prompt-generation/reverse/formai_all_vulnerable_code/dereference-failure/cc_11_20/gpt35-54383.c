//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[])
{
  int sockfd, n;
  struct sockaddr_in servaddr;
  char buffer[MAX_BUF_SIZE];

  if(argc != 3)
  {
    printf("Usage: %s server_address port\n", argv[0]);
    return 1;
  }

  // Create socket
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("Error: Failed to create socket.\n");
    return 1;
  }

  // Set server address and port
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
  {
    printf("Error: Invalid server address.\n");
    return 1;
  }

  // Connect to server
  if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
  {
    printf("Error: Failed to connect to server.\n");
    return 1;
  }

  // Read welcome message from server
  bzero(buffer, MAX_BUF_SIZE);
  n = read(sockfd, buffer, MAX_BUF_SIZE);
  if(n < 0)
  {
    printf("Error: Failed to read from server.\n");
    return 1;
  }
  printf("%s", buffer);

  // Send username to server
  char user[MAX_BUF_SIZE];
  printf("Username: ");
  scanf("%s", user);
  write(sockfd, user, strlen(user));

  // Read password prompt from server
  bzero(buffer, MAX_BUF_SIZE);
  n = read(sockfd, buffer, MAX_BUF_SIZE);
  if(n < 0)
  {
    printf("Error: Failed to read from server.\n");
    return 1;
  }
  printf("%s", buffer);

  // Send password to server
  char pass[MAX_BUF_SIZE];
  printf("Password: ");
  scanf("%s", pass);
  write(sockfd, pass, strlen(pass));

  // Read authentication result from server
  bzero(buffer, MAX_BUF_SIZE);
  n = read(sockfd, buffer, MAX_BUF_SIZE);
  if(n < 0)
  {
    printf("Error: Failed to read from server.\n");
    return 1;
  }
  printf("%s", buffer);

  // Send RETR command to server
  char retr[MAX_BUF_SIZE];
  printf("Message number to retrieve: ");
  scanf("%s", retr);
  write(sockfd, retr, strlen(retr));
  bzero(buffer, MAX_BUF_SIZE);

  // Read message from server
  while((n = read(sockfd, buffer, MAX_BUF_SIZE)) > 0)
  {
    fwrite(buffer, sizeof(char), n, stdout);
    if(n < MAX_BUF_SIZE)
    {
      break;
    }
    bzero(buffer, MAX_BUF_SIZE);
  }
  if(n < 0)
  {
    printf("Error: Failed to read from server.\n");
    return 1;
  }

  // Close connection
  close(sockfd);

  return 0;
}