//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define PORT 8080

int main()
{
  int sockfd, newsockfd, ret;
  struct sockaddr_in serv_addr, cli_addr;
  socklen_t clilen;
  char buffer[256];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
  {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set socket options
  int flags = fcntl(sockfd, F_GETFL, 0);
  if (flags == -1)
  {
    perror("ERROR getting socket flags");
    close(sockfd);
    exit(1);
  }
  if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1)
  {
    perror("ERROR setting socket to non-blocking");
    close(sockfd);
    exit(1);
  }

  // Set server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    perror("ERROR on binding");
    close(sockfd);
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) < 0)
  {
    perror("ERROR on listen");
    close(sockfd);
    exit(1);
  }

  while (1)
  {
    // Accept incoming connections
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
    {
      if (errno == EAGAIN || errno == EWOULDBLOCK)
      {
        // No new connections, continue listening
        continue;
      }
      else
      {
        perror("ERROR on accept");
        close(sockfd);
        exit(1);
      }
    }

    // Read data from the client
    memset(buffer, 0, sizeof(buffer));
    ret = read(newsockfd, buffer, sizeof(buffer) - 1);
    if (ret < 0)
    {
      if (errno == EAGAIN || errno == EWOULDBLOCK)
      {
        // No data available, continue listening
        continue;
      }
      else
      {
        perror("ERROR reading from socket");
        close(newsockfd);
        continue;
      }
    }
    else if (ret == 0)
    {
      // Client closed the connection
      close(newsockfd);
      continue;
    }

    // Write data to the client
    ret = write(newsockfd, buffer, strlen(buffer));
    if (ret < 0)
    {
      if (errno == EAGAIN || errno == EWOULDBLOCK)
      {
        // No data available, continue listening
        continue;
      }
      else
      {
        perror("ERROR writing to socket");
        close(newsockfd);
        continue;
      }
    }

    // Close the connection with the client
    close(newsockfd);
  }

  // Close the socket
  close(sockfd);
  return 0;
}