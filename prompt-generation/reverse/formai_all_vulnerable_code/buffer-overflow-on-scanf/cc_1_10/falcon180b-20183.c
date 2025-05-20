//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 1000000

typedef struct {
    int num;
    int index;
} fib_t;

void generate_fibonacci(int num, int *fib_arr) {
    fib_t *fib_table = (fib_t*)malloc(sizeof(fib_t) * MAX_NUM);
    fib_t *curr_fib = &fib_table[0];
    curr_fib->num = 1;
    curr_fib->index = 0;
    curr_fib = &fib_table[1];
    curr_fib->num = 1;
    curr_fib->index = 1;
    curr_fib = &fib_table[2];
    curr_fib->num = 2;
    curr_fib->index = 2;
    int i = 3;
    while (i < num) {
        curr_fib = &fib_table[i];
        curr_fib->num = fib_table[i-1].num + fib_table[i-2].num;
        curr_fib->index = i;
        i++;
    }
    for (i = 0; i < num; i++) {
        fib_arr[i] = fib_table[i].num;
    }
    free(fib_table);
}

void print_fibonacci(int num, int *fib_arr) {
    int i = 0;
    while (i < num) {
        printf("%d ", fib_arr[i]);
        i++;
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &num);
    int *fib_arr = (int*)malloc(sizeof(int) * num);
    generate_fibonacci(num, fib_arr);
    print_fibonacci(num, fib_arr);
    free(fib_arr);
    return 0;
}