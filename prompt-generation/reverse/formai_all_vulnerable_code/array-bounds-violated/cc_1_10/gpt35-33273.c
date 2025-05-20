//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define IMAP_PORT "143"

int connect_to_mailbox(const char* hostname) {
  int sockfd;
  struct addrinfo hints, *servinfo, *p;
  int rv;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((rv = getaddrinfo(hostname, IMAP_PORT, &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }

  for (p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
      perror("client: socket");
      continue;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      perror("client: connect");
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "client: failed to connect\n");
    return 2;
  }

  freeaddrinfo(servinfo);

  return sockfd;
}

int receive_response(int sockfd) {
  char buf[BUF_SIZE];
  int numbytes;

  if ((numbytes = recv(sockfd, buf, BUF_SIZE - 1, 0)) == -1) {
    perror("client: recv");
    return -1;
  }

  buf[numbytes] = '\0';

  printf("%s", buf);

  return 0;
}

int authenticate(int sockfd, const char* username, const char* password) {
  char buf[BUF_SIZE];
  int numbytes;

  if ((numbytes = recv(sockfd, buf, BUF_SIZE - 1, 0)) == -1) {
    perror("client: recv");
    return -1;
  }

  buf[numbytes] = '\0';

  printf("%s", buf);

  snprintf(buf, sizeof buf, "a001 LOGIN %s %s\r\n", username, password);

  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("client: send");
    return -1;
  }

  if ((numbytes = recv(sockfd, buf, BUF_SIZE - 1, 0)) == -1) {
    perror("client: recv");
    return -1;
  }

  buf[numbytes] = '\0';

  printf("%s", buf);

  return 0;
}

int fetch_mail(int sockfd) {
  char buf[BUF_SIZE];
  int numbytes;

  snprintf(buf, sizeof buf, "a002 SELECT INBOX\r\n");

  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("client: send");
    return -1;
  }

  if ((numbytes = recv(sockfd, buf, BUF_SIZE - 1, 0)) == -1) {
    perror("client: recv");
    return -1;
  }

  buf[numbytes] = '\0';

  printf("%s", buf);

  snprintf(buf, sizeof buf, "a003 FETCH 1 BODY[HEADER.FIELDS (FROM SUBJECT)]\r\n");

  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("client: send");
    return -1;
  }

  if ((numbytes = recv(sockfd, buf, BUF_SIZE - 1, 0)) == -1) {
    perror("client: recv");
    return -1;
  }

  buf[numbytes] = '\0';

  printf("%s", buf);

  return 0;
}

int logout(int sockfd) {
  char buf[BUF_SIZE];
  int numbytes;

  snprintf(buf, sizeof buf, "a004 LOGOUT\r\n");

  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("client: send");
    return -1;
  }

  if ((numbytes = recv(sockfd, buf, BUF_SIZE - 1, 0)) == -1) {
    perror("client: recv");
    return -1;
  }

  buf[numbytes] = '\0';

  printf("%s", buf);

  close(sockfd);

  return 0;
}

int main(int argc, char* argv[]) {
  int sockfd;

  if (argc != 4) {
    fprintf(stderr, "Usage: imap-client hostname username password\n");
    return 1;
  }

  sockfd = connect_to_mailbox(argv[1]);

  if (authenticate(sockfd, argv[2], argv[3]) == -1) {
    return 1;
  }

  if (fetch_mail(sockfd) == -1) {
    return 1;
  }

  if (logout(sockfd) == -1) {
    return 1;
  }

  return 0;
}