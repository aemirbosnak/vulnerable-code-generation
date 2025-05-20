//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 2048
#define PORT_NUMBER 25

int main(int argc, char *argv[]) {
    int client_socket, result;
    char buffer[MAX_BUFFER_SIZE] = {0};
    struct sockaddr_in server_address;
    struct hostent *server_details;

    // Check if the user provided the correct number of arguments
    if(argc != 2) {
        printf("\nUsage: %s <hostname>\n", argv[0]);
        return -1;
    }

    // Resolve the hostname to an IP address
    server_details = gethostbyname(argv[1]);
    if(server_details == NULL) {
        printf("\nError: Cannot resolve hostname\n");
        return -1;
    }

    // Create the socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0) {
        printf("\nError: Cannot create socket\n");
        return -1;
    }

    // Set the server address details
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)server_details->h_addr_list[0]));
    server_address.sin_port = htons(PORT_NUMBER);

    // Connect to the server
    result = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if(result < 0) {
        printf("\nError: Cannot connect to server\n");
        return -1;
    }

    // Receive the welcome message from the server
    result = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if(result < 0) {
        printf("\nError: Failed to receive message from server\n");
        return -1;
    }
    printf("%s\n", buffer);

    // Send the HELO/EHLO command to the server
    sprintf(buffer, "EHLO %s\r\n", argv[1]);
    result = send(client_socket, buffer, strlen(buffer), 0);
    if(result < 0) {
        printf("\nError: Failed to send message to server\n");
        return -1;
    }

    // Receive the response from the server
    result = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if(result < 0) {
        printf("\nError: Failed to receive message from server\n");
        return -1;
    }
    printf("%s\n", buffer);

    // Send the MAIL FROM command to the server
    sprintf(buffer, "MAIL FROM:<user@example.com>\r\n");
    result = send(client_socket, buffer, strlen(buffer), 0);
    if(result < 0) {
        printf("\nError: Failed to send message to server\n");
        return -1;
    }

    // Receive the response from the server
    result = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if(result < 0) {
        printf("\nError: Failed to receive message from server\n");
        return -1;
    }
    printf("%s\n", buffer);

    // Send the RCPT TO command to the server
    sprintf(buffer, "RCPT TO:<user2@example.com>\r\n");
    result = send(client_socket, buffer, strlen(buffer), 0);
    if(result < 0) {
        printf("\nError: Failed to send message to server\n");
        return -1;
    }

    // Receive the response from the server
    result = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if(result < 0) {
        printf("\nError: Failed to receive message from server\n");
        return -1;
    }
    printf("%s\n", buffer);

    // Send the DATA command to the server
    sprintf(buffer, "DATA\r\n");
    result = send(client_socket, buffer, strlen(buffer), 0);
    if(result < 0) {
        printf("\nError: Failed to send message to server\n");
        return -1;
    }

    // Receive the response from the server
    result = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if(result < 0) {
        printf("\nError: Failed to receive message from server\n");
        return -1;
    }
    printf("%s\n", buffer);

    // Send the message body to the server
    sprintf(buffer, "Subject: Hello World\r\n\r\nThis is a test message\r\n.\r\n");
    result = send(client_socket, buffer, strlen(buffer), 0);
    if(result < 0) {
        printf("\nError: Failed to send message to server\n");
        return -1;
    }

    // Receive the response from the server
    result = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if(result < 0) {
        printf("\nError: Failed to receive message from server\n");
        return -1;
    }
    printf("%s\n", buffer);

    // Send the QUIT command to the server
    sprintf(buffer, "QUIT\r\n");
    result = send(client_socket, buffer, strlen(buffer), 0);
    if(result < 0) {
        printf("\nError: Failed to send message to server\n");
        return -1;
    }

    // Receive the response from the server
    result = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if(result < 0) {
        printf("\nError: Failed to receive message from server\n");
        return -1;
    }
    printf("%s\n", buffer);

    // Close the connection
    close(client_socket);

    return 0;
}