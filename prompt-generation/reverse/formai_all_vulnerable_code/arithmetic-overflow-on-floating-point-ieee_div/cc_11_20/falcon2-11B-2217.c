//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float input_value;
    int choice;
    char option[20];
    int unit1, unit2;
    
    printf("Welcome to the Unit Converter!\n");
    printf("-----------------------------\n");
    
    while (1) {
        printf("\n1. Convert length from meters to centimeters\n");
        printf("2. Convert length from centimeters to meters\n");
        printf("3. Convert mass from kilograms to grams\n");
        printf("4. Convert mass from grams to kilograms\n");
        printf("5. Convert temperature from Celsius to Fahrenheit\n");
        printf("6. Convert temperature from Fahrenheit to Celsius\n");
        printf("7. Convert pressure from Pascals to kilopascals\n");
        printf("8. Convert pressure from kilopascals to Pascals\n");
        printf("9. Quit\n");
        printf("-----------------------------\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the length in meters: ");
                scanf("%f", &input_value);
                unit1 = 100;
                unit2 = 0;
                break;
            case 2:
                printf("Enter the length in centimeters: ");
                scanf("%f", &input_value);
                unit1 = 0;
                unit2 = 100;
                break;
            case 3:
                printf("Enter the mass in kilograms: ");
                scanf("%f", &input_value);
                unit1 = 1000;
                unit2 = 0;
                break;
            case 4:
                printf("Enter the mass in grams: ");
                scanf("%f", &input_value);
                unit1 = 0;
                unit2 = 1000;
                break;
            case 5:
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &input_value);
                unit1 = -273.15;
                unit2 = 32;
                break;
            case 6:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &input_value);
                unit1 = 32;
                unit2 = -273.15;
                break;
            case 7:
                printf("Enter the pressure in Pascals: ");
                scanf("%f", &input_value);
                unit1 = 0;
                unit2 = 100000;
                break;
            case 8:
                printf("Enter the pressure in kilopascals: ");
                scanf("%f", &input_value);
                unit1 = 100000;
                unit2 = 0;
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option!\n");
                break;
        }
        
        printf("\nConversion result:\n");
        printf("%f %s = %f %s\n", input_value, unit1, (input_value * unit2) / unit1, unit2);
        
        printf("\nPress any key to continue or '9' to quit...\n");
        getchar();
    }
    
    return 0;
}