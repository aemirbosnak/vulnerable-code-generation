//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void) {
    double x, y, temp;
    int choice;

    do {
        printf("Welcome to the Temperature Monitor!\n");
        printf("Please choose an option:\n");
        printf("1. Convert Fahrenheit to Celsius\n");
        printf("2. Convert Celsius to Fahrenheit\n");
        printf("3. Convert Kelvin to Celsius\n");
        printf("4. Convert Celsius to Kelvin\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temp);
                temp = (temp - 32) * (5.0/9.0);
                printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temp, temp);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temp);
                temp = temp * (9.0/5.0) + 32;
                printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temp, temp);
                break;
            case 3:
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &temp);
                temp = temp - 273.15;
                printf("%.2lf Kelvin is %.2lf degrees Celsius.\n", temp, temp);
                break;
            case 4:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temp);
                temp = temp + 273.15;
                printf("%.2lf degrees Celsius is %.2lf Kelvin.\n", temp, temp);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice!= 5);

    return 0;
}