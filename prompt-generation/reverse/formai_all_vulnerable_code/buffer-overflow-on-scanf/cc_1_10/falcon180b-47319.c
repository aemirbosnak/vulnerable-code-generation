//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the sum of a series using the power function
double power_sum(int n, double base) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(base, i);
    }
    return sum;
}

// Function to calculate the sum of a series using the logarithm function
double log_sum(int n, double base) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += log(base + i);
    }
    return sum;
}

// Function to calculate the sum of a series using the exponential function
double exp_sum(int n, double base) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += exp(i * base);
    }
    return sum;
}

// Function to calculate the sum of a series using the sine function
double sine_sum(int n, double base) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += sin(i * base);
    }
    return sum;
}

int main() {
    int n, choice;
    double base;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the base value: ");
    scanf("%lf", &base);

    printf("Select the function to use:\n");
    printf("1. Power function\n");
    printf("2. Logarithm function\n");
    printf("3. Exponential function\n");
    printf("4. Sine function\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("The sum of the series using the power function is: %lf\n", power_sum(n, base));
            break;
        case 2:
            printf("The sum of the series using the logarithm function is: %lf\n", log_sum(n, base));
            break;
        case 3:
            printf("The sum of the series using the exponential function is: %lf\n", exp_sum(n, base));
            break;
        case 4:
            printf("The sum of the series using the sine function is: %lf\n", sine_sum(n, base));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}