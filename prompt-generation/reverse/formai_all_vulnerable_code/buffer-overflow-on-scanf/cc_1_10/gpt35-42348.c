//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate random numbers between min and max
int getRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Main function
int main() {
    int testNum = 1;    // Keep track of the number of tests
    int numTests;       // Number of speed tests to perform
    int dlSpeed;        // Download speed in megabits per second
    int ulSpeed;        // Upload speed in megabits per second
    char accuracy[20];  // Speed test accuracy (eg. "Good", "Fair", "Poor")

    srand(time(NULL));  // Seed random number generator

    printf("Welcome to the Internet Speed Test App!\n");
    printf("How many speed tests would you like to perform? ");
    scanf("%d", &numTests);

    // Loop for the number of tests specified by user
    while (testNum <= numTests) {
        printf("\nTest %d:\n", testNum);

        // Generate random download and upload speeds between 1-100 mbps
        dlSpeed = getRandom(1, 100);
        ulSpeed = getRandom(1, 100);

        // Determine speed test accuracy based on download speed
        if (dlSpeed > 75) {
            strcpy(accuracy, "Excellent");
        } else if (dlSpeed > 50) {
            strcpy(accuracy, "Good");
        } else if (dlSpeed > 25) {
            strcpy(accuracy, "Fair");
        } else {
            strcpy(accuracy, "Poor");
        }

        printf("Download speed: %d mbps (%s)\n", dlSpeed, accuracy);
        printf("Upload speed: %d mbps\n", ulSpeed);

        testNum++;
    }

    printf("\nThanks for using the Internet Speed Test App!");

    return 0;
}