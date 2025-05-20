//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 1000

void display_menu();
void calculate_average(double *numbers, int count);
void calculate_median(double *numbers, int count);
void calculate_variance(double *numbers, int count);
void calculate_standard_deviation(double *numbers, int count);
void sort_array(double *array, int n);

int main() {
    double numbers[MAX_NUMBERS];
    int count = 0;
    char choice;

    printf("Welcome to the Math Calculation Program!\n");
    printf("You can input up to %d numbers.\n", MAX_NUMBERS);

    // Input loop
    while (count < MAX_NUMBERS) {
        printf("Enter a number (or type 'q' to finish input): ");
        if (scanf("%lf", &numbers[count]) != 1) {
            // Clear the invalid input
            while (getchar() != '\n'); 
            break;
        }
        count++;
    }

    // Display menu and execute based on user choice
    do {
        display_menu();
        choice = getchar();
        while (getchar() != '\n');  // Clear input buffer

        switch (choice) {
            case '1':
                calculate_average(numbers, count);
                break;
            case '2':
                calculate_median(numbers, count);
                break;
            case '3':
                calculate_variance(numbers, count);
                break;
            case '4':
                calculate_standard_deviation(numbers, count);
                break;
            case '5':
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != '5');

    return 0;
}

void display_menu() {
    printf("\nChoose a calculation to perform:\n");
    printf("1. Calculate Average\n");
    printf("2. Calculate Median\n");
    printf("3. Calculate Variance\n");
    printf("4. Calculate Standard Deviation\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

void calculate_average(double *numbers, int count) {
    if (count <= 0) {
        printf("No numbers to calculate the average.\n");
        return;
    }

    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    
    double average = sum / count;
    printf("The average is: %.2lf\n", average);
}

void calculate_median(double *numbers, int count) {
    if (count <= 0) {
        printf("No numbers to calculate the median.\n");
        return;
    }

    sort_array(numbers, count);

    double median;
    if (count % 2 == 0) {
        median = (numbers[count / 2 - 1] + numbers[count / 2]) / 2.0;
    } else {
        median = numbers[count / 2];
    }
    
    printf("The median is: %.2lf\n", median);
}

void calculate_variance(double *numbers, int count) {
    if (count <= 0) {
        printf("No numbers to calculate variance.\n");
        return;
    }

    double sum = 0;
    double average;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    average = sum / count;

    double variance_sum = 0;
    for (int i = 0; i < count; i++) {
        variance_sum += (numbers[i] - average) * (numbers[i] - average);
    }
    
    double variance = variance_sum / count;
    printf("The variance is: %.2lf\n", variance);
}

void calculate_standard_deviation(double *numbers, int count) {
    if (count <= 0) {
        printf("No numbers to calculate standard deviation.\n");
        return;
    }

    double sum = 0;
    double average;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    average = sum / count;

    double variance_sum = 0;
    for (int i = 0; i < count; i++) {
        variance_sum += (numbers[i] - average) * (numbers[i] - average);
    }

    double variance = variance_sum / count;
    double standard_deviation = sqrt(variance);
    printf("The standard deviation is: %.2lf\n", standard_deviation);
}

void sort_array(double *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}