#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void receive_data(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(socket, buffer, sizeof(buffer), 0)) > 0) {
        // Vulnerability: No bounds checking on the buffer
        printf("%.*s", bytes_received, buffer);
    }
}

int main() {
    int socket;
    // Simulate connecting to an FTP server
    socket = 1; // Replace with actual socket creation and connection logic

    receive_data(socket);

    close(socket);
    return 0;
}
