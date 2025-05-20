//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100
#define PI 3.141592653589793

void generate_random_numbers(float numbers[], int size);
void display_numbers(const float numbers[], int size);
float calculate_mean(const float numbers[], int size);
float calculate_variance(const float numbers[], int size, float mean);
float calculate_standard_deviation(float variance);
void calculate_histogram(const float numbers[], int size);

int main() {
    srand(time(0)); // Seed the random number generator

    float numbers[MAX_SIZE];
    int size;

    printf("Welcome to the Magical Math Realm!\n");
    printf("Please enter the number of magical floating point numbers you want to generate (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    if(size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please run the program again and enter a valid number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    generate_random_numbers(numbers, size);
    printf("\nHere are your magical numbers:\n");
    display_numbers(numbers, size);

    float mean = calculate_mean(numbers, size);
    printf("\nThe mystical mean of these numbers is: %.2f\n", mean);

    float variance = calculate_variance(numbers, size, mean);
    printf("The enchanting variance of these numbers is: %.2f\n", variance);

    float stddev = calculate_standard_deviation(variance);
    printf("The illusionary standard deviation is: %.2f\n", stddev);

    printf("\nNow, let's create a beautiful histogram out of your numbers!\n");
    calculate_histogram(numbers, size);

    printf("\nThank you for visiting the Magical Math Realm! Until next time!\n");
    return 0;
}

void generate_random_numbers(float numbers[], int size) {
    for (int i = 0; i < size; i++) {
        numbers[i] = ((float)rand() / RAND_MAX) * 100; // Generate numbers between 0 and 100
    }
}

void display_numbers(const float numbers[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");
}

float calculate_mean(const float numbers[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

float calculate_variance(const float numbers[], int size, float mean) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(numbers[i] - mean, 2);
    }
    return sum / size;
}

float calculate_standard_deviation(float variance) {
    return sqrt(variance);
}

void calculate_histogram(const float numbers[], int size) {
    int histogram[10] = {0}; // Array to hold the count of ranges

    for (int i = 0; i < size; i++) {
        int index = (int)(numbers[i] / 10);
        if (index >= 10) index = 9; // Ensure we don't go out of bounds
        histogram[index]++;
    }

    printf("\nHistogram:\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d - %2d: ", i * 10, i * 10 + 9);
        for (int j = 0; j < histogram[i]; j++) {
            printf("*");
        }
        printf(" (%d)\n", histogram[i]);
    }
}