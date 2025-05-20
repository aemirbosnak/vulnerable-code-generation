//FormAI DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

//Conversion constants
#define CM_PER_INCH 2.54
#define INCH_PER_FOOT 12.0
#define CM_PER_METER 100.0
#define CM_PER_YARD 91.44
#define CM_PER_MILE 160934.4

int main(void)
{
    printf("Welcome to the Ultra-Precise Unit Converter!\n");

    int conversion; //Conversion choice
    double value1, value2; //Input values
    double result; //Conversion result

    //Display conversion options
    printf("\nConversion Options:\n");
    printf("1 - Inches to Centimeters\n");
    printf("2 - Feet to Meters\n");
    printf("3 - Yards to Meters\n");
    printf("4 - Miles to Kilometers\n");

    //Get user's conversion choice
    printf("Enter a conversion option (1-4): ");
    scanf("%d", &conversion);

    //Perform conversion based on user's choice
    switch (conversion)
    {
        case 1:
            //Convert inches to centimeters
            printf("Enter a length in inches: ");
            scanf("%lf", &value1);
            result = value1 * CM_PER_INCH;
            printf("%.2lf inches is equal to %.2lf centimeters.\n", value1, result);
            break;

        case 2:
            //Convert feet to meters
            printf("Enter a length in feet: ");
            scanf("%lf", &value1);
            result = value1 / INCH_PER_FOOT * CM_PER_METER;
            printf("%.2lf feet is equal to %.2lf meters.\n", value1, result);
            break;

        case 3:
            //Convert yards to meters
            printf("Enter a length in yards: ");
            scanf("%lf", &value1);
            result = value1 * CM_PER_YARD / CM_PER_METER;
            printf("%.2lf yards is equal to %.2lf meters.\n", value1, result);
            break;

        case 4:
            //Convert miles to kilometers
            printf("Enter a length in miles: ");
            scanf("%lf", &value1);
            result = value1 * CM_PER_MILE / CM_PER_METER / 1000.0;
            printf("%.2lf miles is equal to %.2lf kilometers.\n", value1, result);
            break;

        default:
            printf("Invalid conversion option.\n");
            break;
    }

    return 0;
}