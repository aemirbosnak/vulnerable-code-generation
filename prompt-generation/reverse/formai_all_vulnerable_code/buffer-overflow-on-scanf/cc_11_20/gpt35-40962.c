//FormAI DATASET v1.0 Category: Unit converter ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

int main()
{
    float value;
    char option;
    
    printf("Welcome to the Unit Converter!\n");
    printf("What would you like to convert today?\n\n");
    
    printf("a. Celsius to Fahrenheit\n");
    printf("b. Fahrenheit to Celsius\n");
    printf("c. Miles to Kilometers\n");
    printf("d. Kilometers to Miles\n");
    printf("e. Inches to Centimeters\n");
    printf("f. Centimeters to Inches\n");
    printf("g. Pounds to Kilograms\n");
    printf("h. Kilograms to Pounds\n");
    printf("i. Feet to Meters\n");
    printf("j. Meters to Feet\n\n");
    
    printf("Enter your option:");
    scanf("%c", &option);

    switch(option)
    {
        case 'a':
        {
            printf("\nEnter the temperature in Celsius:");
            scanf("%f", &value);
            printf("\nThe temperature in Fahrenheit is %.2f\n", (value * 9/5) + 32);
            break;
        }
        case 'b':
        {
            printf("\nEnter the temperature in Fahrenheit:");
            scanf("%f", &value);
            printf("\nThe temperature in Celsius is %.2f\n", (value - 32) * 5/9);
            break;
        }
        case 'c':
        {
            printf("\nEnter the distance in miles:");
            scanf("%f", &value);
            printf("\nThe distance in kilometers is %.2f\n", value * 1.60934);
            break;
        }
        case 'd':
        {
            printf("\nEnter the distance in kilometers:");
            scanf("%f", &value);
            printf("\nThe distance in miles is %.2f\n", value * 0.621371);
            break;
        }
        case 'e':
        {
            printf("\nEnter the length in inches:");
            scanf("%f", &value);
            printf("\nThe length in centimeters is %.2f\n", value * 2.54);
            break;
        }
        case 'f':
        {
            printf("\nEnter the length in centimeters:");
            scanf("%f", &value);
            printf("\nThe length in inches is %.2f\n", value / 2.54);
            break;
        }
        case 'g':
        {
            printf("\nEnter the weight in pounds:");
            scanf("%f", &value);
            printf("\nThe weight in kilograms is %.2f\n", value * 0.453592);
            break;
        }
        case 'h':
        {
            printf("\nEnter the weight in kilograms:");
            scanf("%f", &value);
            printf("\nThe weight in pounds is %.2f\n", value * 2.20462);
            break;
        }
        case 'i':
        {
            printf("\nEnter the length in feet:");
            scanf("%f", &value);
            printf("\nThe length in meters is %.2f\n", value * 0.3048);
            break;
        }
        case 'j':
        {
            printf("\nEnter the length in meters:");
            scanf("%f", &value);
            printf("\nThe length in feet is %.2f\n", value * 3.28084);
            break;
        }
        default:
        {
            printf("Invalid option! Please try again.\n");
            break;
        }
    }
    return 0;
}