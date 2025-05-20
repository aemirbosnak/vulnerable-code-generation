//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>

// Function to convert meters to feet
float metersToFeet(float meters) {
    return meters * 3.28084;
}

// Function to convert kilometers to miles
float kilometersToMiles(float kilometers) {
    return kilometers / 1.60934;
}

// Function to convert liters to gallons
float litersToGallons(float liters) {
    return liters / 3.78541;
}

// Function to convert kilograms to pounds
float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

int main() {
    float meters, kilometers, liters, kilograms;
    char choice;

    // Prompt user for input
    printf("Welcome to Sherlock Holmes' Unit Converter!\n");
    printf("Please enter the value you wish to convert:\n");
    printf("1. Meters to Feet\n2. Kilometers to Miles\n3. Liters to Gallons\n4. Kilograms to Pounds\n");
    scanf("%c", &choice);

    // Convert input based on user's choice
    switch (choice) {
        case '1':
            printf("Enter the value in meters:\n");
            scanf("%f", &meters);
            printf("%.2f meters is equal to %.2f feet.\n", meters, metersToFeet(meters));
            break;
        case '2':
            printf("Enter the value in kilometers:\n");
            scanf("%f", &kilometers);
            printf("%.2f kilometers is equal to %.2f miles.\n", kilometers, kilometersToMiles(kilometers));
            break;
        case '3':
            printf("Enter the value in liters:\n");
            scanf("%f", &liters);
            printf("%.2f liters is equal to %.2f gallons.\n", liters, litersToGallons(liters));
            break;
        case '4':
            printf("Enter the value in kilograms:\n");
            scanf("%f", &kilograms);
            printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, kilogramsToPounds(kilograms));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}