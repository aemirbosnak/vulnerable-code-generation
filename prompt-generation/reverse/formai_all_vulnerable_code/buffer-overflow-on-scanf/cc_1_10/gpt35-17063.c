//FormAI DATASET v1.0 Category: Unit converter ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to convert celsius to fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert fahrenheit to celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert kilometers to miles
float kilometersToMiles(float kilometers) {
    return kilometers * 0.621371;
}

// Function to convert miles to kilometers
float milesToKilometers(float miles) {
    return miles / 0.621371;
}

int main() {
    int choice;
    float value, result;
    char unit[20];

    printf("Welcome to the Medieval Unit Converter!\n\n");

    do {
        printf("Choose an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kilometers to Miles\n");
        printf("4. Miles to Kilometers\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("\nInvalid choice. Try again.\n\n");
            continue;
        }

        printf("\nEnter value: ");
        scanf("%f", &value);

        switch (choice) {
            case 1:
                printf("Enter unit (C/F): ");
                scanf("%s", unit);

                if (strcmp(unit, "C") == 0 || strcmp(unit, "c") == 0 || strcmp(unit, "Celsius") == 0 || strcmp(unit, "celsius") == 0) {
                    result = celsiusToFahrenheit(value);
                    printf("%.2f Celsius is equal to %.2f Fahrenheit\n\n", value, result);
                } else if (strcmp(unit, "F") == 0 || strcmp(unit, "f") == 0 || strcmp(unit, "Fahrenheit") == 0 || strcmp(unit, "fahrenheit") == 0) {
                    result = value;
                    printf("%.2f Fahrenheit is equal to %.2f Fahrenheit (Did you think backwards? Ha!)\n\n", value, result);
                } else {
                    printf("Invalid unit. Try again.\n\n");
                }
                break;
            case 2:
                printf("Enter unit (C/F): ");
                scanf("%s", unit);

                if (strcmp(unit, "F") == 0 || strcmp(unit, "f") == 0 || strcmp(unit, "Fahrenheit") == 0 || strcmp(unit, "fahrenheit") == 0) {
                    result = fahrenheitToCelsius(value);
                    printf("%.2f Fahrenheit is equal to %.2f Celsius\n\n", value, result);
                } else if (strcmp(unit, "C") == 0 || strcmp(unit, "c") == 0 || strcmp(unit, "Celsius") == 0 || strcmp(unit, "celsius") == 0) {
                    result = value;
                    printf("%.2f Celsius is equal to %.2f Celsius (Not hot enough for you? HA!)\n\n", value, result);
                } else {
                    printf("Invalid unit. Try again.\n\n");
                }
                break;
            case 3:
                printf("Enter unit (K/M): ");
                scanf("%s", unit);

                if (strcmp(unit, "K") == 0 || strcmp(unit, "k") == 0 || strcmp(unit, "Kilometers") == 0 || strcmp(unit, "kilometers") == 0) {
                    result = kilometersToMiles(value);
                    printf("%.2f Kilometers is equal to %.2f Miles\n\n", value, result);
                } else if (strcmp(unit, "M") == 0 || strcmp(unit, "m") == 0 || strcmp(unit, "Miles") == 0 || strcmp(unit, "miles") == 0) {
                    result = value;
                    printf("%.2f Miles is equal to %.2f Miles (Very far, indeed!)\n\n", value, result);
                } else {
                    printf("Invalid unit. Try again.\n\n");
                }
                break;
            case 4:
                printf("Enter unit (K/M): ");
                scanf("%s", unit);

                if (strcmp(unit, "M") == 0 || strcmp(unit, "m") == 0 || strcmp(unit, "Miles") == 0 || strcmp(unit, "miles") == 0) {
                    result = milesToKilometers(value);
                    printf("%.2f Miles is equal to %.2f Kilometers\n\n", value, result);
                } else if (strcmp(unit, "K") == 0 || strcmp(unit, "k") == 0 || strcmp(unit, "Kilometers") == 0 || strcmp(unit, "kilometers") == 0) {
                    result = value;
                    printf("%.2f Kilometers is equal to %.2f Kilometers (Halfway? Oh, the journey is far from over!)\n\n", value, result);
                } else {
                    printf("Invalid unit. Try again.\n\n");
                }
                break;
            case 5:
                printf("Exiting...\n\n");
                break;
        }

    } while (choice != 5);
    
    return 0;
}