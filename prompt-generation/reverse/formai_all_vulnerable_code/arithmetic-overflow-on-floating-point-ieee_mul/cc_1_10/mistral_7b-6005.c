//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 80
#define MIN_TEMP -270.0
#define MAX_TEMP 1000.0

void celsius_to_fahrenheit(double celsius) {
    printf("%.2f degrees Celsius is equal to ", celsius);
    printf("%.2f degrees Fahrenheit.\n", (celsius * 9 / 5) + 32);
}

void fahrenheit_to_celsius(double fahrenheit) {
    printf("%.2f degrees Fahrenheit is equal to ", fahrenheit);
    printf("%.2f degrees Celsius.\n", (fahrenheit - 32) * 5 / 9);
}

int main(void) {
    char input[MAX_LINE_LEN];
    double temperature, temp_conversion;
    char *token;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter temperature value in either Celsius or Fahrenheit followed by a space and the unit (C or F):\n");

    while (1) {
        fgets(input, MAX_LINE_LEN, stdin);
        token = strtok(input, " ");

        if (token == NULL) {
            printf("Invalid input! Try again.\n");
            continue;
        }

        temperature = atof(token);

        token = strtok(NULL, " ");

        if (token == NULL) {
            printf("Invalid input! Try again.\n");
            continue;
        }

        if (strcmp(token, "C") == 0) {
            celsius_to_fahrenheit(temperature);
            temp_conversion = temperature;
        } else if (strcmp(token, "F") == 0) {
            fahrenheit_to_celsius(temperature);
            temp_conversion = atof(token);
        } else {
            printf("Invalid unit! Try again.\n");
            continue;
        }

        printf("You have entered temperature value: %.2f %s\n", temp_conversion, token);
        break;
    }

    return 0;
}