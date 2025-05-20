//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define NUM_SAMPLES 10

// Function to calculate the mean
double calculate_mean(double arr[], int size) {
    int i;
    double sum = 0;

    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}

// Function to calculate the standard deviation
double calculate_std_dev(double arr[], int size) {
    int i;
    double mean = calculate_mean(arr, size);
    double sum = 0;

    for (i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }

    return sqrt(sum / size);
}

int main() {
    FILE *file;
    char filename[50];
    double wifi_strength[MAX_SIZE];
    int num_samples = 0;
    double mean, std_dev;

    // Get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read wifi strengths from file
    while (fscanf(file, "%lf", &wifi_strength[num_samples])!= EOF) {
        num_samples++;
    }

    fclose(file);

    // Calculate mean and standard deviation
    mean = calculate_mean(wifi_strength, num_samples);
    std_dev = calculate_std_dev(wifi_strength, num_samples);

    // Print results
    printf("Mean wifi strength: %.2lf\n", mean);
    printf("Standard deviation: %.2lf\n", std_dev);

    return 0;
}