//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUMBERS 100
#define PI 3.14159265358979323846

// Structure to keep track of the statistics
typedef struct {
    double mean;
    double variance;
    double stddev;
    double min;
    double max;
} Statistics;

// Function prototypes
void generate_numbers(double *numbers, int count);
Statistics calculate_statistics(double *numbers, int count);
void print_numbers(double *numbers, int count);
void print_statistics(Statistics stats);

int main() {
    double numbers[MAX_NUMBERS];
    Statistics stats;
    int n;

    printf("Welcome to the C Math Exercise Program!\n");
    printf("How many random numbers would you like to generate (max %d)? ", MAX_NUMBERS);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_NUMBERS) {
        printf("Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        return EXIT_FAILURE;
    }

    generate_numbers(numbers, n);
    print_numbers(numbers, n);

    stats = calculate_statistics(numbers, n);
    print_statistics(stats);

    return EXIT_SUCCESS;
}

void generate_numbers(double *numbers, int count) {
    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        // Generate numbers in the range [0, 100)
        numbers[i] = (double)(rand() % 10000) / 100.0; // Scale to two decimal places
    }
}

Statistics calculate_statistics(double *numbers, int count) {
    Statistics stats = {0.0, 0.0, 0.0, INFINITY, -INFINITY};
    double sum = 0.0;

    for (int i = 0; i < count; i++) {
        sum += numbers[i];
        if (numbers[i] < stats.min) {
            stats.min = numbers[i];
        }
        if (numbers[i] > stats.max) {
            stats.max = numbers[i];
        }
    }

    stats.mean = sum / count;

    for (int i = 0; i < count; i++) {
        double diff = numbers[i] - stats.mean;
        stats.variance += diff * diff;
    }

    stats.variance /= count;
    stats.stddev = sqrt(stats.variance);

    return stats;
}

void print_numbers(double *numbers, int count) {
    printf("\nGenerated Numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");
}

void print_statistics(Statistics stats) {
    printf("\nStatistics:\n");
    printf("Mean: %.2f\n", stats.mean);
    printf("Variance: %.2f\n", stats.variance);
    printf("Standard Deviation: %.2f\n", stats.stddev);
    printf("Minimum: %.2f\n", stats.min);
    printf("Maximum: %.2f\n", stats.max);
}