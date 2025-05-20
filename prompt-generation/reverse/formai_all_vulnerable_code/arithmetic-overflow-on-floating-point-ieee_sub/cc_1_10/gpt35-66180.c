//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include<stdio.h>
#include<math.h>

int main()
{
    int choice;
    float num1, num2, result;

    printf("Choose an operation you would like to perform: \n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("5. Sine\n6. Cosine\n7. Tangent\n8. Square Root\n");

    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("The sum of %f and %f is %f.\n", num1, num2, result);
            break;

        case 2:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("%f minus %f equals %f.\n", num1, num2, result);
            break;

        case 3:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("%f multiplied by %f equals %f.\n", num1, num2, result);
            break;

        case 4:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 / num2;
            printf("%f divided by %f equals %f.\n", num1, num2, result);
            break;

        case 5:
            printf("Enter the number: ");
            scanf("%f", &num1);
            result = sin(num1 * 3.14159 / 180);
            printf("The sine of %f is %f.\n", num1, result);
            break;

        case 6:
            printf("Enter the number: ");
            scanf("%f", &num1);
            result = cos(num1 * 3.14159 / 180);
            printf("The cosine of %f is %f.\n", num1, result);
            break;

        case 7:
            printf("Enter the number: ");
            scanf("%f", &num1);
            result = tan(num1 * 3.14159 / 180);
            printf("The tangent of %f is %f.\n", num1, result);
            break;

        case 8:
            printf("Enter the number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("The square root of %f is %f.\n", num1, result);
            break;

        default:
            printf("Invalid input, please try again!\n");
    }

    return 0;
}