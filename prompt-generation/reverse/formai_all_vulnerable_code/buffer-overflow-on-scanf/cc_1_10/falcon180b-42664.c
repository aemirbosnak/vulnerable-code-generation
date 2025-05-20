//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double number, result;
    
    printf("Enter 1 to convert length\n");
    printf("Enter 2 to convert weight\n");
    printf("Enter 3 to convert temperature\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the length to convert: ");
            scanf("%lf", &number);
            printf("Enter the unit of length: ");
            char unit[10];
            scanf("%s", unit);
            
            if(strcmp(unit, "m") == 0) {
                result = number * 100;
                printf("%lf meters = %lf centimeters\n", number, result);
            }
            else if(strcmp(unit, "cm") == 0) {
                result = number / 100;
                printf("%lf centimeters = %lf meters\n", number, result);
            }
            else {
                printf("Invalid unit of length\n");
            }
            break;
            
        case 2:
            printf("Enter the weight to convert: ");
            scanf("%lf", &number);
            printf("Enter the unit of weight: ");
            char unit2[10];
            scanf("%s", unit2);
            
            if(strcmp(unit2, "kg") == 0) {
                result = number * 2.20462;
                printf("%lf kg = %lf lbs\n", number, result);
            }
            else if(strcmp(unit2, "lbs") == 0) {
                result = number / 2.20462;
                printf("%lf lbs = %lf kg\n", number, result);
            }
            else {
                printf("Invalid unit of weight\n");
            }
            break;
            
        case 3:
            printf("Enter the temperature to convert: ");
            scanf("%lf", &number);
            printf("Enter the unit of temperature: ");
            char unit3[10];
            scanf("%s", unit3);
            
            if(strcmp(unit3, "C") == 0) {
                result = (number * 1.8) + 32;
                printf("%lf C = %lf F\n", number, result);
            }
            else if(strcmp(unit3, "F") == 0) {
                result = (number - 32) / 1.8;
                printf("%lf F = %lf C\n", number, result);
            }
            else {
                printf("Invalid unit of temperature\n");
            }
            break;
            
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}