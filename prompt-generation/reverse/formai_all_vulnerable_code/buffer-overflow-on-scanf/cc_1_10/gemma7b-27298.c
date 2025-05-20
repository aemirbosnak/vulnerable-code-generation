//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  int sockfd, err, send_len, recv_len;
  struct sockaddr_in serv_addr;
  char send_buf[1024], recv_buf[1024];
  char hostname[256];

  printf("Enter the hostname of the server: ");
  scanf("%s", hostname);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, htons(6));
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(1);
  }

  // Connect to the server
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(6);
  serv_addr.sin_addr.s_addr = inet_addr(hostname);

  err = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (err < 0)
  {
    perror("Error connecting to server");
    exit(1);
  }

  // Send a ping message
  send_len = sprintf(send_buf, "PING");
  send(sockfd, send_buf, send_len, 0);

  // Receive the ping response
  recv_len = recv(sockfd, recv_buf, 1024, 0);

  // Print the ping response
  printf("Received response: %s\n", recv_buf);

  // Close the socket
  close(sockfd);

  return 0;
}