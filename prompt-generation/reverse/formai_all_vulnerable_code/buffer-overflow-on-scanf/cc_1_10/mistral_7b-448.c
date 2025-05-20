//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define ARRAY_SIZE 100

typedef struct {
    int value;
    bool is_positive;
} Element;

Element array[ARRAY_SIZE];

void read_array(void) {
    srand(time(NULL));
    printf("Enter %d integers or press Enter to generate random numbers:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        scanf("%d", &array[i].value);
        if (feof(stdin)) {
            array[i].is_positive = false;
            break;
        }
        array[i].is_positive = array[i].value > 0;
    }
}

int sum_positive_integers(void) {
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (array[i].is_positive) {
            sum += array[i].value;
        }
    }
    return sum;
}

void print_sum_average(int sum, float average) {
    printf("\nSum of positive integers: %d\n", sum);
    printf("Average of positive integers: %.2f\n", average);
}

int main(void) {
    clock_t begin = clock();

    read_array();

    int sum = sum_positive_integers();
    float average;
    if (sum == 0) {
        printf("There are no positive integers in the array.\n");
    } else {
        average = (float) sum / ARRAY_SIZE;
        print_sum_average(sum, average);
    }

    clock_t end = clock();
    double elapsed_time = (end - begin) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    return 0;
}