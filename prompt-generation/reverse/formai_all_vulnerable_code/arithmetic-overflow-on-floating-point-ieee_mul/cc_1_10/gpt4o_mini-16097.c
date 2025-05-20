//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>

// Function Prototypes
void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();
void convertArea();
void convertVolume();
void clearBuffer();

int main() {
    int choice;
    while(1) {
        displayMenu();
        printf("Enter your choice (1-5) or 0 to exit: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                convertArea();
                break;
            case 5:
                convertVolume();
                break;
            case 0:
                printf("Exiting the unit converter. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Unit Converter ===\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Area\n");
    printf("5. Volume\n");
    printf("0. Exit\n");
}

void convertLength() {
    double meters, feet;
    printf("\n-- Length Conversion --\n");
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    printf("Length in feet: %.2lf ft\n", feet);
}

void convertWeight() {
    double kg, pounds;
    printf("\n-- Weight Conversion --\n");
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kg);
    pounds = kg * 2.20462;
    printf("Weight in pounds: %.2lf lbs\n", pounds);
}

void convertTemperature() {
    double celsius, fahrenheit;
    printf("\n-- Temperature Conversion --\n");
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0/5.0) + 32;
    printf("Temperature in Fahrenheit: %.2lf °F\n", fahrenheit);
}

void convertArea() {
    double sq_meters, acres;
    printf("\n-- Area Conversion --\n");
    printf("Enter area in square meters: ");
    scanf("%lf", &sq_meters);
    acres = sq_meters * 0.000247105;
    printf("Area in acres: %.6lf acres\n", acres);
}

void convertVolume() {
    double liters, gallons;
    printf("\n-- Volume Conversion --\n");
    printf("Enter volume in liters: ");
    scanf("%lf", &liters);
    gallons = liters * 0.264172;
    printf("Volume in gallons: %.4lf gallons\n", gallons);
}

void clearBuffer() {
    while(getchar() != '\n');
}