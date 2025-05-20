//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 100

// Function Prototypes
int isPrime(int num);
unsigned long long factorial(int n);
void calculateMeanMedianMode(int arr[], int size, double *mean, double *median, int *mode);

int main() {
    int choice, num, size;
    unsigned long long fact;
    double mean, median;
    int mode;
    int numbers[MAX_NUMBERS];

    do {
        printf("\n==========================\n");
        printf(" Math Exercise Program\n");
        printf("==========================\n");
        printf("1. Check Prime Number\n");
        printf("2. Calculate Factorial\n");
        printf("3. Calculate Mean, Median, and Mode\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Check Prime Number
                printf("Enter a number to check if it's prime: ");
                scanf("%d", &num);
                if (isPrime(num)) {
                    printf("%d is a prime number.\n", num);
                } else {
                    printf("%d is not a prime number.\n", num);
                }
                break;

            case 2: // Calculate Factorial
                printf("Enter a non-negative integer for factorial: ");
                scanf("%d", &num);
                if (num < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    fact = factorial(num);
                    printf("Factorial of %d is %llu.\n", num, fact);
                }
                break;

            case 3: // Calculate Mean, Median, and Mode
                printf("Enter the number of elements (max %d): ", MAX_NUMBERS);
                scanf("%d", &size);
                if (size <= 0 || size > MAX_NUMBERS) {
                    printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_NUMBERS);
                    break;
                }
                printf("Enter %d integers:\n", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &numbers[i]);
                }
                calculateMeanMedianMode(numbers, size, &mean, &median, &mode);
                printf("Mean: %.2f\n", mean);
                printf("Median: %.2f\n", median);
                printf("Mode: %d\n", mode);
                break;

            case 4: // Exit
                printf("Exiting the program. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please select from 1 to 4.\n");
        }
    } while(choice != 4);

    return 0;
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Function to calculate Mean, Median, and Mode
void calculateMeanMedianMode(int arr[], int size, double *mean, double *median, int *mode) {
    int count[100] = {0}; // Frequency array
    int maxCount = 0;

    // Calculate mean
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        count[arr[i]]++;
        if (count[arr[i]] > maxCount) {
            maxCount = count[arr[i]];
            *mode = arr[i];
        }
    }
    *mean = (double)sum / size;

    // Calculate median
    // Sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    if (size % 2 == 0) {
        *median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        *median = arr[size / 2];
    }
}