//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_SPEED 1000 // max speed in Mbps
#define TEST_DURATION 10 // test duration in seconds
#define BUFFER_SIZE 1024 // buffer size in bytes

double get_download_speed() {
    // simulate download speed test
    double speed = ((double)rand() / (double)RAND_MAX) * MAX_SPEED;
    printf("Download speed: %0.2f Mbps\n", speed);
    return speed;
}

double get_upload_speed() {
    // simulate upload speed test
    double speed = ((double)rand() / (double)RAND_MAX) * MAX_SPEED;
    printf("Upload speed: %0.2f Mbps\n", speed);
    return speed;
}

int main() {
    // seed random number generator
    srand(time(NULL));

    char choice;
    do {
        // get user choice
        printf("Press D to test download speed or U to test upload speed\n");
        scanf(" %c", &choice);

        // perform speed test
        if (choice == 'D') {
            printf("Starting download speed test...\n");
            double speed = 0;
            for (int i = 1; i <= TEST_DURATION; i++) {
                sleep(1);
                speed += get_download_speed();
            }
            printf("Average download speed over %d seconds: %0.2f Mbps\n", TEST_DURATION, speed / TEST_DURATION);
        } else if (choice == 'U') {
            printf("Starting upload speed test...\n");
            double speed = 0;
            for (int i = 1; i <= TEST_DURATION; i++) {
                sleep(1);
                speed += get_upload_speed();
            }
            printf("Average upload speed over %d seconds: %0.2f Mbps\n", TEST_DURATION, speed / TEST_DURATION);
        } else {
            printf("Invalid choice, please try again.\n");
        }

        // ask user if they want to perform another test
        printf("Do you want to perform another test? (Y/N)\n");
        scanf(" %c", &choice);

    } while (choice == 'Y');

    return 0;
}