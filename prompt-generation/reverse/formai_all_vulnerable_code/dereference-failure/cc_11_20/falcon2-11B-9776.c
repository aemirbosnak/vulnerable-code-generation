//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>

#define BUFFER_SIZE 4096

int main() {
    int server_socket_fd, new_socket_fd, client_socket_fd;
    struct sockaddr_in server_address, client_address;
    struct sockaddr_in new_address;
    struct hostent* host_info;
    int port_number = 12345;
    int optval = 1;
    int optlen = sizeof(optval);
    char buffer[BUFFER_SIZE];
    int buffer_size = sizeof(buffer);

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        printf("Error creating server socket: %s\n", strerror(errno));
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port_number);

    if (bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        printf("Error binding server socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(server_socket_fd, 5) == -1) {
        printf("Error listening on server socket: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        new_socket_fd = accept(server_socket_fd, (struct sockaddr*)&new_address, (socklen_t*)&optlen);
        if (new_socket_fd == -1) {
            printf("Error accepting new connection: %s\n", strerror(errno));
            return 1;
        }

        printf("New client connected\n");
        char* hostname = "localhost";
        if ((host_info = gethostbyname(hostname)) == NULL) {
            printf("Error resolving hostname: %s\n", hstrerror(h_errno));
            return 1;
        }
        new_address.sin_addr = *((struct in_addr*)host_info->h_addr);

        if (connect(new_socket_fd, (struct sockaddr*)&new_address, sizeof(new_address)) == -1) {
            printf("Error connecting to client: %s\n", strerror(errno));
            return 1;
        }

        if (write(new_socket_fd, "Welcome to the server!", strlen("Welcome to the server!") + 1)!= strlen("Welcome to the server!") + 1) {
            printf("Error writing to client: %s\n", strerror(errno));
            return 1;
        }

        if (read(new_socket_fd, buffer, buffer_size)!= buffer_size) {
            printf("Error reading from client: %s\n", strerror(errno));
            return 1;
        }

        printf("Received message from client: %s\n", buffer);

        if (write(new_socket_fd, "Thank you for connecting!", strlen("Thank you for connecting!") + 1)!= strlen("Thank you for connecting!") + 1) {
            printf("Error writing to client: %s\n", strerror(errno));
            return 1;
        }

        close(new_socket_fd);
    }

    return 0;
}