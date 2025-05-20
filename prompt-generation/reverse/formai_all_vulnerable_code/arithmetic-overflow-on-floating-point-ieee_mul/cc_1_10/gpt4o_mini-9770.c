//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>

void convert_length();
void convert_weight();
void convert_volume();
void convert_temperature();
void display_menu();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice (1-5, or 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convert_length();
                break;
            case 2:
                convert_weight();
                break;
            case 3:
                convert_volume();
                break;
            case 4:
                convert_temperature();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n=== Unit Converter ===\n");
    printf("1. Convert Length\n");
    printf("2. Convert Weight\n");
    printf("3. Convert Volume\n");
    printf("4. Convert Temperature\n");
    printf("0. Exit\n");
}

void convert_length() {
    float meters, feet, inches;
    printf("Enter length in meters: ");
    scanf("%f", &meters);

    feet = meters * 3.28084;
    inches = meters * 39.3701;

    printf("%.2f meters is equal to %.2f feet or %.2f inches.\n", meters, feet, inches);
}

void convert_weight() {
    float kg, lbs;
    printf("Enter weight in kilograms: ");
    scanf("%f", &kg);

    lbs = kg * 2.20462;

    printf("%.2f kilograms is equal to %.2f pounds.\n", kg, lbs);
}

void convert_volume() {
    float liters, gallons;
    printf("Enter volume in liters: ");
    scanf("%f", &liters);

    gallons = liters * 0.264172;

    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);
}

void convert_temperature() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}