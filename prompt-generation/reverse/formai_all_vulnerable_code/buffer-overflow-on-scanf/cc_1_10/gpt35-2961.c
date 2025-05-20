//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int testConnection(int downloadSpeed, int uploadSpeed);
void downloadFile(int fileSize);

int main() {
    printf("*** C Internet Speed Test Application ***\n\n");

    // Get download speed from user
    int downloadSpeed;
    printf("Enter your estimated download speed in Mbps: ");
    scanf("%d", &downloadSpeed);

    // Get upload speed from user
    int uploadSpeed;
    printf("Enter your estimated upload speed in Mbps: ");
    scanf("%d", &uploadSpeed);

    printf("\nStart testing connection...\n\n");

    // Test connection recursively by downloading a 100MB file
    int result = testConnection(downloadSpeed, uploadSpeed);

    if (result) {
        printf("\nConnection is stable!\n");
    } else {
        printf("\nConnection is unstable. Please check your network.\n");
    }

    return 0;
}

int testConnection(int downloadSpeed, int uploadSpeed) {
    // Set file size to 100MB
    int fileSize = 100;

    // Download file to test download speed
    downloadFile(fileSize);

    // Calculate download time in seconds
    int downloadTime = fileSize / downloadSpeed;

    // Sleep for upload time
    int uploadTime = fileSize / uploadSpeed;
    printf("Waiting for %d seconds to upload file...\n", uploadTime);
    sleep(uploadTime);

    // Generate random number from 0 to 1
    srand(time(NULL));
    int random = rand() % 2;

    if (random) {
        // Connection is stable if random number is 1
        return 1;
    } else {
        // Test connection recursively if random number is 0
        printf("Connection is unstable. Retrying...\n");
        testConnection(downloadSpeed, uploadSpeed);
    }
}

void downloadFile(int fileSize) {
    printf("Downloading a %dMB file...\n", fileSize);
    // Simulate download by sleeping for download time
    int downloadTime = fileSize / 10;
    sleep(downloadTime);
    printf("Download complete!\n");
}