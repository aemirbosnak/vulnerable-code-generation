//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define SERVER_PORT 110 // Standard port for POP3
#define MAX_BUFFER 1024
#define MAX_EMAILS 100

typedef struct {
    char *hostname;
    char *username;
    char *password;
} pop3_config;

void *establish_connection(void *arg) {
    int sock;
    struct sockaddr_in server_address;
    pop3_config *config = (pop3_config *)arg;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return NULL;
    }

    // Set up server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, config->hostname, &server_address.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sock);
        return NULL;
    }

    return (void *)(long)sock;
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void receive_response(int sock) {
    char buffer[MAX_BUFFER];
    int bytes_received;

    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("%s", buffer);
    }
}

void pop3_authenticate(int sock, pop3_config *config) {
    char command[MAX_BUFFER];

    // Send USER command
    snprintf(command, sizeof(command), "USER %s\r\n", config->username);
    send_command(sock, command);
    receive_response(sock);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", config->password);
    send_command(sock, command);
    receive_response(sock);
}

void list_emails(int sock) {
    char command[] = "LIST\r\n";
    send_command(sock, command);
    receive_response(sock);
}

void fetch_email(int sock, int email_number) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "RETR %d\r\n", email_number);
    send_command(sock, command);
    receive_response(sock);
}

void delete_email(int sock, int email_number) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "DELE %d\r\n", email_number);
    send_command(sock, command);
    receive_response(sock);
}

int main() {
    pthread_t connection_thread;
    pop3_config config;

    // Set POP3 server details
    config.hostname = "pop.example.com"; // Replace with your POP3 server
    config.username = "user@example.com"; // Replace with your username
    config.password = "password"; // Replace with your password

    // Establish connection to the POP3 server
    int sock;
    pthread_create(&connection_thread, NULL, establish_connection, (void *)&config);
    pthread_join(connection_thread, (void **)&sock);

    if (sock > 0) {
        receive_response(sock); // Get server greeting
        pop3_authenticate(sock, &config);
        list_emails(sock);
        
        // Fetch a specific email message
        printf("Fetching email number 1:\n");
        fetch_email(sock, 1);

        // Clean up and delete email if desired
        // delete_email(sock, 1);

        char quit_command[] = "QUIT\r\n";
        send_command(sock, quit_command);
        receive_response(sock);
        close(sock);
    } else {
        printf("Failed to establish connection.\n");
    }

    return 0;
}