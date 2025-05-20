//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: safe
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

void scanip(const char* host, int start_port, int end_port) {
    int sockfd, connfd, port;
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        perror("Error Creating Socket\n");
        exit(1);
    }

    server = gethostbyname(host);

    if(server == NULL) {
        perror("Error: No such Host\n");
        exit(1);
    }

    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&server_addr.sin_addr.s_addr, server->h_length);

    for(port=start_port; port<=end_port; port++) {
        server_addr.sin_port = htons(port);
        connfd = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if(connfd < 0) continue;
        else {
            printf("Port %d is open\n", port);
            close(connfd);
        }
    }
    close(sockfd);
    return;
}

int main() {
    char *host;
    int start_port, end_port;

    printf("Enter the host name: ");
    scanf("%s",host);
    printf("Enter the starting port: ");
    scanf("%d",&start_port);
    printf("Enter the ending port: ");
    scanf("%d",&end_port);

    printf("Scanning....\n");
    scanip(host, start_port, end_port);
    return 0;
}