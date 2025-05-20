//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generate_random_data(int* data, int size);
void print_data(int* data, int size);
double calculate_average(int* data, int size);

int main(int argc, char** argv) {
    int size = 1000000;
    int* data = (int*) malloc(size * sizeof(int));

    srand(time(0));
    generate_random_data(data, size);

    double start_time = difftime(time(0), 0);
    double end_time;

    for (int i = 0; i < 10; i++) {
        end_time = difftime(time(0), 0);
        double elapsed_time = end_time - start_time;
        double average = calculate_average(data, size);
        printf("Iteration %d: Average = %.2f, Elapsed time = %.2f seconds\n", i + 1, average, elapsed_time);
    }

    free(data);
    return 0;
}

void generate_random_data(int* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 1000;
    }
}

void print_data(int* data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

double calculate_average(int* data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return (double) sum / size;
}