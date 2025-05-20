//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <errno.h>

#define PING_COUNT 4
#define BUFFER_SIZE 1024
#define TARGET_IP "8.8.8.8" // Google's public DNS server for QoS monitoring

void ping() {
    printf("\n--- PING TEST ---\n");
    char command[100];
    snprintf(command, sizeof(command), "ping -c %d %s", PING_COUNT, TARGET_IP);
    int result = system(command);
    if (result == -1) {
        perror("Ping failed");
    }
}

void bandwidth_test() {
    printf("\n--- BANDWIDTH TEST ---\n");
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_sent, total_bytes_sent = 0;
    time_t start_time, end_time;
    double elapsed;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // Server port
    server_addr.sin_addr.s_addr = inet_addr(TARGET_IP);

    // Fill buffer with random data
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 'A' + (rand() % 26);
    }

    start_time = time(NULL);

    // Send data to the server
    while (total_bytes_sent < (BUFFER_SIZE * 10)) { // Send 10 times the buffer size
        bytes_sent = sendto(sock, buffer, BUFFER_SIZE, 0,
                            (struct sockaddr*)&server_addr, sizeof(server_addr));
        if (bytes_sent < 0) {
            perror("Send failed");
            close(sock);
            return;
        }
        total_bytes_sent += bytes_sent;
    }

    end_time = time(NULL);
    elapsed = difftime(end_time, start_time);

    printf("Sent %ld bytes in %.2f seconds.\n", total_bytes_sent, elapsed);
    printf("Bandwidth: %.2f KB/s\n", (total_bytes_sent / 1024.0) / elapsed);

    close(sock);
}

int main() {
    srand(time(NULL));
    int choice;

    while (1) {
        printf("\n--- Network Quality of Service (QoS) Monitor ---\n");
        printf("1. Ping Test\n");
        printf("2. Bandwidth Test\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ping();
                break;
            case 2:
                bandwidth_test();
                break;
            case 3:
                printf("Exiting the Network QoS Monitor. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select again.\n");
        }
    }

    return 0;
}