//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    int sockfd, portno, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // initialize SSL
    SSL_library_init();
    SSL_CTX *sslctx;
    SSL *cSSL;
    sslctx = SSL_CTX_new(TLSv1_2_client_method());

    // create new SSL connection state
    cSSL = SSL_new(sslctx);
    SSL_set_fd(cSSL, sockfd);

    // perform SSL handshake with the server
    int status = SSL_connect(cSSL);
    if (status != 1) {
        SSL_get_error(cSSL, status);
        SSL_shutdown(cSSL);
        SSL_free(cSSL);
        SSL_CTX_free(sslctx);
        error("ERROR performing SSL handshake");
    }

    // login to the IMAP server
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    printf("Enter username: ");
    fgets(username, BUFFER_SIZE, stdin);
    printf("Enter password: ");
    fgets(password, BUFFER_SIZE, stdin);

    char login_command[BUFFER_SIZE];
    sprintf(login_command, "LOGIN %s %s\r\n", username, password);
    SSL_write(cSSL, login_command, strlen(login_command));

    // receive response from the server
    n = SSL_read(cSSL, buffer, BUFFER_SIZE - 1);
    buffer[n] = '\0';
    printf("%s", buffer);

    while (1) {
        // prompt the user for a command
        printf("> ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // send the command to the server
        SSL_write(cSSL, buffer, strlen(buffer));

        // receive response from the server
        n = SSL_read(cSSL, buffer, BUFFER_SIZE - 1);
        buffer[n] = '\0';
        printf("%s", buffer);

        // check if the user entered the "logout" command
        if (strncmp(buffer, "logout", 6) == 0) {
            // logout from IMAP server and close SSL connection
            SSL_write(cSSL, "LOGOUT\r\n", strlen("LOGOUT\r\n"));
            SSL_shutdown(cSSL);
            SSL_free(cSSL);
            SSL_CTX_free(sslctx);
            close(sockfd);
            break;
        }
    }

    return 0;
}