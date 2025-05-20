//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_HTTP_SIZE 2048

int main(int argc, char *argv[]){
    char host[255], page[255];
    char request[MAX_HTTP_SIZE], response[MAX_HTTP_SIZE];
    struct hostent *server;
    struct sockaddr_in server_address;
    int sockfd, port_number, bytes_sent, bytes_received;

    printf("Enter the hostname (without http://): ");
    scanf("%s", host);
    printf("Enter the page to request (e.g. /index.html): ");
    scanf("%s", page);
    printf("Enter the port number: ");
    scanf("%d", &port_number);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("socket");
        exit(1);
    }

    // Get host by name
    server = gethostbyname(host);
    if(server == NULL){
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    // Set up server address
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, 
          (char *) &server_address.sin_addr.s_addr,
          server->h_length);
    server_address.sin_port = htons(port_number);

    // Connect to server
    if(connect(sockfd,
               (struct sockaddr *) &server_address,
               sizeof(server_address)) < 0){
        perror("connect");
        exit(1);
    }

    // Construct HTTP request
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", page, host);

    // Send HTTP request
    bytes_sent = send(sockfd, request, strlen(request), 0);
    if(bytes_sent < 0){
        perror("send");
        exit(1);
    }

    // Receive HTTP response
    bytes_received = recv(sockfd, response, MAX_HTTP_SIZE - 1, 0);
    if(bytes_received < 0){
        perror("recv");
        exit(1);
    }
    response[bytes_received] = '\0';

    // Print HTTP response
    printf("%s\n", response);

    // Close socket
    close(sockfd);
    return 0;
}