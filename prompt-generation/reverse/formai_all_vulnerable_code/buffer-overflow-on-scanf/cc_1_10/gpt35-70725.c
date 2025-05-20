//FormAI DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    float temperature;
    char original_unit[10], converted_unit[10];

    printf("Welcome to the futuristic temperature converter!\n");
    printf("Please enter your temperature value:\n");
    scanf("%f", &temperature);

    printf("Please enter the original unit of your temperature (C, F, or K):\n");
    scanf("%s", original_unit);

    printf("Please enter the unit to which you would like to convert your temperature (C, F, or K):\n");
    scanf("%s", converted_unit);

    if (strcmp(original_unit, "C") == 0) {
        if (strcmp(converted_unit, "F") == 0) {
            temperature = (temperature * 9/5) + 32;
            printf("Your converted temperature is %.2f%s.\n", temperature, converted_unit);
        }
        else if (strcmp(converted_unit, "K") == 0) {
            temperature = temperature + 273.15;
            printf("Your converted temperature is %.2f%s.\n", temperature, converted_unit);
        }
        else {
            printf("Your original and converted units are the same. Temperature remains unchanged: %.2f%s.\n", temperature, original_unit);
        }
    }
    else if (strcmp(original_unit, "F") == 0) {
        if (strcmp(converted_unit, "C") == 0) {
            temperature = (temperature - 32) * 5/9;
            printf("Your converted temperature is %.2f%s.\n", temperature, converted_unit);
        }
        else if (strcmp(converted_unit, "K") == 0) {
            temperature = (temperature - 32) * 5/9 + 273.15;
            printf("Your converted temperature is %.2f%s.\n", temperature, converted_unit);
        }
        else {
            printf("Your original and converted units are the same. Temperature remains unchanged: %.2f%s.\n", temperature, original_unit);
        }
    }
    else if (strcmp(original_unit, "K") == 0) {
        if (strcmp(converted_unit, "C") == 0) {
            temperature = temperature - 273.15;
            printf("Your converted temperature is %.2f%s.\n", temperature, converted_unit);
        }
        else if (strcmp(converted_unit, "F") == 0) {
            temperature = (temperature - 273.15) * 9/5 + 32;
            printf("Your converted temperature is %.2f%s.\n", temperature, converted_unit);
        }
        else {
            printf("Your original and converted units are the same. Temperature remains unchanged: %.2f%s.\n", temperature, original_unit);
        }
    }
    else {
        printf("I'm sorry, the original unit you entered is invalid. Please try again.\n");
    }

    return 0;
}