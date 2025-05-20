//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void neon_glow(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("%c", 247);
    }
    printf("\n");
}

int main()
{
    char operator;
    float num1, num2;

    system("clear");
    neon_glow(50);

    printf("Enter Operator (+, -, *, /, %): ");
    operator = getchar();

    printf("Enter First Number: ");
    scanf("%f", &num1);

    printf("Enter Second Number: ");
    scanf("%f", &num2);

    switch (operator)
    {
        case '+':
            printf("The result is: %.2f", num1 + num2);
            break;
        case '-':
            printf("The result is: %.2f", num1 - num2);
            break;
        case '*':
            printf("The result is: %.2f", num1 * num2);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Cannot divide by zero!");
            }
            else
            {
                printf("The result is: %.2f", num1 / num2);
            }
            break;
        default:
            printf("Invalid operator!");
            break;
    }

    neon_glow(50);

    return 0;
}