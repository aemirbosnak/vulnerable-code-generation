//FormAI DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include<stdio.h>

float CelsiusToFahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

float FahrenheitToCelsius(float fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

int main(){
    int menu_choice;
    float temp, converted_temp;
    
    do{
        printf("TEMPERATURE CONVERTER\n\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);
        
        switch(menu_choice){
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temp);
                
                converted_temp = CelsiusToFahrenheit(temp);
                printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n\n", temp, converted_temp);
                break;
                
            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temp);
                
                converted_temp = FahrenheitToCelsius(temp);
                printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n\n", temp, converted_temp);
                break;
                
            case 3:
                printf("\nThank you for using the temperature converter!\n");
                break;
                
            default:
                printf("\nInvalid selection. Please choose a valid option.\n\n");
                break;
        }
    } while(menu_choice != 3);
    
    return 0;
}