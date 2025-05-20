//FormAI DATASET v1.0 Category: Temperature Converter ; Style: intelligent
#include <stdio.h>

void displayMenu();
double celsiusToFahrenheit(double celsius);
double celsiusToKelvin(double celsius);

int main() {
    int choice;
    double celsiusTemp, fahrenheitTemp, kelvinTemp;
    
    do {
        displayMenu(); // display the menu choices
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%lf", &celsiusTemp);
                
                fahrenheitTemp = celsiusToFahrenheit(celsiusTemp);
                printf("\n%.2f Celsius = %.2f Fahrenheit", celsiusTemp, fahrenheitTemp);
                break;
            
            case 2:
                printf("\nEnter temperature in Celsius: ");
                scanf("%lf", &celsiusTemp);
                
                kelvinTemp = celsiusToKelvin(celsiusTemp);
                printf("\n%.2f Celsius = %.2f Kelvin", celsiusTemp, kelvinTemp);
                break;
            
            case 3:
                printf("\nExiting program...\n");
                break;
                
            default:
                printf("\nInvalid choice, please try again.\n");    
        }
        
    } while(choice != 3);
    
    return 0;
}

/*
 * Function to display the menu choices
 */
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Celsius to Kelvin\n");
    printf("3. Exit program\n");
}

/*
 * Function to convert Celsius to Fahrenheit
 */
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

/*
 * Function to convert Celsius to Kelvin
 */
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}