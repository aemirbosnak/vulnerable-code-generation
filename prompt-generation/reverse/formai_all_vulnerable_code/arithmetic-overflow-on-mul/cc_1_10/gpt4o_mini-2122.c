//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void performArithmetic(int a, int b);
void introspectOperation(const char *operation, int a, int b, int result);
void squareNumber(int number);
void factorial(int num);
int gcd(int a, int b);

int main() {
    int num1, num2;
    char choice;
    
    printf("Welcome to the Introspective Arithmetic Program!\n");
    
    while (1) {
        displayMenu();
        
        printf("Select an option (1-6) or 'q' to quit: ");
        choice = getchar();
        while (getchar() != '\n');  // Clear the input buffer

        if (choice == 'q') {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case '1':
                printf("Enter two integers (e.g., 5 3): ");
                scanf("%d %d", &num1, &num2);
                while (getchar() != '\n');  // Clear the input buffer
                performArithmetic(num1, num2);
                break;
            case '2':
                printf("Enter a number to square: ");
                scanf("%d", &num1);
                while (getchar() != '\n');  // Clear the input buffer
                squareNumber(num1);
                break;
            case '3':
                printf("Enter a number to find its factorial: ");
                scanf("%d", &num1);
                while (getchar() != '\n');  // Clear the input buffer
                factorial(num1);
                break;
            case '4':
                printf("Enter two integers to compute GCD (e.g., 56 98): ");
                scanf("%d %d", &num1, &num2);
                while (getchar() != '\n');  // Clear the input buffer
                printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));
                break;
            case '5':
                printf("Enter two numbers to perform operations: ");
                scanf("%d %d", &num1, &num2);
                while (getchar() != '\n');  // Clear the input buffer
                performArithmetic(num1, num2);
                break;
            case '6':
                printf("Enter two numbers to introspect: ");
                scanf("%d %d", &num1, &num2);
                while (getchar() != '\n');  // Clear the input buffer
                performArithmetic(num1, num2);
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nArithmetic Operations Menu:\n");
    printf("1. Basic Arithmetic Operations (+, -, *, /)\n");
    printf("2. Square a Number\n");
    printf("3. Factorial of a Number\n");
    printf("4. GCD of Two Numbers\n");
    printf("5. Advanced Operations (with introspection)\n");
    printf("6. Introspective Operations\n");
}

void performArithmetic(int a, int b) {
    if (b == 0) {
        printf("Division by zero is not permitted!\n");
        return;
    }

    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    float quotient = (float)a / b;

    printf("\nPerforming arithmetic on %d and %d:\n", a, b);
    introspectOperation("Addition", a, b, sum);
    introspectOperation("Subtraction", a, b, difference);
    introspectOperation("Multiplication", a, b, product);
    // Check for division by zero before performing division
    if (b != 0) {
        introspectOperation("Division", a, b, (int)quotient);
    }
}

void introspectOperation(const char *operation, int a, int b, int result) {
    printf("%s of %d and %d is: %d\n", operation, a, b, result);
    printf("Introspection: The operation '%s' combines two numeric values into a result reflecting their relationship.\n",
           operation);
    
    // Additional insights based on the operation
    if (operation == "Addition") {
        printf("Adding %d increases the value proportionately.\n", b);
    } else if (operation == "Subtraction") {
        printf("Subtracting %d provides a measure of distance between %d and the result.\n", b, a);
    } else if (operation == "Multiplication") {
        printf("Multiplying by %d amplifies %d by the factor of %d.\n", b, a, b);
    } else if (operation == "Division") {
        printf("Dividing %d by %d gives a proportionate relationship and scales the original number down.\n", a, b);
    }
}

void squareNumber(int number) {
    int result = number * number;
    printf("The square of %d is: %d\n", number, result);
    printf("An introspective view: Squaring a number reflects its expanded area of influence on a two-dimensional plane.\n");
}

void factorial(int num) {
    if (num < 0) {
        printf("Factorial of a negative number is undefined.\n");
        return;
    }
    long long result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    printf("The factorial of %d is: %lld\n", num, result);
    printf("Introspection: The factorial operation captures the essence of combinatorial growth.\n");
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}