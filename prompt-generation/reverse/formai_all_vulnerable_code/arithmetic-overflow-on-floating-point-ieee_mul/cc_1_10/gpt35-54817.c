//FormAI DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

float celsius_to_kelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

int main() {
    int choice;
    float celsius, result;
    
    printf("Welcome to Temperature Converter!\n");
    
    do {
        printf("\nPlease select an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Celsius to Kelvin\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                
                result = celsius_to_fahrenheit(celsius);
                
                printf("%.2f degrees Celsius = %.2f degrees Fahrenheit\n", celsius, result);
                break;
                
            case 2:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                
                result = celsius_to_kelvin(celsius);
                
                printf("%.2f degrees Celsius = %.2f degrees Kelvin\n", celsius, result);
                break;
                
            case 3:
                printf("\nThank you for using Temperature Converter!");
                break;
                
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 3);
    
    return 0;
}