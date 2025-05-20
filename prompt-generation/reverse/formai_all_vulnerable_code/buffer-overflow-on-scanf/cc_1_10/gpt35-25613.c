//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_REQUEST_LEN 1024
#define MAX_RESPONSE_LEN 4096
#define PORT 80

void print_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void sanitize_input(char *input) {
    int input_len = strlen(input);
    for(int i = 0; i < input_len; i++){
        if(!isalnum(input[i]) && input[i] != '.' && input[i] != '-') {
            printf("Invalid character found.\n");
            printf("Input can only contain alphanumeric letters, periods, and hyphens.\n");
            exit(EXIT_FAILURE);         
        }
    }
}

int create_socket(const struct sockaddr_in *server_address) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        print_error("Error creating socket");
    }

    int connect_status = connect(sockfd, (struct sockaddr *) server_address, sizeof(*server_address));
    if(connect_status < 0) {
        print_error("Error connecting to server");
    }

    return sockfd;
}

void prepare_request(char *request, const char *hostname, const char *path) {
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
}

void receive_response(int sockfd, char *response) {
    int num_bytes_received = recv(sockfd, response, MAX_RESPONSE_LEN - 1, 0);

    if(num_bytes_received < 0) {
        print_error("Error receiving response from server");
    }

    response[num_bytes_received] = '\0';
}

int main() {
    struct sockaddr_in server_address;
    char hostname[MAX_HOSTNAME_LEN];
    char request[MAX_REQUEST_LEN];
    char response[MAX_RESPONSE_LEN];

    printf("Please enter the hostname: ");
    scanf("%s", hostname);
    sanitize_input(hostname);

    printf("Please enter the path: ");
    scanf("%s", request);
    sanitize_input(request);

    memset(&server_address, 0, sizeof(server_address));

    struct hostent *server = gethostbyname(hostname);
    if(server == NULL) {
        printf("Error: No such host exists.\n");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    memcpy(&server_address.sin_addr, server->h_addr_list[0], server->h_length);

    int sockfd = create_socket(&server_address);

    prepare_request(request, hostname, request);

    int num_bytes_sent = send(sockfd, request, strlen(request), 0);
    if(num_bytes_sent < 0) {
        print_error("Error sending request to server");
    }

    receive_response(sockfd, response);

    printf("%s", response);

    close(sockfd);
    return 0;
}