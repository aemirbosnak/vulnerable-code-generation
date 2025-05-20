//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main(void) {
    printf("Welcome to the Internet Speed Test Application\n\n");

    // Ask user for number of measurements
    int num_measurements;
    do {
        printf("How many measurements would you like to take? (must be a positive integer): ");
        scanf("%d", &num_measurements);
    } while (num_measurements <= 0);

    printf("\nThank you, we will now begin with the speed test...\n");

    // Initialize variables
    double total_download_speed = 0, total_upload_speed = 0;
    char command[BUFFER_SIZE], output[BUFFER_SIZE];
    clock_t start_time, end_time;
    int i;

    // Run speed test for specified number of measurements
    for (i = 1; i <= num_measurements; i++) {
        printf("\nMeasurement #%d:\n", i);

        // Download speed test
        start_time = clock();
        sprintf(command, "curl -o /dev/null https://speedtest-ny.turnkeyinternet.net/10mb.bin");
        system(command);
        end_time = clock();
        double download_speed = 10.0 / ((double)(end_time - start_time) / CLOCKS_PER_SEC);
        printf("Download speed: %.2f Mbps\n", download_speed);
        total_download_speed += download_speed;

        // Upload speed test
        start_time = clock();
        sprintf(command, "curl -F file=@/dev/zero https://speedtest-ny.turnkeyinternet.net/handle.php");
        system(command);
        end_time = clock();
        double upload_speed = 10.0 / ((double)(end_time - start_time) / CLOCKS_PER_SEC);
        printf("Upload speed: %.2f Mbps\n", upload_speed);
        total_upload_speed += upload_speed;

        // Pause for a moment before proceeding to next measurement
        printf("Pausing for 5 seconds...\n");
        sleep(5);
    }

    // Calculate and display average speeds
    double avg_download_speed = total_download_speed / num_measurements;
    double avg_upload_speed = total_upload_speed / num_measurements;
    printf("\nAverage download speed: %.2f Mbps\n", avg_download_speed);
    printf("Average upload speed: %.2f Mbps\n", avg_upload_speed);

    printf("\nThank you for using the Internet Speed Test Application. Goodbye!\n");

    return 0;
}