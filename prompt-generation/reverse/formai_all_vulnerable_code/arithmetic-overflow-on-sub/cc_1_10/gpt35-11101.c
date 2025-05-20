//FormAI DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000000 // the maximum number of integers to be generated
#define MAX_VALUE 100 // the maximum value that an integer can have

int generate_random_numbers(int *numbers, int max_numbers, int max_value);
int compute_average(int *numbers, int max_numbers);
int sort_numbers(int *numbers, int max_numbers);

int main() {
    int numbers[MAX_NUMBERS];
    int num_numbers;
    clock_t start_time, end_time;
    double cpu_time_used;

    num_numbers = generate_random_numbers(numbers, MAX_NUMBERS, MAX_VALUE);

    start_time = clock();
    int avg = compute_average(numbers, num_numbers);
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Average: %d\n", avg);
    printf("Time taken to compute average: %f seconds\n", cpu_time_used);

    start_time = clock();
    sort_numbers(numbers, num_numbers);
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted numbers: ");
    for (int i = 0; i < num_numbers; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("Time taken to sort numbers: %f seconds\n", cpu_time_used);

    return 0;
}

int generate_random_numbers(int *numbers, int max_numbers, int max_value) {
    srand(time(NULL));
    int num_numbers = rand() % max_numbers + 1;
    for (int i = 0; i < num_numbers; i++) {
        numbers[i] = rand() % max_value + 1;
    }
    return num_numbers;
}

int compute_average(int *numbers, int max_numbers) {
    int sum = 0;
    for (int i = 0; i < max_numbers; i++) {
        sum += numbers[i];
    }
    return sum/max_numbers;
}

int sort_numbers(int *numbers, int max_numbers) {
    int i, j, temp;
    for (i = 0; i < max_numbers - 1; i++) {
        for (j = 0; j < max_numbers - i - 1; j++) {
            if (numbers[j] > numbers[j+1]) {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    return 0;
}