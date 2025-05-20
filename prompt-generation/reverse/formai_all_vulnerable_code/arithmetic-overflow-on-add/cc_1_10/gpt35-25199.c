//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 10240  // 10 KiB
#define SMALL_BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    struct sockaddr_in server_address;
    char *request_message, buffer[BUFFER_SIZE], response_message[SMALL_BUFFER_SIZE];
    int sock, message_len, byte_count_total = 0;
    struct timeval start, end;

    // Create TCP socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Clear server address structure and set server address and port to connect to
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "8.8.8.8", &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Unable to connect to server");
        exit(EXIT_FAILURE);
    }

    // Construct HTTP GET request message
    request_message = "GET / HTTP/1.1\r\n"
                      "Host: google.com\r\n"
                      "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:80.0) Gecko/20100101 Firefox/80.0\r\n"
                      "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
                      "Accept-Language: en-US,en;q=0.5\r\n"
                      "Accept-Encoding: gzip, deflate, br\r\n"
                      "Connection: keep-alive\r\n"
                      "\r\n";
    message_len = strlen(request_message);

    // Start timer before sending request message
    gettimeofday(&start, NULL);

    // Send request message to server
    if (send(sock, request_message, message_len, 0) < 0) {
        perror("Error sending request message");
        exit(EXIT_FAILURE);
    }

    // Receive response message from server
    while (1) {
        int byte_count = recv(sock, buffer, BUFFER_SIZE, 0);
        if (byte_count < 0) {
            perror("Error receiving response message");
            exit(EXIT_FAILURE);
        } else if (byte_count == 0) {
            break;
        } else {
            byte_count_total += byte_count;
        }
    }

    // Stop timer after receiving response message
    gettimeofday(&end, NULL);

    // Calculate total time taken in seconds
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Close socket
    close(sock);

    // Print result
    sprintf(response_message, "%d bytes in %.2f seconds\n", byte_count_total, elapsed_time);
    printf("%s\n", response_message);

    return EXIT_SUCCESS;
}