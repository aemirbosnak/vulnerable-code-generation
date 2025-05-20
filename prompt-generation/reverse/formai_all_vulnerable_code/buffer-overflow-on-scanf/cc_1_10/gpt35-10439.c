//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pwd.h>
#include <unistd.h>
#include <ctype.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100

struct threadArgs {
    char* ipAddr;
    int port;
};

// function to scan individual IP addresses and ports
void* scanner(void* arg) {
    struct threadArgs* args = (struct threadArgs*) arg;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket() error");
        return NULL;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(args->port);
    inet_pton(AF_INET, args->ipAddr, &(servaddr.sin_addr));

    int ret = connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
    if (ret == 0) {
        printf("%-15s %d: Open\n", args->ipAddr, args->port);
    }

    close(sockfd);
    return NULL;
}

int main() {
    printf("C Wireless Network Scanner\n");

    char* ipAddr = malloc(sizeof(char) * 16);
    printf("Enter the IP address range to scan (e.g. 192.168.0): ");
    fgets(ipAddr, 16, stdin);
    ipAddr[strcspn(ipAddr, "\n")] = 0;

    int startPort, endPort;
    printf("Enter the starting port number to scan: ");
    scanf("%d", &startPort);
    printf("Enter the ending port number to scan: ");
    scanf("%d", &endPort);

    pthread_t threads[MAX_THREADS];
    int threadCount = 0;
    struct threadArgs args[MAX_THREADS];

    for (int port = startPort; port <= endPort; port++) {
        for (int i = 1; i <= 255; i++) {
            char* finalAddr = malloc(sizeof(char) * 16);
            sprintf(finalAddr, "%s.%d", ipAddr, i);

            args[threadCount] = (struct threadArgs) {finalAddr, port};
            pthread_create(&threads[threadCount], NULL, scanner, &args[threadCount]);

            threadCount++;
            if (threadCount == MAX_THREADS) {
                for (int j = 0; j < threadCount; j++) {
                    pthread_join(threads[j], NULL);
                }
                threadCount = 0;
            }
        }
    }

    for (int j = 0; j < threadCount; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("Scan complete.\n");
    return 0;
}