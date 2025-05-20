//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

const char* blocked_ips[] = {"192.168.1.1", "192.168.1.2", "10.0.0.1"};

int main(int argc, char* argv[]) {
  if (argc!= 3) {
    fprintf(stderr, "Usage: %s <port> <log_file>\n", argv[0]);
    exit(1);
  }

  int port = atoi(argv[1]);
  char* log_file = argv[2];

  int sockfd;
  struct sockaddr_in server_addr;
  struct hostent* server;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    int numfds;
    fd_set readfds;
    struct timeval tv;

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    numfds = select(sockfd+1, &readfds, NULL, NULL, &tv);
    if (numfds < 0) {
      perror("select");
      exit(1);
    }

    if (numfds == 0) {
      printf("No incoming connections\n");
      continue;
    }

    printf("Incoming connection from ");

    socklen_t client_addr_len = sizeof(struct sockaddr_in);
    struct sockaddr_in client_addr;

    int client_fd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_fd < 0) {
      perror("accept");
      exit(1);
    }

    struct in_addr client_addr_in;
    inet_ntoa(client_addr.sin_addr);

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr_in, client_ip, INET_ADDRSTRLEN);

    if (client_ip[0] == '0') {
      continue;
    }

    printf("%s\n", client_ip);

    for (int i = 0; i < 3; i++) {
      if (strcmp(client_ip, blocked_ips[i]) == 0) {
        close(client_fd);
        printf("Connection from %s blocked\n", client_ip);
        break;
      }
    }
  }

  return 0;
}