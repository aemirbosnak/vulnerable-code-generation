//FormAI DATASET v1.0 Category: Simple Web Server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno, clientlen;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[BUFFER_SIZE];
  
  if (argc < 2) {
    fprintf(stderr,"ERROR, no port provided\n");
    exit(1);
  }
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  memset((char *) &serv_addr, 0, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
  
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }
  
  listen(sockfd, 5);
  printf("Server running on port %d...\n", portno);
  
  while (1) {
    clientlen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clientlen);
    
    if (newsockfd < 0) {
      perror("ERROR on accept");
      continue;
    }
    
    memset(buffer, 0, BUFFER_SIZE);
    read(newsockfd, buffer, BUFFER_SIZE);
    
    char method[10], path[50], protocol[10];
    sscanf(buffer, "%s %s %s", method, path, protocol);
    
    printf("Client request for %s %s\n", method, path);
    
    if (strcmp(path, "/") == 0) {
      strcpy(path, "/index.html");
    }
    
    char *ext = strrchr(path, '.');
    if (ext != NULL) {
      if (strcmp(ext, ".html") == 0) {
        sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
      } else if (strcmp(ext, ".jpg") == 0) {
        sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: image/jpeg\r\n\r\n");
      } else if (strcmp(ext, ".pdf") == 0) {
        sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: application/pdf\r\n\r\n");
      } else {
        sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n");
      }
    } else {
      sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n");
    }
    
    write(newsockfd, buffer, strlen(buffer));
    
    char *file_path = malloc(50 + strlen(path));
    sprintf(file_path, "webroot%s", path);
    
    FILE *file = fopen(file_path, "r");
    if (file != NULL) {
      memset(buffer, 0, BUFFER_SIZE);
      int bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
      while (bytes_read > 0) {
        write(newsockfd, buffer, bytes_read);
        bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
      }
      fclose(file);
    }
    
    close(newsockfd);
  }
  
  close(sockfd);
  return 0;
}