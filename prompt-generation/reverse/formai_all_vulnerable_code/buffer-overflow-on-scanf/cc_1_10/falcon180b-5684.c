//Falcon-180B DATASET v1.0 Category: Networking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

//struct to hold the server's address
struct sockaddr_in server_addr;

//function to print error message and exit
void error(char *message) {
    perror(message);
    exit(1);
}

//function to send data to the server
int send_data(int sock, char *data) {
    int bytes_sent = send(sock, data, strlen(data), 0);
    if (bytes_sent == -1) {
        error("Send failed");
    }
    return bytes_sent;
}

//function to receive data from the server
int receive_data(int sock, char *buffer) {
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        error("Receive failed");
    }
    buffer[bytes_received] = '\0';
    return bytes_received;
}

//main function
int main() {
    int sock;
    char hostname[100];
    char port[10];
    char send_buffer[BUFFER_SIZE];
    char receive_buffer[BUFFER_SIZE];

    //get server address from user
    printf("Enter server address: ");
    scanf("%s:%s", hostname, port);

    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("Socket creation failed");
    }

    //set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid hostname");
    }

    //connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("Connection failed");
    }

    //send data to server
    strcpy(send_buffer, "Hello, server!");
    send_data(sock, send_buffer);

    //receive data from server
    receive_data(sock, receive_buffer);
    printf("Received from server: %s\n", receive_buffer);

    //close socket
    close(sock);

    return 0;
}