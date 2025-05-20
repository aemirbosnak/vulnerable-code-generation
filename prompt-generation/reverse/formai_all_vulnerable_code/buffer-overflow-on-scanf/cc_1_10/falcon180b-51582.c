//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_temp[10];
    char unit_temp[3];
    float temp;
    int choice;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please enter the temperature in degrees Celsius or Fahrenheit followed by its unit (C or F): ");
    scanf("%s %s", input_temp, unit_temp);

    // Convert the input temperature to float
    temp = atof(input_temp);

    // Convert Celsius to Fahrenheit
    if (temp < -273.15) {
        printf("Invalid temperature.\n");
        exit(1);
    } else if (unit_temp[0] == 'C') {
        temp = (temp * 9/5) + 32;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n\n", temp, temp);
    }

    // Convert Fahrenheit to Celsius
    else if (unit_temp[0] == 'F') {
        temp = (temp - 32) * 5/9;
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n\n", temp, temp);
    }

    // Menu
    printf("1. Convert another temperature\n");
    printf("2. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            main();
            break;

        case 2:
            exit(0);

        default:
            printf("Invalid choice. Exiting program.\n");
            exit(1);
    }

    return 0;
}