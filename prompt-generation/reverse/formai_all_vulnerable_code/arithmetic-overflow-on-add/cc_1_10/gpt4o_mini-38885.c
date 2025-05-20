//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100
#define MIN_NUM 1

// Function prototypes
void paranoid_add(int, int);
void paranoid_subtract(int, int);
void paranoid_multiply(int, int);
void paranoid_divide(int, int);
void paranoid_modulus(int, int);
int get_random_number(int, int);
void display_menu();

int main() {
    int choice, num1, num2;

    srand(time(NULL)); // Seed the random number generator

    while (1) {
        display_menu();
        printf("Enter your choice (1-6, or 0 to exit): ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        if (choice == 0) {
            printf("Exiting the program. Stay vigilant!\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            fprintf(stderr, "Please select a valid option between 1 and 6.\n");
            continue;
        }

        // Generate random numbers if the choice exceeds 5
        if (choice > 5) {
            num1 = get_random_number(MIN_NUM, MAX_NUM);
            num2 = get_random_number(MIN_NUM, MAX_NUM);
            printf("Random numbers generated: %d and %d\n", num1, num2);
        } else {
            printf("Enter two integers for the operation:\n");
            printf("Number 1: ");
            if (scanf("%d", &num1) != 1) {
                fprintf(stderr, "Invalid input! Please enter a number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue;
            }
            printf("Number 2: ");
            if (scanf("%d", &num2) != 1) {
                fprintf(stderr, "Invalid input! Please enter a number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue;
            }
        }

        switch (choice) {
            case 1:
                paranoid_add(num1, num2);
                break;
            case 2:
                paranoid_subtract(num1, num2);
                break;
            case 3:
                paranoid_multiply(num1, num2);
                break;
            case 4:
                paranoid_divide(num1, num2);
                break;
            case 5:
                paranoid_modulus(num1, num2);
                break;
            case 6:
                printf("Option 6 selected! Just trust your instincts.\n");
                // Option for future development...
                break;
            default:
                fprintf(stderr, "Unexpected error occurred! Stay alert!\n");
        }
    }

    return 0;
}

void paranoid_add(int a, int b) {
    int result = a + b;
    printf("Adding %d and %d gives you %d.\n", a, b, result);
    printf("Double-check your calculations; they may be watching!\n");
}

void paranoid_subtract(int a, int b) {
    int result = a - b;
    printf("Subtracting %d from %d gives you %d.\n", b, a, result);
    printf("Are you sure about your answer? Never underestimate them!\n");
}

void paranoid_multiply(int a, int b) {
    int result = a * b;
    printf("Multiplying %d by %d gives you %d.\n", a, b, result);
    printf("Multiplication is a serious business; don't take it lightly!\n");
}

void paranoid_divide(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "The divisor cannot be zero! They're out to get you!\n");
        return;
    }
    float result = (float)a / b;
    printf("Dividing %d by %d gives you %.2f.\n", a, b, result);
    printf("Fractional results can reveal too much—watch your back!\n");
}

void paranoid_modulus(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "The divisor cannot be zero! Double-check your intentions!\n");
        return;
    }
    int result = a % b;
    printf("The modulus of %d and %d is %d.\n", a, b, result);
    printf("Remainders can be deceiving; always confirm your findings!\n");
}

int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void display_menu() {
    printf("\n--- Paranoid Arithmetic Operations ---\n");
    printf("1. Add two numbers\n");
    printf("2. Subtract second number from first\n");
    printf("3. Multiply two numbers\n");
    printf("4. Divide first number by second\n");
    printf("5. Modulus of first number by second\n");
    printf("6. Generate random arithmetic operation (1-5)\n");
    printf("---------------------------------------\n");
}