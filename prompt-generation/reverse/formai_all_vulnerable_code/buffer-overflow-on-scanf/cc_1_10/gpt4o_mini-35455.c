//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    double data[MAX_SIZE];
    int size;
} Array;

void initializeArray(Array* array) {
    array->size = 0;
}

void addElement(Array* array, double element) {
    if (array->size < MAX_SIZE) {
        array->data[array->size] = element;
        array->size++;
    } else {
        printf("Array is full. Cannot add more elements.\n");
    }
}

void printArray(const Array* array) {
    printf("Array elements:\n");
    for (int i = 0; i < array->size; i++) {
        printf("%.2f ", array->data[i]);
    }
    printf("\n");
}

double calculateMean(const Array* array) {
    if (array->size == 0) {
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < array->size; i++) {
        sum += array->data[i];
    }
    return sum / array->size;
}

double calculateVariance(const Array* array) {
    if (array->size == 0) {
        return 0;
    }
    double mean = calculateMean(array);
    double varianceSum = 0;
    for (int i = 0; i < array->size; i++) {
        varianceSum += pow(array->data[i] - mean, 2);
    }
    return varianceSum / array->size;
}

double calculateStandardDeviation(const Array* array) {
    return sqrt(calculateVariance(array));
}

void sortArray(Array* array) {
    for (int i = 0; i < array->size - 1; i++) {
        for (int j = 0; j < array->size - i - 1; j++) {
            if (array->data[j] > array->data[j + 1]) {
                double temp = array->data[j];
                array->data[j] = array->data[j + 1];
                array->data[j + 1] = temp;
            }
        }
    }
}

void printStatistics(const Array* array) {
    printf("Statistics of the array:\n");
    printf("Mean: %.2f\n", calculateMean(array));
    printf("Variance: %.2f\n", calculateVariance(array));
    printf("Standard Deviation: %.2f\n", calculateStandardDeviation(array));
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Add an element to the array\n");
    printf("2. Display the array\n");
    printf("3. Calculate statistics (mean, variance, standard deviation)\n");
    printf("4. Sort the array\n");
    printf("5. Exit\n");
}

int main() {
    Array myArray;
    initializeArray(&myArray);
    int choice;
    double element;

    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%lf", &element);
                addElement(&myArray, element);
                break;

            case 2:
                printArray(&myArray);
                break;

            case 3:
                printStatistics(&myArray);
                break;

            case 4:
                sortArray(&myArray);
                printf("Array sorted successfully.\n");
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}