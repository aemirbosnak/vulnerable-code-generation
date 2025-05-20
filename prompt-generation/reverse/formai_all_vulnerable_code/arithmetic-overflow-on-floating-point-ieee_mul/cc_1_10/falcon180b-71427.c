//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input[100];
    char output[100];
    char *endptr;
    double num;
    int choice;
    int is_negative = 0;
    int is_invalid = 0;

    // Prompt the user to enter a temperature
    printf("Enter a temperature: ");
    fgets(input, 100, stdin);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) == 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert the input string to a double
    num = strtod(input, &endptr);

    if (endptr == input) {
        printf("Invalid input.\n");
        return 1;
    }

    // Check if the input is negative
    if (num < 0) {
        is_negative = 1;
        num *= -1;
    }

    printf("Choose a temperature scale:\n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n4. Rankine\n");
    scanf("%d", &choice);

    // Convert the temperature to the selected scale
    switch (choice) {
        case 1:
            num += 273.15;
            printf("%.2f degrees Celsius is %.2f degrees Celsius.\n", num, num);
            break;
        case 2:
            num = (num * 9.0 / 5.0) + 32.0;
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", num, num);
            break;
        case 3:
            num += 273.15;
            printf("%.2f degrees Celsius is %.2f Kelvin.\n", num, num);
            break;
        case 4:
            num = (num * 9.0 / 5.0) + 459.67;
            printf("%.2f degrees Celsius is %.2f Rankine.\n", num, num);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    return 0;
}