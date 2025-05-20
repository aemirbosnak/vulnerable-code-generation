//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 100

void gather_data(int data[], int *size);
double calculate_mean(int data[], int size);
double calculate_variance(int data[], int size, double mean);
double calculate_standard_deviation(double variance);

int main() {
    int data[MAX_SAMPLES];
    int size = 0;

    printf("Welcome to the Statistical Data Analyzer!\n");
    printf("This program will gather data, then calculate and display statistical results.\n");
    
    gather_data(data, &size);
    
    if (size == 0) {
        printf("No data collected. Exiting program.\n");
        return 1;
    }

    double mean = calculate_mean(data, size);
    double variance = calculate_variance(data, size, mean);
    double std_dev = calculate_standard_deviation(variance);

    printf("\nStatistical Results:\n");
    printf("Number of samples: %d\n", size);
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", std_dev);

    return 0;
}

void gather_data(int data[], int *size) {
    int sample;
    char choice;

    do {
        if (*size >= MAX_SAMPLES) {
            printf("Maximum samples reached! Can't collect more data.\n");
            break;
        }

        printf("Enter a sample value: ");
        scanf("%d", &sample);
        data[*size] = sample;
        (*size)++;

        printf("Would you like to enter another sample? (y/n): ");
        getchar();  // Clear newline from input buffer
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');
}

double calculate_mean(int data[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return (double)sum / size;
}

double calculate_variance(int data[], int size, double mean) {
    double variance = 0.0;
    for (int i = 0; i < size; i++) {
        variance += pow(data[i] - mean, 2);
    }
    return variance / size;
}

double calculate_standard_deviation(double variance) {
    return sqrt(variance);
}