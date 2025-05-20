//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;
    double value, result;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter 'L' to convert length units,\n");
    printf("Enter 'W' to convert weight units,\n");
    printf("Enter 'T' to convert temperature units,\n");
    printf("Enter 'V' to convert volume units,\n");
    printf("Enter 'Q' to quit.\n");

    scanf("%c", &choice);

    while(choice!= 'Q') {
        switch(choice) {
            case 'L':
                printf("Enter the value to convert: ");
                scanf("%lf", &value);
                printf("Enter the unit to convert from (m, cm, mm, km, in, ft, yd): ");
                scanf("%s", &result);
                printf("The converted value is: %.2lf %s\n", value, result);
                break;
            case 'W':
                printf("Enter the value to convert: ");
                scanf("%lf", &value);
                printf("Enter the unit to convert from (kg, g, lb, oz): ");
                scanf("%s", &result);
                printf("The converted value is: %.2lf %s\n", value, result);
                break;
            case 'T':
                printf("Enter the value to convert: ");
                scanf("%lf", &value);
                printf("Enter the unit to convert from (C, F): ");
                scanf("%s", &result);
                if(result == 'C') {
                    printf("The converted value is: %.2lf F\n", (value * 9/5) + 32);
                } else {
                    printf("The converted value is: %.2lf C\n", (value - 32) * 5/9);
                }
                break;
            case 'V':
                printf("Enter the value to convert: ");
                scanf("%lf", &value);
                printf("Enter the unit to convert from (l, ml, fl oz, gal): ");
                scanf("%s", &result);
                printf("The converted value is: %.2lf %s\n", value, result);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Enter 'Q' to quit or any other key to continue: ");
        scanf("%c", &choice);
    }

    printf("Exiting program...\n");

    return 0;
}