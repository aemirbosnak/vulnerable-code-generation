//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SSL_PORT 990
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 3 || argc > 4) {
        printf("Usage: %s <ftp server> <ftp port> [username:password]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *ftp_server = argv[1];
    int ftp_port = atoi(argv[2]);
    char *auth = argc == 4 ? argv[3] : "";
    char request[BUFFER_SIZE], response[BUFFER_SIZE];

    SSL_library_init();
    SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv23_client_method());
    SSL *ssl = SSL_new(ssl_ctx);

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(ftp_port);

    if(inet_pton(AF_INET, ftp_server, &serv_addr.sin_addr) <= 0) {
        printf("Invalid address of the FTP server.\n");
        exit(EXIT_FAILURE);
    }

    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Failed to create socket.\n");
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Failed to connect to FTP server.\n");
        exit(EXIT_FAILURE);
    }

    SSL_set_fd(ssl, sockfd);
    SSL_connect(ssl);

    SSL_write(ssl, "USER anonymous\r\n", strlen("USER anonymous\r\n"));
    SSL_read(ssl, response, BUFFER_SIZE);
    printf("%s", response);

    SSL_write(ssl, "PASS anonymous@\r\n", strlen("USER anonymous@\r\n"));
    SSL_read(ssl, response, BUFFER_SIZE);
    printf("%s", response);

    strcat(request, "PWD\r\n");
    SSL_write(ssl, request, strlen(request));
    memset(&response, 0, BUFFER_SIZE);
    SSL_read(ssl, response, BUFFER_SIZE);
    printf("%s\n", response);

    SSL_write(ssl, "PASV\r\n", strlen("PASV\r\n"));
    SSL_read(ssl, response, BUFFER_SIZE);
    printf("%s", response);
    int port = atoi(strrchr(response, ',') + 1);
    char *pasv_ip = strtok(response + 3, ",");
    for(int i = 0; i < 2; i++) {
        pasv_ip = strtok(NULL, ",");
    }
    for(int i = 3; i < 5; i++) {
        char *token = strtok(NULL, ",");
        port = (port << 8) + atoi(token);
    }

    printf("FTP PASV IP:PORT: %s:%d\n", pasv_ip, port);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, pasv_ip, &serv_addr.sin_addr) <= 0) {
        printf("Invalid address of the FTP data server.\n");
        exit(EXIT_FAILURE);
    }

    int pasv_sockfd;
    if((pasv_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Failed to create socket.\n");
        exit(EXIT_FAILURE);
    }

    if(connect(pasv_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Failed to connect to FTP data server.\n");
        exit(EXIT_FAILURE);
    }

    SSL *pasv_ssl = SSL_new(ssl_ctx);
    SSL_set_fd(pasv_ssl, pasv_sockfd);
    SSL_connect(pasv_ssl);

    strcat(request, "TYPE I\r\n");
    SSL_write(ssl, request, strlen(request));
    SSL_read(ssl, response, BUFFER_SIZE);
    printf("%s", response);

    strcat(request, "LIST\r\n");
    SSL_write(ssl, request, strlen(request));
    memset(&response, 0, BUFFER_SIZE);
    SSL_read(ssl, response, BUFFER_SIZE);
    printf("%s", response);

    printf("FTP directory contents:\n");
    char buffer[BUFFER_SIZE];
    int num_bytes;
    while((num_bytes = SSL_read(pasv_ssl, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, num_bytes, stdout);
    }

    memset(&request, 0, BUFFER_SIZE);
    strcat(request, "QUIT\r\n");
    SSL_write(ssl, request, strlen(request));

    SSL_shutdown(pasv_ssl);
    SSL_free(pasv_ssl);
    close(pasv_sockfd);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);

    SSL_CTX_free(ssl_ctx);

    return 0;
}