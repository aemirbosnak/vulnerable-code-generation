//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>

void convert_length();
void convert_weight();
void convert_temperature();
void display_menu();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

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
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n******** Unit Converter ********\n");
    printf("1. Convert Length\n");
    printf("2. Convert Weight\n");
    printf("3. Convert Temperature\n");
    printf("4. Exit\n");
}

void convert_length() {
    float meters, kilometers, miles;
    int option;

    printf("\nLength Conversion:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            printf("Enter length in meters: ");
            scanf("%f", &meters);
            kilometers = meters / 1000;
            printf("%.2f meters is %.5f kilometers.\n", meters, kilometers);
            break;
        case 2:
            printf("Enter length in kilometers: ");
            scanf("%f", &kilometers);
            meters = kilometers * 1000;
            printf("%.2f kilometers is %.2f meters.\n", kilometers, meters);
            break;
        case 3:
            printf("Enter length in miles: ");
            scanf("%f", &miles);
            kilometers = miles * 1.60934;
            printf("%.2f miles is %.5f kilometers.\n", miles, kilometers);
            break;
        case 4:
            printf("Enter length in kilometers: ");
            scanf("%f", &kilometers);
            miles = kilometers / 1.60934;
            printf("%.2f kilometers is %.5f miles.\n", kilometers, miles);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void convert_weight() {
    float kilograms, grams, pounds, ounces;
    int option;

    printf("\nWeight Conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            printf("Enter weight in kilograms: ");
            scanf("%f", &kilograms);
            pounds = kilograms * 2.20462;
            printf("%.2f kilograms is %.5f pounds.\n", kilograms, pounds);
            break;
        case 2:
            printf("Enter weight in pounds: ");
            scanf("%f", &pounds);
            kilograms = pounds / 2.20462;
            printf("%.2f pounds is %.5f kilograms.\n", pounds, kilograms);
            break;
        case 3:
            printf("Enter weight in grams: ");
            scanf("%f", &grams);
            ounces = grams / 28.3495;
            printf("%.2f grams is %.5f ounces.\n", grams, ounces);
            break;
        case 4:
            printf("Enter weight in ounces: ");
            scanf("%f", &ounces);
            grams = ounces * 28.3495;
            printf("%.2f ounces is %.5f grams.\n", ounces, grams);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void convert_temperature() {
    float celsius, fahrenheit;
    int option;

    printf("\nTemperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9 / 5) + 32;
            printf("%.2f Celsius is %.2f Fahrenheit.\n", celsius, fahrenheit);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5 / 9;
            printf("%.2f Fahrenheit is %.2f Celsius.\n", fahrenheit, celsius);
            break;
        default:
            printf("Invalid choice!\n");
    }
}