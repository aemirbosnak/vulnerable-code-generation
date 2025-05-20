//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>

int main()
{
    printf("Welcome to the Math Exercise Program!\n");

    int num1, num2;
    char operation;

    printf("Enter your first number: ");
    scanf("%d", &num1);

    printf("Enter your second number: ");
    scanf("%d", &num2);

    printf("Choose an operation (+, -, *, /): ");
    scanf(" %c", &operation);

    int result;

    switch (operation)
    {
        case '+':
            result = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%d * %d = %d\n", num1, num2, result);
            break;
        case '/':
            result = num1 / num2;
            printf("%d / %d = %d\n", num1, num2, result);
            break;
        default:
            printf("Invalid operation, please try again.\n");
            return 1;
    }

    printf("Now let's do some more math!\n");

    int num3 = 5;
    int num4 = 7;

    printf("Let's find the sum of %d and %d: ", num3, num4);
    int sum = num3 + num4;
    printf("%d\n", sum);

    printf("Let's find the difference of %d and %d: ", num3, num4);
    int diff = num3 - num4;
    printf("%d\n", diff);

    printf("Let's find the product of %d and %d: ", num3, num4);
    int prod = num3 * num4;
    printf("%d\n", prod);

    printf("Let's find the quotient of %d and %d: ", num4, num3);
    int quot = num4 / num3;
    printf("%d\n", quot);

    printf("Now let's do some more advanced math!\n");

    float radius = 3.5;
    float pi = 3.141592;

    printf("Let's find the area of a circle with radius %.2f: ", radius);
    float area = pi * radius * radius;
    printf("%.2f\n", area);

    printf("Let's find the circumference of a circle with radius %.2f: ", radius);
    float circum = 2 * pi * radius;
    printf("%.2f\n", circum);

    printf("Let's find the volume of a sphere with radius %.2f: ", radius);
    float volume = (4 * pi * radius * radius * radius) / 3;
    printf("%.2f\n", volume);

    printf("Thanks for using the Math Exercise Program!\n");

    return 0;
}