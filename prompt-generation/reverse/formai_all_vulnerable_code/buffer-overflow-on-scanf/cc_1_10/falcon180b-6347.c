//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char *token;
    char *unit = " ";
    double value = 0;
    double result = 0;
    int choice = 0;
    char choice_str[20];

    printf("Enter the value to convert: ");
    scanf("%s", input);

    token = strtok(input, " ");
    while (token!= NULL) {
        strcat(unit, token);
        strcat(unit, " ");
        token = strtok(NULL, " ");
    }

    printf("Enter the unit of measurement: ");
    scanf("%s", unit);

    printf("Enter the unit you want to convert to:\n");
    printf("1. Millimeters\n");
    printf("2. Centimeters\n");
    printf("3. Meters\n");
    printf("4. Kilometers\n");
    printf("5. Inches\n");
    printf("6. Feet\n");
    printf("7. Yards\n");
    printf("8. Miles\n");

    scanf("%s", choice_str);

    switch (choice_str[0]) {
        case '1':
            result = value * 25.4;
            break;
        case '2':
            result = value * 2.54;
            break;
        case '3':
            result = value;
            break;
        case '4':
            result = value / 1000;
            break;
        case '5':
            result = value * 25.4;
            break;
        case '6':
            result = value * 30.48;
            break;
        case '7':
            result = value * 91.44;
            break;
        case '8':
            result = value / 1609.34;
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    printf("%.2f %s is equal to %.2f %s.\n", value, unit, result, choice_str);

    return 0;
}