//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_DEVICES 100
#define MAX_IP_LENGTH 16

typedef struct {
    char hostname[MAX_IP_LENGTH];
    char ip_address[MAX_IP_LENGTH];
} Device;

int num_devices = 0;
Device devices[MAX_DEVICES];

void *pingHost(void *args) {
    char *ip_address = (char *) args;

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &(server.sin_addr));

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket error");
        return NULL;
    }

    int res = connect(sockfd, (struct sockaddr *) &server, sizeof(server));
    if (res == -1) {
        close(sockfd);
        return NULL;
    }

    struct hostent *host_info;
    host_info = gethostbyaddr(&(server.sin_addr), sizeof(struct in_addr), AF_INET);

    if (host_info == NULL) {
        strcpy(devices[num_devices].hostname, "Unknown");
    } else {
        strcpy(devices[num_devices].hostname, host_info->h_name);
    }

    strcpy(devices[num_devices].ip_address, ip_address);
    num_devices++;

    close(sockfd);

    return NULL;
}

int main(int argc, char *argv[]) {
    char subnet[MAX_IP_LENGTH];
    printf("Enter the subnet to scan (Eg. 192.168.1): ");
    scanf("%s", subnet);

    pthread_t threads[256];
    int rc, i;

    for (i = 1; i < 255; i++) {
        char ip_address[MAX_IP_LENGTH];
        sprintf(ip_address, "%s.%d", subnet, i);

        rc = pthread_create(&threads[i], NULL, pingHost, (void *) ip_address);
        if (rc) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(1);
        }
    }

    for (i = 1; i < 255; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Found %d devices on the network:\n", num_devices);
    for (i = 0; i < num_devices; i++) {
        printf("%-20.20s %s\n", devices[i].hostname, devices[i].ip_address);
    }

    return 0;
}