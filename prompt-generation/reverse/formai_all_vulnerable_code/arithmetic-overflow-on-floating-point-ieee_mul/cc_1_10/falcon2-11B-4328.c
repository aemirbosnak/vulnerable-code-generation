//Falcon2-11B DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
#include <stdio.h>

int main() {
    char celsiusOrFahrenheit;
    float temp;
    float celsius;
    float fahrenheit;
    
    printf("Welcome to the Temperature Converter!\n");
    
    do {
        printf("Please enter the temperature unit you want to use: \n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("Enter 1 or 2: ");
        scanf("%c", &celsiusOrFahrenheit);
        
        switch (celsiusOrFahrenheit) {
            case '1':
                printf("You have selected Celsius!\n");
                break;
            case '2':
                printf("You have selected Fahrenheit!\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
        
        printf("Please enter the temperature you want to convert: \n");
        scanf("%f", &temp);
        
        switch (celsiusOrFahrenheit) {
            case '1':
                celsius = temp;
                fahrenheit = (celsius * 9 / 5) + 32;
                printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
                break;
            case '2':
                fahrenheit = temp;
                celsius = (fahrenheit - 32) * 5 / 9;
                printf("The temperature in Celsius is: %.2f\n", celsius);
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
        
        printf("Do you want to convert another temperature? (y/n): ");
        scanf("%c", &celsiusOrFahrenheit);
        if (celsiusOrFahrenheit!= 'y') {
            printf("Thank you for using the Temperature Converter!\n");
            break;
        }
    } while (celsiusOrFahrenheit == 'y');
    
    return 0;
}