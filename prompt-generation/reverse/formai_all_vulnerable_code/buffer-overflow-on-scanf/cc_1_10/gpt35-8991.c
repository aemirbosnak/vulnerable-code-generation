//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>
#include<openssl/ssl.h>
#include<openssl/err.h>

//Function to print the error
void print_error(const char *error_msg) {
    fprintf(stderr, "%s\n", error_msg);
    exit(EXIT_FAILURE);
}

//Function to connect to the server
int connect_server(const char *server, const char *port) {
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if(getaddrinfo(server,port,&hints,&res) != 0) {
        print_error("getaddrinfo failed");
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(sockfd == -1) {
        print_error("socket failed");
    }

    if(connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        print_error("connect failed");
    }

    freeaddrinfo(res);

    return sockfd;
}

int main(int argc, char **argv) {
    char username[50];
    char password[50];
    char server[100];
    char port[10];
    char command[1024];
    char buf[4096];
    char *ptr, *end;
    int sockfd, numbytes;
    SSL_CTX *ctx;
    SSL *ssl;

    printf("Enter server address: ");
    scanf("%s", server);

    printf("Enter port: ");
    scanf("%s", port);

    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    sockfd = connect_server(server, port);

    //Initialize SSL library
    SSL_library_init();
    SSL_load_error_strings();

    //Create SSL context
    ctx = SSL_CTX_new(TLS_client_method());

    //Create SSL connection object and attach socket to it
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    //Connect to SSL server
    if(SSL_connect(ssl) == -1) {
        print_error("SSL connect failed");
    }

    //Send login command
    sprintf(command, "LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, command, strlen(command));
    
    //Read response from server and print it
    numbytes = SSL_read(ssl, buf, 4096);
    buf[numbytes] = '\0';
    printf("%s", buf);

    //Check if login was successful
    if(buf[0] == '+') {
        printf("Login successful\n");
        
        //Send select command
        sprintf(command, "SELECT Inbox\r\n");
        SSL_write(ssl, command, strlen(command));
        
        //Read response from server and print it
        numbytes = SSL_read(ssl, buf, 4096);
        buf[numbytes] = '\0';
        printf("%s", buf);

        //Send fetch command
        sprintf(command, "FETCH 1 BODY[HEADER.FIELDS (FROM SUBJECT DATE)]\r\n");
        SSL_write(ssl, command, strlen(command));
        
        //Read response from server and print it
        numbytes = SSL_read(ssl, buf, 4096);
        buf[numbytes] = '\0';
        printf("%s", buf);

        //Find the end of the header
        ptr = strstr(buf, "\r\n\r\n");
        if(ptr == NULL) {
            print_error("Error finding end of header");
        }

        //Parse the header
        printf("From: ");
        end = strchr(buf, '<');
        if(end == NULL) {
            end = strchr(buf, ':');
        }
        else {
            end--;
        }
        *end = '\0';
        printf("%s\n", buf+6); //Skip "From: "

        printf("Subject: ");
        ptr = strstr(buf, "Subject:");
        if(ptr == NULL) {
            print_error("Error finding Subject field");
        }
        ptr += strlen("Subject:");
        while(*ptr == ' ' || *ptr == '\t') {
            ptr++;
        }
        printf("%s", ptr);

        ptr = strstr(buf, "Date:");
        if(ptr == NULL) {
            print_error("Error finding Date field");
        }
        ptr += strlen("Date:");
        while(*ptr == ' ' || *ptr == '\t') {
            ptr++;
        }
        printf("Date: %s\n", ptr);
        
    }
    else {
        printf("Login failed\n");
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}