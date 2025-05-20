//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A funny benchmarking example program */

int main() {
    printf("Welcome to the Benchmarking Program. Let's see who is faster!\n");

    printf("Please enter the number of loops for benchmarking: ");
    int num_loops;
    scanf("%d", &num_loops);

    // random number generator initialization
    srand(time(NULL));

    int sum = 0;
    clock_t start_time = clock();
    for (int i = 0; i < num_loops; i++) {
        int rand_num = rand() % 1000;
        sum += rand_num;
    }
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Looping through %d numbers took %f seconds in C.\n", num_loops, elapsed_time);

    int sum_py = 0;
    start_time = clock();
    for (int i = 0; i < num_loops; i++) {
        int rand_num = rand() % 1000;
        sum_py += rand_num;
    }
    end_time = clock();

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Looping through %d numbers took %f seconds in Python.\n", num_loops, elapsed_time);

    // winner calculation
    printf("And the winner is... ");
    if (sum > sum_py) {
        printf("C! Congratulations!\n");
    } else if (sum < sum_py) {
        printf("Python! Well done!\n");
    } else {
        printf("a draw! How exciting!\n");
    }

    printf("Thanks for benchmarking with us. See you next time!\n");

    return 0;
}