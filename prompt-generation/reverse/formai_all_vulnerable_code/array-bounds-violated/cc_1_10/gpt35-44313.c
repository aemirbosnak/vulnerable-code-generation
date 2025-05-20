//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define HOSTNAME "imap.gmail.com"
#define PORT "993"

/* Function to set up a socket connection */
int setup_socket(const char *hostname, const char *port) {
    struct addrinfo hints, *result, *rp;
    int sfd, s;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET6;     /* Allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM; /* Stream socket */
    hints.ai_flags = 0;
    hints.ai_protocol = 0;           /* Any protocol */

    s = getaddrinfo(hostname, port, &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        return -1;
    }

    /* getaddrinfo() returns a list of address structures.
     * Try each address until we successfully connect(2).
     * If socket(2) (or connect(2)) fails, we (close the socket
     * and) try the next address. */
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sfd == -1)
            continue;

        if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
            break; /* Success */

        close(sfd);
    }

    if (rp == NULL) { /* No address succeeded */
        fprintf(stderr, "Could not connect\n");
        return -1;
    }

    freeaddrinfo(result); /* Free the memory allocated by getaddrinfo() */
    return sfd;
}

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    struct timeval timeout;
    fd_set readfds;
    int sockfd, i, err, bytes;
    char buf[1024];
    char username[100];
    char password[100];
    char command[100];

    /* Init SSL */
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    /* Set up socket connection */
    sockfd = setup_socket(HOSTNAME, PORT);

    /* Set timeout for socket connection */
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    /* Init SSL context */
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    /* Init SSL connection */
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) == -1)
        ERR_print_errors_fp(stderr);

    /* Prompt user for IMAP username and password */
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    /* Log in to IMAP server */
    sprintf(command, "LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, command, strlen(command));
    bytes = SSL_read(ssl, buf, sizeof(buf)-1);
    buf[bytes] = '\0';
    printf("%s\n", buf);

    /* Send LIST command to retrieve list of mailboxes */
    SSL_write(ssl, "LIST \"\" *\r\n", strlen("LIST \"\" *\r\n"));
    bytes = SSL_read(ssl, buf, sizeof(buf)-1);
    buf[bytes] = '\0';
    printf("%s\n", buf);

    /* Close SSL connection */
    SSL_shutdown(ssl);
    SSL_free(ssl); 

    /* Clean up */
    close(sockfd);
    SSL_CTX_free(ctx);

    return 0;
}