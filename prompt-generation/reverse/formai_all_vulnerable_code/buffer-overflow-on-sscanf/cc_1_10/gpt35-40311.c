//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    // Check if the arguments are provided
    if(argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Get the host name and the path
    char host_name[256] = "";
    char path[256] = "";

    sscanf(argv[1], "http://%[^/]/%s", host_name, path);

    // Get the IP address of the host
    struct hostent *he;

    if((he = gethostbyname(host_name)) == NULL) {
        perror("gethostbyname() failed");
        exit(EXIT_FAILURE);
    }

    // Create the server address struct
    struct sockaddr_in server_address;

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *((struct in_addr *)he->h_addr);
    server_address.sin_port = htons(80);

    // Connect to the server
    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) != 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send the HTTP request
    char request[BUFFER_SIZE] = "";

    sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host_name);

    int bytes_sent = send(client_socket, request, strlen(request), 0);

    if(bytes_sent == -1) {
        perror("Sending request failed");
        exit(EXIT_FAILURE);
    }

    // Receive the HTTP response
    char response[BUFFER_SIZE] = "";
    int bytes_received = recv(client_socket, response, BUFFER_SIZE-1, 0);

    if(bytes_received == -1) {
        perror("Receiving response failed");
        exit(EXIT_FAILURE);
    }

    // Print the HTTP response
    printf("%s", response);

    // Close the socket
    close(client_socket);

    return 0;
}