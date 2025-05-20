//FormAI DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>

double convert_to_celsius(double fahrenheit);
double convert_to_fahrenheit(double celsius);
double convert_to_miles(double kilometers);
double convert_to_kilometers(double miles);
void print_menu();

int main() {
    int choice;
    double value, converted_value;
    char option;

    do {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a temperature in Fahrenheit: ");
                scanf("%lf", &value);
                converted_value = convert_to_celsius(value);
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", value, converted_value);
                break;

            case 2:
                printf("Enter a temperature in Celsius: ");
                scanf("%lf", &value);
                converted_value = convert_to_fahrenheit(value);
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", value, converted_value);
                break;

            case 3:
                printf("Enter a distance in kilometers: ");
                scanf("%lf", &value);
                converted_value = convert_to_miles(value);
                printf("%.2lf kilometers is equal to %.2lf miles.\n", value, converted_value);
                break;

            case 4:
                printf("Enter a distance in miles: ");
                scanf("%lf", &value);
                converted_value = convert_to_kilometers(value);
                printf("%.2lf miles is equal to %.2lf kilometers.\n", value, converted_value);
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to convert another unit (y/n)? ");
        scanf(" %c", &option);
    } while(option == 'y' || option == 'Y');

    printf("Thanks for using the unit converter program!\n");

    return 0;
}

void print_menu() {
    printf("\nUnit Converter Menu\n\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("Enter your choice: ");
}

double convert_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double convert_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double convert_to_miles(double kilometers) {
    return kilometers * 0.621371;
}

double convert_to_kilometers(double miles) {
    return miles * 1.60934;
}