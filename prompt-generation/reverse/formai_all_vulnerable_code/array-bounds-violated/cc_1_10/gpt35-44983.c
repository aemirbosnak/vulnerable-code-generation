//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    struct sockaddr_in server_addr;
    char message[1000], server_reply[2000];
    int socket_fd, recv_size;

    //Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Could not create socket");
        return 1;
    }

    //Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(80);

    //Connect to remote server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection error");
        return 1;
    }

    //Send some data
    strcpy(message, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    //Receive a reply from the server
    while ((recv_size = recv(socket_fd, server_reply, 2000, 0)) > 0) {
        // Null terminate the string
        server_reply[recv_size] = '\0';
        // Print the response
        printf("%s", server_reply);
    }

    if (recv_size == 0) {
        printf("Connection closed");
    } else if (recv_size == -1) {
        printf("Receive failed");
        return 1;
    }

    close(socket_fd);

    return 0;
}