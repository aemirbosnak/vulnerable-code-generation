//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char unit[10];
    int choice;
    double temperature;

    // Prompt the user to enter a temperature and its unit
    printf("Enter a temperature and its unit (e.g. 20 C): ");
    scanf("%s %s", input, unit);

    // Remove the unit from the input string
    strcpy(input, strtok(input, " "));

    // Convert the temperature to Celsius
    temperature = atof(input);

    // Convert Celsius to Fahrenheit
    if (choice == 1) {
        temperature = (temperature * 9/5) + 32;
        printf("%s C is %s F.\n", input, input);
    }

    // Convert Celsius to Kelvin
    else if (choice == 2) {
        temperature = temperature + 273.15;
        printf("%s C is %s K.\n", input, input);
    }

    // Convert Fahrenheit to Celsius
    else if (choice == 3) {
        temperature = (temperature - 32) * 5/9;
        printf("%s F is %s C.\n", input, input);
    }

    // Convert Fahrenheit to Kelvin
    else if (choice == 4) {
        temperature = (temperature - 32) * 5/9 + 273.15;
        printf("%s F is %s K.\n", input, input);
    }

    // Convert Kelvin to Celsius
    else if (choice == 5) {
        temperature = temperature - 273.15;
        printf("%s K is %s C.\n", input, input);
    }

    // Convert Kelvin to Fahrenheit
    else if (choice == 6) {
        temperature = (temperature - 273.15) * 9/5 + 32;
        printf("%s K is %s F.\n", input, input);
    }

    // Invalid choice
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}