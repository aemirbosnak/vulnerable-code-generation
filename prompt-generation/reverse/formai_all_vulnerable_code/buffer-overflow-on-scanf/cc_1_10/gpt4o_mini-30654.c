//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>

void display_welcome_message() {
    printf("****************************************\n");
    printf("          WELCOME TO UNIT CONVERTER     \n");
    printf("****************************************\n");
}

void display_menu() {
    printf("Choose an option to convert:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Pounds to Kilograms\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
    printf("7. Exit\n");
}

float meters_to_feet(float meters) {
    return meters * 3.28084;
}

float feet_to_meters(float feet) {
    return feet / 3.28084;
}

float kilograms_to_pounds(float kg) {
    return kg * 2.20462;
}

float pounds_to_kilograms(float lbs) {
    return lbs / 2.20462;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    int choice = 0;
    float input_value, converted_value;

    display_welcome_message();

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program. Thank you!\n");
            break;
        }

        printf("Enter value for conversion: ");
        scanf("%f", &input_value);

        switch (choice) {
            case 1:
                converted_value = meters_to_feet(input_value);
                printf("%.2f Meters = %.2f Feet\n", input_value, converted_value);
                break;

            case 2:
                converted_value = feet_to_meters(input_value);
                printf("%.2f Feet = %.2f Meters\n", input_value, converted_value);
                break;

            case 3:
                converted_value = kilograms_to_pounds(input_value);
                printf("%.2f Kilograms = %.2f Pounds\n", input_value, converted_value);
                break;

            case 4:
                converted_value = pounds_to_kilograms(input_value);
                printf("%.2f Pounds = %.2f Kilograms\n", input_value, converted_value);
                break;

            case 5:
                converted_value = celsius_to_fahrenheit(input_value);
                printf("%.2f Celsius = %.2f Fahrenheit\n", input_value, converted_value);
                break;

            case 6:
                converted_value = fahrenheit_to_celsius(input_value);
                printf("%.2f Fahrenheit = %.2f Celsius\n", input_value, converted_value);
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }

        printf("\n");
    }

    return 0;
}