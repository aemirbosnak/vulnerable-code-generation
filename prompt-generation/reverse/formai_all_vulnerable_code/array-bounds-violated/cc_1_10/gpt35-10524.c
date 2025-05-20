//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 4096
#define MAX_RESP 1024
#define MAX_USER_LEN 256
#define MAX_PASS_LEN 256

void print_error(char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

void print_response(int sock_fd) {
    char resp[MAX_RESP];
    int resp_len;
    while ((resp_len = recv(sock_fd, resp, MAX_RESP, 0)) > 0) {
        fwrite(resp, sizeof(char), resp_len, stdout);
        if (resp[resp_len-1] == '\n') {
            break;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    char* hostname = argv[1];
    char* username = argv[2];
    char* password = argv[3];
    
    // create socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        print_error("Could not create socket");
    }

    // get IP address
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        print_error("Could not resolve host");
    }

    // build server address struct
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110); // POP3 port
    serv_addr.sin_addr = *((struct in_addr*)host->h_addr);

    // connect to server
    if (connect(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        print_error("Could not connect to server");
    }

    // receive greeting message
    print_response(sock_fd);

    // send username
    char user[MAX_USER_LEN];
    sprintf(user, "USER %s\r\n", username);
    send(sock_fd, user, strlen(user), 0);

    // receive response to username
    print_response(sock_fd);

    // send password
    char pass[MAX_PASS_LEN];
    sprintf(pass, "PASS %s\r\n", password);
    send(sock_fd, pass, strlen(pass), 0);

    // receive response to password
    print_response(sock_fd);

    // send QUIT command
    char quit[] = "QUIT\r\n";
    send(sock_fd, quit, strlen(quit), 0);

    // receive farewell message
    print_response(sock_fd);

    // close socket
    close(sock_fd);

    return 0;
}