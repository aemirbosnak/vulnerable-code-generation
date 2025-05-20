//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    // Arguments check
    if(argc < 4) {
        fprintf(stderr, "Usage: %s [server_host] [port] [username]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // SSL Setup
    SSL_library_init();
    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());

    SSL* ssl;
    int sd;

    // DNS Resolving
    char* server_host = argv[1];
    int port = atoi(argv[2]);
    struct hostent* server;
    struct in_addr addr;

    if(inet_aton(server_host, &addr)) {
        server = gethostbyaddr((char *)&addr, 4, AF_INET);
    } else {
        server = gethostbyname(server_host);
    }

    if(server == NULL) {
        fprintf(stderr, "ERROR: DNS Resolving failed.\n");
        exit(EXIT_FAILURE);
    }

    // Socket Connection
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd < 0) {
        fprintf(stderr, "ERROR: Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    int connect_status = connect(sd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if(connect_status < 0) {
        fprintf(stderr, "ERROR: Connection failed.\n");
        exit(EXIT_FAILURE);
    }

    // SSL Connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sd);
    SSL_connect(ssl);

    char response[MAX_BUFFER + 1];
    int rx_size;

    // Login
    char* username = argv[3];
    char* login_command_template = "1 LOGIN %s \"%s\"\n";
    char login_command[MAX_BUFFER + 1] = {'\0'};
    sprintf(login_command, login_command_template, username, "");
    SSL_write(ssl, login_command, strlen(login_command));
    rx_size = SSL_read(ssl, response, MAX_BUFFER);
    response[rx_size] = '\0';

    // Inbox Selection
    char* inbox_command = "2 SELECT INBOX\n";
    SSL_write(ssl, inbox_command, strlen(inbox_command));
    rx_size = SSL_read(ssl, response, MAX_BUFFER);
    response[rx_size] = '\0';

    // Message Search
    char* search_command = "3 SEARCH UNSEEN\n";
    SSL_write(ssl, search_command, strlen(search_command));
    rx_size = SSL_read(ssl, response, MAX_BUFFER);
    response[rx_size] = '\0';

    // Message Fetch
    char fetch_command[MAX_BUFFER + 1] = {'\0'};
    char message_id[MAX_BUFFER + 1] = {'\0'};
    sscanf(response, "* SEARCH %s", message_id);
    sprintf(fetch_command, "4 FETCH %s BODY[]\n", message_id);
    SSL_write(ssl, fetch_command, strlen(fetch_command));
    rx_size = SSL_read(ssl, response, MAX_BUFFER);
    response[rx_size] = '\0';

    // Message Print
    printf("%s", response);

    // SSL Termination
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    // Close Connection
    close(sd);

    return 0;
}