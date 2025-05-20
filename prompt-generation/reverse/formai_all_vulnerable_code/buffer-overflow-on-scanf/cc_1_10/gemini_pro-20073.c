//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

    // A warm welcome to our temperature converter!
    printf("Greetings, intrepid temperature adventurer!\n");
    printf("Prepare to embark on a transformative journey where degrees dance and units intertwine.\n");

    // Let's gather the necessary information.
    char input[100];
    double temperature;
    char fromUnit[10];
    char toUnit[10];

    // Prompt the user to input the initial temperature.
    printf("Unveil the initial temperature, oh intrepid one:\n");
    printf("Temperature: ");
    scanf("%lf", &temperature);

    // Now, let's inquire about the units.
    printf("From which realm do these degrees hail?\n");
    printf("Unit (Celsius/Fahrenheit): ");
    scanf("%s", fromUnit);

    // And where shall we transport these degrees?
    printf("To what unit should their essence be transmuted?\n");
    printf("Unit (Celsius/Fahrenheit): ");
    scanf("%s", toUnit);

    // Time to perform the conversion magic.
    double convertedTemperature;
    if (strcmp(fromUnit, "Celsius") == 0) {
        if (strcmp(toUnit, "Fahrenheit") == 0) {
            convertedTemperature = (temperature * 9 / 5) + 32;
        } else if (strcmp(toUnit, "Celsius") == 0) {
            convertedTemperature = temperature;
        } else {
            printf("Hmm, it seems you've stumbled upon an unknown unit. Please choose Celsius or Fahrenheit.\n");
            exit(1);
        }
    } else if (strcmp(fromUnit, "Fahrenheit") == 0) {
        if (strcmp(toUnit, "Celsius") == 0) {
            convertedTemperature = (temperature - 32) * 5 / 9;
        } else if (strcmp(toUnit, "Fahrenheit") == 0) {
            convertedTemperature = temperature;
        } else {
            printf("Hmm, it seems you've stumbled upon an unknown unit. Please choose Celsius or Fahrenheit.\n");
            exit(1);
        }
    } else {
        printf("Hmm, it seems you've stumbled upon an unknown unit. Please choose Celsius or Fahrenheit.\n");
        exit(1);
    }

    // Behold, the result of our alchemical conversion!
    printf("And now, the moment of truth:\n");
    printf("Converted Temperature: %.2f %s\n", convertedTemperature, toUnit);

    // A graceful farewell.
    printf("May your temperature adventures always be enlightening and precise. Farewell, intrepid one!\n");
    
    return 0;
}