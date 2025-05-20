//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[256];

  printf("Enter website URL: ");
  scanf("%s", buffer);

  portno = 80;

  /* Create a socket point */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  /* Fill in server address structure */
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  serv_addr.sin_addr.s_addr = inet_addr(buffer);

  /* Connect to server */
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  /* Send HTTP request */
  strcpy(buffer, "GET / HTTP/1.1\r\nHost: ");
  strcat(buffer, buffer);
  strcat(buffer, "\r\n\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  /* Read HTTP response */
  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  /* Check if website is up */
  if (strstr(buffer, "200 OK") != NULL) {
    printf("Website is up and running!\n");
  } else {
    printf("Website is down or inaccessible.\n");
  }

  /* Close socket */
  close(sockfd);

  return 0;
}