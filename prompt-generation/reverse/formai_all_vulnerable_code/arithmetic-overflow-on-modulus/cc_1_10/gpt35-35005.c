//FormAI DATASET v1.0 Category: Calculator ; Style: bold
#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;
    printf("Welcome to the Bold Calculator!\n\n");

    do {
        printf("Choose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Quit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers separated by a space: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                printf("Enter two numbers separated by a space: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                printf("Enter two numbers separated by a space: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                printf("Enter two numbers separated by a space: ");
                scanf("%f %f", &num1, &num2);
                if (num2 == 0){
                    printf("Cannot divide by zero. Try again.\n");
                    break;
                }
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                break;
            case 5:
                printf("Enter two numbers separated by a space: ");
                scanf("%f %f", &num1, &num2);
                if(num2 == 0){
                    printf("Cannot perform modulus operation with divisor as 0. Try again.\n");
                    break;
                }
                result = ((int)num1 % (int)num2);
                printf("%.2f %% %.2f = %.2f\n", num1, num2, result);
                break;
            case 6:
                printf("Thanks for using the Bold Calculator!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(choice != 6);

    return 0;
}