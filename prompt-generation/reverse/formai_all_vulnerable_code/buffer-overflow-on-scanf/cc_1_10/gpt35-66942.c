//FormAI DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Display menu options
    printf("Welcome to C Unit Converter!\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Feet to Meters\n");
    printf("4. Meters to Feet\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    
    // Prompt user for menu selection
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    // Define variables for conversions
    float f, c, feet, meters, pounds, kilograms;
    
    // Perform conversion based on user's choice
    switch(choice)
    {
        case 1:
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%f", &f);
            c = (f - 32) * 5/9;
            printf("\n%.2f degrees Fahrenheit is %.2f degrees Celsius\n", f, c);
            break;
            
        case 2:
            printf("\nEnter temperature in Celsius: ");
            scanf("%f", &c);
            f = (c * 9/5) + 32;
            printf("\n%.2f degrees Celsius is %.2f degrees Fahrenheit\n", c, f);
            break;
            
        case 3:
            printf("\nEnter length in feet: ");
            scanf("%f", &feet);
            meters = feet / 3.281;
            printf("\n%.2f feet is %.2f meters\n", feet, meters);
            break;
            
        case 4:
            printf("\nEnter length in meters: ");
            scanf("%f", &meters);
            feet = meters * 3.281;
            printf("\n%.2f meters is %.2f feet\n", meters, feet);
            break;
            
        case 5:
            printf("\nEnter weight in pounds: ");
            scanf("%f", &pounds);
            kilograms = pounds / 2.205;
            printf("\n%.2f pounds is %.2f kilograms\n", pounds, kilograms);
            break;
            
        case 6:
            printf("\nEnter weight in kilograms: ");
            scanf("%f", &kilograms);
            pounds = kilograms * 2.205;
            printf("\n%.2f kilograms is %.2f pounds\n", kilograms, pounds);
            break;
            
        default:
            printf("\nInvalid choice. Please try again.\n");
    }
    
    return 0;
}