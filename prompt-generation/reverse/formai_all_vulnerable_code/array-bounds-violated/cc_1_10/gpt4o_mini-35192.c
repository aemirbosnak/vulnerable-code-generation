//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFFER 1024

void log_and_display(const char *message) {
    printf("Holmes: %s\n", message);
}

void handle_openssl_errors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

int establish_connection(const char *hostname, int port) {
    struct sockaddr_in server;
    int sock;
    
    log_and_display("I am observing the connection to our suspect's lair...");
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        log_and_display("Holmes: Alas! The socket could not be created.");
        return -1;
    }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server.sin_addr);
    
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        log_and_display("Holmes: The lair remains elusive; connection attempt failed.");
        close(sock);
        return -1;
    }
    
    log_and_display("We have made contact with our target!");
    return sock;
}

void fetch_mailboxes(int sock, SSL *ssl) {
    char buffer[MAX_BUFFER];
    char command[MAX_BUFFER];

    snprintf(command, sizeof(command), "A001 SELECT INBOX\r\n");
    SSL_write(ssl, command, strlen(command));
    log_and_display("I am sifting through the mail...");
    
    // Read server response
    int bytes = SSL_read(ssl, buffer, sizeof(buffer)-1);
    if (bytes < 0) {
        log_and_display("Holmes: The response eludes me!");
        return;
    }
    buffer[bytes] = '\0';
    
    log_and_display("The contents of the mailbox have been unveiled:");
    printf("%s\n", buffer);
}

void fetch_recent_emails(int sock, SSL *ssl) {
    char buffer[MAX_BUFFER];
    char command[MAX_BUFFER];

    snprintf(command, sizeof(command), "A002 FETCH 1:* (FLAGS SUBJECT)\r\n");
    SSL_write(ssl, command, strlen(command));
    log_and_display("We are now fetching the recent emails...");

    // Read server response
    int bytes = SSL_read(ssl, buffer, sizeof(buffer)-1);
    if (bytes < 0) {
        log_and_display("Holmes: Once again, the response remains shrouded in mystery!");
        return;
    }
    buffer[bytes] = '\0';

    log_and_display("Here are the recent emails for our investigation:");
    printf("%s\n", buffer);
}

void clean_up(SSL *ssl, SSL_CTX *ctx, int sock) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    log_and_display("We have successfully closed our investigation.");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) handle_openssl_errors();
    
    int sock = establish_connection(hostname, port);
    if (sock < 0) return EXIT_FAILURE;

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    
    if (SSL_connect(ssl) <= 0) handle_openssl_errors();
    log_and_display("We are now in the presence of our target with SSL!");

    fetch_mailboxes(sock, ssl);
    fetch_recent_emails(sock, ssl);
    
    clean_up(ssl, ctx, sock);
    return EXIT_SUCCESS;
}