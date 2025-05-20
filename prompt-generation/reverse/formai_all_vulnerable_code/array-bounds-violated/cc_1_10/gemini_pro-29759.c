//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define the constants
    const int MAX_NUM = 100;
    const int MIN_NUM = 1;

    // Get the number of integers to generate
    int num_ints;
    printf("How many integers do you want to generate? ");
    scanf("%d", &num_ints);

    // Generate the integers
    int integers[num_ints];
    for (int i = 0; i < num_ints; i++) {
        integers[i] = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
    }

    // Print the integers
    printf("The integers are:\n");
    for (int i = 0; i < num_ints; i++) {
        printf("%d ", integers[i]);
    }
    printf("\n");

    // Find the sum of the integers
    int sum = 0;
    for (int i = 0; i < num_ints; i++) {
        sum += integers[i];
    }

    // Find the average of the integers
    double average = (double)sum / num_ints;

    // Find the maximum of the integers
    int max = integers[0];
    for (int i = 1; i < num_ints; i++) {
        if (integers[i] > max) {
            max = integers[i];
        }
    }

    // Find the minimum of the integers
    int min = integers[0];
    for (int i = 1; i < num_ints; i++) {
        if (integers[i] < min) {
            min = integers[i];
        }
    }

    // Print the sum, average, maximum, and minimum of the integers
    printf("The sum of the integers is: %d\n", sum);
    printf("The average of the integers is: %f\n", average);
    printf("The maximum of the integers is: %d\n", max);
    printf("The minimum of the integers is: %d\n", min);

    return 0;
}