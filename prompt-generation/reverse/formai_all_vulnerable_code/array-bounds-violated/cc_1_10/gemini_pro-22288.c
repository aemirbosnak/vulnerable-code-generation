//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

struct sockaddr_in servaddr, cliaddr;
int sockfd;

void *receive_thread(void *args) {
    int len;
    char buffer[1024];

    while (1) {
        len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &cliaddr, &len);
        buffer[len] = '\0';
        printf("Received: %s\n", buffer);
    }

    return 0;
}

int main() {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    pthread_t tid;
    pthread_create(&tid, NULL, receive_thread, NULL);

    while (1) {
        char buffer[1024];
        fgets(buffer, sizeof(buffer), stdin);

        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *) &cliaddr, sizeof(cliaddr));
    }

    return 0;
}