//FormAI DATASET v1.0 Category: Unit converter ; Style: funny
#include<stdio.h>

int main()
{
    printf("Welcome to the Wacky Unit Converter!\n");
    
    int menuChoice, conversionChoice;
    float inputValue;
    
    do
    {
        printf("\nWhat would you like to convert today?\n");
        printf("1. Temperature\n");
        printf("2. Length\n");
        printf("3. Weight\n");
        printf("4. Quit\n");
        scanf("%d", &menuChoice);
        
        switch (menuChoice)
        {
            case 1:
                printf("\nWhat temperature is it?\n");
                printf("1. Celsius\n");
                printf("2. Fahrenheit\n");
                scanf("%d", &conversionChoice);
                printf("\nEnter the temperature:\n");
                scanf("%f", &inputValue);
                
                if (conversionChoice == 1)
                {
                    printf("\n%.2f degrees Celsius is equal to %.2f degrees Kelvin and %.2f degrees Fahrenheit.\n", inputValue, inputValue + 273.15, inputValue * 9/5 + 32);
                }
                else if (conversionChoice == 2)
                {
                    printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius and %.2f degrees Kelvin.\n", inputValue, (inputValue - 32) * 5/9, (inputValue - 32) * 5/9 + 273.15);
                }
                break;
            
            case 2:
                printf("\nWhat length do you want to convert?\n");
                printf("1. Centimeters\n");
                printf("2. Inches\n");
                scanf("%d", &conversionChoice);
                printf("\nEnter the length:\n");
                scanf("%f", &inputValue);
                
                if (conversionChoice == 1)
                {
                    printf("\n%.2f centimeters is equal to %.2f inches.\n", inputValue, inputValue / 2.54);
                }
                else if (conversionChoice == 2)
                {
                    printf("\n%.2f inches is equal to %.2f centimeters.\n", inputValue, inputValue * 2.54);
                }
                break;
                
            case 3:
                printf("\nWhat weight do you want to convert?\n");
                printf("1. Kilograms\n");
                printf("2. Pounds\n");
                scanf("%d", &conversionChoice);
                printf("\nEnter the weight:\n");
                scanf("%f", &inputValue);
                
                if (conversionChoice == 1)
                {
                    printf("\n%.2f kilograms is equal to %.2f pounds.\n", inputValue, inputValue * 2.20462);
                }
                else if (conversionChoice == 2)
                {
                    printf("\n%.2f pounds is equal to %.2f kilograms.\n", inputValue, inputValue / 2.20462);
                }
                break;
                
            case 4:
                printf("\nThanks for using the Wacky Unit Converter! Have a nice day!\n");
                break;
                
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
        
    } while (menuChoice != 4);
    
    return 0;
}