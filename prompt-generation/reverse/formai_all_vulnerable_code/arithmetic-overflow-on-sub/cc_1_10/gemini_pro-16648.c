//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

#define SERVER_PORT 8080
#define MAX_BUFFER_SIZE 1024

typedef struct {
    char *buffer;
    size_t length;
} DataPacket;

int createSocket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(1);
    }
    return sockfd;
}

struct sockaddr_in createSocketAddress(char *ip, int port) {
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(ip);
    return servaddr;
}

void connectToServer(int sockfd, struct sockaddr_in servaddr) {
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
}

DataPacket receiveData(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    int n;
    if ((n = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) < 0) {
        perror("Error receiving data");
        exit(1);
    }
    DataPacket dataPacket;
    dataPacket.buffer = malloc(n);
    memcpy(dataPacket.buffer, buffer, n);
    dataPacket.length = n;
    return dataPacket;
}

void sendData(int sockfd, char *data, size_t length) {
    if (send(sockfd, data, length, 0) < 0) {
        perror("Error sending data");
        exit(1);
    }
}

double calculateSpeed(size_t totalBytes, double timeTaken) {
    return (double) totalBytes / timeTaken;
}

void printSpeed(double speed) {
    printf("Speed: %.2f Mbps\n", speed);
}

int main() {
    int sockfd;
    char *serverIp = "127.0.0.1";

    sockfd = createSocket();
    struct sockaddr_in servaddr = createSocketAddress(serverIp, SERVER_PORT);
    connectToServer(sockfd, servaddr);

    char msg[MAX_BUFFER_SIZE];
    sprintf(msg, "SPEED_TEST");
    sendData(sockfd, msg, strlen(msg));

    clock_t start = clock();
    DataPacket dataPacket = receiveData(sockfd);
    clock_t end = clock();
    double timeTaken = (double) (end - start) / CLOCKS_PER_SEC;

    double speed = calculateSpeed(dataPacket.length, timeTaken);
    printSpeed(speed);

    close(sockfd);
    free(dataPacket.buffer);
    return 0;
}