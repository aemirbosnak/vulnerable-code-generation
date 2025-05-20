//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_FIB 1000000

int fibonacci[MAX_FIB];

void generate_fibonacci() {
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < MAX_FIB; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

void print_fibonacci(int index) {
    if (index >= MAX_FIB) {
        printf("\n");
        return;
    }

    printf("%4d ", fibonacci[index]);

    if (index % WIDTH == 0) {
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    generate_fibonacci();

    int start_index = rand() % MAX_FIB;
    int end_index = rand() % MAX_FIB;

    if (end_index < start_index) {
        int temp = end_index;
        end_index = start_index;
        start_index = temp;
    }

    int current_index = start_index;

    while (current_index <= end_index) {
        print_fibonacci(current_index);
        current_index++;
    }

    return 0;
}