//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void display_menu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
void generate_random_numbers(int *num1, int *num2);

int main() {
    int choice, num1, num2, result_int;
    float result_float;

    // Seed random number generator
    srand(time(NULL));

    printf("Welcome to the Visionary Arithmetic Program!\n");
    printf("Unleash the power of numbers through a simple interface.\n");
    
    while (1) {
        display_menu();
        printf("Please input your choice (1-5) or 0 to exit: ");
        scanf("%d", &choice);

        // Exit condition
        if (choice == 0) {
            printf("Thank you for using the Visionary Arithmetic Program. Farewell!\n");
            break;
        }

        // Generate random numbers for operations
        generate_random_numbers(&num1, &num2);
        printf("The numbers selected for your operation are: %d and %d\n", num1, num2);
        
        switch (choice) {
            case 1:
                result_int = add(num1, num2);
                printf("The result of %d + %d is: %d\n\n", num1, num2, result_int);
                break;
            case 2:
                result_int = subtract(num1, num2);
                printf("The result of %d - %d is: %d\n\n", num1, num2, result_int);
                break;
            case 3:
                result_int = multiply(num1, num2);
                printf("The result of %d * %d is: %d\n\n", num1, num2, result_int);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Division by zero is not allowed. Please try again.\n\n");
                } else {
                    result_float = divide(num1, num2);
                    printf("The result of %d / %d is: %.2f\n\n", num1, num2, result_float);
                }
                break;
            default:
                printf("Invalid choice. Please select an option between 0 and 5.\n\n");
        }
    }
    
    return 0;
}

void display_menu() {
    printf("--------- Menu ---------\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("0. Exit\n");
    printf("------------------------\n");
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / (float)b;
}

void generate_random_numbers(int *num1, int *num2) {
    *num1 = rand() % 100; // Random number between 0 and 99
    *num2 = rand() % 100; // Random number between 0 and 99
}