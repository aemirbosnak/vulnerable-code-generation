//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>

// Function declarations for temperature conversions
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);

// Function for displaying the menu options
void display_menu() {
    printf("\nTemperature Converter\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Main program execution starts here
int main() {
    int choice;
    float temperature, converted;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                // Calling the conversion function
                converted = celsius_to_fahrenheit(temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, converted);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                // Calling the conversion function
                converted = fahrenheit_to_celsius(temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, converted);
                break;

            case 3:
                printf("Exiting program. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    // Using the conversion formula: F = (C * 9/5) + 32
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    // Using the conversion formula: C = (F - 32) * 5/9
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Additional utility function for input validation
int is_valid_temperature(float temp, int scale) {
    // Scale 1 indicates Celsius, Scale 2 indicates Fahrenheit
    if (scale == 1) {
        return (temp >= -273.15); // Minimum Celsius value
    } else {
        return (temp >= -459.67); // Minimum Fahrenheit value
    }
}

// Enhanced user input handling function
void get_temperature_input(float *temp, int scale) {
    int valid = 0;
    while (!valid) {
        printf("Enter temperature: ");
        scanf("%f", temp);
        valid = is_valid_temperature(*temp, scale);
        if (!valid) {
            printf("Invalid temperature! Please enter a value above absolute zero.\n");
        }
    }
}

// More advanced display function for converting multiple temperatures
void convert_multiple_temperatures(int scale) {
    int n;
    printf("How many temperatures would you like to convert? ");
    scanf("%d", &n);
    float temperatures[n], converted[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter temperature %d: ", i + 1);
        get_temperature_input(&temperatures[i], scale);
    }

    printf("Conversions:\n");
    for (int i = 0; i < n; i++) {
        if (scale == 1) {
            converted[i] = celsius_to_fahrenheit(temperatures[i]);
            printf("%.2f C = %.2f F\n", temperatures[i], converted[i]);
        } else {
            converted[i] = fahrenheit_to_celsius(temperatures[i]);
            printf("%.2f F = %.2f C\n", temperatures[i], converted[i]);
        }
    }
}

// An option to convert multiple temperatures from menu
void handle_conversion_menu() {
    int choice;
    do {
        printf("Choose conversion type:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Back to main menu\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convert_multiple_temperatures(1);
                break;
            case 2:
                convert_multiple_temperatures(2);
                break;
            case 3:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);
}