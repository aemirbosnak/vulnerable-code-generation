//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

int main()
{
  int sockfd, port, err, i, j, k, n;
  char hostname[256], msg[1024], recv_msg[1024];
  struct sockaddr_in server_addr;

  printf("Welcome to the immersive Ping Test!\n");
  printf("Please enter the hostname of the server: ");
  scanf("%s", hostname);
  printf("Enter the port number of the server: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(hostname);

  err = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (err < 0)
  {
    perror("Error connecting to server");
    exit(1);
  }

  printf("Connection established!\n");

  for (i = 0; i < 5; i++)
  {
    printf("Sending message...");
    scanf("Enter your message: ", msg);
    send(sockfd, msg, strlen(msg) + 1, 0);

    printf("Receiving message...");
    recv(sockfd, recv_msg, 1024, 0);
    printf("Received message: %s\n", recv_msg);
  }

  close(sockfd);
  printf("Connection closed.\n");

  return 0;
}