//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

struct hostent *hosts[MAX_THREADS];
int ports[MAX_THREADS];
int num_threads;

void *scan_thread(void *arg) {
    int sock;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    struct sockaddr_in server_addr;
    memcpy(&server_addr, arg, sizeof(server_addr));

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return NULL;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
        close(sock);
        return NULL;
    }

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0))!= 0) {
        buffer[bytes_received] = '\0';
        printf("Received %d bytes from %s:%d: %s\n", bytes_received, inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port), buffer);
    }

    close(sock);
    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];
    char ip[16];
    int port;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter port range (start-end): ");
    scanf("%d-%d", &port, &port);

    num_threads = 0;

    for (i = port; i <= port; i++) {
        if (num_threads >= MAX_THREADS) {
            printf("Maximum number of threads reached\n");
            break;
        }

        if (gethostbyname(ip) == NULL) {
            printf("Invalid hostname\n");
            return 1;
        }

        hosts[num_threads] = gethostbyname(ip);
        ports[num_threads] = i;
        num_threads++;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_thread, (void *)&hosts[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}