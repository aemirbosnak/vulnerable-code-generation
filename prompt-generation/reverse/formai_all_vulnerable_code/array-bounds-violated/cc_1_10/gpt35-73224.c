//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_COMMAND_SIZE 1024
#define MAX_USERNAME_SIZE 128
#define MAX_PASSWORD_SIZE 128
#define MAX_SERVER_ADDRESS_SIZE 128
#define MAX_MAILBOX_NAME_SIZE 128

int setup_socket(const char* server_address, const char* port);
SSL* setup_ssl(int socket_descriptor);
void send_receive(SSL* ssl, const char* command);
void login(SSL* ssl, const char* username, const char* password);
void select_mailbox(SSL* ssl, const char* mailbox_name);
void list_mailboxes(SSL* ssl);
void fetch_email(SSL* ssl, int email_number);
void display_error();

int main(int argc, char* argv[]) {
    char command[MAX_COMMAND_SIZE], username[MAX_USERNAME_SIZE], password[MAX_PASSWORD_SIZE], server_address[MAX_SERVER_ADDRESS_SIZE], mailbox_name[MAX_MAILBOX_NAME_SIZE];
    int email_number, socket, select_value;
    SSL* ssl;
    fd_set read_fds;
    printf("IMAP Client - Post-Apocalyptic Edition\n");
    printf("Enter your email address: ");
    fgets(username, MAX_USERNAME_SIZE, stdin);
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_SIZE, stdin);
    printf("Enter your server address: ");
    fgets(server_address, MAX_SERVER_ADDRESS_SIZE, stdin);
    printf("Connecting to server...\n");
    if ((socket = setup_socket(server_address, "993")) == -1) {
        display_error();
        exit(EXIT_FAILURE);
    }
    printf("Connected to server!\n");
    ssl = setup_ssl(socket);
    login(ssl, username, password);
    printf("Login successful.\n");
    list_mailboxes(ssl);
    printf("Enter the mailbox name: ");
    fgets(mailbox_name, MAX_MAILBOX_NAME_SIZE, stdin);
    select_mailbox(ssl, mailbox_name);
    printf("Enter the number of the email you want to fetch: ");
    scanf("%d", &email_number);
    while(1) {
        FD_ZERO(&read_fds);
        FD_SET(0, &read_fds);
        select_value = select(1, &read_fds, NULL, NULL, NULL);
        if(select_value == -1) {
            display_error();
            break;
        }
        if(FD_ISSET(0,&read_fds)) {
            fgets(command, MAX_COMMAND_SIZE, stdin);
            command[strcspn(command, "\r\n")] = '\0';
            if(strcmp(command, "exit") == 0)
                break;
            if(strcmp(command, "help") == 0) {
                printf("Available commands:\n");
                printf("- exit: Close the client.\n");
                printf("- fetch <email_number>: Fetches and displays the given email.\n");
                printf("- help: Display the list of available commands.\n");
                continue;
            }
            if(strncmp(command, "fetch", 5) == 0) {
                sscanf(command + 6, "%d", &email_number);
                fetch_email(ssl, email_number);
            } else {
                send_receive(ssl, command);
            }
        }
    }
    SSL_shutdown(ssl);
    close(socket);
    SSL_free(ssl);
    return 0;
}

int setup_socket(const char* server_address, const char* port) {
    struct addrinfo hints, *address;
    int socket_descriptor;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(server_address, port, &hints, &address) != 0) {
        return -1;
    }
    socket_descriptor = socket(address->ai_family, address->ai_socktype, address->ai_protocol);
    if (socket_descriptor == -1) {
        return -1;
    }
    if (connect(socket_descriptor, address->ai_addr, address->ai_addrlen) == -1) {
        return -1;
    }
    freeaddrinfo(address);
    return socket_descriptor;
}

SSL* setup_ssl(int socket_descriptor) {
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();
    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());
    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, socket_descriptor);
    if (SSL_connect(ssl) != 1) {
        display_error();
        exit(EXIT_FAILURE);
    }
    return ssl;
}

void send_receive(SSL* ssl, const char* command) {
    char buffer[MAX_BUFFER_SIZE];
    int receive_result;
    SSL_write(ssl, command, strlen(command));
    while ((receive_result = SSL_read(ssl, buffer, MAX_BUFFER_SIZE - 1)) > 0) {
        buffer[receive_result] = '\0';
        printf("%s", buffer);
        if (receive_result < MAX_BUFFER_SIZE - 1)
            break;
    }
    printf("\n");
}

void login(SSL* ssl, const char* username, const char* password) {
    char command[MAX_COMMAND_SIZE];
    sprintf(command, "a001 LOGIN %s %s\r\n", username, password);
    send_receive(ssl, command);
}

void select_mailbox(SSL* ssl, const char* mailbox_name) {
    char command[MAX_COMMAND_SIZE];
    sprintf(command, "a001 SELECT \"%s\"\r\n", mailbox_name);
    send_receive(ssl, command);
}

void list_mailboxes(SSL* ssl) {
    char command[MAX_COMMAND_SIZE];
    sprintf(command, "a001 LIST \"\" \"*\"\r\n");
    send_receive(ssl, command);
}

void fetch_email(SSL* ssl, int email_number) {
    char command[MAX_COMMAND_SIZE];
    sprintf(command, "a001 FETCH %d BODY[TEXT]\r\n", email_number);
    send_receive(ssl, command);
}

void display_error() {
    char error_message[MAX_BUFFER_SIZE];
    ERR_error_string_n(ERR_get_error(), error_message, MAX_BUFFER_SIZE);
    printf("%s\n", error_message);
}