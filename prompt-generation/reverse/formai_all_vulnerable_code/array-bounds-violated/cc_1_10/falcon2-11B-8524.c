//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080

typedef struct {
    int speed;
    char direction;
} Vehicle;

void* rcVehicle(void* arg) {
    Vehicle* vehicle = (Vehicle*)arg;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
    int ret = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if (ret == -1) {
        printf("Failed to connect\n");
        return NULL;
    }
    char msg[1024];
    sprintf(msg, "Speed: %d, Direction: %c\n", vehicle->speed, vehicle->direction);
    send(sockfd, msg, strlen(msg), 0);
    while (1) {
        char recvmsg[1024];
        int n = recv(sockfd, recvmsg, 1024, 0);
        if (n == -1) {
            printf("Failed to receive\n");
            break;
        }
        recvmsg[n] = '\0';
        printf("%s\n", recvmsg);
    }
    close(sockfd);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    Vehicle vehicle = {rand() % 5, rand() % 2 == 0? 'F' : 'B'};
    pthread_t thread;
    pthread_create(&thread, NULL, rcVehicle, &vehicle);
    pthread_join(thread, NULL);
    return 0;
}