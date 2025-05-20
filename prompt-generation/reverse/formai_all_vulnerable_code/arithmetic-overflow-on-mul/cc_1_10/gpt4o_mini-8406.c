//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void display_wasteland();
int generate_random_number(int min, int max);
void perform_arithmetic_operation(int a, int b, char operation);
void handle_enclave();

int main() {
    srand(time(NULL)); // Seed random number generator
    
    int option = 0;
    int a, b;
    char operation;

    printf("Welcome to the Post-Apocalyptic Wasteland!\n");
    display_wasteland();

    while (1) {
        printf("\nYou can choose to do the following:\n");
        printf("1. Enter two numbers for arithmetic operation\n");
        printf("2. Search for survivors (random number generation)\n");
        printf("3. Hide in an enclave (exit)\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter first number: ");
                scanf("%d", &a);
                
                printf("Enter second number: ");
                scanf("%d", &b);
                
                printf("Choose an operation (+, -, *, /): ");
                scanf(" %c", &operation);
                perform_arithmetic_operation(a, b, operation);
                break;
                
            case 2:
                printf("Searching for survivors...\n");
                int survivors = generate_random_number(0, 100);
                printf("You found %d potential survivors wandering in the wasteland.\n", survivors);
                break;
                
            case 3:
                printf("You have found a safe enclave. Exiting the wasteland...\n");
                handle_enclave();
                exit(0);
                
            default:
                printf("Invalid option! Try again.\n");
                break;
        }
    }

    return 0;
}

// Function to simulate display of a post-apocalyptic wasteland
void display_wasteland() {
    printf("      _.-^-._     \n");
    printf("   .-'       '-.   \n");
    printf("  /             \\  \n");
    printf(" |               | \n");
    printf("  \\             /  \n");
    printf("   '-._______ .-'   \n");
}

// Function to generate a random number between min and max
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to perform arithmetic operations
void perform_arithmetic_operation(int a, int b, char operation) {
    switch (operation) {
        case '+':
            printf("Result of %d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("Result of %d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("Result of %d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            if (b != 0) {
                printf("Result of %d / %d = %.2f\n", a, b, (float)a / b);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
        default:
            printf("Unknown operation! Please choose +, -, *, or /.\n");
            break;
    }
}

// Function to handle exiting the program
void handle_enclave() {
    printf("You are now safe from the dangers of the wasteland...\n");
    printf("Thank you for using the Post-Apocalyptic Calculator!\n");
    printf("Until next time, stay safe!\n");
}