//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PENDING 5
#define MAX_LINE 256

int main(int argc, char *argv[]) {
    struct sockaddr_in sin;
    struct hostent *host;
    char *host_name;
    char buffer[MAX_LINE];
    int serversock, clientsock;
    unsigned short server_port = 8080;
    int addr_len;
    int ret;
    int yes = 1;

    if (argc == 2)
        server_port = atoi(argv[1]);

    if ((serversock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("error creating serversock\n");
        exit(1);
    }

    if (setsockopt(serversock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(serversock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("bind failed\n");
        exit(1);
    }

    if (listen(serversock, MAX_PENDING) < 0) {
        perror("listen failed\n");
        exit(1);
    }

    printf("listening on %d\n", server_port);

    addr_len = sizeof(struct sockaddr_in);

    while (1) {
        if ((clientsock = accept(serversock, (struct sockaddr *)&sin, (socklen_t *)&addr_len)) < 0) {
            perror("accept failed\n");
            exit(1);
        }
        
        if ((host = gethostbyaddr((char *)&sin.sin_addr, sizeof(sin.sin_addr), AF_INET)) == NULL) {
            fprintf(stderr, "gethostbyaddr failed\n");
            exit(1);
        }

        host_name = host->h_name;
        printf("Received connection from %s\n", host_name);

        memset(buffer, 0, sizeof(buffer));

        if ((ret = recv(clientsock, buffer, MAX_LINE, 0)) < 0) {
            perror("recv failed\n");
            exit(1);
        }

        printf("%s", buffer);

        strcpy(buffer, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n<html><head><title>C Network QoS Monitor</title></head><body><h1>C Network QoS Monitor Example Program</h1><p>This is a unique C Network Quality of Service (QoS) monitor example program.</p></body></html>\r\n");

        if (send(clientsock, buffer, strlen(buffer), 0) < 0) {
            perror("send failed\n");
            exit(1);
        }

        close(clientsock);
    }

    close(serversock);

    return 0;
}