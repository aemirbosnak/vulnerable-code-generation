//Gemma-7B DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_PORT 143
#define POP3_HOST "localhost"

int main()
{
  int sockfd, n, len, i;
  char buf[1024], msg[1024], username[256], password[256];
  struct sockaddr_in sock_addr;

  printf("Enter username: ");
  scanf("%s", username);

  printf("Enter password: ");
  scanf("%s", password);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(POP3_PORT));
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(1);
  }

  memset(&sock_addr, 0, sizeof(sock_addr));
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(POP3_PORT);
  sock_addr.sin_addr.s_addr = inet_addr(POP3_HOST);

  if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
  {
    perror("Error connecting to server");
    exit(1);
  }

  sprintf(buf, "USER %s\r\n", username);
  write(sockfd, buf, strlen(buf));

  sprintf(buf, "PASS %s\r\n", password);
  write(sockfd, buf, strlen(buf));

  sprintf(buf, "LIST\r\n");
  write(sockfd, buf, strlen(buf));

  len = read(sockfd, buf, 1024);
  printf("Received message: %s\n", buf);

  for (i = 0; i < len; i++)
  {
    if (buf[i] == '\n')
    {
      printf("\n");
    }
    else
    {
      printf("%c", buf[i]);
    }
  }

  close(sockfd);
  return 0;
}