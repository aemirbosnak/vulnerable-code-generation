//FormAI DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define SERVER_ROOT "/var/www/html/"
#define IS_GET(m) ((strncmp(m, "GET", 3) == 0))
#define NOT_FOUND "<h1>404 Not Found</h1>"

int main(int argc, char **argv)
{
    int sockfd, connfd, port, fd, n;
    struct sockaddr_in addr;
    socklen_t addrlen;
    char filename[128], webpage[4096], buf[1024], method[8], *ptr;

    if(argc == 2) port = atoi(argv[1]);
    else port = 80;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) exit(-1);

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if(bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) exit(-1);

    if(listen(sockfd, 10) < 0) exit(-1);

    while(1) {
        addrlen = sizeof(addr);
        connfd = accept(sockfd, (struct sockaddr *)&addr, &addrlen);
        if(connfd < 0) break;

        n = read(connfd, buf, sizeof(buf));
        sscanf(buf, "%s %s", method, filename);

        if(IS_GET(method)) {
            ptr = strchr(filename, '?');
            if(ptr) *ptr++ = 0;

            sprintf(webpage, "%s%s", SERVER_ROOT, filename);
            fd = open(webpage, O_RDONLY);
            if(fd < 0) {
                write(connfd, NOT_FOUND, sizeof(NOT_FOUND));
                close(fd);
            } else {
                n = 0;
                while((n = read(fd, webpage, sizeof(webpage))) > 0) {
                    write(connfd, webpage, n);
                }
                close(fd);
            }
        }
        close(connfd);
    }

    return 0;
}