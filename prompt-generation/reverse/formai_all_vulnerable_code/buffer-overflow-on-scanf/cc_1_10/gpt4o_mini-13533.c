//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Function to print a welcome message
void printWelcome() {
    printf("Welcome to the C Math Exercise Program!\n");
    printf("This program performs various mathematical calculations.\n");
    printf("You can enter a set of numbers, and it will calculate the mean, median, and standard deviation.\n");
    printf("Enjoy!\n\n");
}

// Function to calculate mean
double calculateMean(double arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate median
double calculateMedian(double arr[], int n) {
    // Sorting the array
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Finding median
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

// Function to calculate standard deviation
double calculateSD(double arr[], double mean, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return sqrt(sum / n);
}

// Function to read numbers into an array
int readNumbers(double arr[]) {
    int n;
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    if (n > MAX_SIZE || n <= 0) {
        printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 0;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &arr[i]);
    }
    return n;
}

// Function to display results
void displayResults(double mean, double median, double sd) {
    printf("Results:\n");
    printf("Mean: %.2lf\n", mean);
    printf("Median: %.2lf\n", median);
    printf("Standard Deviation: %.2lf\n", sd);
}

int main() {
    double numbers[MAX_SIZE];
    int count;

    printWelcome();
    
    // Read numbers and calculate statistics
    count = readNumbers(numbers);
    
    if (count == 0) {
        return 1; // End program if invalid input
    }
    
    double mean = calculateMean(numbers, count);
    double median = calculateMedian(numbers, count);
    double sd = calculateSD(numbers, mean, count);
    
    // Display the results
    displayResults(mean, median, sd);
    
    return 0;
}