//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

#define OP_ADD 0
#define OP_SUB 1
#define OP_MUL 2
#define OP_DIV 3

typedef struct {
    int op;
    int a, b;
} Operation;

int main(int argc, char *argv[]) {
    int i, j;
    Operation *operations;
    double start, end;

    srand(time(NULL));

    operations = (Operation *)malloc(MAX_SIZE * sizeof(Operation));

    for (i = 0; i < MAX_SIZE; i++) {
        operations[i].op = rand() % 4;
        switch (operations[i].op) {
            case OP_ADD:
                operations[i].a = rand() % 1000;
                operations[i].b = rand() % 1000;
                break;
            case OP_SUB:
                operations[i].a = rand() % 1000;
                operations[i].b = rand() % 1000;
                break;
            case OP_MUL:
                operations[i].a = rand() % 1000;
                operations[i].b = rand() % 1000;
                break;
            case OP_DIV:
                operations[i].a = rand() % 1000;
                operations[i].b = rand() % 1000;
                break;
        }
    }

    start = clock();

    for (i = 0; i < MAX_SIZE; i++) {
        switch (operations[i].op) {
            case OP_ADD:
                j = operations[i].a + operations[i].b;
                break;
            case OP_SUB:
                j = operations[i].a - operations[i].b;
                break;
            case OP_MUL:
                j = operations[i].a * operations[i].b;
                break;
            case OP_DIV:
                j = operations[i].a / operations[i].b;
                break;
        }
    }

    end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(operations);

    return 0;
}