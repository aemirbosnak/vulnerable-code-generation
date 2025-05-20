//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100

// Function to display the menu
void displayMenu() {
    printf("\n==============================\n");
    printf("       Math Exercise Program    \n");
    printf("==============================\n");
    printf("1. Generate Random Integers\n");
    printf("2. Calculate Mean and Standard Deviation\n");
    printf("3. Find Maximum and Minimum\n");
    printf("4. Check Prime Numbers\n");
    printf("5. Quit\n");
    printf("==============================\n");
    printf("Choose an option (1-5): ");
}

// Function to generate random integers
void generateRandomIntegers(int arr[], int size) {
    srand(time(NULL)); // Seed for random number generation
    printf("Generating %d random integers...\n", size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random integers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate mean and standard deviation
void calculateMeanAndSD(int arr[], int size, double *mean, double *stdDev) {
    double sum = 0.0, sumSq = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        sumSq += arr[i] * arr[i]; // Squared value for stdDev calculation
    }
    *mean = sum / size;
    *stdDev = sqrt((sumSq / size) - (*mean * *mean));
}

// Function to find maximum and minimum
void findMaxAndMin(int arr[], int size, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime numbers
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0; // Not a prime number
    }
    return 1; // It's a prime number
}

// Function to check and list prime numbers in the array
void checkPrimeNumbers(int arr[], int size) {
    printf("Checking for prime numbers:\n");
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            printf("%d is a prime number.\n", arr[i]);
        } else {
            printf("%d is not a prime number.\n", arr[i]);
        }
    }
}

// Main function
int main() {
    int option, size = MAX_SIZE;
    int arr[MAX_SIZE];
    double mean = 0.0, stdDev = 0.0;
    int max = 0, min = 0;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                generateRandomIntegers(arr, size);
                break;
            case 2:
                calculateMeanAndSD(arr, size, &mean, &stdDev);
                printf("Mean: %.2f, Standard Deviation: %.2f\n", mean, stdDev);
                break;
            case 3:
                findMaxAndMin(arr, size, &max, &min);
                printf("Maximum: %d, Minimum: %d\n", max, min);
                break;
            case 4:
                checkPrimeNumbers(arr, size);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please choose between 1 and 5.\n");
                break;
        }
    }
    
    return 0;
}