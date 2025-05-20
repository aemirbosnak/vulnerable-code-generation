//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

typedef struct
{
  const char *key;
  const char *value;
} header_t;

int main()
{
  printf("Cheerful POP3 Client\n");

  // Yay, we'll connect to a POP3 server :)
  const char *hostname = "pop.example.com";
  const char *username = "john.doe";
  const char *password = "s3cret";

  // Initiate connection with the POP3 server
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  int err = getaddrinfo(hostname, "110", &hints, &res);
  if (err != 0)
  {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
    return 1;
  }

  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd == -1)
  {
    perror("socket");
    freeaddrinfo(res);
    return 1;
  }

  if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1)
  {
    perror("connect");
    freeaddrinfo(res);
    close(sockfd);
    return 1;
  }

  freeaddrinfo(res);

  // Let's greet the server with a cheerful "Hello"
  char buf[1024];
  if (recv(sockfd, buf, 1024, 0) <= 0)
  {
    perror("recv");
    close(sockfd);
    return 1;
  }
  printf("Server: %s", buf);

  // Now let's send our username
  snprintf(buf, 1024, "USER %s\r\n", username);
  if (send(sockfd, buf, strlen(buf), 0) <= 0)
  {
    perror("send");
    close(sockfd);
    return 1;
  }
  if (recv(sockfd, buf, 1024, 0) <= 0)
  {
    perror("recv");
    close(sockfd);
    return 1;
  }
  printf("Server: %s", buf);

  // And our password
  snprintf(buf, 1024, "PASS %s\r\n", password);
  if (send(sockfd, buf, strlen(buf), 0) <= 0)
  {
    perror("send");
    close(sockfd);
    return 1;
  }
  if (recv(sockfd, buf, 1024, 0) <= 0)
  {
    perror("recv");
    close(sockfd);
    return 1;
  }
  printf("Server: %s", buf);

  // We're in! Let's check how many emails we have
  snprintf(buf, 1024, "STAT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) <= 0)
  {
    perror("send");
    close(sockfd);
    return 1;
  }
  if (recv(sockfd, buf, 1024, 0) <= 0)
  {
    perror("recv");
    close(sockfd);
    return 1;
  }
  printf("Server: %s", buf);

  // And finally, let's read the first email
  snprintf(buf, 1024, "RETR 1\r\n");
  if (send(sockfd, buf, strlen(buf), 0) <= 0)
  {
    perror("send");
    close(sockfd);
    return 1;
  }

  // Let's store the email in a buffer
  FILE *email = fopen("email.txt", "w");
  while (1)
  {
    if (recv(sockfd, buf, 1024, 0) <= 0)
    {
      perror("recv");
      fclose(email);
      close(sockfd);
      return 1;
    }
    fprintf(email, "%s", buf);
    if (strstr(buf, "\r\n.\r\n") != NULL)
    {
      break;
    }
  }
  fclose(email);

  printf("Hurray! We've got our email!\n");

  // And let's quit the server
  snprintf(buf, 1024, "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) <= 0)
  {
    perror("send");
    close(sockfd);
    return 1;
  }

  close(sockfd);

  printf("Thank you for using our cheerful POP3 client!\n");
  return 0;
}