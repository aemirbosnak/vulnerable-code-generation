//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Socket, mail server, and mailbox data
int sockfd;
struct sockaddr_in serv_addr;
char mailbox[100];

// Function prototypes
void connect_to_server(const char*);
void send_email(const char*, const char*, const char*);
void receive_email();
void display_help();

int main() {
    char user_input[100];
    bool quit = false;

    printf("Welcome to the Cyberpunk Email Client. Type 'help' for assistance.\n");

    while (!quit) {
        printf("\nEnter command: ");
        scanf("%s", user_input);

        if (!strcmp(user_input, "connect")) {
            char server[100];
            printf("Enter mail server address: ");
            scanf("%s", server);
            connect_to_server(server);
        } else if (!strcmp(user_input, "send")) {
            char recipient[100], subject[100], body[100];
            printf("Enter recipient email address: ");
            scanf("%s", recipient);
            printf("Enter subject: ");
            scanf("%s", subject);
            printf("Enter email body: ");
            scanf("%s", body);
            send_email(recipient, subject, body);
        } else if (!strcmp(user_input, "receive")) {
            receive_email();
        } else if (!strcmp(user_input, "help")) {
            display_help();
        } else if (!strcmp(user_input, "quit")) {
            quit = true;
        } else {
            printf("Invalid command. Type 'help' for assistance.\n");
        }
    }

    return 0;
}

void connect_to_server(const char *server) {
    struct hostent *host_info = gethostbyname(server);
    if (!host_info) {
        printf("Error: Invalid mail server address.\n");
        return;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, host_info->h_addr_list[0], host_info->h_length);
    serv_addr.sin_port = htons(25);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket.\n");
        return;
    }

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not connect to mail server.\n");
        return;
    }

    printf("Connected to mail server.\n");
}

void send_email(const char *recipient, const char *subject, const char *body) {
    char message[500];
    sprintf(message, "MAIL FROM: <%s>\r\nRCPT TO: <%s>\r\nDATA\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", mailbox, recipient, subject, body);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        printf("Error: Could not send email.\n");
        return;
    }

    printf("Email sent.\n");
}

void receive_email() {
    char recv_buffer[500];
    if (recv(sockfd, recv_buffer, sizeof(recv_buffer), 0) < 0) {
        printf("Error: Could not receive email.\n");
        return;
    }

    printf("%s", recv_buffer);
}

void display_help() {
    printf("Commands:\n");
    printf("connect: Connect to mail server\n");
    printf("send: Send an email\n");
    printf("receive: Receive emails\n");
    printf("help: Display this help message\n");
    printf("quit: Quit the client\n");
}