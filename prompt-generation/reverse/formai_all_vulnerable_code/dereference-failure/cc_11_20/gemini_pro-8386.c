//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110

int main()
{
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  char buffer[256];

  /* Create a socket. */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  /* Check if the socket was created successfully. */
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  /* Set the server address. */
  portno = POP3_PORT;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv_addr.sin_port = htons(portno);

  /* Connect to the server. */
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    perror("Error connecting to server");
    exit(EXIT_FAILURE);
  }

  /* Send a greeting to the server. */
  sprintf(buffer, "HELO %s\r\n", "MY_NAME");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0)
  {
    perror("Error sending greeting to server");
    exit(EXIT_FAILURE);
  }

  /* Receive a response from the server. */
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
  {
    perror("Error receiving response from server");
    exit(EXIT_FAILURE);
  }

  printf("%s", buffer);

  /* Send a username to the server. */
  sprintf(buffer, "USER %s\r\n", "MY_USERNAME");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0)
  {
    perror("Error sending username to server");
    exit(EXIT_FAILURE);
  }

  /* Receive a response from the server. */
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
  {
    perror("Error receiving response from server");
    exit(EXIT_FAILURE);
  }

  printf("%s", buffer);

  /* Send a password to the server. */
  sprintf(buffer, "PASS %s\r\n", "MY_PASSWORD");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0)
  {
    perror("Error sending password to server");
    exit(EXIT_FAILURE);
  }

  /* Receive a response from the server. */
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
  {
    perror("Error receiving response from server");
    exit(EXIT_FAILURE);
  }

  printf("%s", buffer);

  /* Send a command to the server to list the messages. */
  if (send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) < 0)
  {
    perror("Error sending command to server");
    exit(EXIT_FAILURE);
  }

  /* Receive a response from the server. */
  while (recv(sockfd, buffer, sizeof(buffer), 0) > 0)
  {
    printf("%s", buffer);
  }

  /* Send a command to the server to retrieve a message. */
  if (send(sockfd, "RETR 1\r\n", strlen("RETR 1\r\n"), 0) < 0)
  {
    perror("Error sending command to server");
    exit(EXIT_FAILURE);
  }

  /* Receive a response from the server. */
  while (recv(sockfd, buffer, sizeof(buffer), 0) > 0)
  {
    printf("%s", buffer);
  }

  /* Send a command to the server to delete a message. */
  if (send(sockfd, "DELE 1\r\n", strlen("DELE 1\r\n"), 0) < 0)
  {
    perror("Error sending command to server");
    exit(EXIT_FAILURE);
  }

  /* Receive a response from the server. */
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
  {
    perror("Error receiving response from server");
    exit(EXIT_FAILURE);
  }

  printf("%s", buffer);

  /* Send a command to the server to quit. */
  if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0)
  {
    perror("Error sending command to server");
    exit(EXIT_FAILURE);
  }

  /* Receive a response from the server. */
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
  {
    perror("Error receiving response from server");
    exit(EXIT_FAILURE);
  }

  printf("%s", buffer);

  /* Close the socket. */
  close(sockfd);

  return 0;
}