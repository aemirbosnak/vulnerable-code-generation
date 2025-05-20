//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 10

// Function prototypes
void inputNumbers(double arr[], int size);
void displayNumbers(double arr[], int size);
double calculateSum(double arr[], int size);
double calculateAverage(double arr[], int size);
double calculateVariance(double arr[], int size, double average);
double calculateStandardDeviation(double variance);
void sortNumbers(double arr[], int size);
void displayStatistics(double arr[], int size);

int main() {
    double numbers[MAX_NUMBERS];
    int choice;

    do {
        printf("\n--- Arithmetic Operations Menu ---\n");
        printf("1. Input Numbers\n");
        printf("2. Display Numbers\n");
        printf("3. Calculate Sum\n");
        printf("4. Calculate Average\n");
        printf("5. Calculate Variance\n");
        printf("6. Calculate Standard Deviation\n");
        printf("7. Sort Numbers\n");
        printf("8. Display Statistics\n");
        printf("9. Exit\n");
        printf("Choose an option (1-9): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                inputNumbers(numbers, MAX_NUMBERS);
                break;
            case 2:
                displayNumbers(numbers, MAX_NUMBERS);
                break;
            case 3: {
                double sum = calculateSum(numbers, MAX_NUMBERS);
                printf("Sum: %.2f\n", sum);
                break;
            }
            case 4: {
                double average = calculateAverage(numbers, MAX_NUMBERS);
                printf("Average: %.2f\n", average);
                break;
            }
            case 5: {
                double average = calculateAverage(numbers, MAX_NUMBERS);
                double variance = calculateVariance(numbers, MAX_NUMBERS, average);
                printf("Variance: %.2f\n", variance);
                break;
            }
            case 6: {
                double average = calculateAverage(numbers, MAX_NUMBERS);
                double variance = calculateVariance(numbers, MAX_NUMBERS, average);
                double stddev = calculateStandardDeviation(variance);
                printf("Standard Deviation: %.2f\n", stddev);
                break;
            }
            case 7:
                sortNumbers(numbers, MAX_NUMBERS);
                printf("Numbers sorted successfully.\n");
                break;
            case 8:
                displayStatistics(numbers, MAX_NUMBERS);
                break;
            case 9:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option (1-9).\n");
        }
    } while (choice != 9);

    return 0;
}

void inputNumbers(double arr[], int size) {
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }
}

void displayNumbers(double arr[], int size) {
    printf("Numbers entered:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

double calculateSum(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(double arr[], int size) {
    double sum = calculateSum(arr, size);
    return sum / size;
}

double calculateVariance(double arr[], int size, double average) {
    double variance = 0;
    for (int i = 0; i < size; i++) {
        variance += pow(arr[i] - average, 2);
    }
    return variance / size;
}

double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}

void sortNumbers(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayStatistics(double arr[], int size) {
    double average = calculateAverage(arr, size);
    double variance = calculateVariance(arr, size, average);
    double stddev = calculateStandardDeviation(variance);
    
    printf("Statistics:\n");
    printf("Sum: %.2f\n", calculateSum(arr, size));
    printf("Average: %.2f\n", average);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);
}