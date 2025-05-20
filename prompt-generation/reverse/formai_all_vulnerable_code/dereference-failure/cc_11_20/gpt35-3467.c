//FormAI DATASET v1.0 Category: Networking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define LISTENQ 5
#define MAXLINE 1024

int main(int argc, char **argv) {
    int listenfd, connfd, port, n;
    socklen_t clientlen = sizeof(struct sockaddr_in);
    char buf[MAXLINE], client_ip[MAXLINE];
    struct sockaddr_in clientaddr, serveraddr;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);
    
    // create TCP socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket error");
        exit(1);
    }
    
    // set server IP address and port
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    // bind TCP socket to server address
    if (bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind error");
        exit(1);
    }
    
    // listen for incoming TCP connections
    if (listen(listenfd, LISTENQ) < 0) {
        perror("listen error");
        exit(1);
    }
    printf("Server listening on port %d...\n", port);
    
    while (1) {
        // accept incoming TCP connection
        connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
        if (connfd < 0) {
            perror("accept error");
            continue;
        }
        inet_ntop(AF_INET, &clientaddr.sin_addr, client_ip, MAXLINE);
        printf("Received incoming connection from %s:%d...\n", client_ip, ntohs(clientaddr.sin_port));
        
        // read data from client
        while ((n = read(connfd, buf, MAXLINE)) > 0) {
            printf("Received %d bytes from client %s:%d...\n", n, client_ip, ntohs(clientaddr.sin_port));
            printf("Message from client: %s", buf);
            
            // modify the message, toUpperCase style :)
            for(int i = 0; i < n; i++) {
                buf[i] = toupper(buf[i]);
            }
            
            // write modified message back to client
            if (write(connfd, buf, n) < 0) {
                perror("write error");
                exit(1);
            }
        }
        if (n == 0) {
            printf("Connection to %s:%d closed by client...\n", client_ip, ntohs(clientaddr.sin_port));
        } else {
            perror("read error");
            exit(1);
        }
        close(connfd);
    }

    return 0;
}