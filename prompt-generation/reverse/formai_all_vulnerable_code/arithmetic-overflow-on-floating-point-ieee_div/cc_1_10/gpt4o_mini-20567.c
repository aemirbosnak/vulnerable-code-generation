//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>

void display_menu() {
    printf("\n");
    printf("********** Unit Converter **********\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
    printf("7. Exit\n");
    printf("************************************\n");
}

double kilometers_to_miles(double km) {
    return km * 0.621371;
}

double miles_to_kilometers(double miles) {
    return miles / 0.621371;
}

double meters_to_feet(double meters) {
    return meters * 3.28084;
}

double feet_to_meters(double feet) {
    return feet / 3.28084;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void perform_conversion(int choice) {
    double input, output;
    
    switch (choice) {
        case 1:
            printf("Enter distance in kilometers: ");
            scanf("%lf", &input);
            output = kilometers_to_miles(input);
            printf("%.2lf kilometers is equal to %.2lf miles\n", input, output);
            break;
        case 2:
            printf("Enter distance in miles: ");
            scanf("%lf", &input);
            output = miles_to_kilometers(input);
            printf("%.2lf miles is equal to %.2lf kilometers\n", input, output);
            break;
        case 3:
            printf("Enter distance in meters: ");
            scanf("%lf", &input);
            output = meters_to_feet(input);
            printf("%.2lf meters is equal to %.2lf feet\n", input, output);
            break;
        case 4:
            printf("Enter distance in feet: ");
            scanf("%lf", &input);
            output = feet_to_meters(input);
            printf("%.2lf feet is equal to %.2lf meters\n", input, output);
            break;
        case 5:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &input);
            output = celsius_to_fahrenheit(input);
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", input, output);
            break;
        case 6:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &input);
            output = fahrenheit_to_celsius(input);
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", input, output);
            break;
        case 7:
            printf("Thank you for using the unit converter. Have a peaceful day!\n");
            break;
        default:
            printf("Invalid choice. Please choose a valid option.\n");
            break;
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 7) {
            perform_conversion(choice);
            break;
        }

        perform_conversion(choice);
    }

    return 0;
}