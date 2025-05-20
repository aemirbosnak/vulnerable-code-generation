//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFFER_SIZE 1024

void displayResponse(char *response) {
    printf("\n--- Response from the Server ---\n");
    printf("%s\n", response);
    printf("----------------------------------\n");
}

void make_request(const char *hostname, const char *path) {
    int sock;
    struct sockaddr_in server_address;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];

    // Declare the fates that bind us
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Oh cruel fate! Socket creation failed...");
        exit(EXIT_FAILURE);
    }

    // To the walls of fair Verona we go
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(hostname);

    // To seek our love, we connect
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Alas! Connection could not be made...");
        close(sock);
        exit(EXIT_FAILURE);
    }
    
    // A request for the heart of our beloved
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    
    // With trembling hands, we send the request
    send(sock, request, strlen(request), 0);

    // Response we await with bated breath
    int bytes_received = recv(sock, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        perror("Oh tragic twist! Failed to receive response...");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Terminating the response with a null character for safety
    response[bytes_received] = '\0';

    // We gaze upon the beloved's face
    displayResponse(response);
    
    // And then, as fate would have us, we bid farewell
    close(sock);
}

int main() {
    char hostname[BUFFER_SIZE], path[BUFFER_SIZE];

    // As dear Juliet did crave for love, we crave an address
    printf("O most sweet and gentle soul, bestow upon us the hostname: ");
    fgets(hostname, sizeof(hostname), stdin);
    hostname[strcspn(hostname, "\n")] = 0; // Remove newline

    // The path, a winding road we must traverse
    printf("Now, dear suitor, what path dost thou wish to tread? ");
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = 0; // Remove newline

    // Thus, with a heart full of hope, we request thy love's embrace
    make_request(hostname, path);

    // And as daylight fades, we part with sighs
    printf("Farewell, sweet dreams await us all!\n");
    return 0;
}