//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_address;
    char *message, response[2000];
    int message_length = 0, read_size = 0;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    puts("Socket created");

    // Set server address
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");   // IP address of server
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);                     // Port number of server

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error: ");
        return 1;
    }

    puts("Connected");

    // Send request to server
    message = "GET / HTTP/1.1\r\n\r\n";
    message_length = strlen(message);

    if (send(sock, message, message_length, 0) < 0) {
        puts("Send failed");
        return 1;
    }

    puts("Request sent");

    // Receive response from server
    while((read_size = recv(sock, response, 2000, 0)) > 0) {
        // Null terminate response
        response[read_size] = '\0';

        // Print received response
        printf("%s", response);
    }

    if (read_size == 0) {
        puts("Server disconnected");
    } else if (read_size == -1) {
        perror("Error: ");
        return 1;
    }

    return 0;
}