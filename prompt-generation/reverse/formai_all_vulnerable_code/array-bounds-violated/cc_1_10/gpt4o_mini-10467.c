//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define IMAP_PORT 143
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_server(const char *server) {
    int sock;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        error("Invalid address / Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to the server failed");
    }

    return sock;
}

void disconnect(int sock) {
    close(sock);
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void read_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytesRead;

    while ((bytesRead = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) {
            break;
        }
    }
}

void login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", username, password);
    send_command(sock, command);
    read_response(sock);
}

void list_mailboxes(int sock) {
    const char *command = "A002 LIST \"\" \"*\"\r\n";
    send_command(sock, command);
    read_response(sock);
}

void select_mailbox(int sock, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A003 SELECT \"%s\"\r\n", mailbox);
    send_command(sock, command);
    read_response(sock);
}

void fetch_email(int sock, const char *email_id) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A004 FETCH %s BODY[]\r\n", email_id);
    send_command(sock, command);
    read_response(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP_server_ip> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock = connect_to_server(server);
    
    read_response(sock); // Read the server's greeting

    login(sock, username, password);
    list_mailboxes(sock);
    
    const char *mailbox = "INBOX"; // adjust as needed
    select_mailbox(sock, mailbox);
    
    fetch_email(sock, "1"); // Fetching the first email, you can adjust as needed

    disconnect(sock);
    return 0;
}