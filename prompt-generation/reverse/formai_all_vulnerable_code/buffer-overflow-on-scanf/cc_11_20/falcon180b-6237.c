//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[10];
    int choice;
    double value;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the unit you want to convert:\n");
    scanf("%s", input);

    tolower(input[0]);

    printf("Please enter the value you want to convert:\n");
    scanf("%lf", &value);

    printf("Please enter the unit you want to convert to:\n");
    scanf("%s", input);

    tolower(input[0]);

    printf("Please enter your choice:\n");
    printf("1. Length\n2. Weight\n3. Volume\n4. Temperature\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(strcmp(input, "meters") == 0) {
                printf("%lf meters is equal to %lf feet.\n", value, value * 3.28084);
            } else if(strcmp(input, "feet") == 0) {
                printf("%lf feet is equal to %lf meters.\n", value, value / 3.28084);
            } else {
                printf("Invalid unit.\n");
            }
            break;
        case 2:
            if(strcmp(input, "kilograms") == 0) {
                printf("%lf kilograms is equal to %lf pounds.\n", value, value * 2.20462);
            } else if(strcmp(input, "pounds") == 0) {
                printf("%lf pounds is equal to %lf kilograms.\n", value, value / 2.20462);
            } else {
                printf("Invalid unit.\n");
            }
            break;
        case 3:
            if(strcmp(input, "liters") == 0) {
                printf("%lf liters is equal to %lf gallons.\n", value, value * 0.264172);
            } else if(strcmp(input, "gallons") == 0) {
                printf("%lf gallons is equal to %lf liters.\n", value, value / 0.264172);
            } else {
                printf("Invalid unit.\n");
            }
            break;
        case 4:
            if(strcmp(input, "celsius") == 0) {
                printf("%lf degrees Celsius is equal to %lf degrees Fahrenheit.\n", value, (value * 9/5) + 32);
            } else if(strcmp(input, "fahrenheit") == 0) {
                printf("%lf degrees Fahrenheit is equal to %lf degrees Celsius.\n", value, (value - 32) * 5/9);
            } else {
                printf("Invalid unit.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}