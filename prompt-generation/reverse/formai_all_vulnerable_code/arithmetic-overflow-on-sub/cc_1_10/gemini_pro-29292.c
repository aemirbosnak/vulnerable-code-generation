//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define BUFSIZE 1024
#define INTERVAL 1000000  // 1 second

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in servaddr;
  struct timeval start, end;
  char buf[BUFSIZE];
  int n;
  int seq = 0;
  int lost = 0;

  if (argc != 3) {
    fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // get the server address
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    herror("gethostbyname");
    return EXIT_FAILURE;
  }
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

  // connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // start the timer
  gettimeofday(&start, NULL);

  while (1) {
    // send a message to the server
    sprintf(buf, "seq=%d\n", seq);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
      perror("send");
      return EXIT_FAILURE;
    }

    // wait for a response from the server
    if ((n = recv(sockfd, buf, BUFSIZE, 0)) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }

    // check if the response is correct
    if (strcmp(buf, "ack") != 0) {
      printf("received incorrect response: %s\n", buf);
      lost++;
    }

    // update the sequence number
    seq++;

    // end the timer
    gettimeofday(&end, NULL);

    // calculate the elapsed time
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // print the results
    printf("seq=%d, elapsed=%f, lost=%d\n", seq, elapsed, lost);

    // if the elapsed time has exceeded the interval, reset the timer
    if (elapsed > INTERVAL / 1000000.0) {
      gettimeofday(&start, NULL);
    }
  }

  // close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}