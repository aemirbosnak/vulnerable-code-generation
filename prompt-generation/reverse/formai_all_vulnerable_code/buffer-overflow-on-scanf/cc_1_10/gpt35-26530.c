//FormAI DATASET v1.0 Category: Unit converter ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

void display_menu() {
    printf("Welcome to the unit converter.\n");
    printf("Please select an option:\n");
    printf("1. Convert meters to feet\n");
    printf("2. Convert pounds to kilograms\n");
    printf("3. Convert Celsius to Fahrenheit\n");
    printf("4. Convert kilometers to miles\n");
    printf("5. Quit\n");
}

int get_user_input() {
    int option;
    printf("Enter your option: ");
    scanf("%d", &option);
    return option;
}

void convert_meters_to_feet() {
    float meters, feet;
    printf("Enter the value in meters: ");
    scanf("%f", &meters);
    feet = meters * 3.28084;
    printf("%f meters is equal to %f feet.\n", meters, feet);
}

void convert_pounds_to_kilograms() {
    float pounds, kilograms;
    printf("Enter the value in pounds: ");
    scanf("%f", &pounds);
    kilograms = pounds * 0.453592;
    printf("%f pounds is equal to %f kilograms.\n", pounds, kilograms);
}

void convert_celsius_to_fahrenheit() {
    float celsius, fahrenheit;
    printf("Enter the value in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 1.8) + 32.0;
    printf("%f Celsius is equal to %f Fahrenheit.\n", celsius, fahrenheit);
}

void convert_kilometers_to_miles() {
    float kilometers, miles;
    printf("Enter the value in kilometers: ");
    scanf("%f", &kilometers);
    miles = kilometers * 0.621371;
    printf("%f kilometers is equal to %f miles.\n", kilometers, miles);
}

int main() {
    int option;
    
    while(1) {
        display_menu();
        option = get_user_input();
        
        switch(option) {
            case 1:
                convert_meters_to_feet();
                break;
            case 2:
                convert_pounds_to_kilograms();
                break;
            case 3:
                convert_celsius_to_fahrenheit();
                break;
            case 4:
                convert_kilometers_to_miles();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}