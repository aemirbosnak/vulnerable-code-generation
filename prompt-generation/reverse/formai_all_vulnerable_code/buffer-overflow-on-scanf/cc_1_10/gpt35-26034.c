//FormAI DATASET v1.0 Category: Email Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFFER_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER_SIZE];
    char email[MAX_BUFFER_SIZE];
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    char subject[MAX_BUFFER_SIZE];
    FILE* fp;
    SSL_CTX *ctx;
    SSL *ssl;

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    SSL_library_init();
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx)
        error("ERROR initializing SSL context");

    ssl = SSL_new(ctx);
    if (!ssl)
        error("ERROR creating SSL connection");

    if (SSL_set_fd(ssl, sockfd) == 0)
        error("ERROR setting SSL file descriptor");

    if (SSL_connect(ssl) <= 0)
        error("ERROR connecting SSL");

    printf("Email address: ");
    scanf("%s", email);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    sprintf(buffer, "USER %s\r\n", username);
    SSL_write(ssl, buffer, strlen(buffer));
    bzero(buffer, MAX_BUFFER_SIZE);
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    if(strncmp(buffer, "+OK", 3) != 0)
        error("ERROR: Authentication failed");

    sprintf(buffer, "PASS %s\r\n", password);
    SSL_write(ssl, buffer, strlen(buffer));
    bzero(buffer, MAX_BUFFER_SIZE);
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    if(strncmp(buffer, "+OK", 3) != 0)
        error("ERROR: Authentication failed");

    printf("Subject: ");
    scanf("%s", subject);

    sprintf(buffer, "MAIL FROM: <%s>\r\n", email);
    SSL_write(ssl, buffer, strlen(buffer));
    bzero(buffer, MAX_BUFFER_SIZE);
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    if(strncmp(buffer, "+OK", 3) != 0)
        error("ERROR: Could not send mail");

    sprintf(buffer, "RCPT TO: <%s>\r\n", email);
    SSL_write(ssl, buffer, strlen(buffer));
    bzero(buffer, MAX_BUFFER_SIZE);
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    if(strncmp(buffer, "+OK", 3) != 0)
        error("ERROR: Could not send mail");

    sprintf(buffer, "DATA\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    bzero(buffer, MAX_BUFFER_SIZE);
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    if(strncmp(buffer, "+OK", 3) != 0)
        error("ERROR: Could not send mail");

    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n", email, email, subject);
    SSL_write(ssl, buffer, strlen(buffer));
    bzero(buffer, MAX_BUFFER_SIZE);

    printf("Enter text:\n");
    fp = fdopen(sockfd, "w+");
    while(fgets(buffer, MAX_BUFFER_SIZE, stdin)) {
        if(strcmp(buffer, ".\n") == 0)
            break;
        fprintf(fp, "%s", buffer);
    }
    fclose(fp);

    sprintf(buffer, ".\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    bzero(buffer, MAX_BUFFER_SIZE);
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    if(strncmp(buffer, "+OK", 3) != 0)
        error("ERROR: Could not send mail");

    sprintf(buffer, "QUIT\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    bzero(buffer, MAX_BUFFER_SIZE);
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    if(strncmp(buffer, "+OK", 3) != 0)
        error("ERROR: Could not terminate session");

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}