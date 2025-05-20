//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <netdb.h>

  #define PORT 80
  #define MAX_PACKET_SIZE 1024

  int main(int argc, char *argv[]) {
      struct addrinfo hints, *server_info, *p;
      int sock, status, packet_size;
      char send_buffer[MAX_PACKET_SIZE], recv_buffer[MAX_PACKET_SIZE];

      if (argc != 2) {
          fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
          return 1;
      }

      memset(&hints, 0, sizeof(hints));
      hints.ai_family = AF_UNSPEC;
      hints.ai_socktype = SOCK_STREAM;
      hints.ai_protocol = IPPROTO_TCP;

      if ((status = getaddrinfo(argv[1], NULL, &hints, &server_info)) != 0) {
          fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
          return 1;
      }

      for (p = server_info; p != NULL; p = p->ai_next) {
          if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
              perror("socket");
              continue;
          }

          if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
              close(sock);
              perror("connect");
              continue;
          }

          break;
      }

      if (p == NULL) {
          fprintf(stderr, "Failed to connect to server\n");
          return 1;
      }

      freeaddrinfo(server_info);

      snprintf(send_buffer, MAX_PACKET_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
      if ((status = send(sock, send_buffer, strlen(send_buffer), 0)) == -1) {
          perror("send");
          return 1;
      }

      if ((status = recv(sock, recv_buffer, MAX_PACKET_SIZE, 0)) == -1) {
          perror("recv");
          return 1;
      }

      close(sock);

      printf("Website response: %s\n", recv_buffer);

      return 0;
  }