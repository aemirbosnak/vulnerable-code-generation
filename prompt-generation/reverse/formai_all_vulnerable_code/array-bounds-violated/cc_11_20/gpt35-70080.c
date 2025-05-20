//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<openssl/ssl.h>
#include<openssl/err.h>

#define BUF_SIZE 1024
#define HOSTNAME "imap.gmail.com"
#define PORT "993"

int main(int argc, char **argv) {

    int sock, recv_len, ret, num_msgs, msg_cnt = 1;
    char buf[BUF_SIZE];
    char user[BUF_SIZE], pass[BUF_SIZE];
    SSL_CTX *ctx;
    SSL *ssl;

    // Open SSL library init
    SSL_library_init();
    // Load all error messages
    SSL_load_error_strings();

    // Initialize OpenSSL context and create TLS client.
    if((ctx = SSL_CTX_new(TLS_client_method())) == NULL) {
        printf("\nOpenSSL context creation failed.\n");
        return -1;
    }

    // Create a socket
    if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        printf("\nSocket creation failed.\n");
        return -1;
    }

    // Resolve server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));

    if(inet_pton(AF_INET, HOSTNAME, &server_addr.sin_addr) == -1) {
        printf("\nAddress resolution failed.\n");
        return -1;
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        printf("\nServer connection failed.\n");
        return -1;
    }

    // Create SSL object
    if((ssl = SSL_new(ctx)) == NULL) {
        printf("\nSSL creation failed.\n");
        return -1;
    }

    SSL_set_fd(ssl, sock);

    // Establish TLS connection with server
    if(SSL_connect(ssl) != 1) {
        printf("\nTLS connection establishment failed.\n");
        return -1;
    }

    printf("\nTLS connection established.\n");

    // Read message from server
    if((recv_len = SSL_read(ssl, buf, sizeof(buf) - 1)) == -1) {
        printf("\nMessage read failed.\n");
        return -1;
    }
    buf[recv_len] = '\0';
    printf("%s", buf);

    // Send login credentials to server.
    printf("Enter user name:\n");
    scanf("%s", user);

    printf("Enter password:\n");
    scanf("%s", pass);

    sprintf(buf, "a001 LOGIN %s %s\n", user, pass);
    ret = SSL_write(ssl, buf, strlen(buf));
    if(ret == -1) {
        printf("Login credentials transmission failed.\n", strerror(errno));
        return -1;
    }
    while(msg_cnt++ <= num_msgs) {
        sprintf(buf, "a%03d FETCH %d FLAGS\n", msg_cnt, msg_cnt);
        ret = SSL_write(ssl, buf, strlen(buf));
        if(ret == -1) {
            printf("Message transmission failed: %s\n", strerror(errno));
            return -1;
        }       
        if((recv_len = SSL_read(ssl, buf, sizeof(buf) - 1)) == -1) {
            printf("\nMessage read failed.\n");
            return -1;
        }
        buf[recv_len] = '\0';
        printf("%s", buf);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);

    return 0;
}