#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void receive_data(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);
    }
}

int main() {
    int socket = 0; // Simulated socket
    char filename[BUFFER_SIZE];

    printf("Enter file name: ");
    fgets(filename, sizeof(filename), stdin);

    // Vulnerability: No bounds checking on filename length
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (!feof(file)) {
        receive_data(socket); // Simulate receiving data from FTP server
    }

    fclose(file);
    return EXIT_SUCCESS;
}
