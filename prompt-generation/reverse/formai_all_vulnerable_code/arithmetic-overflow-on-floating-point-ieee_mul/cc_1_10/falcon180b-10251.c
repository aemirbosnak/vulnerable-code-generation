//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    char input[20];
    int choice;
    double num, result;

printf("WELCOME TO THE TEMPERATURE CONVERTER\n");

do {
    printf("\n");
    printf("1. CELSIUS TO FAHRENHEIT\n");
    printf("2. FAHRENHEIT TO CELSIUS\n");
    printf("3. EXIT\n");
    printf("\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n");
            printf("ENTER THE TEMPERATURE IN CELSIUS: ");
            scanf("%lf", &num);
            result = (num * 9/5) + 32;
            printf("\n");
            printf("THE TEMPERATURE IN FAHRENHEIT IS: %.2lf\n", result);
            break;
        case 2:
            printf("\n");
            printf("ENTER THE TEMPERATURE IN FAHRENHEIT: ");
            scanf("%lf", &num);
            result = (num - 32) * 5/9;
            printf("\n");
            printf("THE TEMPERATURE IN CELSIUS IS: %.2lf\n", result);
            break;
        case 3:
            printf("\n");
            printf("THANK YOU FOR USING THE TEMPERATURE CONVERTER\n");
            break;
        default:
            printf("\n");
            printf("INVALID CHOICE. PLEASE TRY AGAIN.\n");
            break;
    }
} while(choice!= 3);

return 0;
}