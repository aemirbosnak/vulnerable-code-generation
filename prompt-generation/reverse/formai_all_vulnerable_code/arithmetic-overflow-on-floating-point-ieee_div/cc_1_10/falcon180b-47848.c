//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert length from meters to feet
double metersToFeet(double meters) {
    return meters * 3.28084;
}

// Function to convert length from feet to meters
double feetToMeters(double feet) {
    return feet / 3.28084;
}

// Function to convert weight from kilograms to pounds
double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

// Function to convert weight from pounds to kilograms
double poundsToKilograms(double pounds) {
    return pounds / 2.20462;
}

// Function to convert volume from liters to gallons
double litersToGallons(double liters) {
    return liters * 0.264172;
}

// Function to convert volume from gallons to liters
double gallonsToLiters(double gallons) {
    return gallons / 0.264172;
}

int main() {
    char unit;
    double value;

    // Get user input
    printf("Enter the unit you want to convert: ");
    scanf("%c", &unit);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    // Convert length
    if (unit =='m' || unit == 'M') {
        printf("%.2lf meters = %.2lf feet\n", value, metersToFeet(value));
    } else if (unit == 'f' || unit == 'F') {
        printf("%.2lf feet = %.2lf meters\n", value, feetToMeters(value));
    } else {
        printf("Invalid unit.\n");
    }

    // Convert weight
    if (unit == 'kg' || unit == 'K') {
        printf("%.2lf kilograms = %.2lf pounds\n", value, kilogramsToPounds(value));
    } else if (unit == 'lb' || unit == 'L') {
        printf("%.2lf pounds = %.2lf kilograms\n", value, poundsToKilograms(value));
    } else {
        printf("Invalid unit.\n");
    }

    // Convert volume
    if (unit == 'l' || unit == 'L') {
        printf("%.2lf liters = %.2lf gallons\n", value, litersToGallons(value));
    } else if (unit == 'gal' || unit == 'G') {
        printf("%.2lf gallons = %.2lf liters\n", value, gallonsToLiters(value));
    } else {
        printf("Invalid unit.\n");
    }

    return 0;
}