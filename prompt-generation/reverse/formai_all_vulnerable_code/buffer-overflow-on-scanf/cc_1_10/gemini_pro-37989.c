//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
// Welcome to the realm of digital explorers, where the winds of electrons carry whispers of data across the boundless expanse of the Internet. In this grand adventure, we embark on a quest to craft our very own FTP client, a fearless navigator in this vast cyber sea.

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

// The heart of our FTP client, the main function.
int main(int argc, char **argv) {
  // Parsing the command-line arguments, our trusty map to the server's abode.
  if (argc != 3) {
    printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
    return 1;
  }

  int port = atoi(argv[2]);
  char *ip = argv[1];

  // Casting our nets into the digital deep, creating the socket that will connect us to the remote server.
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  // Plotting our course, setting the server's address and port.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip);
  server_addr.sin_port = htons(port);

  // Setting sail, connecting to the remote server.
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Greeting the server, exchanging pleasantries.
  char welcome_msg[256];
  int welcome_msg_len = recv(sock, welcome_msg, sizeof(welcome_msg), 0);
  if (welcome_msg_len == -1) {
    perror("recv");
    return 1;
  }
  printf("%s", welcome_msg);

  // Ready for action, a blank canvas for commands.
  char command[256];
  while (1) {
    printf("> ");
    scanf("%s", command);

    // Sending the command to the server, our beacon in the digital fog.
    int command_len = strlen(command);
    if (send(sock, command, command_len, 0) == -1) {
      perror("send");
      return 1;
    }

    // Receiving the server's response, a treasure chest of data.
    char response[1024];
    int response_len = recv(sock, response, sizeof(response), 0);
    if (response_len == -1) {
      perror("recv");
      return 1;
    }

    // Displaying the server's response, a glimpse into the digital realm.
    printf("%s", response);

    // Time to bid farewell, closing the connection and setting the socket adrift.
    if (strcmp(command, "QUIT") == 0) {
      break;
    }
  }

  close(sock);
  return 0;
}