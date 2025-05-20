//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 4096

/* Function to generate random integers */
int generateRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to simulate internet speed test */
double simulateSpeedTest(int downloadMax, int uploadMax) {
    int downloadSpeed = generateRandom(1, downloadMax);
    int uploadSpeed = generateRandom(1, uploadMax);
    double latency = ((double) generateRandom(1, 100)) / 100.0;
    double downloadTime = ((double) BUFFER_SIZE) / ((double) downloadSpeed);
    double uploadTime = ((double) BUFFER_SIZE) / ((double) uploadSpeed);
    double totalTime = downloadTime + uploadTime + latency;
    printf("Simulating internet speed test...\n\n");
    printf("Download speed: %d Mbps\n", downloadSpeed);
    printf("Upload speed: %d Mbps\n", uploadSpeed);
    printf("Latency: %.2f ms\n", latency);
    printf("Download time for %d MB file: %.2f seconds\n", BUFFER_SIZE / 1000000, downloadTime);
    printf("Upload time for %d MB file: %.2f seconds\n", BUFFER_SIZE / 1000000, uploadTime);
    printf("Total time for speed test: %.2f seconds\n\n", totalTime);
    return totalTime;
}

/* Main function */
int main() {
    srand(time(NULL));
    int downloadMax, uploadMax;
    printf("Enter maximum download speed (in Mbps): ");
    scanf("%d", &downloadMax);
    printf("Enter maximum upload speed (in Mbps): ");
    scanf("%d", &uploadMax);
    double totalTime = simulateSpeedTest(downloadMax, uploadMax);
    if (totalTime <= 3.0) {
        printf("Awesome internet speed!\n");
    } else if (totalTime <= 5.0) {
        printf("Good internet speed.\n");
    } else if (totalTime <= 8.0) {
        printf("Average internet speed.\n");
    } else {
        printf("Poor internet speed.\n");
    }
    return 0;
}