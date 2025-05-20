//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct stat_data {
    int count;
    double avg;
    double sum;
};

int main() {
    int sock, cli_sock;
    struct sockaddr_in server, client;
    struct stat_data data;

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        cli_sock = accept(sock, (struct sockaddr *)&client, NULL);
        if (cli_sock < 0) {
            perror("Accept failed");
            continue;
        }

        // Read data from the client
        read(cli_sock, &data, sizeof(data));

        // Calculate the statistical data
        data.count++;
        data.sum += data.count;
        data.avg = (data.sum / data.count);

        // Send the statistical data back to the client
        write(cli_sock, &data, sizeof(data));

        // Close the client socket
        close(cli_sock);
    }

    return 0;
}