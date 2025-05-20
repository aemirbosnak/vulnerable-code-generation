//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 100

void printMenu() {
    printf("\n*** Scientific Calculator ***\n");
    printf("1. Calculate Mean\n");
    printf("2. Calculate Median\n");
    printf("3. Calculate Variance\n");
    printf("4. Calculate Standard Deviation\n");
    printf("5. Exit\n");
    printf("Select an option (1-5): ");
}

double calculateMean(double numbers[], int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum / count;
}

double calculateMedian(double numbers[], int count) {
    // Sort the array
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] > numbers[j]) {
                double temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    if (count % 2 == 0) {
        return (numbers[count / 2 - 1] + numbers[count / 2]) / 2.0;
    } else {
        return numbers[count / 2];
    }
}

double calculateVariance(double numbers[], int count, double mean) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += (numbers[i] - mean) * (numbers[i] - mean);
    }
    return sum / count;
}

double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}

int main() {
    double numbers[MAX_NUMBERS];
    int count = 0;
    int option;
    
    while (1) {
        printMenu();
        scanf("%d", &option);

        if (option == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        if (option < 1 || option > 4) {
            printf("Invalid option. Please select again.\n");
            continue;
        }

        printf("Enter the number of data points (1 to %d): ", MAX_NUMBERS);
        scanf("%d", &count);
        if (count < 1 || count > MAX_NUMBERS) {
            printf("Invalid number of data points. Please enter between 1 and %d.\n", MAX_NUMBERS);
            continue;
        }

        printf("Enter the data points: \n");
        for (int i = 0; i < count; i++) {
            scanf("%lf", &numbers[i]);
        }

        switch (option) {
            case 1: {
                double mean = calculateMean(numbers, count);
                printf("Mean = %.2lf\n", mean);
                break;
            }
            case 2: {
                double median = calculateMedian(numbers, count);
                printf("Median = %.2lf\n", median);
                break;
            }
            case 3: {
                double mean = calculateMean(numbers, count);
                double variance = calculateVariance(numbers, count, mean);
                printf("Variance = %.2lf\n", variance);
                break;
            }
            case 4: {
                double mean = calculateMean(numbers, count);
                double variance = calculateVariance(numbers, count, mean);
                double stddev = calculateStandardDeviation(variance);
                printf("Standard Deviation = %.2lf\n", stddev);
                break;
            }
        }
    }
    return 0;
}