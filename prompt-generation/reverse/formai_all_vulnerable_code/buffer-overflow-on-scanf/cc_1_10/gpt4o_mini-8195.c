//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_RETRIES 3

void display_welcome();
int get_user_choice();
void perform_operation(int choice);
void add_numbers();
void subtract_numbers();
void multiply_numbers();
void divide_numbers();
void square_root();
void exponentiation();
void clear_buffer();

int main() {
    int choice;

    display_welcome();

    while (1) {
        choice = get_user_choice();
        
        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        
        perform_operation(choice);
    }

    return 0;
}

void display_welcome() {
    printf("=====================================\n");
    printf("         Welcome to Math Mania!     \n");
    printf("=====================================\n");
    printf("Select an operation to perform:\n");
    printf("1. Add numbers\n");
    printf("2. Subtract numbers\n");
    printf("3. Multiply numbers\n");
    printf("4. Divide numbers\n");
    printf("5. Square Root\n");
    printf("6. Exponentiation (a^b)\n");
    printf("0. Exit\n");
}

int get_user_choice() {
    int choice;
    int valid_input = 0;
    int retries = 0;

    while (!valid_input && retries < MAX_RETRIES) {
        printf("Enter your choice (0-6): ");
        int result = scanf("%d", &choice);
        
        if (result == 1 && choice >= 0 && choice <= 6) {
            valid_input = 1;
        } else {
            printf("Invalid input, please enter a number between 0 and 6.\n");
            clear_buffer();
            retries++;
        }
    }

    if (retries == MAX_RETRIES) {
        printf("Too many invalid attempts. Exiting.\n");
        exit(1);
    }

    return choice;
}

void perform_operation(int choice) {
    switch (choice) {
        case 1:
            add_numbers();
            break;
        case 2:
            subtract_numbers();
            break;
        case 3:
            multiply_numbers();
            break;
        case 4:
            divide_numbers();
            break;
        case 5:
            square_root();
            break;
        case 6:
            exponentiation();
            break;
        default:
            printf("Invalid operation selected.\n");
            break;
    }
}

void add_numbers() {
    double num1, num2;
    printf("Enter two numbers to add: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Result: %.2lf\n", num1 + num2);
}

void subtract_numbers() {
    double num1, num2;
    printf("Enter two numbers to subtract: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Result: %.2lf\n", num1 - num2);
}

void multiply_numbers() {
    double num1, num2;
    printf("Enter two numbers to multiply: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Result: %.2lf\n", num1 * num2);
}

void divide_numbers() {
    double num1, num2;
    printf("Enter two numbers to divide (numerator denominator): ");
    scanf("%lf %lf", &num1, &num2);
    if (num2 != 0) {
        printf("Result: %.2lf\n", num1 / num2);
    } else {
        printf("Error: Division by zero!\n");
    }
}

void square_root() {
    double num;
    printf("Enter a number to find the square root: ");
    scanf("%lf", &num);
    if (num >= 0) {
        printf("Square root of %.2lf is: %.2lf\n", num, sqrt(num));
    } else {
        printf("Error: Cannot calculate the square root of a negative number!\n");
    }
}

void exponentiation() {
    double base, exponent;
    printf("Enter base and exponent (base^exponent): ");
    scanf("%lf %lf", &base, &exponent);
    printf("Result: %.2lf\n", pow(base, exponent));
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}