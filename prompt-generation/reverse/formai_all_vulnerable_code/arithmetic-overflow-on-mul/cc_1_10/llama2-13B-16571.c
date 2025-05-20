//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_LEN 100
#define MIN_INPUT_LEN 2

struct input_error {
    char* message;
    int line_number;
};

void check_input(const char* message, int line_number) {
    if (strlen(message) == 0) {
        return;
    }

    printf("Error: %s (%d)\n", message, line_number);
    exit(EXIT_FAILURE);
}

int main() {
    int num1, num2, sum, product, standard_deviation;
    char op[2];

    printf("Enter two numbers: ");
    scanf("%d%c%d", &num1, &op[0], &num2);

    if (op[0] == '+') {
        sum = num1 + num2;
    } else if (op[0] == '-') {
        sum = num1 - num2;
    } else if (op[0] == '*') {
        product = num1 * num2;
    } else if (op[0] == '/') {
        if (num2 == 0) {
            check_input("Division by zero!", __LINE__);
        }
        standard_deviation = num1 / num2;
    } else {
        check_input("Invalid operator!", __LINE__);
    }

    if (standard_deviation == INFINITY) {
        printf("Error: Division by zero! (%d)\n", __LINE__);
        exit(EXIT_FAILURE);
    }

    printf("Sum: %d\nProduct: %d\nStandard Deviation: %f\n", sum, product, standard_deviation);

    return 0;
}