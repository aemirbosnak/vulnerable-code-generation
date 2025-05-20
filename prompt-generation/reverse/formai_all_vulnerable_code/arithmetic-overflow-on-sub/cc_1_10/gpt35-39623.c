//FormAI DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min_num and max_num
int generate_random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;
    
    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    }
    else
    {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

// Function to sum two numbers using a pointer
void sum_using_pointer(int *num1, int *num2)
{
    int sum = *num1 + *num2;
    printf("The sum of %d and %d is %d\n", *num1, *num2, sum);
}

int main()
{
    int min_num = 1, max_num = 10;
    int num1 = generate_random_number(min_num, max_num);
    int num2 = generate_random_number(min_num, max_num);

    printf("Benchmarking program to measure the time taken to sum two random numbers...\n");

    // Start the timer
    clock_t start = clock();

    // Sum the two numbers
    sum_using_pointer(&num1, &num2);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken to sum the two numbers
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to perform the addition operation: %f seconds\n", time_taken);
    return 0;
}