//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define SERVER_PORT 80
#define MAX_BUFFER 2048
#define URL "http://speed.hetzner.de/100MB.bin" // Sample speed test file location

void displayWelcomeMessage() {
    printf("\033[1;34m"); // Change text color to blue
    printf("======= Cyberpunk Internet Speed Test =======\n");
    printf("    ~ In the neon-lit world of cyberspace ~    \n");
    printf("\033[0m"); // Reset text color
}

long fetchDataSize(const char *url) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *request;
    char buffer[MAX_BUFFER];
    long total_bytes = 0;
    
    host = gethostbyname("speed.hetzner.de");
    if (host == NULL) {
        perror("Error retrieving host");
        exit(EXIT_FAILURE);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    asprintf(&request, "GET /100MB.bin HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", "speed.hetzner.de");
    send(sock, request, strlen(request), 0);

    while (recv(sock, buffer, sizeof(buffer) - 1, 0) > 0) {
        total_bytes += strlen(buffer);
    }

    free(request);
    close(sock);
    return total_bytes;
}

double calculateSpeed(long bytes_transferred, double duration_seconds) {
    return (bytes_transferred * 8.0) / (duration_seconds * 1e6); // Speed in Mbps
}

void displayResults(long bytes_transferred, double speed) {
    printf("\033[1;32m"); // Change text color to green
    printf("======== Speed Test Results ========\n");
    printf("Bytes Transferred: %ld bytes\n", bytes_transferred);
    printf("Speed: %.2f Mbps\n", speed);
    printf("===================================\n");
    printf("\033[0m"); // Reset text color
}

int main() {
    displayWelcomeMessage();

    clock_t start_time = clock();
    long bytes_transferred = fetchDataSize(URL);
    clock_t end_time = clock();

    double duration_seconds = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    double speed = calculateSpeed(bytes_transferred, duration_seconds);

    displayResults(bytes_transferred, speed);

    printf("\033[1;35m"); // Change text color to purple
    printf("Hit 'Enter' to exit into the shadows...\n");
    printf("\033[0m"); // Reset text color
    getchar(); // Wait for user to press enter

    return 0;
}