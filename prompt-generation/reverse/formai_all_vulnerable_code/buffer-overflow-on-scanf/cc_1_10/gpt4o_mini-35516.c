//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

void convert_length();
void convert_weight();
void convert_temperature();
void display_menu();

int main() {
    int choice;

    printf("Welcome to the Ultimate Unit Converter! 🎉\n");
    
    while (1) {
        display_menu();
        printf("Please select an option (1-4): ");
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
            printf("Invalid choice! Please try again.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                convert_length();
                break;
            case 2:
                convert_weight();
                break;
            case 3:
                convert_temperature();
                break;
            case 4:
                printf("Exiting the converter. Goodbye! 👋\n");
                return 0;
            default:
                printf("Unexpected error! Please choose a valid option.\n");
        }
        printf("\n");
    }

    return 0;
}

void display_menu() {
    printf("\n======== Unit Converter Menu ========\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
    printf("=====================================\n");
}

void convert_length() {
    double meters, feet, inches;

    printf("You chose Length Conversion! 📏\n");
    printf("Enter the length in meters: ");
    scanf("%lf", &meters);
    
    feet = meters * 3.28084;
    inches = meters * 39.3701;

    printf("%.2f meters is equal to:\n", meters);
    printf("%.2f feet\n", feet);
    printf("%.2f inches\n", inches);
}

void convert_weight() {
    double kilograms, pounds, ounces;

    printf("You chose Weight Conversion! ⚖️\n");
    printf("Enter the weight in kilograms: ");
    scanf("%lf", &kilograms);
    
    pounds = kilograms * 2.20462;
    ounces = kilograms * 35.274;

    printf("%.2f kilograms is equal to:\n", kilograms);
    printf("%.2f pounds\n", pounds);
    printf("%.2f ounces\n", ounces);
}

void convert_temperature() {
    double celsius, fahrenheit;

    printf("You chose Temperature Conversion! 🌡️\n");
    printf("Enter the temperature in Celsius: ");
    scanf("%lf", &celsius);
    
    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2f Celsius is equal to:\n", celsius);
    printf("%.2f Fahrenheit\n", fahrenheit);
}