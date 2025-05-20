//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: Romeo and Juliet
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  int optval = 1;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(atoi(argv[1]));

  if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  listen(sockfd, 3);

  while (1) {
    portno = accept(sockfd, (struct sockaddr*) NULL, NULL);
    if (portno < 0) {
      perror("ERROR on accept");
      exit(1);
    }

    if (portno == -1) {
      perror("ERROR on accept");
      exit(1);
    }

    if (portno < 0) {
      perror("ERROR on accept");
      exit(1);
    }

    n = read(portno, buffer, 256);
    if (n < 0) {
      perror("ERROR reading from client");
      exit(1);
    }

    printf("Received %d bytes from client: %s\n", n, buffer);

    if (write(portno, "HTTP/1.1 200 OK\r\n", 17) < 0) {
      perror("ERROR writing to client");
      exit(1);
    }

    if (write(portno, "Content-Type: text/html\r\n\r\n", 31) < 0) {
      perror("ERROR writing to client");
      exit(1);
    }

    if (write(portno, "<!DOCTYPE HTML><html><head><title>Internet Speed Test</title></head><body><h1>Internet Speed Test</h1><p>Enter the URL of the website you want to test:</p><form action=\"http://localhost:8080/\" method=\"POST\"><input type=\"text\" name=\"url\" size=\"80\"><input type=\"submit\" value=\"Submit\"></form><p>Enter the number of bytes you want to download:</p><input type=\"text\" name=\"bytes\" size=\"10\"><input type=\"submit\" value=\"Download\"></form></body></html>", 192) < 0) {
      perror("ERROR writing to client");
      exit(1);
    }

    if (close(portno) < 0) {
      perror("ERROR closing socket");
      exit(1);
    }
  }

  return 0;
}