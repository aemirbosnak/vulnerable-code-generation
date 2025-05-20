//FormAI DATASET v1.0 Category: Simple Web Server ; Style: statistical
/*
This is a simple web server program written in C language.
It listens to incoming connections from clients and sends back a response with HTTP headers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define HTTP_OK 200
#define HTTP_NOT_FOUND 404
#define DEFAULT_PORT 8080

int main() {
  int server_fd, client_fd;
  struct sockaddr_in server_address, client_address;
  socklen_t client_len = sizeof(client_address);
  char response[1024], request[1024];
  int port = DEFAULT_PORT;

  // create a socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    printf("Failed to create socket: %s\n", strerror(errno));
    return -1;
  }

  // set the socket to be reusable
  int opt = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    printf("Failed to setsocketopt: %s\n", strerror(errno));
    return -1;
  }

  // set server address and port
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(port);

  // bind socket to the server address and port
  if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("Failed to bind socket: %s\n", strerror(errno));
    return -1;
  }

  // listen for connections
  if (listen(server_fd, 3) < 0) {
    printf("Failed to listen for connections: %s\n", strerror(errno));
    return -1;
  }

  // loop forever
  while (1) {
    // accept a new connection from a client
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_len)) < 0) {
      printf("Failed to accept connection: %s\n", strerror(errno));
      continue;
    }

    // read the request from the client
    int len = read(client_fd, request, sizeof(request));
    if (len < 0) {
      printf("Failed to read request: %s\n", strerror(errno));
      close(client_fd);
      continue;
    }

    // parse the request
    char *method = strtok(request, " \t\r\n");
    char *path = strtok(NULL, " \t\r\n");
    char *version = strtok(NULL, " \t\r\n");

    // check if the request is GET
    if (strcmp(method, "GET") != 0) {
      // send back HTTP 501 Not Implemented
      sprintf(response, "HTTP/1.1 501 Not Implemented\r\n\r\n");
    } else {
      // check if the requested file exists
      struct stat st;
      if (stat(path, &st) < 0) {
        // send back HTTP 404 Not Found
        sprintf(response, "HTTP/1.1 404 Not Found\r\n\r\n");
      } else if (!(S_ISREG(st.st_mode) && (st.st_mode & S_IRUSR))) {
        // send back HTTP 403 Forbidden
        sprintf(response, "HTTP/1.1 403 Forbidden\r\n\r\n");
      } else {
        // open the requested file and send back its contents
        int file_fd = open(path, O_RDONLY);
        sprintf(response, "HTTP/1.1 %d OK\r\n\r\n", HTTP_OK);
        send(client_fd, response, strlen(response), 0);
        while ((len = read(file_fd, response, sizeof(response))) > 0) {
          send(client_fd, response, len, 0);
        }
        close(file_fd);
        close(client_fd);
        continue;
      }
    }

    // send back the HTTP response
    send(client_fd, response, strlen(response), 0);

    // close the client connection
    close(client_fd);
  }

  // close the server socket
  close(server_fd);

  return 0;
}