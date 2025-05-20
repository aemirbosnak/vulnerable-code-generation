//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: peaceful
#include <stdio.h>
#include <math.h>

int main() {
    // Define the menu
    const char* menu[] = {
        "1. Addition",
        "2. Subtraction",
        "3. Multiplication",
        "4. Division",
        "5. Square Root",
        "6. Exit",
        0
    };

    // Initialize variables
    int choice = 0;
    double num1 = 0.0, num2 = 0.0;

    // Loop until the user chooses to exit
    while (choice!= 6) {
        // Print the menu
        printf("Scientific Calculator\n");
        printf("Choose an operation:\n");
        for (int i = 0; menu[i]!= 0; i++)
            printf("%d. %s\n", i + 1, menu[i]);

        // Read the user's choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                printf("Result: %.2lf\n", num1 + num2);
                break;

            case 2:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                printf("Result: %.2lf\n", num1 - num2);
                break;

            case 3:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                printf("Result: %.2lf\n", num1 * num2);
                break;

            case 4:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                printf("Result: %.2lf\n", num1 / num2);
                break;

            case 5:
                printf("Enter number: ");
                scanf("%lf", &num1);
                printf("Result: %.2lf\n", sqrt(num1));
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    // Exit the program
    return 0;
}