//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "192.168.1.100"

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_size;
    time_t start_time, end_time;
    double total_time;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);
    send(sock, "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n"), 0);

    while ((data_size = recv(sock, data, MAX_DATA_SIZE, 0)) > 0) {
        data[data_size] = '\0';
        printf("%s", data);
    }

    end_time = time(NULL);
    total_time = difftime(end_time, start_time);

    printf("Total time: %.2lf seconds\n", total_time);

    close(sock);

    return 0;
}