//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

bool is_connected = false;

int connect_to_server(char *server_ip, int port) {
    struct sockaddr_in serv_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        printf("Invalid server IP address\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Unable to connect to server\n");
        exit(1);
    }

    is_connected = true;

    return sock;
}

void send_data(int sock, char message[BUFFER_SIZE]) {
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Unable to send message\n");
        exit(1);
    }
}

void read_data(int sock, char buffer[BUFFER_SIZE]) {
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Unable to read data from socket\n");
        exit(1);
    }
}

int main() {
    char server_ip[50];
    int port = 993;

    printf("Enter server IP address: ");
    scanf("%s", server_ip);

    int sock = connect_to_server(server_ip, port);

    char buffer[BUFFER_SIZE];
    read_data(sock, buffer);

    printf("%s", buffer);

    char username[50];
    char password[50];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    snprintf(buffer, BUFFER_SIZE, "LOGIN %s %s", username, password);
    send_data(sock, buffer);

    read_data(sock, buffer);

    if (strstr(buffer, "OK") != NULL) {
        printf("Successfully logged in!\n");
    } else {
        printf("Unable to log in. Please check your credentials and try again.\n");
        exit(0);
    }

    while (true) {
        printf("Enter an IMAP command: ");
        scanf("%s", buffer);

        send_data(sock, buffer);

        if (strcmp(buffer, "QUIT") == 0) {
            break;
        }

        read_data(sock, buffer);

        printf("%s\n", buffer);
    }

    close(sock);

    return 0;
}