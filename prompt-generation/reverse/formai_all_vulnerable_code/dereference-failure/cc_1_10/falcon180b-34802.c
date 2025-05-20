//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *he;
    struct sockaddr_in serv_addr;
    char send_data[MAX_DATA_SIZE];
    char recv_data[MAX_DATA_SIZE];
    int len;
    int data_len;
    struct timeval tv;
    fd_set readfds;

    if (argc!= 3) {
        printf("Usage:./ping <hostname/IP> <data_size>\n");
        exit(1);
    }

    strcpy(send_data, argv[2]);
    data_len = strlen(send_data);

    if ((he = gethostbyname(argv[1])) == NULL) {
        printf("Error: Invalid hostname/IP\n");
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr.s_addr = *(unsigned long *)he->h_addr;

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    while (1) {
        if (select(sock + 1, &readfds, NULL, NULL, &tv) == -1) {
            printf("Error: Select failed\n");
            exit(1);
        }

        if (FD_ISSET(sock, &readfds)) {
            memset(recv_data, 0, MAX_DATA_SIZE);

            if ((len = recv(sock, recv_data, MAX_DATA_SIZE, 0)) <= 0) {
                printf("Error: Data reception failed\n");
                exit(1);
            }

            printf("Received data: %s\n", recv_data);
        }
    }

    close(sock);

    return 0;
}