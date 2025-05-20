//FormAI DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>

// function to convert Celsius to Fahrenheit
double convertCtoF(double celsius) {
    return (celsius * 9/5) + 32;
}

// function to convert Fahrenheit to Celsius
double convertFtoC(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// function to convert miles to kilometers
double convertMtoKm(double miles) {
    return miles * 1.60934;
}

// function to convert kilometers to miles
double convertKmtoM(double kilometers) {
    return kilometers / 1.60934;
}

int main() {
    int choice;
    double value;
    
    printf("Welcome to the Unit Converter program!\n\n");
    
    do {
        printf("Please choose an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Kilometers to Miles\n");
        printf("5. Exit\n\n");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Please enter a temperature in Celsius: ");
                scanf("%lf", &value);
                printf("%.2lf Celsius is equivalent to %.2lf Fahrenheit.\n\n", 
                    value, convertCtoF(value));
                break;
            case 2:
                printf("Please enter a temperature in Fahrenheit: ");
                scanf("%lf", &value);
                printf("%.2lf Fahrenheit is equivalent to %.2lf Celsius.\n\n", 
                    value, convertFtoC(value));
                break;
            case 3:
                printf("Please enter a distance in miles: ");
                scanf("%lf", &value);
                printf("%.2lf miles is equivalent to %.2lf kilometers.\n\n", 
                    value, convertMtoKm(value));
                break;
            case 4:
                printf("Please enter a distance in kilometers: ");
                scanf("%lf", &value);
                printf("%.2lf kilometers is equivalent to %.2lf miles.\n\n", 
                    value, convertKmtoM(value));
                break;
            case 5:
                printf("Thank you for using the Unit Converter program!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}