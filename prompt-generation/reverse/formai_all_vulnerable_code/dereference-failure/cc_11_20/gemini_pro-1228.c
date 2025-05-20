//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 465
#define HOST "smtp.example.com"

int main(int argc, char *argv[]) {
    int sockfd, rc;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    SSL_CTX *ctx;
    SSL *ssl;

    // Initialize the SSL library
    SSL_library_init();
    ERR_load_BIO_strings();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Error creating SSL context\n");
        return 1;
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    // Get the server IP address
    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr, "Error getting server IP address\n");
        return 1;
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr *)server->h_addr)));
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    rc = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (rc < 0) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    // Create the SSL connection
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        fprintf(stderr, "Error creating SSL connection\n");
        return 1;
    }
    SSL_set_fd(ssl, sockfd);
    rc = SSL_connect(ssl);
    if (rc < 0) {
        fprintf(stderr, "Error connecting to server using SSL\n");
        return 1;
    }

    // Send the SMTP commands
    rc = SSL_write(ssl, "HELO localhost\r\n", strlen("HELO localhost\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending HELO command\n");
        return 1;
    }

    rc = SSL_write(ssl, "MAIL FROM: <me@example.com>\r\n", strlen("MAIL FROM: <me@example.com>\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending MAIL FROM command\n");
        return 1;
    }

    rc = SSL_write(ssl, "RCPT TO: <you@example.com>\r\n", strlen("RCPT TO: <you@example.com>\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending RCPT TO command\n");
        return 1;
    }

    rc = SSL_write(ssl, "DATA\r\n", strlen("DATA\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending DATA command\n");
        return 1;
    }

    // Send the email message
    rc = SSL_write(ssl, "Subject: Test email\r\n", strlen("Subject: Test email\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending email subject\n");
        return 1;
    }

    rc = SSL_write(ssl, "From: me@example.com\r\n", strlen("From: me@example.com\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending email from address\n");
        return 1;
    }

    rc = SSL_write(ssl, "To: you@example.com\r\n", strlen("To: you@example.com\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending email to address\n");
        return 1;
    }

    rc = SSL_write(ssl, "\r\n", strlen("\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending email body\n");
        return 1;
    }

    rc = SSL_write(ssl, "This is a test email.\r\n", strlen("This is a test email.\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending email body\n");
        return 1;
    }

    rc = SSL_write(ssl, ".\r\n", strlen(".\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending email end marker\n");
        return 1;
    }

    // Quit the SMTP session
    rc = SSL_write(ssl, "QUIT\r\n", strlen("QUIT\r\n"));
    if (rc < 0) {
        fprintf(stderr, "Error sending QUIT command\n");
        return 1;
    }

    // Clean up
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}