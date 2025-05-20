//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Failed to create socket\n");
        return 1;
    }

    // Get the local IP address
    struct sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(8888);
    bind(socket_fd, (struct sockaddr*)&local_addr, sizeof(local_addr));

    // Listen for incoming connections
    listen(socket_fd, 5);

    while (1) {
        // Accept a new connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd < 0) {
            printf("Failed to accept connection\n");
            return 1;
        }

        // Get the remote IP address
        struct hostent *remote_host = gethostbyaddr((const char*)&client_addr.sin_addr, sizeof(client_addr.sin_addr), AF_INET);
        if (remote_host == NULL) {
            printf("Failed to get remote host address\n");
            close(client_fd);
            continue;
        }

        // Send a test file to the remote host
        char test_file[] = "test.txt";
        int test_file_len = strlen(test_file);
        send(client_fd, test_file, test_file_len, 0);

        // Receive the test file from the remote host
        char response[1024];
        int response_len = recv(client_fd, response, sizeof(response), 0);
        if (response_len < 0) {
            printf("Failed to receive response\n");
            close(client_fd);
            continue;
        }

        // Calculate the transfer time
        struct timeval start, end;
        gettimeofday(&start, NULL);
        send(client_fd, "START", strlen("START"), 0);
        gettimeofday(&end, NULL);
        double transfer_time = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;

        // Calculate the transfer speed
        double transfer_speed = response_len / transfer_time;
        printf("Transfer speed: %.2f KB/s\n", transfer_speed / 1024);

        // Send a confirmation message to the remote host
        send(client_fd, "END", strlen("END"), 0);

        // Close the connection
        close(client_fd);
    }

    // Close the socket
    close(socket_fd);

    return 0;
}