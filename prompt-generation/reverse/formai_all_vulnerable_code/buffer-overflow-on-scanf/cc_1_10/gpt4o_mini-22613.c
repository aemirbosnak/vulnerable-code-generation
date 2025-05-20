//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
void printFibonacci(int n);
int isPrime(int num);
float calculateMean(int *arr, int size);
float calculateVariance(int *arr, int size, float mean);
float calculateStandardDeviation(float variance);

int main() {
    int n, i, number;
    printf("Welcome to the Advanced Arithmetic and Statistics Program!\n\n");
    
    // Fibonacci Series
    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &n);
    printf("Fibonacci Series with %d terms:\n", n);
    printFibonacci(n);
    
    // Prime Number Check
    printf("\nEnter a number to check if it is prime: ");
    scanf("%d", &number);
    if (isPrime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }
    
    // Statistics Calculation
    printf("\nHow many numbers do you want to enter for statistical analysis? ");
    scanf("%d", &n);
    int *numbers = (int*)malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    
    float mean = calculateMean(numbers, n);
    float variance = calculateVariance(numbers, n, mean);
    float stddev = calculateStandardDeviation(variance);
    
    printf("\nStatistics for the entered numbers:\n");
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);
    
    // Memory Release
    free(numbers);
    
    printf("\nThank you for using the program!\n");
    return 0;
}

// Function Definitions
void printFibonacci(int n) {
    int a = 0, b = 1, next;
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

float calculateMean(int *arr, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

float calculateVariance(int *arr, int size, float mean) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return sum / size;
}

float calculateStandardDeviation(float variance) {
    return sqrt(variance);
}