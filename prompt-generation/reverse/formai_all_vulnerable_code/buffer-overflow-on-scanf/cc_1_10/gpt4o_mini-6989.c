//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA 1000

// Function prototypes
void generate_data(int data[], int size);
double calculate_mean(int data[], int size);
double calculate_median(int data[], int size);
double calculate_variance(int data[], int size, double mean);
double calculate_standard_deviation(double variance);
void sort_data(int data[], int size);
void display_data(int data[], int size);

int main() {
    // Seed random number generator
    srand(time(NULL));

    int data[MAX_DATA];
    int size;

    // Prompt user for the number of data points
    printf("Enter the number of data points (1 to %d): ", MAX_DATA);
    scanf("%d", &size);

    if (size < 1 || size > MAX_DATA) {
        printf("Invalid size entered. Please enter a valid number.\n");
        return 1;
    }

    // Generate random data
    generate_data(data, size);
    
    // Display the generated data
    printf("\nGenerated Data:\n");
    display_data(data, size);

    // Calculate and display statistical measures
    double mean = calculate_mean(data, size);
    printf("Mean: %.2f\n", mean);

    double median = calculate_median(data, size);
    printf("Median: %.2f\n", median);

    double variance = calculate_variance(data, size, mean);
    printf("Variance: %.2f\n", variance);

    double std_dev = calculate_standard_deviation(variance);
    printf("Standard Deviation: %.2f\n", std_dev);

    return 0;
}

// Function to generate random data
void generate_data(int data[], int size) {
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100; // random numbers between 0 and 99
    }
}

// Function to calculate the mean
double calculate_mean(int data[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

// Function to calculate the median
double calculate_median(int data[], int size) {
    sort_data(data, size);
    if (size % 2 == 0) {
        // Even number of elements
        return (data[size/2 - 1] + data[size/2]) / 2.0;
    } else {
        // Odd number of elements
        return data[size/2];
    }
}

// Function to calculate the variance
double calculate_variance(int data[], int size, double mean) {
    double sum_squared_diff = 0.0;
    for (int i = 0; i < size; i++) {
        sum_squared_diff += (data[i] - mean) * (data[i] - mean);
    }
    return sum_squared_diff / size;
}

// Function to calculate the standard deviation
double calculate_standard_deviation(double variance) {
    return sqrt(variance);
}

// Function to sort the data in ascending order
void sort_data(int data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // Swap elements
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// Function to display data
void display_data(int data[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}