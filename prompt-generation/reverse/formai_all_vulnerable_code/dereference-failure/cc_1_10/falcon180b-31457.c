//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

typedef struct {
    char *ip;
    int port;
} server_info;

void print_usage(char *prog_name) {
    printf("Usage: %s <server_ip> <server_port>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    server_info server = {
       .ip = server_ip,
       .port = server_port
    };

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    time_t start_time = time(NULL);

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Connection closed by server\n");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);

        if (difftime(time(NULL), start_time) >= 10) {
            double speed = (double)bytes_received / (difftime(time(NULL), start_time) * 1000);
            printf("Speed: %.2f KB/s\n", speed);
            bytes_received = 0;
            start_time = time(NULL);
        }
    }

    close(sock);
    return 0;
}