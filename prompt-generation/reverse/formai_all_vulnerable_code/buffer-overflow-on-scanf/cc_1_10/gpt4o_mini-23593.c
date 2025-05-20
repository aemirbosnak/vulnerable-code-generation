//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int get_integer() {
    int number;
    char term;

    while (1) {
        printf("Please enter an integer: ");
        if (scanf("%d%c", &number, &term) != 2 || term != '\n') {
            clear_input_buffer();
            printf("Error: Invalid input! Please enter a valid integer.\n");
        } else {
            clear_input_buffer();
            return number;
        }
    }
}

float safe_division(int numerator, int denominator) {
    if (denominator == 0) {
        fprintf(stderr, "Error: Division by zero! The denominator cannot be zero.\n");
        return -1; // Returning -1 to indicate an error
    }
    return (float)numerator / denominator;
}

void display_result(int num1, int num2, float result) {
    if (result != -1) {
        printf("%d divided by %d is %.2f\n", num1, num2, result);
    } else {
        printf("Division could not be performed due to a prior error.\n");
    }
}

int main() {
    int num1, num2;
    float result;

    printf("Welcome to the Division Program!\n");

    num1 = get_integer();
    num2 = get_integer();

    result = safe_division(num1, num2);
    display_result(num1, num2, result);

    printf("Thank you for using the Division Program. Have a great day!\n");
    return 0;
}