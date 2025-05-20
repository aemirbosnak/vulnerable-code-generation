//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>
#include <math.h>

void main()
{
    int unit_type;
    float number;
    char operation;

    printf("Enter the unit type (e.g. km, kg, etc.): ");
    scanf("%d", &unit_type);

    printf("Enter the number: ");
    scanf("%f", &number);

    printf("Enter the operation (+, -, *, /, ^): ");
    scanf("%c", &operation);

    switch (unit_type)
    {
        case 1:
            switch (operation)
            {
                case '+':
                    printf("The result is: %.2f km\n", number * 1000);
                    break;
                case '-':
                    printf("The result is: %.2f km\n", number * 1000 - 1000);
                    break;
                case '*':
                    printf("The result is: %.2f km\n", number * 1000 * 1000);
                    break;
                case '/':
                    printf("The result is: %.2f km\n", number * 1000 / 1000);
                    break;
                case '^':
                    printf("The result is: %.2f km\n", number * pow(1000, 2));
                    break;
            }
            break;
        case 2:
            switch (operation)
            {
                case '+':
                    printf("The result is: %.2f kg\n", number * 1000);
                    break;
                case '-':
                    printf("The result is: %.2f kg\n", number * 1000 - 1000);
                    break;
                case '*':
                    printf("The result is: %.2f kg\n", number * 1000 * 1000);
                    break;
                case '/':
                    printf("The result is: %.2f kg\n", number * 1000 / 1000);
                    break;
                case '^':
                    printf("The result is: %.2f kg\n", number * pow(1000, 2));
                    break;
            }
            break;
        default:
            printf("Invalid unit type.\n");
    }

    return;
}