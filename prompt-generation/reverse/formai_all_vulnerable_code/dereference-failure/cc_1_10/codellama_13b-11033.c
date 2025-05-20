//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #include <unistd.h>
   #include <sys/types.h>
   #include <sys/socket.h>
   #include <netinet/in.h>
   #include <arpa/inet.h>
   #include <netdb.h>

   int main(int argc, char *argv[]) {
       int sock;
       struct sockaddr_in server;
       struct hostent *host;
       char *hostname = argv[1];
       char *message = "PING";
       char *buffer = malloc(1024);
       int bytes_received;

       if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
           perror("socket");
           exit(1);
       }

       memset(&server, 0, sizeof(server));
       server.sin_family = AF_INET;
       server.sin_port = htons(80);

       if ((host = gethostbyname(hostname)) == NULL) {
           herror("gethostbyname");
           exit(1);
       }

       memcpy(&server.sin_addr, host->h_addr, host->h_length);

       if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
           perror("connect");
           exit(1);
       }

       send(sock, message, strlen(message), 0);
       bytes_received = recv(sock, buffer, 1024, 0);
       buffer[bytes_received] = '\0';

       printf("Received %d bytes: %s\n", bytes_received, buffer);

       close(sock);

       return 0;
   }