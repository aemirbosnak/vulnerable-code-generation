//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// The main function, where the program starts
int main()
{
    // Calculate the time that has passed before the program began
    time_t time_before_program = time(NULL);

    // Seed the random number generator
    srand(time_before_program);

    // Initialize the variables
    double x = 0;
    double y = 0;
    double z = 0;
    double w = 0;
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;

    // Generate random numbers for the variables
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z = (double)rand() / RAND_MAX;
    w = (double)rand() / RAND_MAX;
    a = (double)rand() / RAND_MAX;
    b = (double)rand() / RAND_MAX;
    c = (double)rand() / RAND_MAX;
    d = (double)rand() / RAND_MAX;

    // Print the variables
    printf("x = %f\n", x);
    printf("y = %f\n", y);
    printf("z = %f\n", z);
    printf("w = %f\n", w);
    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("c = %f\n", c);
    printf("d = %f\n", d);

    // Calculate the time that has passed after the program began
    time_t time_after_program = time(NULL);

    // Print the time that has passed
    printf("Time passed: %ld seconds\n", time_after_program - time_before_program);

    // Return 0 to indicate that the program has run successfully
    return 0;
}