//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110

#define BUF_SIZE 1024

void send_command(int socket, const char* command) {
    char buffer[BUF_SIZE];
    sprintf(buffer, "%s\r\n", command);
    printf("Sending command: %s\n", buffer);
    send(socket, buffer, strlen(buffer), 0);
}

void check_response(int socket, const char* expected) {
    char buffer[BUF_SIZE];
    int bytes_received = recv(socket, buffer, BUF_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Received response: %s", buffer);
    if (strncmp(buffer, expected, strlen(expected)) != 0) {
        printf("Error: unexpected response from server.\n");
        exit(1);
    }
}

void get_mailbox_status(int socket, int* num_messages) {
    send_command(socket, "STAT");
    char buffer[BUF_SIZE];
    int bytes_received = recv(socket, buffer, BUF_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Received response: %s", buffer);
    sscanf(buffer, "+OK %d", num_messages);
}

void get_message(int socket, int message_num) {
    char buffer[BUF_SIZE];
    sprintf(buffer, "RETR %d", message_num);
    send_command(socket, buffer);
    while (1) {
        int bytes_received = recv(socket, buffer, BUF_SIZE - 1, 0);
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "\r\n.\r\n") != NULL) {
            printf("\n");
            break;
        }
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: could not create socket.\n");
        exit(1);
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(POP3_PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: could not connect to server.\n");
        exit(1);
    }
    check_response(sock, "+OK");
    send_command(sock, "USER testuser");
    check_response(sock, "+OK");
    send_command(sock, "PASS testpass");
    check_response(sock, "+OK");
    int num_messages;
    get_mailbox_status(sock, &num_messages);
    printf("You have %d messages.\n", num_messages);
    for (int i = 1; i <= num_messages; i++) {
        printf("Message %d:\n", i);
        get_message(sock, i);
    }
    send_command(sock, "QUIT");
    check_response(sock, "+OK");
    close(sock);
    return 0;
}