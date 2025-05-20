//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>

void display_menu() {
    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void perform_conversion(int choice) {
    float input_temp, converted_temp;
    
    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input_temp);
            converted_temp = celsius_to_fahrenheit(input_temp);
            printf("%.2f Celsius is %.2f Fahrenheit\n", input_temp, converted_temp);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input_temp);
            converted_temp = fahrenheit_to_celsius(input_temp);
            printf("%.2f Fahrenheit is %.2f Celsius\n", input_temp, converted_temp);
            break;
        case 3:
            printf("Exiting the program. Have a nice day!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        if (choice == 3) {
            perform_conversion(choice);
            break;
        }
        perform_conversion(choice);
    }

    return 0;
}