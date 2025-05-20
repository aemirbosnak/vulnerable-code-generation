//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculateFactorial() {
    int n;
    unsigned long long factorial = 1;
    
    printf("\nEnter a positive integer for factorial: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("\nFactorial is not defined for negative numbers.\n");
        return;
    }
    
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    
    printf("Factorial of %d = %llu\n", n, factorial);
}

void fibonacciSeries() {
    int n;

    printf("\nEnter the number of Fibonacci terms: ");
    scanf("%d", &n);
    
    int first = 0, second = 1, next;

    printf("Fibonacci Series: %d, %d", first, second);
    
    for (int i = 3; i <= n; ++i) {
        next = first + second;
        printf(", %d", next);
        first = second;
        second = next;
    }
    printf("\n");
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void checkPrime() {
    int n;

    printf("\nEnter a positive integer to check if it's prime: ");
    scanf("%d", &n);
    
    if (isPrime(n))
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);
}

void calculateStatistics() {
    int n;
    printf("\nEnter the number of data points: ");
    scanf("%d", &n);
    
    double *data = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; ++i) {
        printf("Enter data point %d: ", i + 1);
        scanf("%lf", &data[i]);
    }

    // Calculate mean
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += data[i];
    }
    double mean = sum / n;

    // Calculate median
    double median;
    // Sort the data array
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (data[i] > data[j]) {
                double temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    if (n % 2 == 0)
        median = (data[n / 2 - 1] + data[n / 2]) / 2;
    else
        median = data[n / 2];

    // Calculate mode
    int *count = (int *)calloc(n, sizeof(int));
    int modeIndex = 0, maxCount = 0;
    for (int i = 0; i < n; ++i) {
        count[i] = 1;
        for (int j = i + 1; j < n; ++j) {
            if (data[i] == data[j]) {
                count[i]++;
            }
        }
        if (count[i] > maxCount) {
            maxCount = count[i];
            modeIndex = i;
        }
    }

    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    if (maxCount > 1) {
        printf("Mode: %.2f\n", data[modeIndex]);
    } else {
        printf("No mode found.\n");
    }

    free(data);
    free(count);
}

int main() {
    int choice;
    
    do {
        printf("\nMathematical Operations Menu:");
        printf("\n1. Calculate Factorial");
        printf("\n2. Fibonacci Series");
        printf("\n3. Check Prime Number");
        printf("\n4. Calculate Statistics (Mean, Median, Mode)");
        printf("\n5. Exit");
        printf("\n\nSelect an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                calculateFactorial();
                break;
            case 2:
                fibonacciSeries();
                break;
            case 3:
                checkPrime();
                break;
            case 4:
                calculateStatistics();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 to 5.\n");
        }
        
    } while (choice != 5);
    
    return 0;
}