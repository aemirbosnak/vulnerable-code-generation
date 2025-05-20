//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPTION_LENGTH 50
#define MAX_CONVERSION_TYPE 20

void displayMenu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n");
    printf("----------------------\n");
    printf("Choose an option (1-4): ");
}

void convertLength() {
    double length;
    char unitFrom[MAX_OPTION_LENGTH], unitTo[MAX_OPTION_LENGTH];
    
    printf("\n--- Length Converter ---\n");
    printf("Enter length: ");
    scanf("%lf", &length);
    
    printf("Convert from (meters, kilometers, miles): ");
    scanf("%s", unitFrom);
    
    printf("Convert to (meters, kilometers, miles): ");
    scanf("%s", unitTo);
    
    if (strcmp(unitFrom, "meters") == 0) {
        if (strcmp(unitTo, "kilometers") == 0) {
            length /= 1000;
        } else if (strcmp(unitTo, "miles") == 0) {
            length /= 1609.34;
        }
    } else if (strcmp(unitFrom, "kilometers") == 0) {
        if (strcmp(unitTo, "meters") == 0) {
            length *= 1000;
        } else if (strcmp(unitTo, "miles") == 0) {
            length /= 1.60934;
        }
    } else if (strcmp(unitFrom, "miles") == 0) {
        if (strcmp(unitTo, "meters") == 0) {
            length *= 1609.34;
        } else if (strcmp(unitTo, "kilometers") == 0) {
            length *= 1.60934;
        }
    } else {
        printf("Invalid length units provided.\n");
        return;
    }
    printf("Converted Length: %.2f %s\n", length, unitTo);
}

void convertWeight() {
    double weight;
    char unitFrom[MAX_OPTION_LENGTH], unitTo[MAX_OPTION_LENGTH];
    
    printf("\n--- Weight Converter ---\n");
    printf("Enter weight: ");
    scanf("%lf", &weight);
    
    printf("Convert from (grams, kilograms, pounds): ");
    scanf("%s", unitFrom);
    
    printf("Convert to (grams, kilograms, pounds): ");
    scanf("%s", unitTo);
    
    if (strcmp(unitFrom, "grams") == 0) {
        if (strcmp(unitTo, "kilograms") == 0) {
            weight /= 1000;
        } else if (strcmp(unitTo, "pounds") == 0) {
            weight /= 453.592;
        }
    } else if (strcmp(unitFrom, "kilograms") == 0) {
        if (strcmp(unitTo, "grams") == 0) {
            weight *= 1000;
        } else if (strcmp(unitTo, "pounds") == 0) {
            weight *= 2.20462;
        }
    } else if (strcmp(unitFrom, "pounds") == 0) {
        if (strcmp(unitTo, "grams") == 0) {
            weight *= 453.592;
        } else if (strcmp(unitTo, "kilograms") == 0) {
            weight /= 2.20462;
        }
    } else {
        printf("Invalid weight units provided.\n");
        return;
    }
    printf("Converted Weight: %.2f %s\n", weight, unitTo);
}

void convertTemperature() {
    double temperature;
    char unitFrom[MAX_OPTION_LENGTH], unitTo[MAX_OPTION_LENGTH];
    
    printf("\n--- Temperature Converter ---\n");
    printf("Enter temperature: ");
    scanf("%lf", &temperature);
    
    printf("Convert from (Celsius, Fahrenheit, Kelvin): ");
    scanf("%s", unitFrom);
    
    printf("Convert to (Celsius, Fahrenheit, Kelvin): ");
    scanf("%s", unitTo);
    
    if (strcmp(unitFrom, "Celsius") == 0) {
        if (strcmp(unitTo, "Fahrenheit") == 0) {
            temperature = (temperature * 9.0 / 5.0) + 32;
        } else if (strcmp(unitTo, "Kelvin") == 0) {
            temperature += 273.15;
        }
    } else if (strcmp(unitFrom, "Fahrenheit") == 0) {
        if (strcmp(unitTo, "Celsius") == 0) {
            temperature = (temperature - 32) * 5.0 / 9.0;
        } else if (strcmp(unitTo, "Kelvin") == 0) {
            temperature = ((temperature - 32) * 5.0 / 9.0) + 273.15;
        }
    } else if (strcmp(unitFrom, "Kelvin") == 0) {
        if (strcmp(unitTo, "Celsius") == 0) {
            temperature -= 273.15;
        } else if (strcmp(unitTo, "Fahrenheit") == 0) {
            temperature = ((temperature - 273.15) * 9.0 / 5.0) + 32;
        }
    } else {
        printf("Invalid temperature units provided.\n");
        return;
    }
    printf("Converted Temperature: %.2f %s\n", temperature, unitTo);
}

int main() {
    int option;
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
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
                printf("Thank you for using the Unit Converter! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}