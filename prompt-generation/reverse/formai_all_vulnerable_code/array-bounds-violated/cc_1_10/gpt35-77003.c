//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT    80
#define BUFFER_SIZE 1024

int create_socket(char *url);
char *get_ip_address(char *url);
void send_http_request(int socket, char *url);
void receive_http_response(int socket, char *url);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = create_socket(argv[1]);
    send_http_request(sockfd, argv[1]);
    receive_http_response(sockfd, argv[1]);

    return 0;
}

int create_socket(char *url) {
    int sockfd;
    struct sockaddr_in servaddr;
    char *ip_address;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    ip_address = get_ip_address(url);
    if (inet_pton(AF_INET, ip_address, &servaddr.sin_addr) <= 0) {
        perror("Unable to set IP address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Unable to connect");
        exit(EXIT_FAILURE);
    }

    free(ip_address);

    return sockfd;
}

char *get_ip_address(char *url) {
    struct hostent *host_entry;
    struct in_addr **address_list;
    char *ip_address;

    if ((host_entry = gethostbyname(url)) == NULL) {
        perror("Unable to get IP address");
        exit(EXIT_FAILURE);
    }

    address_list = (struct in_addr **) host_entry->h_addr_list;

    ip_address = malloc(INET_ADDRSTRLEN);
    if (inet_ntop(host_entry->h_addrtype, *address_list, ip_address, INET_ADDRSTRLEN) == NULL) {
        perror("Unable to convert IP address");
        exit(EXIT_FAILURE);
    }

    return ip_address;
}

void send_http_request(int sockfd, char *url) {
    char request[BUFFER_SIZE];

    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.96 Safari/537.36\r\nConnection: close\r\n\r\n", url);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("Unable to send HTTP request");
        exit(EXIT_FAILURE);
    }
}

void receive_http_response(int sockfd, char *url) {
    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    if (bytes_received == -1) {
        perror("Unable to receive HTTP response");
        exit(EXIT_FAILURE);
    }

    printf("\n");
}