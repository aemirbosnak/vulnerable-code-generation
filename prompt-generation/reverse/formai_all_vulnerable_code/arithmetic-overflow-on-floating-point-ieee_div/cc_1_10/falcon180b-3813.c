//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT "80"
#define SERVER_NAME "www.example.com"

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_size = 0;
    double total_time = 0;
    double avg_time = 0;
    int num_requests = 0;
    double min_time = 99999;
    double max_time = 0;
    int i;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(SERVER_PORT));
    server_addr.sin_addr.s_addr = inet_addr(SERVER_NAME);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send HTTP request
    char http_request[100];
    sprintf(http_request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_NAME);
    send(sock, http_request, strlen(http_request), 0);

    // Receive response
    data_size = recv(sock, data, MAX_DATA_SIZE, 0);
    if (data_size <= 0) {
        printf("Error receiving data from server\n");
        exit(1);
    }

    // Close socket
    close(sock);

    // Calculate response time
    double response_time = (double)data_size / (double)num_requests;

    // Print results
    printf("Total requests: %d\n", num_requests);
    printf("Average response time: %.2f ms\n", response_time * 1000);
    printf("Minimum response time: %.2f ms\n", response_time * 1000);
    printf("Maximum response time: %.2f ms\n", response_time * 1000);

    return 0;
}