//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

//Function definitions
void error(char *msg);
void IMAP_login(SSL *ssl);
void list_messages(SSL *ssl);
void retrieve_message(SSL *ssl, int msg_num);

int main(int argc, char *argv[])
{
    //Initial setup
    SSL_CTX *ctx;
    SSL *ssl;
    int portno = 993;
    char hostname[] = "imap.gmail.com";
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[256];
    int n;

    //OpenSSL init
    SSL_library_init();
    ctx = SSL_CTX_new(TLSv1_2_client_method());

    //Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

    //Resolve host
    server = gethostbyname(hostname);

    if (server == NULL)
        error("ERROR, no such host");

    //Setup server address
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    //Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    //Start the SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) < 0)
        error("ERROR connecting with SSL");

    printf("Connected to %s on port %d with SSL encryption\n", hostname, portno);

    //Login with credentials
    IMAP_login(ssl);

    //List messages
    list_messages(ssl);

    //Retrieve a specific message
    retrieve_message(ssl, 2);

    //Close SSL and socket
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return 0;
}

//Function to display errors and exit
void error(char *msg)
{
    perror(msg);
    exit(0);
}

//Function to login to the IMAP server
void IMAP_login(SSL *ssl)
{
    char buffer[256];
    int n;

    //Receive welcome message
    n = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (n < 0)
        error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s", buffer);

    //Send login commands
    char user[] = "USER username";
    char pass[] = "PASS password";
    n = SSL_write(ssl, user, strlen(user));
    if (n < 0)
        error("ERROR writing to socket");
    n = SSL_write(ssl, pass, strlen(pass));
    if (n < 0)
        error("ERROR writing to socket");

    //Receive login response
    n = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (n < 0)
        error("ERROR reading from socket");
    buffer[n] = '\0';
    if (strstr(buffer, "OK") == NULL)
        error("ERROR logging in");
    printf("%s", buffer);
}

//Function to list the subject lines of the messages in the inbox
void list_messages(SSL *ssl)
{
    char buffer[256];
    int n;

    //Send command to list messages
    char list[] = "LIST (SUBSCRIBED) \"\" *";
    n = SSL_write(ssl, list, strlen(list));
    if (n < 0)
        error("ERROR writing to socket");

    //Receive list response
    n = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (n < 0)
        error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("\nList of messages:\n%s", buffer);
}

//Function to retrieve a specific message
void retrieve_message(SSL *ssl, int msg_num)
{
    char buffer[256];
    int n;

    //Send command to retrieve message
    char msg_cmd[20];
    sprintf(msg_cmd, "FETCH %d BODY[HEADER.FIELDS (SUBJECT)]", msg_num);
    n = SSL_write(ssl, msg_cmd, strlen(msg_cmd));
    if (n < 0)
        error("ERROR writing to socket");

    //Receive message response
    n = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (n < 0)
        error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("\nRetrieved message:\n%s", buffer);
}