//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 2048
#define SERVER_URL "http://example.com" // Replace with actual speed test server
#define MAX_RETRIES 5

void print_welcome_message() {
    printf("*****************************************\n");
    printf("* Welcome to the Lightning Speed Test! *\n");
    printf("*****************************************\n");
}

double calculate_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0; // milliseconds
}

void simulate_download_test() {
    printf("Initiating download test...\n");
    struct timeval start, end;
    gettimeofday(&start, NULL);
    size_t total_bytes = 0;
    char buffer[BUFFER_SIZE];

    for (int i = 0; i < MAX_RETRIES; i++) {
        // Simulating a download of data for 1 second
        size_t bytes_downloaded = BUFFER_SIZE;  // Simulating bytes downloaded
        usleep(1000000); // Sleep for 1 second
        total_bytes += bytes_downloaded;
    }

    gettimeofday(&end, NULL);
    double elapsed_time = calculate_time_diff(start, end);
    double speed_mbps = (total_bytes * 8) / (elapsed_time * 1000); // convert to Mbps
    printf("Download test completed: %.2f Mbps\n", speed_mbps);
}

void simulate_upload_test() {
    printf("Initiating upload test...\n");
    struct timeval start, end;
    gettimeofday(&start, NULL);
    size_t total_bytes = 0;
    char buffer[BUFFER_SIZE];

    for (int i = 0; i < MAX_RETRIES; i++) {
        // Simulating an upload of data for 1 second
        size_t bytes_uploaded = BUFFER_SIZE; // Simulating bytes uploaded
        usleep(1000000); // Sleep for 1 second
        total_bytes += bytes_uploaded;
    }

    gettimeofday(&end, NULL);
    double elapsed_time = calculate_time_diff(start, end);
    double speed_mbps = (total_bytes * 8) / (elapsed_time * 1000); // convert to Mbps
    printf("Upload test completed: %.2f Mbps\n", speed_mbps);
}

int main() {
    print_welcome_message();

    int choice;
    while (1) {
        printf("\nChoose test type:\n");
        printf("1. Download Speed Test\n");
        printf("2. Upload Speed Test\n");
        printf("3. Full Speed Test\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                simulate_download_test();
                break;
            case 2:
                simulate_upload_test();
                break;
            case 3:
                simulate_download_test();
                simulate_upload_test();
                break;
            case 4:
                printf("Exiting the speed test. Have a great day!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}