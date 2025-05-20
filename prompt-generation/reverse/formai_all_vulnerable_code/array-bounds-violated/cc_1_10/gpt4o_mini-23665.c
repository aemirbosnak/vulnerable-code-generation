//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9090
#define BUF_SIZE 1024
#define MAIL_BOX "whispers_of_the_void.txt"

void create_mail_box();
void send_message(const char *message);
void receive_message(int socket_desc);
void magical_realm();
void invoke_message(const char *message);

int main() {
    magical_realm();
    return 0;
}

void magical_realm() {
    int sock;
    struct sockaddr_in server;
    char message[BUF_SIZE], server_response[BUF_SIZE];

    create_mail_box();

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("The universe trembled as the socket failed to form");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("The stars aligned incorrectly, connection failed");
        exit(EXIT_FAILURE);
    }

    printf("In this realm of byte and shadow, a rhyme unfolds:\n");
    while (1) {
        printf("You: ");
        fgets(message, BUF_SIZE, stdin);
        invoke_message(message);      
        send_message(message);

        if (strstr(message, "exit")) {
            printf("You have exited the loop of time, until we meet again.\n");
            break;
        }

        receive_message(sock);
    }

    close(sock);
    printf("The connection has been severed, yet echoes linger.\n");
}

void create_mail_box() {
    FILE *fptr = fopen(MAIL_BOX, "a");
    if (!fptr) {
        perror("Cannot open the ethereal mailbox");
        exit(EXIT_FAILURE);
    }
    fclose(fptr);
}

void send_message(const char *message) {
    FILE *fptr = fopen(MAIL_BOX, "a");
    if (!fptr) {
        perror("The whispers of the void cannot be captured");
        return;
    }

    fprintf(fptr, "Sent: %s", message);
    fclose(fptr);
}

void receive_message(int socket_desc) {
    char response[BUF_SIZE];
    int read_size;

    read_size = recv(socket_desc, response, BUF_SIZE, 0);
    if (read_size > 0) {
        response[read_size] = '\0';
        printf("Server: %s\n", response);
        send_message(response);
    } else {
        perror("The echo of the server faded into silence");
    }
}

void invoke_message(const char *message) {
    char *cmd = malloc(BUF_SIZE);
    snprintf(cmd, BUF_SIZE, "echo \"You've sent a message into the cosmic void: %s\" >> %s", message, MAIL_BOX);
    system(cmd);
    free(cmd);
}