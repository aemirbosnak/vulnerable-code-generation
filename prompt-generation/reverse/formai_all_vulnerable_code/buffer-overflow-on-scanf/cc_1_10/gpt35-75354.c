//FormAI DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>

/* Conversion factors */
#define KM_PER_MI 1.609344
#define GAL_PER_L 0.264172052
#define KG_PER_LB 0.45359237

/* Function prototypes */
double to_miles(double km);
double to_kilometers(double mi);
double to_gallons(double l);
double to_liters(double gal);
double to_pounds(double kg);
double to_kilograms(double lb);

/* Main function */
int main()
{
    char option;    /* User's option */
    double value;   /* User's input value */

    while (1)   /* The program runs until the user quits */
    {
        printf("Which conversion would you like to perform?\n");
        printf("1. Convert miles to kilometers\n");
        printf("2. Convert kilometers to miles\n");
        printf("3. Convert gallons to liters\n");
        printf("4. Convert liters to gallons\n");
        printf("5. Convert pounds to kilograms\n");
        printf("6. Convert kilograms to pounds\n");
        printf("7. Quit\n");
        printf("Enter an option: ");

        scanf(" %c", &option);

        switch (option)
        {
            case '1':
                printf("Enter the value in miles: ");
                scanf("%lf", &value);
                printf("%.2f miles = %.2f kilometers.\n",
                    value, to_kilometers(value));
                break;

            case '2':
                printf("Enter the value in kilometers: ");
                scanf("%lf", &value);
                printf("%.2f kilometers = %.2f miles.\n",
                    value, to_miles(value));
                break;

            case '3':
                printf("Enter the value in gallons: ");
                scanf("%lf", &value);
                printf("%.2f gallons = %.2f liters.\n",
                    value, to_liters(value));
                break;

            case '4':
                printf("Enter the value in liters: ");
                scanf("%lf", &value);
                printf("%.2f liters = %.2f gallons.\n",
                    value, to_gallons(value));
                break;

            case '5':
                printf("Enter the value in pounds: ");
                scanf("%lf", &value);
                printf("%.2f pounds = %.2f kilograms.\n",
                    value, to_kilograms(value));
                break;

            case '6':
                printf("Enter the value in kilograms: ");
                scanf("%lf", &value);
                printf("%.2f kilograms = %.2f pounds.\n",
                    value, to_pounds(value));
                break;

            case '7':
                return 0;   /* Program terminates */

            default:
                printf("Invalid option. Try again.\n");
                break;
        }

        /* Discard any remaining input */
        while (getchar() != '\n');
    }
}

/* Converts miles to kilometers */
double to_kilometers(double mi)
{
    return mi * KM_PER_MI;
}

/* Converts kilometers to miles */
double to_miles(double km)
{
    return km / KM_PER_MI;
}

/* Converts gallons to liters */
double to_liters(double gal)
{
    return gal * GAL_PER_L;
}

/* Converts liters to gallons */
double to_gallons(double l)
{
    return l / GAL_PER_L;
}

/* Converts pounds to kilograms */
double to_kilograms(double lb)
{
    return lb * KG_PER_LB;
}

/* Converts kilograms to pounds */
double to_pounds(double kg)
{
    return kg / KG_PER_LB;
}