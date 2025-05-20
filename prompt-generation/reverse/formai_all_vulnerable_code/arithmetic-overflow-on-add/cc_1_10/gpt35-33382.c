//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 32

void* scan(void* arg);

int main(int argc, char** argv) {

    int start_ip, end_ip, threads;
    struct sockaddr_in server_addr;

    if (argc != 4) {
        printf("Usage: ./wireless_scanner <starting IP> <ending IP> <threads>\n");
        return 1;
    }

    // get the starting and ending IP addresses
    start_ip = inet_addr(argv[1]);
    end_ip = inet_addr(argv[2]);

    // get the number of threads to use
    threads = atoi(argv[3]);

    // initialize the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(80);

    // create an array of thread IDs
    pthread_t tids[MAX_THREADS];

    // loop through the range of IP addresses and spawn threads
    int i, ip;
    for (i = 0, ip = start_ip; ip <= end_ip; i++, ip++) {
        // if we've reached the maximum number of threads, wait for them to finish
        if (i == threads) {
            int j;
            for (j = 0; j < threads; j++) {
                pthread_join(tids[j], NULL);
            }
            i = 0;
        }

        // create a thread to scan the IP address
        pthread_create(&tids[i], NULL, scan, &server_addr.sin_addr.s_addr);
    }

    // wait for the remaining threads to finish
    int j;
    for (j = 0; j < i; j++) {
        pthread_join(tids[j], NULL);
    }

    return 0;
}

void* scan(void* arg) {
    struct in_addr* address = arg;
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        // error opening socket - print error message and exit thread
        printf("ERROR opening socket\n");
        pthread_exit(NULL);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, address, sizeof(struct in_addr));
    server_addr.sin_port = htons(80);

    // attempt to connect to the server
    if (connect(sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) >= 0) {
        // server is up - print its IP address
        printf("Server found at IP: %s\n", inet_ntoa(*address));
    }

    // close the socket and exit thread
    close(sock_fd);
    pthread_exit(NULL);
}