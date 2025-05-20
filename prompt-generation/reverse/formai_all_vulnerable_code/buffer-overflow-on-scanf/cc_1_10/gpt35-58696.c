//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <math.h>

// Function prototypes
void display_menu(void);
void add(float num1, float num2);
void subtract(float num1, float num2);
void multiply(float num1, float num2);
void divide(float num1, float num2);

int main(void)
{
    float num1, num2;
    int choice;

    printf("Welcome to the Paranoid Scientific Calculator!\n\n");

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                add(num1, num2);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                subtract(num1, num2);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                multiply(num1, num2);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%f %f", &num1, &num2);
                divide(num1, num2);
                break;
            case 5:
                printf("Good bye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

void display_menu(void)
{
    printf("Please choose an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
    printf("Choice: ");
}

void add(float num1, float num2)
{
    printf("%.2f + %.2f = %.2f\n\n", num1, num2, num1 + num2);
}

void subtract(float num1, float num2)
{
    printf("%.2f - %.2f = %.2f\n\n", num1, num2, num1 - num2);
}

void multiply(float num1, float num2)
{
    printf("%.2f * %.2f = %.2f\n\n", num1, num2, num1 * num2);
}

void divide(float num1, float num2)
{
    if (num2 == 0) {
        printf("Error: division by zero.\n\n");
    } else {
        printf("%.2f / %.2f = %.2f\n\n", num1, num2, num1 / num2);
    }
}