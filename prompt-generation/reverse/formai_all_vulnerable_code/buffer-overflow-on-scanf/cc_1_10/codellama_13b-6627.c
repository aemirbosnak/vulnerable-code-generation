//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: satisfied
// Unit converter example program in C

#include <stdio.h>

// Function to convert distance from kilometers to miles
float kmToMiles(float distance) {
    return distance * 0.621371;
}

// Function to convert distance from miles to kilometers
float milesToKm(float distance) {
    return distance / 0.621371;
}

// Function to convert weight from pounds to kilograms
float poundsToKilograms(float weight) {
    return weight * 0.453592;
}

// Function to convert weight from kilograms to pounds
float kilogramsToPounds(float weight) {
    return weight / 0.453592;
}

// Main function to run the program
int main() {
    float distance, weight;
    char unit;

    // Get user input for distance
    printf("Enter the distance: ");
    scanf("%f", &distance);

    // Get user input for unit (km or miles)
    printf("Enter the unit (km or miles): ");
    scanf(" %c", &unit);

    // Convert distance based on unit
    if (unit == 'k' || unit == 'K') {
        distance = kmToMiles(distance);
    } else if (unit == 'm' || unit == 'M') {
        distance = milesToKm(distance);
    } else {
        printf("Invalid unit\n");
        return 1;
    }

    // Get user input for weight
    printf("Enter the weight: ");
    scanf("%f", &weight);

    // Get user input for unit (pounds or kilograms)
    printf("Enter the unit (pounds or kilograms): ");
    scanf(" %c", &unit);

    // Convert weight based on unit
    if (unit == 'p' || unit == 'P') {
        weight = poundsToKilograms(weight);
    } else if (unit == 'k' || unit == 'K') {
        weight = kilogramsToPounds(weight);
    } else {
        printf("Invalid unit\n");
        return 1;
    }

    // Print the converted values
    printf("Distance: %f %s\n", distance, (unit == 'k' || unit == 'K') ? "km" : "miles");
    printf("Weight: %f %s\n", weight, (unit == 'p' || unit == 'P') ? "pounds" : "kilograms");

    return 0;
}