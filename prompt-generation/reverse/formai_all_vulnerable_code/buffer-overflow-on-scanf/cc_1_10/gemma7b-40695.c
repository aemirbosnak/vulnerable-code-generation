//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main()
{
    double d_value, f_value, t_value, k_value, c_value;
    int choice;

    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert meters to kilometers\n");
    printf("2. Convert liters to cubic meters\n");
    printf("3. Convert kilograms to tons\n");
    printf("4. Convert Celsius to Fahrenheit\n");
    printf("5. Convert miles to kilometers\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the number of meters:");
            scanf("%lf", &d_value);
            f_value = d_value * 1000;
            printf("The number of kilometers is: %.2lf\n", f_value);
            break;

        case 2:
            printf("Enter the number of liters:");
            scanf("%lf", &d_value);
            t_value = d_value * 1000;
            printf("The number of cubic meters is: %.2lf\n", t_value);
            break;

        case 3:
            printf("Enter the number of kilograms:");
            scanf("%lf", &d_value);
            k_value = d_value * 1000;
            printf("The number of tons is: %.2lf\n", k_value);
            break;

        case 4:
            printf("Enter the temperature in Celsius:");
            scanf("%lf", &d_value);
            c_value = (d_value * 9.0 / 5.0) + 32.0;
            printf("The temperature in Fahrenheit is: %.2lf\n", c_value);
            break;

        case 5:
            printf("Enter the number of miles:");
            scanf("%lf", &d_value);
            k_value = d_value * 1.613;
            printf("The number of kilometers is: %.2lf\n", k_value);
            break;

        default:
            printf("Invalid selection.\n");
    }

    return 0;
}