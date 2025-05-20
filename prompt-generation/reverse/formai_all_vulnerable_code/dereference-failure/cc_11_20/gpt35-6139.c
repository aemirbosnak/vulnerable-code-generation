//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc, char *argv[]) {

  int sock, portNum, n, option;
  int len = sizeof(option);
  char buffer[1024];
  struct sockaddr_in serv_addr;
  struct hostent *server;
  fd_set readfds;

  if(argc < 2) {
    printf("\nUsage:\n%s [hostname] [port number]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  portNum = atoi(argv[2]);
  sock = socket(AF_INET, SOCK_STREAM, 0);

  if(sock < 0) {
    perror("Error opening socket");
    exit(EXIT_FAILURE);
  }

  server = gethostbyname(argv[1]);

  if(server == NULL) {
    printf("\nError: no such host\n");
    exit(EXIT_FAILURE);
  }

  memset((char *) &serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portNum);
  serv_addr.sin_addr = *((struct in_addr *) server->h_addr);

  if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("\nError: Connection failed\n");
    exit(EXIT_FAILURE);
  }

  printf("\nConnected to server - %s:%d!\n\n", argv[1], portNum);

  printf("--------------------------Wireless Network Scanner-------------------------\n");
  printf("Enter the number of the option you want to select:\n");
  printf("1. Scan network for available devices\n2. Get device information\n3. Exit\n\n");

  while(1) {

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);
    FD_SET(STDIN_FILENO, &readfds);

    if(select(sock + 1, &readfds, NULL, NULL, NULL) < 0) {
      perror("\nError: Select failed\n");
      exit(EXIT_FAILURE);
    }

    if(FD_ISSET(sock, &readfds)) {

      memset(buffer, 0, sizeof(buffer));
      n = read(sock, buffer, sizeof(buffer));

      if(n < 0) {
        perror("\nError: Read failed\n");
        exit(EXIT_FAILURE);
      }

      if(strncmp(buffer, "Found device:", 13) == 0)
        printf("\n%s\n\n", buffer);

      else if(strncmp(buffer, "Device info:", 12) == 0)
        printf("\n%s\n\n", buffer);

      else {
        printf("\n%s\n\n", buffer);
        close(sock);
        printf("Connection closed!\n");
        break;
      }

    }

    if(FD_ISSET(STDIN_FILENO, &readfds)) {

      scanf("%d", &option);

      if(option != 1 && option != 2 && option != 3) {
        printf("\nInvalid option, please try again!\n\n");
        continue;
      }

      write(sock, &option, sizeof(option));
    }

  }

  return 0;

}