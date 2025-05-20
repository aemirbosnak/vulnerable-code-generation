//FormAI DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;
    float celsius, fahrenheit, kelvin;
    
    do{
        system("cls"); // clear console screen
        
        printf("  TEMPERATURE CONVERTER\n");
        printf("---------------------------\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 9/5) + 32;
                printf("Temperature in Fahrenheit: %.2fF", fahrenheit);
                break;
            case '2':
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) * 5/9;
                printf("Temperature in Celsius: %.2fC", celsius);
                break;
            case '3':
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                kelvin = celsius + 273.15;
                printf("Temperature in Kelvin: %.2fK", kelvin);
                break;
            case '4': 
                printf("\nEnter temperature in Kelvin: ");
                scanf("%f", &kelvin);
                celsius = kelvin - 273.15;
                printf("Temperature in Celsius: %.2fC", celsius);
                break;
            default:
                printf("\nInvalid choice! Please try again.");
        }
        
        printf("\n\n");
        system("pause");
        fflush(stdin); // clear input buffer
    } while(choice != '0');
    
    printf("\n\nProgram terminated.");
    return 0;
}