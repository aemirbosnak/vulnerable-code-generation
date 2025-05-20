//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 50
#define MIN_FACTORIAL_VALUE 0

int _fact(int n);
int get_number(char *input, int *index);

int main() {
    char input[MAX_INPUT_SIZE];
    int number, index = 0;

    printf("Enter a non-negative integer: ");
    fgets(input, sizeof(input), stdin);

    if (get_number(input, &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (number < MIN_FACTORIAL_VALUE) {
        printf("Factorial of negative numbers or non-numeric inputs is undefined.\n");
        return 1;
    }

    printf("Factorial of %d = %d\n", number, _fact(number));
    return 0;
}

int _fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * _fact(n - 1);
}

int get_number(char *input, int *number) {
    int i = 0;
    int sign = 1;

    while (isspace(input[i])) i++;

    if (input[i] == '-') {
        sign = -1;
        i++;
    }

    for (; isdigit(input[i]); i++) {
        if (i >= MAX_INPUT_SIZE) {
            printf("Input too long.\n");
            return 0;
        }
        *number = 10 * (*number) + (input[i] - '0');
    }

    if (i > 0) *number *= sign;

    return 1;
}