//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
#define PI 3.14159265

// Function Declarations
void inputNumbers(double arr[], int n);
void displayNumbers(double arr[], int n);
double calculateSum(double arr[], int n);
double calculateAverage(double arr[], int n);
double calculateStandardDeviation(double arr[], int n, double average);
double calculateVariance(double arr[], int n, double average);
void displayResults(double sum, double avg, double variance, double stddev);

int main() {
    double numbers[SIZE];
    int count = 0;

    printf("Welcome to the Complex Arithmetic Calculation Program!\n");
    printf("Please enter the number of elements you would like to input (max %d): ", SIZE);
    scanf("%d", &count);

    if (count <= 0 || count > SIZE) {
        printf("Invalid count. Exiting program.\n");
        return 1;
    }

    inputNumbers(numbers, count);
    displayNumbers(numbers, count);
    
    double sum = calculateSum(numbers, count);
    double average = calculateAverage(numbers, count);
    double variance = calculateVariance(numbers, count, average);
    double stddev = calculateStandardDeviation(numbers, count, average);

    displayResults(sum, average, variance, stddev);
    
    return 0;
}

void inputNumbers(double arr[], int n) {
    printf("Please enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Number %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }
}

void displayNumbers(double arr[], int n) {
    printf("You have entered the following numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

double calculateSum(double arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(double arr[], int n) {
    double sum = calculateSum(arr, n);
    return sum / n;
}

double calculateVariance(double arr[], int n, double average) {
    double variance = 0.0;
    for (int i = 0; i < n; i++) {
        variance += pow(arr[i] - average, 2);
    }
    return variance / n;
}

double calculateStandardDeviation(double arr[], int n, double average) {
    double variance = calculateVariance(arr, n, average);
    return sqrt(variance);
}

void displayResults(double sum, double avg, double variance, double stddev) {
    printf("\nResults:\n");
    printf("Total Sum: %.2f\n", sum);
    printf("Average: %.2f\n", avg);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);
    
    printf("\n--- Statistics in Angle (degrees) ---\n");
    double angles[SIZE];
    int angleCount = SIZE < sizeof(angles) / sizeof(angles[0]) ? SIZE : sizeof(angles) / sizeof(angles[0]);

    for (int i = 0; i < angleCount; i++) {
        angles[i] = (sum + i * 10) * (PI / 180); // Convert to radians
        printf("Angle for input %d: %.2f radians\n", i + 1, angles[i]);
    }
    
    printf("\n--- Exiting program successfully ---\n");
}