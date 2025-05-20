//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

// Let's get our boogie on and start the party!
int main() {
  // Declaring all the groovy stuff we're gonna need
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;

  // Let's set the stage and pick a port to listen on
  printf("Hey there, what port do you fancy? ");
  scanf("%d", &portno);

  // Creating the socket, like a virtual dance floor
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket creation failed. Bummer!");
    return 1;
  }

  // Setting up our server's address, like our VIP booth
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  // Binding the socket to our address, like securing our spot
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Bind failed. Darn! Try another port.");
    return 1;
  }

  // Ready to groove! Let's start listening for incoming connections
  listen(sockfd, 5);

  // Loop to welcome all the cool cats and kittens
  while (1) {
    // Waiting for a request to come knocking
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("Accept failed. It's like the dance floor is empty!");
      continue;
    }

    // Let's jam! Serve them up a groovy response
    printf("Yay, someone's here! Let's show them our moves.\n");
    strcpy(buffer, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Hello, web world!</h1>");
    write(newsockfd, buffer, strlen(buffer));

    // Closing the connection, time for the next dance partner
    close(newsockfd);
  }

  // All the fun has ended. Let's clean up the mess
  close(sockfd);
  return 0;
}