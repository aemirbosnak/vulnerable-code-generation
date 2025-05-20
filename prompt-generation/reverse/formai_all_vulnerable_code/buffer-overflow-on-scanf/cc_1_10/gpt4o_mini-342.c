//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>

void convertTemperature();
void convertLength();
void convertWeight();
void convertVolume();

int main() {
    int choice;
    
    while (1) {
        printf("\n🎉 Welcome to the Universal Unit Converter! 🚀\n");
        printf("Choose an option to convert:\n");
        printf("1. Temperature\n");
        printf("2. Length\n");
        printf("3. Weight\n");
        printf("4. Volume\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                convertTemperature();
                break;
            case 2:
                convertLength();
                break;
            case 3:
                convertWeight();
                break;
            case 4:
                convertVolume();
                break;
            case 5:
                printf("Thank you for using the Unit Converter! Goodbye! 🎈\n");
                return 0;
            default:
                printf("😕 Invalid choice, please try again!\n");
        }
    }
}

void convertTemperature() {
    float celsius, fahrenheit;
    printf("\n🧊 Temperature Conversion 🧊\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose an option: ");
    
    int option;
    scanf("%d", &option);
    
    if (option == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9/5) + 32;
        printf("🌡️ %.2f °C is %.2f °F\n", celsius, fahrenheit);
    } else if (option == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5/9;
        printf("🌡️ %.2f °F is %.2f °C\n", fahrenheit, celsius);
    } else {
        printf("😕 Invalid option!\n");
    }
}

void convertLength() {
    float meters, kilometers, miles;
    printf("\n📏 Length Conversion 📏\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Miles to Kilometers\n");
    printf("Choose an option: ");
    
    int option;
    scanf("%d", &option);
    
    if (option == 1) {
        printf("Enter length in Meters: ");
        scanf("%f", &meters);
        kilometers = meters / 1000;
        printf("🛤️ %.2f M is %.2f KM\n", meters, kilometers);
    } else if (option == 2) {
        printf("Enter length in Kilometers: ");
        scanf("%f", &kilometers);
        meters = kilometers * 1000;
        printf("🛤️ %.2f KM is %.2f M\n", kilometers, meters);
    } else if (option == 3) {
        printf("Enter length in Miles: ");
        scanf("%f", &miles);
        kilometers = miles * 1.60934;
        printf("🛣️ %.2f Miles is %.2f KM\n", miles, kilometers);
    } else {
        printf("😕 Invalid option!\n");
    }
}

void convertWeight() {
    float kilograms, pounds;
    printf("\n⚖️ Weight Conversion ⚖️\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Choose an option: ");
    
    int option;
    scanf("%d", &option);
    
    if (option == 1) {
        printf("Enter weight in Kilograms: ");
        scanf("%f", &kilograms);
        pounds = kilograms * 2.20462;
        printf("🥩 %.2f Kg is %.2f lbs\n", kilograms, pounds);
    } else if (option == 2) {
        printf("Enter weight in Pounds: ");
        scanf("%f", &pounds);
        kilograms = pounds / 2.20462;
        printf("🥩 %.2f lbs is %.2f Kg\n", pounds, kilograms);
    } else {
        printf("😕 Invalid option!\n");
    }
}

void convertVolume() {
    float liters, gallons;
    printf("\n💧 Volume Conversion 💧\n");
    printf("1. Liters to Gallons\n");
    printf("2. Gallons to Liters\n");
    printf("Choose an option: ");
    
    int option;
    scanf("%d", &option);
    
    if (option == 1) {
        printf("Enter volume in Liters: ");
        scanf("%f", &liters);
        gallons = liters / 3.78541;
        printf("🌊 %.2f L is %.2f Gallons\n", liters, gallons);
    } else if (option == 2) {
        printf("Enter volume in Gallons: ");
        scanf("%f", &gallons);
        liters = gallons * 3.78541;
        printf("🌊 %.2f Gallons is %.2f L\n", gallons, liters);
    } else {
        printf("😕 Invalid option!\n");
    }
}