//FormAI DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>

void displayOptions();
float convertToMeter(int choice, float value);
float convertToCentimeter(int choice, float value);
float convertToInch(int choice, float value);
float convertToFeet(int choice, float value);
float convertToYard(int choice, float value);
float convertToMiles(int choice, float value);

int main()
{
    int choice;
    float value;

    printf("Welcome to the Unit Converter\n");

    do
    {
        displayOptions();
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value in kilometer:");
                scanf("%f", &value);
                printf("%.2f km = %.2f m\n", value, convertToMeter(choice, value));
                break;
            case 2:
                printf("Enter value in meter:");
                scanf("%f", &value);
                printf("%.2f m = %.2f cm\n", value, convertToCentimeter(choice, value));
                break;
            case 3:
                printf("Enter value in centimeter:");
                scanf("%f", &value);
                printf("%.2f cm = %.2f inch\n", value, convertToInch(choice, value));
                break;
            case 4:
                printf("Enter value in inch:");
                scanf("%f", &value);
                printf("%.2f inch = %.2f feet\n", value, convertToFeet(choice, value));
                break;
            case 5:
                printf("Enter value in feet:");
                scanf("%f", &value);
                printf("%.2f feet = %.2f yard\n", value, convertToYard(choice, value));
                break;
            case 6:
                printf("Enter value in kilometers:");
                scanf("%f", &value);
                printf("%.2f miles = %.2f km\n", value, convertToMiles(choice, value));
                break;
            case 7:
                printf("Thank you for using the Unit Converter!\n");
                break;
            default:
                printf("Invalid input! Please try again.\n");
        }
    }
    while(choice != 7);

    return 0;
}

void displayOptions()
{
    printf("\n1. Kilometer to Meter\n");
    printf("2. Meter to Centimeter\n");
    printf("3. Centimeter to Inch\n");
    printf("4. Inch to Feet\n");
    printf("5. Feet to Yard\n");
    printf("6. Miles to Kilometer\n");
    printf("7. Exit\n");
}

float convertToMeter(int choice, float value)
{
    return value * 1000;
}

float convertToCentimeter(int choice, float value)
{
    return value * 100;
}

float convertToInch(int choice, float value)
{
    return value * 2.54;
}

float convertToFeet(int choice, float value)
{
    return value / 12;
}

float convertToYard(int choice, float value)
{
    return value / 3;
}

float convertToMiles(int choice, float value)
{
    return value * 1.60934;
}