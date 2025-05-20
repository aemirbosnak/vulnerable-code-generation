//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBERS 10

typedef enum {
    ADD,
    SUB,
    MUL,
    DIV,
    MODE_SELECT
} operation_t;

typedef struct {
    int number;
    operation_t operation;
} operation_struct_t;

operation_struct_t operations[MAX_OPERATIONS];
int current_operation = 0;

void setup_operations() {
    operations[0].number = 10;
    operations[0].operation = ADD;

    operations[1].number = 20;
    operations[1].operation = SUB;

    operations[2].number = 30;
    operations[2].operation = MUL;

    operations[3].number = 40;
    operations[3].operation = DIV;
}

void execute_operation() {
    if (current_operation < MAX_OPERATIONS) {
        int result = 0;

        switch (operations[current_operation].operation) {
            case ADD:
                result = operations[current_operation].number + get_number();
                break;
            case SUB:
                result = operations[current_operation].number - get_number();
                break;
            case MUL:
                result = operations[current_operation].number * get_number();
                break;
            case DIV:
                result = operations[current_operation].number / get_number();
                break;
        }

        printf("Result: %d\n", result);

        current_operation++;
    }
}

int get_number() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    return number;
}

int main() {
    setup_operations();

    while (1) {
        execute_operation();
    }

    return 0;
}