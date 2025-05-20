//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: safe
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int opt = 1;
    struct timeval timeout;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8888);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    listen(sockfd, 5);

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    while (1) {
        portno = htons(atoi(gets(buffer)));
        if (portno == 0) {
            break;
        }

        timeout.tv_sec = 2;
        timeout.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        if ((n = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0) {
            perror("connect failed");
            continue;
        }

        printf("Connected to port %d\n", portno);

        char command[1024];
        sprintf(command, "curl -s -o /dev/null -w \"%{speed_download}\" http://localhost:%d/speedtest", portno);
        system(command);
        printf("Download Speed: %s\n", buffer);

        sprintf(command, "curl -s -o /dev/null -w \"%{speed_upload}\" http://localhost:%d/speedtest", portno);
        system(command);
        printf("Upload Speed: %s\n", buffer);

        close(sockfd);
    }

    return 0;
}