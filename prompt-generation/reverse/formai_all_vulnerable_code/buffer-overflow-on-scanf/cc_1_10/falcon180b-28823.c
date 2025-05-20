//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_menu();
void run_benchmark(int num_iterations);

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                run_benchmark(1000000);
                break;
            case 2:
                run_benchmark(10000000);
                break;
            case 3:
                run_benchmark(100000000);
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}

void print_menu() {
    printf("\n");
    printf("Choose a benchmark:\n");
    printf("1. 1,000,000 iterations\n");
    printf("2. 10,000,000 iterations\n");
    printf("3. 100,000,000 iterations\n");
    printf("\n");
}

void run_benchmark(int num_iterations) {
    clock_t start_time = clock();

    for (int i = 0; i < num_iterations; i++) {
        // Do some work
        int a = i * i;
        int b = i * 10;
        int c = a + b;
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n");
    printf("Benchmark completed in %.6f seconds.\n", elapsed_time);
}