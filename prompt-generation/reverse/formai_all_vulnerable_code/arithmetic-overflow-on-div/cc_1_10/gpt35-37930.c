//FormAI DATASET v1.0 Category: Error handling ; Style: unmistakable
#include <stdio.h>

void print_error_message(int error_code) {
    switch(error_code) {
        case 1:
            printf("Error: Division by zero\n");
            break;

        case 2:
            printf("Error: Invalid input\n");
            break;

        case 3:
            printf("Error: Out of memory\n");
            break;

        default:
            printf("Unknown error occurred\n");
            break;
    }
}

int divide_numbers(int dividend, int divisor, int *result) {
    if(divisor == 0) {
        print_error_message(1);
        return 1;
    }

    *result = dividend / divisor;
    return 0;
}

int get_user_input(int *input) {
    printf("Enter a number: ");
    if(scanf("%d", input) != 1) {
        print_error_message(2);
        return 1;
    }

    return 0;
}

int main() {
    int dividend, divisor, quotient;

    int input_error = get_user_input(&dividend);
    if(input_error) {
        return 1;
    }

    input_error = get_user_input(&divisor);
    if(input_error) {
        return 1;
    }

    int divide_error = divide_numbers(dividend, divisor, &quotient);
    if(divide_error) {
        return divide_error;
    }

    printf("%d / %d = %d\n", dividend, divisor, quotient);

    return 0;
}