//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdbool.h> // Required to use bool variables in C

/* Function Prototypes */
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double base, double exponent);
int factorial(int num);
bool is_valid_operator(char op);
bool is_valid_num(double num);
int get_operator_prec(char op);
double perform_operation(char op, double num1, double num2);
void calculate();

/* Main Function */
int main() {
    printf("Welcome to the Scientific Calculator!\n");
    printf("Please enter your desired calculations.\n");
    // Call the calculate() function to start the program
    calculate();
    return 0;
}

void calculate() {
    double num1, num2, result;
    char op;

    // Ask the user for the first number
    printf("Enter your first number: ");
    scanf("%lf", &num1);

    // Ask the user for the operator they want to use
    printf("Enter the operator you want to use (+,-,*,/,^,!): ");
    scanf(" %c", &op);

    // Check if operator is valid
    if (!is_valid_operator(op)) {
        printf("Invalid operator entered. Please try again.\n");
        calculate();
        return;
    }
    
    // Check if the operator is ! (factorial), as that only requires 1 number
    if (op == '!') {
        // Check if the number entered is valid
        if (!is_valid_num(num1)) {
            printf("Invalid number entered. Please try again.\n");
            calculate();
            return;
        }
        // Calculate the factorial and print the result
        result = factorial(num1);
        printf("Result: %.2f\n", result);
        calculate(); // Ask the user for another calculation
        return;
    }
    
    // Ask the user for the second number
    printf("Enter your second number: ");
    scanf("%lf", &num2);

    // Check if the numbers are valid
    if (!is_valid_num(num1) || !is_valid_num(num2)) {
        printf("Invalid numbers entered. Please try again.\n");
        calculate();
        return;
    }

    // Calculate the result using the selected operator
    result = perform_operation(op, num1, num2);

    // Print the result
    printf("Result: %.2f\n", result);

    // Ask the user if they want to perform another calculation
    char choice;
    printf("Do you want to perform another calculation? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        calculate();
    } else {
        printf("Thank you for using the Scientific Calculator!\n");
        return;
    }
}

/* Function Definitions */
double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    return num1 / num2;
}

double power(double base, double exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int factorial(int num) {
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

bool is_valid_operator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '!');
}

bool is_valid_num(double num) {
    return !(num < 0 && num > -1); // Only allow negative numbers with a decimal point
}

int get_operator_prec(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    } else if (op == '!') {
        return 4;
    } else {
        return 0; // Invalid operator
    }
}

double perform_operation(char op, double num1, double num2) {
    switch(op) {
        case '+':
            return add(num1, num2);
        case '-':
            return subtract(num1, num2);
        case '*':
            return multiply(num1, num2);
        case '/':
            return divide(num1, num2);
        case '^':
            return power(num1, num2);
        default:
            // Invalid operator
            printf("Invalid operator entered. Please try again.\n");
            calculate();
            return 0;
    }
}