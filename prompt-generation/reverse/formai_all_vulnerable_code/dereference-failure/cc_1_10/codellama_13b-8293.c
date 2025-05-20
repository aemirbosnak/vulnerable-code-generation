//Code Llama-13B DATASET v1.0 Category: Wireless Network Scanner ; Style: Cryptic
#include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>

    #define PORT 80
    #define MAX_BUF_LEN 1024

    int main(int argc, char *argv[]) {
        int sock, n;
        char recv_buf[MAX_BUF_LEN];
        struct sockaddr_in server_addr;
        struct hostent *server;

        if (argc != 2) {
            printf("Usage: %s <hostname>\n", argv[0]);
            return 1;
        }

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Error: socket()");
            return 1;
        }

        server = gethostbyname(argv[1]);
        if (server == NULL) {
            perror("Error: gethostbyname()");
            return 1;
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);
        memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Error: connect()");
            return 1;
        }

        while (1) {
            memset(recv_buf, 0, MAX_BUF_LEN);
            n = recv(sock, recv_buf, MAX_BUF_LEN, 0);
            if (n < 0) {
                perror("Error: recv()");
                break;
            }
            printf("Received: %s\n", recv_buf);
        }

        close(sock);
        return 0;
    }