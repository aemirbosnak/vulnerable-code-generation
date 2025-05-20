//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return min + rand() % (max + 1 - min);
}

// Function to get a random number in a given range
double rand_double(double min, double max) {
    return min + (max - min) * (double) rand() / (double) RAND_MAX;
}

// Function to get a random number in a given range with a specified step size
double rand_double_step(double min, double max, double step) {
    double range = max - min;
    int num_steps = range / step;
    return min + step * rand_int(0, num_steps);
}

// Function to get a random number in a given range with a specified number of decimal places
double rand_double_decimals(double min, double max, int decimals) {
    double range = max - min;
    double multiplier = pow(10, decimals);
    return min + range * (double) rand() / (double) RAND_MAX / multiplier;
}

// Function to get a random number in a given range with a specified number of significant digits
double rand_double_sig_figs(double min, double max, int digits) {
    double range = max - min;
    double multiplier = pow(10, digits - 1);
    return min + range * (double) rand() / (double) RAND_MAX / multiplier * multiplier;
}

// Function to get a random number in a given range with a specified probability
double rand_double_probability(double min, double max, double probability) {
    double range = max - min;
    if (probability <= 0 || probability >= 1) {
        return min + rand_double(min, max);
    } else {
        return min + range * (double) rand() / (double) RAND_MAX * probability;
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random number between 0 and 100
    int num1 = rand_int(0, 100);

    // Generate a random double between 0 and 100
    double num2 = rand_double(0, 100);

    // Generate a random number between 0 and 100 with a step size of 5
    double num3 = rand_double_step(0, 100, 5);

    // Generate a random number between 0 and 100 with 2 decimal places
    double num4 = rand_double_decimals(0, 100, 2);

    // Generate a random number between 0 and 100 with 3 significant digits
    double num5 = rand_double_sig_figs(0, 100, 3);

    // Generate a random number between 0 and 100 with a probability of 50%
    double num6 = rand_double_probability(0, 100, 0.5);

    // Print the random numbers
    printf("Random number between 0 and 100: %d\n", num1);
    printf("Random double between 0 and 100: %f\n", num2);
    printf("Random double between 0 and 100 with a step size of 5: %f\n", num3);
    printf("Random double between 0 and 100 with 2 decimal places: %f\n", num4);
    printf("Random double between 0 and 100 with 3 significant digits: %f\n", num5);
    printf("Random double between 0 and 100 with a probability of 50%%: %f\n", num6);

    return 0;
}