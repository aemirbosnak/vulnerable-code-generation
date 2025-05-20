//Gemma-7B DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("-------------------------\n");
    printf("Welcome to the Calculator!\n");
    printf("-------------------------\n");
    printf("Please select an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Enter your choice:");
}

int main() {
    int choice;
    float num1, num2;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers:");
                scanf("%f %f", &num1, &num2);
                printf("The result is: %.2f\n", num1 + num2);
                break;
            case 2:
                printf("Enter two numbers:");
                scanf("%f %f", &num1, &num2);
                printf("The result is: %.2f\n", num1 - num2);
                break;
            case 3:
                printf("Enter two numbers:");
                scanf("%f %f", &num1, &num2);
                printf("The result is: %.2f\n", num1 * num2);
                break;
            case 4:
                printf("Enter two numbers:");
                scanf("%f %f", &num1, &num2);
                printf("The result is: %.2f\n", num1 / num2);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}