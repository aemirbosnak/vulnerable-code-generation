//Code Llama-13B DATASET v1.0 Category: Wireless Network Scanner ; Style: relaxed
#include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>

    int main(int argc, char *argv[])
    {
        int sockfd, n;
        struct sockaddr_in server_addr;
        struct hostent *server;
        char buffer[256];

        if (argc != 3) {
            fprintf(stderr,"usage: %s <IP address> <port>\n", argv[0]);
            exit(0);
        }

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket");
            exit(0);
        }

        server = gethostbyname(argv[1]);
        if (server == NULL) {
            fprintf(stderr,"ERROR, no such host\n");
            exit(0);
        }

        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
        server_addr.sin_port = htons(atoi(argv[2]));

        if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            exit(0);
        }

        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(0);
        }

        printf("%s\n", buffer);

        return 0;
    }