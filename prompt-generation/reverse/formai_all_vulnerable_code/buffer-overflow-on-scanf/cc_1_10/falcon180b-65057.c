//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define NUM_TESTS 5
#define TEST_INTERVAL 1 // in seconds

void send_request(int sock, char *server_ip) {
    char request[100] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, server_ip);
    strcat(request, "\r\nConnection: close\r\n\r\n");

    send(sock, request, strlen(request), 0);
}

double measure_speed(int sock, char *server_ip) {
    struct timeval start, end;
    double elapsed_time;

    gettimeofday(&start, NULL);
    send_request(sock, server_ip);
    recv(sock, NULL, 0, 0); // discard response
    gettimeofday(&end, NULL);

    elapsed_time = ((end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec) / 1000000.0;

    return elapsed_time;
}

int main() {
    int sock, ret;
    struct sockaddr_in server_addr;
    char server_ip[20];
    double speeds[NUM_TESTS];

    printf("Enter the IP address of the server: ");
    scanf("%s", server_ip);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    for (int i = 0; i < NUM_TESTS; i++) {
        speeds[i] = measure_speed(sock, server_ip);
        printf("Test %d: %.2f Mbps\n", i+1, speeds[i] / (1024*1024));
        usleep(TEST_INTERVAL * 1000000); // wait for a second
    }

    close(sock);
    return 0;
}