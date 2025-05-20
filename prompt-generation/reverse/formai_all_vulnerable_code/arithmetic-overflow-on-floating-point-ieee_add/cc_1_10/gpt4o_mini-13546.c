//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERATIONS 10

void displayWelcomeMessage() {
    printf("********************************************************\n");
    printf("*                 Welcome to the Magical Calculator!    *\n");
    printf("*                                                      *\n");
    printf("*  Here, numbers dance and calculations come alive!    *\n");
    printf("********************************************************\n\n");
}

void getInput(double *a, double *b) {
    printf("Enter the first magical number (a): ");
    scanf("%lf", a);
    printf("Enter the second magical number (b): ");
    scanf("%lf", b);
}

void performArithmeticOperations(double a, double b) {
    printf("\nHere are the results of our mystical calculations:\n");
    printf("---------------------------------------------------\n");
    printf("1. Add them:        a + b = %.2f + %.2f = %.2f\n", a, b, a + b);
    printf("2. Subtract them:   a - b = %.2f - %.2f = %.2f\n", a, b, a - b);
    printf("3. Multiply them:   a * b = %.2f * %.2f = %.2f\n", a, b, a * b);
    
    if (b != 0) {
        printf("4. Divide them:     a / b = %.2f / %.2f = %.2f\n", a, b, a / b);
    } else {
        printf("4. Divide them:     a / b = undefined (cannot divide by zero!)\n");
    }

    printf("5. Modulus them:    a %% b = %.0f %% %.0f = %.0f\n", a, b, (int)a % (int)b);
}

void displayGoodbyeMessage() {
    printf("\nThank you for using the Magical Calculator!\n");
    printf("Remember, numbers have feelings too!\n");
    printf("********************************************************\n");
}

int main() {
    double a, b;
    int operations_count = 0;

    displayWelcomeMessage();

    while (operations_count < MAX_OPERATIONS) {
        getInput(&a, &b);
        performArithmeticOperations(a, b);
        
        operations_count++;
        char choice;
        printf("\nDo you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    displayGoodbyeMessage();
    return 0;
}