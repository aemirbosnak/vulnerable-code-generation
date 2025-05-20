//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MBPS 1000000 // bytes per second

int main()
{
    srand(time(NULL));
    
    // Generate random internet speed between 1 and 100 Mbps
    int speed = (rand() % 100) + 1;
    
    // Convert speed to bytes per second
    int speed_bps = speed * MBPS;
    
    printf("Welcome to the Internet Speed Test!\n\n");
    printf("Testing your internet speed...\n\n");
    printf("Your internet speed is: %d Mbps\n\n", speed);
    
    // Prompt user to start the speed test
    printf("Would you like to start the speed test? (y/n): ");
    char response;
    scanf("%c", &response);
    
    // If user responds with 'y', start the speed test
    if (response == 'y') {
        printf("\nStarting download speed test...\n\n");
        printf("Downloading file...  ");
        // Simulate download speed test by sleeping for 5 seconds
        int i;
        for (i = 0; i < 5; i++) {
            printf(".");
            fflush(stdout); // Flush output buffer so dots appear immediately
            sleep(1); // Sleep for 1 second
        }
        // Calculate download speed and display results
        float download_speed = (float) rand() / (float) RAND_MAX * speed_bps;
        printf("\n\nDownload speed: %.2f Mbps\n\n", download_speed / MBPS);
        printf("Starting upload speed test...\n\n");
        printf("Uploading file...  ");
        // Simulate upload speed test by sleeping for 5 seconds
        for (i = 0; i < 5; i++) {
            printf(".");
            fflush(stdout); // Flush output buffer so dots appear immediately
            sleep(1); // Sleep for 1 second
        }
        // Calculate upload speed and display results
        float upload_speed = (float) rand() / (float) RAND_MAX * speed_bps;
        printf("\n\nUpload speed: %.2f Mbps\n\n", upload_speed / MBPS);
    } else {
        printf("\nSpeed test cancelled.\n\n");
    }
    
    return 0;
}