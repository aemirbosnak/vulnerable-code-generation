//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 8192
#define SERVER_ADDRESS "speed.hetzner.de"
#define PORT 80

void print_results(double download_speed, double upload_speed, double download_time, double upload_time) {
    printf("\n--- Internet Speed Test Results ---\n");
    printf("Download Speed: %.2f Mbps (%.2f MB in %.2fs)\n", download_speed / 1e6, download_speed * download_time / 8e6, download_time);
    printf("Upload Speed: %.2f Mbps (%.2f MB in %.2fs)\n", upload_speed / 1e6, upload_speed * upload_time / 8e6, upload_time);
    printf("-----------------------------------\n");
}

double download_test(int sock) {
    char buffer[BUFFER_SIZE];
    double total_bytes = 0;
    time_t start_time = time(NULL);
    
    // Simple HTTP request
    snprintf(buffer, sizeof(buffer), "GET /100MB.zip HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_ADDRESS);
    send(sock, buffer, strlen(buffer), 0);
    
    // Read the response
    while (recv(sock, buffer, sizeof(buffer), 0) > 0) {
        total_bytes += sizeof(buffer);
    }
    
    time_t end_time = time(NULL);
    return (double)(total_bytes / (end_time - start_time));
}

double upload_test(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'A', sizeof(buffer));  // Fill buffer with 'A's
    double total_bytes = 0;
    time_t start_time = time(NULL);
    
    // Simulate file upload
    for (int i = 0; i < 10; ++i) {  // Sending data in chunks
        send(sock, buffer, sizeof(buffer), 0);
        total_bytes += sizeof(buffer);
    }
    
    time_t end_time = time(NULL);
    return (double)(total_bytes / (end_time - start_time));
}

int create_socket(const char* address, int port) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *he;

    if ((he = gethostbyname(address)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

int main() {
    int sock;
    double download_speed, upload_speed, download_time, upload_time;

    // Connect to server
    sock = create_socket(SERVER_ADDRESS, PORT);
    
    // Download Test
    printf("Starting Download Speed Test...\n");
    download_speed = download_test(sock);
    printf("Download Test Completed\n");
    
    // Close the socket and re-establish for upload test
    close(sock);
    sock = create_socket(SERVER_ADDRESS, PORT);

    // Upload Test
    printf("Starting Upload Speed Test...\n");
    upload_speed = upload_test(sock);
    printf("Upload Test Completed\n");

    // Close the socket
    close(sock);

    // Print the results
    print_results(download_speed, upload_speed, download_time, upload_time);
    
    return 0;
}