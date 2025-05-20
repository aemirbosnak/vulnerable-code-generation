//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// function to calculate download time
double downloadTime(double fileSize, double speed) {
    return fileSize / (speed * 1024);
}

int main() {
    double fileSize = 50;   // in MB
    double speed;       // in Mbps
    char input[256];

    printf("Welcome to the Internet Speed Test Application\n");
    printf("Please enter your internet speed (in Mbps): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%lf", &speed);

    printf("\nTesting your download speed...\n");
    double downloadTimeInSec = downloadTime(fileSize, speed);

    // simulate download speed
    int totalTime = (int)ceil(downloadTimeInSec);
    int remainingTime = totalTime;

    printf("Download speed: %.2lf Mbps\n", speed);
    printf("File size: %.2lf MB\n", fileSize);
    printf("Estimated download time: %d seconds\n\n", totalTime);

    // simulate download using random delays
    srand(time(NULL));
    while (remainingTime > 0) {
        int delay = rand() % 5 + 1;     // simulate random delay between 1-5 seconds
        if (delay > remainingTime) {
            delay = remainingTime;
        }
        remainingTime -= delay;
        printf("[");
        int i;
        for (i = 0; i < (totalTime - remainingTime); i++) {
            printf("=");
        }
        for (i = 0; i < remainingTime; i++) {
            printf(" ");
        }
        printf("] %d%% (%d seconds remaining)\n", (int)(((double)(totalTime - remainingTime) / totalTime) * 100), remainingTime);
        sleep(delay);       // simulate delay
    }

    printf("\nDownload complete!\n");

    return 0;
}