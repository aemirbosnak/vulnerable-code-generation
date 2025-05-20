//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_IP "127.0.0.1" // Replace with your server address for testing
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define TEST_DURATION 10

void print_intro() {
    printf("\n=============================\n");
    printf("    Internet Speed Tester    \n");
    printf("=============================\n");
    printf("This application measures your\n");
    printf("internet connection's download\n");
    printf("and upload speed.\n");
    printf("Press Enter to start the test...\n");
    getchar();
}

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

double measure_upload_speed(int socket) {
    char *buffer = (char *)malloc(BUFFER_SIZE);
    struct timeval start, end;
    double elapsed_time;
    size_t total_bytes = 0;

    for (int i = 0; i < TEST_DURATION; i++) {
        gettimeofday(&start, NULL);
        send(socket, buffer, BUFFER_SIZE, 0);
        gettimeofday(&end, NULL);

        elapsed_time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
        total_bytes += BUFFER_SIZE;

        printf("Uploaded %zu bytes in %.2f ms\n", BUFFER_SIZE, elapsed_time);
        usleep(100000); // Sleep to simulate continuous upload
    }

    free(buffer);
    return (total_bytes / (elapsed_time / 1000)) * 8; // kbps
}

double measure_download_speed(int socket) {
    char *buffer = (char *)malloc(BUFFER_SIZE);
    struct timeval start, end;
    double elapsed_time;
    size_t total_bytes = 0;

    for (int i = 0; i < TEST_DURATION; i++) {
        gettimeofday(&start, NULL);
        total_bytes += recv(socket, buffer, BUFFER_SIZE, 0);
        gettimeofday(&end, NULL);

        elapsed_time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
        printf("Downloaded %zu bytes in %.2f ms\n", BUFFER_SIZE, elapsed_time);
    }

    free(buffer);
    return (total_bytes / (elapsed_time / 1000)) * 8; // kbps
}

int main() {
    print_intro();

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error_exit("Could not create socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Connection to server failed");
    }

    printf("Testing upload speed...\n");
    double upload_speed = measure_upload_speed(sock);
    printf("Your upload speed is: %.2f kbps\n", upload_speed);

    printf("\nTesting download speed...\n");
    double download_speed = measure_download_speed(sock);
    printf("Your download speed is: %.2f kbps\n", download_speed);

    close(sock);
    printf("Speed test completed. Thank you!\n");
    return 0;
}