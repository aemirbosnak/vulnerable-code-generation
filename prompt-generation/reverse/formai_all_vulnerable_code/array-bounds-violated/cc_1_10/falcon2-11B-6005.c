//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

struct email_client {
    int connection_socket;
    char* hostname;
    char* port;
    char* username;
    char* password;
};

struct email_message {
    char* sender;
    char* recipient;
    char* subject;
    char* body;
};

struct email_client* create_client(char* hostname, char* port, char* username, char* password) {
    struct email_client* client = (struct email_client*) malloc(sizeof(struct email_client));
    client->hostname = hostname;
    client->port = port;
    client->username = username;
    client->password = password;
    return client;
}

int connect_to_server(struct email_client* client) {
    int connection_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (connection_socket == -1) {
        fprintf(stderr, "Error creating socket\n");
        return 0;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(client->port));
    server_address.sin_addr.s_addr = inet_addr(client->hostname);

    int result = connect(connection_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if (result == -1) {
        fprintf(stderr, "Error connecting to server\n");
        return 0;
    }

    client->connection_socket = connection_socket;
    return 1;
}

int send_email(struct email_client* client, char* recipient, char* subject, char* body) {
    char email_message[BUFFER_SIZE];
    sprintf(email_message, "To: %s\nFrom: %s\nSubject: %s\n\n%s", recipient, client->username, subject, body);
    int result = send(client->connection_socket, email_message, strlen(email_message), 0);
    if (result == -1) {
        fprintf(stderr, "Error sending email\n");
        return 0;
    }

    return 1;
}

int receive_email(struct email_client* client, char* sender, char* subject, char* body) {
    char email_message[BUFFER_SIZE];
    int result = recv(client->connection_socket, email_message, BUFFER_SIZE, 0);
    if (result == -1) {
        fprintf(stderr, "Error receiving email\n");
        return 0;
    }

    int end_of_email = email_message[strlen(email_message) - 1] == '\n';
    char* message = email_message;
    char* end_of_message = strstr(message, "\n\n");
    if (end_of_message == NULL) {
        fprintf(stderr, "Error parsing email\n");
        return 0;
    }

    char* sender_field = strstr(message, "To:");
    char* subject_field = strstr(message, "Subject:");
    char* body_field = strstr(message, "\n\n");

    if (sender_field!= NULL) {
        sender = &message[strlen(sender_field) + 4];
    }

    if (subject_field!= NULL) {
        subject = &message[strlen(subject_field) + 8];
    }

    if (body_field!= NULL) {
        body = &message[strlen(body_field) + 4];
    }

    strcpy(body, end_of_message + 4);
    return 1;
}

void close_connection(struct email_client* client) {
    close(client->connection_socket);
    free(client);
}

void exit_program() {
    printf("Email Client Program\n");
    printf("=====================\n");
    printf("Press [Enter] to exit\n");
    getchar();
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        exit_program();
    }

    char* hostname = argv[1];
    char* port = argv[2];
    char* username = argv[3];
    char* password = argv[4];

    struct email_client* client = create_client(hostname, port, username, password);
    if (client == NULL) {
        exit_program();
    }

    if (!connect_to_server(client)) {
        close_connection(client);
        exit_program();
    }

    char recipient[BUFFER_SIZE];
    char subject[BUFFER_SIZE];
    char body[BUFFER_SIZE];

    if (!send_email(client, recipient, subject, body)) {
        close_connection(client);
        exit_program();
    }

    if (!receive_email(client, recipient, subject, body)) {
        close_connection(client);
        exit_program();
    }

    close_connection(client);
    exit_program();
}