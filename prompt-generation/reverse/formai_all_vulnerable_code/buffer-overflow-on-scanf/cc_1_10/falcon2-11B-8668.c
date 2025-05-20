//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct Proxy {
    char host[64];
    int port;
};

void handleProxy(struct Proxy* proxy) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(proxy->port);
    inet_pton(AF_INET, proxy->host, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to proxy");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer));
    while (n > 0) {
        write(STDOUT_FILENO, buffer, n);
        n = read(STDIN_FILENO, buffer, sizeof(buffer));
    }

    close(sockfd);
    printf("Proxy closed\n");
    exit(EXIT_SUCCESS);
}

int main() {
    char url[64];
    printf("Enter URL: ");
    scanf("%s", url);

    char* cmd = (char*)malloc(sizeof(char) * 100);
    sprintf(cmd, "xdg-open http://%s", url);
    system(cmd);

    struct Proxy proxy;
    strcpy(proxy.host, "127.0.0.1");
    proxy.port = 8080;

    handleProxy(&proxy);

    return 0;
}