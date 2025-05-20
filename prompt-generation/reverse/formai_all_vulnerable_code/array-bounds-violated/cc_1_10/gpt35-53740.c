//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: genious
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT "993" // IMAP TCP port
#define MAX_BUFFER_LEN 1024
#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50
#define MAX_COMMAND_LEN 200

int main(int argc, char *argv[]) {
    int sock_fd, num_bytes;
    char buffer[MAX_BUFFER_LEN];
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char command[MAX_COMMAND_LEN];
    struct addrinfo hints, *result;
    SSL_CTX *ctx;
    SSL *ssl;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    // setup SSL context
    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Error creating SSL context\n");
        return 1;
    }

    // resolve hostname
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(argv[1], PORT, &hints, &result) != 0) {
        fprintf(stderr, "Error resolving hostname\n");
        return 1;
    }

    // create socket
    sock_fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock_fd < 0) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    // connect to server
    if (connect(sock_fd, result->ai_addr, result->ai_addrlen) != 0) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    // setup SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock_fd);
    if (SSL_connect(ssl) < 0) {
        fprintf(stderr, "Error establishing SSL connection\n");
        return 1;
    }

    // prompt for username
    printf("Enter username: ");
    fflush(stdout);
    fgets(username, MAX_USERNAME_LEN, stdin);
    username[strcspn(username, "\r\n")] = 0;

    // send login command
    sprintf(command, "LOGIN %s {1}\r\n", username);
    SSL_write(ssl, command, strlen(command));

    // receive OK response
    num_bytes = SSL_read(ssl, buffer, MAX_BUFFER_LEN);
    buffer[num_bytes] = '\0';
    if (strstr(buffer, "OK") != NULL) {
        printf("Login successful!\n");

        // prompt for password
        printf("Enter password: ");
        fflush(stdout);
        fgets(password, MAX_PASSWORD_LEN, stdin);
        password[strcspn(password, "\r\n")] = 0;

        // send password command
        sprintf(command, "%s {1}\r\n", password);
        SSL_write(ssl, command, strlen(command));

        // receive OK response
        num_bytes = SSL_read(ssl, buffer, MAX_BUFFER_LEN);
        buffer[num_bytes] = '\0';
        if (strstr(buffer, "OK") != NULL) {
            printf("Password accepted!\n");

            // send select command
            sprintf(command, "SELECT INBOX\r\n");
            SSL_write(ssl, command, strlen(command));

            // receive select response
            num_bytes = SSL_read(ssl, buffer, MAX_BUFFER_LEN);
            buffer[num_bytes] = '\0';
            if (strstr(buffer, "OK") != NULL) {
                printf("Selected mailbox INBOX\n");

                // send list command
                sprintf(command, "LIST \"\" *\r\n");
                SSL_write(ssl, command, strlen(command));

                // receive list response
                num_bytes = SSL_read(ssl, buffer, MAX_BUFFER_LEN);
                buffer[num_bytes] = '\0';
                printf("%s", buffer);
            }
            else {
                printf("Error selecting mailbox\n");
            }
        }
        else {
            printf("Invalid password\n");
        }
    }
    else {
        printf("Invalid username\n");
    }

    // close SSL connection and free resources
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    freeaddrinfo(result);
    close(sock_fd);

    return 0;
}