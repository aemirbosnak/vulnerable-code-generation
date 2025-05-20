//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>

// Function prototypes for conversions
void convert_length();
void convert_weight();
void convert_temperature();
void convert_time();

int main() {
    int choice;

    // Welcome message
    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("Choose the type of conversion you'd like to perform:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Time\n");
    printf("5. Exit Program\n");

    while(1) {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
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
                convert_time();
                break;
            case 5:
                printf("Thank you for using the Ultimate Unit Converter! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose a number between 1 and 5.\n");
        }
    }
}

void convert_length() {
    double meters, feet;

    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084; // Conversion factor
    printf("%.2lf meters is equivalent to %.2lf feet.\n", meters, feet);
}

void convert_weight() {
    double kilograms, pounds;

    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462; // Conversion factor
    printf("%.2lf kilograms is equivalent to %.2lf pounds.\n", kilograms, pounds);
}

void convert_temperature() {
    double celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0/5.0) + 32.0; // Conversion formula
    printf("%.2lf Celsius is equivalent to %.2lf Fahrenheit.\n", celsius, fahrenheit);
}

void convert_time() {
    int seconds, minutes, hours;

    printf("Enter time in seconds: ");
    scanf("%d", &seconds);
    minutes = seconds / 60; // Converting to minutes
    hours = minutes / 60; // Converting to hours
    minutes %= 60; // Remaining minutes after hours
    seconds %= 60; // Remaining seconds after minutes
    
    printf("%d seconds is equivalent to %d hours, %d minutes, and %d seconds.\n", seconds, hours, minutes, seconds);
}