//FormAI DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice, source, target;
    float number, result;

    printf("*** Retro Unit Converter ***\n\n");

    // Display available unit conversions
    printf("Choose a conversion:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Speed\n");
    printf("5. Volume\n");
    printf("6. Time\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get user input
    printf("Enter the value to convert: ");
    scanf("%f", &number);
    printf("Enter the source unit code: ");
    scanf("%d", &source);
    printf("Enter the target unit code: ");
    scanf("%d", &target);

    // Perform conversion based on user inputs
    switch(choice)
    {
        case 1: // Length
            if(source == 1 && target == 2) // Convert from meters to feet
                result = number * 3.28084;
            else if(source == 2 && target == 1) // Convert from feet to meters
                result = number / 3.28084;
            else
            {
                printf("Invalid source/target unit combination.\n");
                exit(1);
            }

            printf("%.2f meters is equal to %.2f feet.\n", number, result);
            break;

        case 2: // Weight
            if(source == 1 && target == 2) // Convert from kilograms to pounds
                result = number * 2.20462;
            else if(source == 2 && target == 1) // Convert from pounds to kilograms
                result = number / 2.20462;
            else
            {
                printf("Invalid source/target unit combination.\n");
                exit(1);
            }

            printf("%.2f kilograms is equal to %.2f pounds.\n", number, result);
            break;

        case 3: // Temperature
            if(source == 1 && target == 2) // Convert from Celsius to Fahrenheit
                result = (number * 1.8) + 32;
            else if(source == 2 && target == 1) // Convert from Fahrenheit to Celsius
                result = (number - 32) / 1.8;
            else
            {
                printf("Invalid source/target unit combination.\n");
                exit(1);
            }

            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", number, result);
            break;

        case 4: // Speed
            if(source == 1 && target == 2) // Convert from meters/second to miles/hour
                result = number * 2.23694;
            else if(source == 2 && target == 1) // Convert from miles/hour to meters/second
                result = number / 2.23694;
            else
            {
                printf("Invalid source/target unit combination.\n");
                exit(1);
            }

            printf("%.2f meters/second is equal to %.2f miles/hour.\n", number, result);
            break;

        case 5: // Volume
            if(source == 1 && target == 2) // Convert from liters to gallons
                result = number * 0.264172;
            else if(source == 2 && target == 1) // Convert from gallons to liters
                result = number / 0.264172;
            else
            {
                printf("Invalid source/target unit combination.\n");
                exit(1);
            }

            printf("%.2f liters is equal to %.2f gallons.\n", number, result);
            break;

        case 6: // Time
            if(source == 1 && target == 2) // Convert from seconds to minutes
                result = number / 60;
            else if(source == 2 && target == 1) // Convert from minutes to seconds
                result = number * 60;
            else
            {
                printf("Invalid source/target unit combination.\n");
                exit(1);
            }

            printf("%.2f seconds is equal to %.2f minutes.\n", number, result);
            break;

        default:
            printf("Invalid conversion choice.\n");
            exit(1);
    }

    return 0; 
}