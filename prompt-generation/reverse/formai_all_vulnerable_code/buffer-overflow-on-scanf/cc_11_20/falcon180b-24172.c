//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
    float value, result;
    char unit;
    int choice;
    printf("Enter the value to be converted: ");
    scanf("%f", &value);
    printf("Enter the unit of the value (m, cm, kg, g, l, ml): ");
    scanf(" %c", &unit);
    printf("Enter the unit to convert to (m, cm, kg, g, l, ml): ");
    scanf(" %c", &unit);
    printf("Enter your choice:\n1. Length\n2. Mass\n3. Volume\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            if(unit =='m' || unit == 'M') {
                result = value * 100;
                printf("%f %c = %f cm", value, unit, result);
            }
            else if(unit == 'cm' || unit == 'C') {
                result = value / 100;
                printf("%f %c = %f m", value, unit, result);
            }
            break;
        case 2:
            if(unit == 'kg' || unit == 'K') {
                result = value * 1000;
                printf("%f %c = %f g", value, unit, result);
            }
            else if(unit == 'g' || unit == 'G') {
                result = value / 1000;
                printf("%f %c = %f kg", value, unit, result);
            }
            break;
        case 3:
            if(unit == 'l' || unit == 'L') {
                result = value * 1000;
                printf("%f %c = %f ml", value, unit, result);
            }
            else if(unit =='ml' || unit == 'M') {
                result = value / 1000;
                printf("%f %c = %f l", value, unit, result);
            }
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}