//Falcon-180B DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_DATA_SIZE 1000

// Function to calculate the mean of an array
double calculate_mean(double data[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

// Function to calculate the standard deviation of an array
double calculate_std_dev(double data[], int size) {
    double mean = calculate_mean(data, size);
    double deviation = 0;
    for (int i = 0; i < size; i++) {
        deviation += pow((data[i] - mean), 2);
    }
    return sqrt(deviation / size);
}

// Function to generate random data
void generate_data(double data[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100;
    }
}

// Main function to run the program
int main() {
    double data[MAX_DATA_SIZE];
    int size;

    // Get the size of the data set from the user
    printf("Enter the size of the data set: ");
    if (scanf("%d", &size)!= 1 || size <= 0 || size > MAX_DATA_SIZE) {
        printf("Invalid input. Please enter a positive integer less than or equal to %d.\n", MAX_DATA_SIZE);
        return 1;
    }

    // Generate random data
    generate_data(data, size);

    // Calculate the mean and standard deviation
    double mean = calculate_mean(data, size);
    double std_dev = calculate_std_dev(data, size);

    // Print the results
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", std_dev);

    return 0;
}