//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surrealist
#include <stdio.h>

float imaginary_part(float num)
{
    return num * 1.5; // surrealism at its finest
}

float real_part(float num)
{
    return num * 2; // reality is just an illusion
}

int main()
{
    printf("Welcome to the Psychedelic Calculator!\n");

    int option;
    float num1;
    float num2;
    float result;

    do {
        printf("\nMENU\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Sinusoidal\n");
        printf("6. Imaginary Part\n");
        printf("7. Real Part\n");
        printf("8. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                printf("\nEnter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                printf("\nEnter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                printf("\nEnter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1 / num2;
                printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
                break;
            case 5:
                printf("\nEnter a number: ");
                scanf("%f", &num1);
                result = sin(num1);
                printf("\nsin(%.2f) = %.2f\n", num1, result);
                break;
            case 6:
                printf("\nEnter a number: ");
                scanf("%f", &num1);
                result = imaginary_part(num1);
                printf("\nImaginary part of %.2f is %.2f\n", num1, result);
                break;
            case 7:
                printf("\nEnter a number: ");
                scanf("%f", &num1);
                result = real_part(num1);
                printf("\nReal part of %.2f is %.2f\n", num1, result);
                break;
            case 8:
                printf("\nExiting the Psychedelic Calculator!\n");
                break;
            default:
                printf("\nInvalid option. Try again.\n");
        }

    } while (option != 8);

    return 0;
}