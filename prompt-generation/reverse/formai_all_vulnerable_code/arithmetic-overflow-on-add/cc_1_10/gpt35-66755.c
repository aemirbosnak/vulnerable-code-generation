//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

int is_running = 1;
pthread_t monitor_thread, sender_thread;

void signal_handler(int sig) {
    is_running = 0;
    printf("\nStopping the network quality of service monitor...\n");
    pthread_cancel(monitor_thread);
    pthread_cancel(sender_thread);
    fflush(stdout);
    exit(0);
}

void* send_data() {
    int sock, bytes_sent;
    struct sockaddr_in addr;
    char buf[1024];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) <= 0) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (is_running) {
        strcpy(buf, "This is test data for network quality of service monitor");
        bytes_sent = send(sock, buf, strlen(buf), 0);
        if (bytes_sent < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        sleep(1);
    }

    close(sock);

    pthread_exit(NULL);
}

void* monitor_network_qos() {
    int sock, bytes_received, total_bytes_received = 0;
    struct sockaddr_in addr;
    char buf[1024];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 1) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    int client_sock, client_addr_len;
    struct sockaddr_in client_addr;
    client_addr_len = sizeof(client_addr);

    if ((client_sock = accept(sock, (struct sockaddr*)&client_addr, &client_addr_len)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Network quality of service monitor started...\n");

    while (is_running) {
        bytes_received = recv(client_sock, buf, sizeof(buf), 0);
        if (bytes_received < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        total_bytes_received += bytes_received;

        if (total_bytes_received % 10 == 0) {
            printf(".");
            fflush(stdout);
        }

        if (total_bytes_received % 500 == 0) {
            printf("\n");
            fflush(stdout);
        }

        sleep(1);
    }

    close(sock);
    close(client_sock);

    pthread_exit(NULL);
}

int main() {
    signal(SIGINT, signal_handler);

    if (pthread_create(&monitor_thread, NULL, monitor_network_qos, NULL) != 0) {
        perror("monitor thread creation failed");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&sender_thread, NULL, send_data, NULL) != 0) {
        perror("sender thread creation failed");
        exit(EXIT_FAILURE);
    }

    pthread_join(monitor_thread, NULL);
    pthread_join(sender_thread, NULL);

    return 0;
}