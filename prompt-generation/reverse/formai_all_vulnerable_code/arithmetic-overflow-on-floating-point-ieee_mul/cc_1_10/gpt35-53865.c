//FormAI DATASET v1.0 Category: Temperature Converter ; Style: thoughtful
#include<stdio.h>

double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main() {
    double temperature = 0.0;
    int choice = 0;
    
    printf("Temperature Converter\n");
    printf("=====================\n");
    
    do {
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
      
        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2lfC = %.2lfF\n\n", temperature, celsius_to_fahrenheit(temperature));
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("%.2lfF = %.2lfC\n\n", temperature, fahrenheit_to_celsius(temperature));
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please select again.\n\n");
                break;
        }
      
    } while(choice != 3);
    
    return 0;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}