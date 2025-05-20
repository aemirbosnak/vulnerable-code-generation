//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBER 1000000
#define MAX_OPERATIONS 10

typedef struct operation {
    char op;
    int a, b;
} operation;

operation operations[MAX_OPERATIONS];
int num_operations = 0;

void add_operation(char op, int a, int b) {
    operations[num_operations].op = op;
    operations[num_operations].a = a;
    operations[num_operations].b = b;
    num_operations++;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_NUMBER; i++) {
        int num1 = rand() % 100;
        int num2 = rand() % 100;

        // Generate random operations
        char op;
        switch (rand() % 3) {
            case 0:
                op = '+';
                break;
            case 1:
                op = '-';
                break;
            case 2:
                op = '*';
                break;
        }

        int a = num1;
        int b = num2;

        add_operation(op, a, b);
    }

    // Evaluate operations
    for (int i = 0; i < num_operations; i++) {
        char op = operations[i].op;
        int a = operations[i].a, b = operations[i].b;

        switch (op) {
            case '+':
                printf("%d + %d = %d\n", a, b, a + b);
                break;
            case '-':
                printf("%d - %d = %d\n", a, b, a - b);
                break;
            case '*':
                printf("%d x %d = %d\n", a, b, a * b);
                break;
        }
    }

    return 0;
}