//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double num, result;
    char unit[10];
    
    printf("Welcome to the Unit Converter!\n");
    printf("Please enter a number: ");
    scanf("%lf", &num);
    printf("Please enter the unit of the number: ");
    scanf("%s", unit);
    
    printf("Please choose the unit you want to convert to:\n");
    printf("1. Millimeters\n");
    printf("2. Centimeters\n");
    printf("3. Meters\n");
    printf("4. Kilometers\n");
    printf("5. Inches\n");
    printf("6. Feet\n");
    printf("7. Yards\n");
    printf("8. Miles\n");
    
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            result = num * 1000;
            printf("The result is %.2lf millimeters.\n", result);
            break;
        case 2:
            result = num / 100;
            printf("The result is %.2lf centimeters.\n", result);
            break;
        case 3:
            result = num;
            printf("The result is %.2lf meters.\n", result);
            break;
        case 4:
            result = num / 1000;
            printf("The result is %.2lf kilometers.\n", result);
            break;
        case 5:
            result = num * 25.4;
            printf("The result is %.2lf inches.\n", result);
            break;
        case 6:
            result = num / 0.3048;
            printf("The result is %.2lf feet.\n", result);
            break;
        case 7:
            result = num / 0.9144;
            printf("The result is %.2lf yards.\n", result);
            break;
        case 8:
            result = num / 160934.4;
            printf("The result is %.2lf miles.\n", result);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    return 0;
}