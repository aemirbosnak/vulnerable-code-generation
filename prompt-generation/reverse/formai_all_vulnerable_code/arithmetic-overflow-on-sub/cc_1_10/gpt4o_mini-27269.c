//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>

#define SAMPLE_COUNT 10

// Function to simulate internet speed test
double simulateSpeedTest() {
    // Simulating download speed (in Mbps)
    return (double)(rand() % 100 + 1); // Random speed between 1 and 100 Mbps
}

// Function to perform statistical analysis
void calculateStatistics(double speeds[], int count, double *mean, double *stddev) {
    double sum = 0.0, sum_sq = 0.0;

    for (int i = 0; i < count; i++) {
        sum += speeds[i];
        sum_sq += speeds[i] * speeds[i];
    }

    *mean = sum / count;
    *stddev = sqrt((sum_sq / count) - (*mean * *mean));
}

// Function to display results in a formatted way
void displayResults(double speeds[], int count, double mean, double stddev) {
    printf("\n----- Internet Speed Test Results -----\n");
    printf("Sample Count: %d\n", count);
    printf("Speeds (Mbps): ");

    for (int i = 0; i < count; i++) {
        printf("%.2f ", speeds[i]);
    }

    printf("\nMean Speed: %.2f Mbps\n", mean);
    printf("Standard Deviation: %.2f Mbps\n", stddev);
    printf("---------------------------------------\n");
}

int main() {
    double speeds[SAMPLE_COUNT];
    double mean = 0.0, stddev = 0.0;
    struct timeval start, end;

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Performing speed tests...\n");

    srand(time(NULL)); // Seed for random number generation

    for (int i = 0; i < SAMPLE_COUNT; i++) {
        gettimeofday(&start, NULL);
        speeds[i] = simulateSpeedTest();
        usleep(500000); // Simulate a delay of 0.5 seconds between tests
        gettimeofday(&end, NULL);
        
        long mtime = ((end.tv_sec - start.tv_sec) * 1000000L + end.tv_usec) - start.tv_usec;
        printf("Test %d: %.2f Mbps (Time: %ld microseconds)\n", i + 1, speeds[i], mtime);
    }

    // Calculate statistics
    calculateStatistics(speeds, SAMPLE_COUNT, &mean, &stddev);
    
    // Display results
    displayResults(speeds, SAMPLE_COUNT, mean, stddev);

    return 0;
}