//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

typedef struct {
    int num;
    int index;
} Number;

void generate_fibonacci(int limit, Number arr[], int *size) {
    arr[0].num = 0;
    arr[0].index = 0;
    arr[1].num = 1;
    arr[1].index = 1;
    *size = 2;

    for (int i = 2; i < limit; i++) {
        Number next_num = {0, 0};
        int j = 1;
        while (arr[j - 1].num + arr[j].num <= i) {
            next_num.num = arr[j - 1].num + arr[j].num;
            next_num.index = (arr[j - 1].index * 10) + arr[j].index; // combine indices for visualization purposes
            j++;
        }
        arr[*size] = next_num;
        (*size)++;
    }
}

void print_fibonacci(Number arr[], int size) {
    printf("Fibonacci numbers up to %d:\n", arr[size - 1].num);
    for (int i = 0; i < size; i++) {
        printf("%d (%d)\n", arr[i].num, arr[i].index);
    }
}

void main() {
    srand(time(NULL));
    int limit = rand() % 100 + 1; // generate a random limit between 1 and 100

    Number arr[MAX_NUMBERS];
    int size = 0;

    generate_fibonacci(limit, arr, &size);
    printf("Generated %d Fibonacci numbers.\n", size);

    print_fibonacci(arr, size);
}