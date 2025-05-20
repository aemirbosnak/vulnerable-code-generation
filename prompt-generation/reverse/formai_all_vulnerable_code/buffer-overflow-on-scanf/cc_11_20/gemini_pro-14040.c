//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Elementary, my dear Watson!
int main() {
    // The case of the perplexing units
    printf("Elementary, my dear Watson!\n");
    printf("Let us embark on a journey of unit conversions.\n\n");

    // The suspects: a motley crew of units
    char unit_from[50], unit_to[50];
    float value, result;

    // The investigation begins: gathering evidence
    printf("State the unit you wish to convert from, my good sir:\n");
    scanf("%s", unit_from);
    printf("And the unit you desire to convert to, my astute friend:\n");
    scanf("%s", unit_to);
    printf("Now, the value you seek to transform, if you would be so kind:\n");
    scanf("%f", &value);

    // The deductions: applying our knowledge
    if (strcmp(unit_from, "inches") == 0 && strcmp(unit_to, "feet") == 0) {
        result = value / 12;
        printf("From inches to feet, the value becomes: %.2f\n", result);
    } else if (strcmp(unit_from, "feet") == 0 && strcmp(unit_to, "inches") == 0) {
        result = value * 12;
        printf("From feet to inches, the value evolves into: %.2f\n", result);
    } else if (strcmp(unit_from, "miles") == 0 && strcmp(unit_to, "kilometers") == 0) {
        result = value * 1.60934;
        printf("From miles to kilometers, the value transforms into: %.2f\n", result);
    } else if (strcmp(unit_from, "kilometers") == 0 && strcmp(unit_to, "miles") == 0) {
        result = value / 1.60934;
        printf("From kilometers to miles, the value transmutes into: %.2f\n", result);
    } else if (strcmp(unit_from, "pounds") == 0 && strcmp(unit_to, "kilograms") == 0) {
        result = value * 0.453592;
        printf("From pounds to kilograms, the value becomes: %.2f\n", result);
    } else if (strcmp(unit_from, "kilograms") == 0 && strcmp(unit_to, "pounds") == 0) {
        result = value / 0.453592;
        printf("From kilograms to pounds, the value evolves into: %.2f\n", result);
    } else if (strcmp(unit_from, "celsius") == 0 && strcmp(unit_to, "fahrenheit") == 0) {
        result = (value * 9 / 5) + 32;
        printf("From Celsius to Fahrenheit, the value transforms into: %.2f\n", result);
    } else if (strcmp(unit_from, "fahrenheit") == 0 && strcmp(unit_to, "celsius") == 0) {
        result = (value - 32) * 5 / 9;
        printf("From Fahrenheit to Celsius, the value transmutes into: %.2f\n", result);
    } else {
        printf("I fear the units you have provided are beyond my current capabilities.\n");
    }

    // The conclusion: presenting our findings
    printf("\nYour conversion, my esteemed colleague, is complete.\n");
    return 0;
}