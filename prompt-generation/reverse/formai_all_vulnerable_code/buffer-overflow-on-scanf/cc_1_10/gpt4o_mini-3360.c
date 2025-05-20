//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>

#define KG_TO_LBS 2.20462
#define LBS_TO_KG 0.453592
#define M_TO_FT 3.28084
#define FT_TO_M 0.3048
#define C_TO_F 1.8
#define F_TO_C 0.555556

void display_menu() {
    printf("\n======================\n");
    printf("   Unit Converter\n");
    printf("======================\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
    printf("0. Exit\n");
    printf("======================\n");
}

void kilograms_to_pounds() {
    double kg;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kg);
    printf("%.2f kg = %.2f lbs\n", kg, kg * KG_TO_LBS);
}

void pounds_to_kilograms() {
    double lbs;
    printf("Enter weight in pounds: ");
    scanf("%lf", &lbs);
    printf("%.2f lbs = %.2f kg\n", lbs, lbs * LBS_TO_KG);
}

void meters_to_feet() {
    double m;
    printf("Enter distance in meters: ");
    scanf("%lf", &m);
    printf("%.2f m = %.2f ft\n", m, m * M_TO_FT);
}

void feet_to_meters() {
    double ft;
    printf("Enter distance in feet: ");
    scanf("%lf", &ft);
    printf("%.2f ft = %.2f m\n", ft, ft * FT_TO_M);
}

void celsius_to_fahrenheit() {
    double c;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &c);
    printf("%.2f °C = %.2f °F\n", c, (c * C_TO_F) + 32);
}

void fahrenheit_to_celsius() {
    double f;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &f);
    printf("%.2f °F = %.2f °C\n", f, (f - 32) * F_TO_C);
}

int main() {
    int choice;
    
    printf("=== Welcome to the Unit Converter ===\n");
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                kilograms_to_pounds();
                break;
            case 2:
                pounds_to_kilograms();
                break;
            case 3:
                meters_to_feet();
                break;
            case 4:
                feet_to_meters();
                break;
            case 5:
                celsius_to_fahrenheit();
                break;
            case 6:
                fahrenheit_to_celsius();
                break;
            case 0:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}