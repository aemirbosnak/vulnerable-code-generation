//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE   1
#define FALSE  0
#define PORT 8080
#define MAX 100

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char send_data[MAX];
    char recv_data[MAX];
    int len;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == 0) {
        printf("\n Socket creation failed \n");
        exit(0);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Connection failed \n");
        exit(0);
    }

    printf("\n Connection Established with the server \n");

    while (TRUE) {
        memset(send_data, '\0', sizeof(send_data));
        printf("\n Enter the data to be sent to the server:");
        scanf("%[^\n]s", send_data);

        send(sock, send_data, strlen(send_data), 0);

        memset(recv_data, '\0', sizeof(recv_data));
        len = recv(sock, recv_data, sizeof(recv_data), 0);

        if (len <= 0) {
            printf("\n Disconnected from the server \n");
            break;
        }

        printf("\n Data received from the server: %s", recv_data);
    }

    close(sock);

    return 0;
}