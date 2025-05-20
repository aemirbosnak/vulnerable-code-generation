//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sock_fd;
    struct sockaddr_in server_address;
    char send_buffer[MAX_BUFFER_SIZE] = {0};
    char receive_buffer[MAX_BUFFER_SIZE] = {0};

    //create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        return EXIT_FAILURE;
    }

    //set server address information
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    //convert ipv4 and ipv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return EXIT_FAILURE;
    }

    //connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        return EXIT_FAILURE;
    }

    //read/send messages to/from server
    while(1) {

        printf("Enter message: ");
        fgets(send_buffer, MAX_BUFFER_SIZE, stdin);

        //trim newline character at end of message
        send_buffer[strcspn(send_buffer, "\n")] = 0;

        //send message to server
        send(sock_fd, send_buffer, strlen(send_buffer), 0);

        //receive message from server
        ssize_t bytes_received = recv(sock_fd, receive_buffer, MAX_BUFFER_SIZE, 0);

        //if server has disconnected, end loop
        if (bytes_received == 0) {
            printf("Server disconnected\n");
            break;
        }

        receive_buffer[bytes_received] = '\0';
        printf("Received from server: %s\n", receive_buffer);
    }

    close(sock_fd);
    return EXIT_SUCCESS;
}