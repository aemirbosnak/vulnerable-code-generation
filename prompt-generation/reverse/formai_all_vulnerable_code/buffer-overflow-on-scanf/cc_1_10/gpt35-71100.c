//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define DEFAULT_PORT 8080

void* scan_wireless_network(void* arg);

int main(int argc, char const *argv[])
{
    int i, sock;
    struct sockaddr_in server;
    pthread_t scanner_threads[255];
    char* ip_address_prefix;

    ip_address_prefix = malloc(sizeof(char) * 16);
    printf("Enter the IP address prefix to scan, e.g. 192.168.0: ");
    scanf("%s", ip_address_prefix);

    for(i = 1; i < 255; i++) {
        char* ip_address = malloc(sizeof(char) * 16);
        sprintf(ip_address, "%s.%d", ip_address_prefix, i);

        pthread_create(&scanner_threads[i], NULL, scan_wireless_network, (void*) ip_address);
    }

    for(i = 1; i < 255; i++) {
        pthread_join(scanner_threads[i], NULL);
    }

    free(ip_address_prefix);

    return 0;
}

void* scan_wireless_network(void* arg)
{
    char* ip_address = (char*) arg;
    int sock;
    struct sockaddr_in server;

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error %d: %s\n", errno, strerror(errno));
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(DEFAULT_PORT);
    server.sin_addr.s_addr = inet_addr(ip_address);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0 )
    {
        close(sock);
        return NULL;
    }

    printf("Wireless network found at %s:%d\n", ip_address, DEFAULT_PORT);

    close(sock);

    return NULL;
}