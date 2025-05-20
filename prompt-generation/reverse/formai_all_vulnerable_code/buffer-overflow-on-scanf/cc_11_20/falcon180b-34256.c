//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char input[50];
    double value;
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter the value to be converted: ");
    scanf("%s", input);
    printf("Enter the unit of the value: ");
    scanf("%s", input);

    printf("Enter the unit you want to convert to:\n");
    printf("1. Length\n2. Weight\n3. Volume\n4. Temperature\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(strcmp(input, "meters") == 0) {
                value = atof(input);
                printf("%.2f meters = %.2f feet\n", value, value*3.28084);
            } else if(strcmp(input, "feet") == 0) {
                value = atof(input);
                printf("%.2f feet = %.2f meters\n", value, value/3.28084);
            } else {
                printf("Invalid unit.\n");
            }
            break;
        case 2:
            if(strcmp(input, "kilograms") == 0) {
                value = atof(input);
                printf("%.2f kilograms = %.2f pounds\n", value, value*2.20462);
            } else if(strcmp(input, "pounds") == 0) {
                value = atof(input);
                printf("%.2f pounds = %.2f kilograms\n", value, value/2.20462);
            } else {
                printf("Invalid unit.\n");
            }
            break;
        case 3:
            if(strcmp(input, "liters") == 0) {
                value = atof(input);
                printf("%.2f liters = %.2f gallons\n", value, value*0.264172);
            } else if(strcmp(input, "gallons") == 0) {
                value = atof(input);
                printf("%.2f gallons = %.2f liters\n", value, value/0.264172);
            } else {
                printf("Invalid unit.\n");
            }
            break;
        case 4:
            if(strcmp(input, "celsius") == 0) {
                value = atof(input);
                printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value*1.8)+32);
            } else if(strcmp(input, "fahrenheit") == 0) {
                value = atof(input);
                printf("%.2f Fahrenheit = %.2f Celsius\n", value, (value-32)/1.8);
            } else {
                printf("Invalid unit.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}