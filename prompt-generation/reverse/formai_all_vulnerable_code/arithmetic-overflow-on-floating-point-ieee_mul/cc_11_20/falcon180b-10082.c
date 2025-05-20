//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
    double celsius, fahrenheit, kelvin;
    char choice;
    int count = 0;

    printf("Welcome to the Surrealist Temperature Converter!\n");
    printf("Please choose a temperature unit: C, F, or K\n");
    scanf("%c", &choice);

    while(choice!= 'q') {
        if(choice == 'c' || choice == 'C') {
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            kelvin = celsius + 273.15;
            printf("%.2lf Celsius is %.2lf Fahrenheit and %.2lf Kelvin.\n", celsius, fahrenheit, kelvin);
        }
        else if(choice == 'f' || choice == 'F') {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            kelvin = (fahrenheit + 459.67) * 5/9;
            printf("%.2lf Fahrenheit is %.2lf Celsius and %.2lf Kelvin.\n", fahrenheit, celsius, kelvin);
        }
        else if(choice == 'k' || choice == 'K') {
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &kelvin);
            celsius = kelvin - 273.15;
            fahrenheit = (kelvin - 459.67) * 9/5;
            printf("%.2lf Kelvin is %.2lf Celsius and %.2lf Fahrenheit.\n", kelvin, celsius, fahrenheit);
        }
        else {
            printf("Invalid choice. Please choose C, F, or K.\n");
        }

        printf("Do you want to convert another temperature? (y/n): ");
        scanf(" %c", &choice);

        if(choice == 'y' || choice == 'Y') {
            count++;
        }
        else if(choice!= 'n' && choice!= 'N') {
            printf("Invalid choice. Please choose y or n.\n");
        }
        else {
            if(count > 0) {
                printf("Thank you for using the Surrealist Temperature Converter! Goodbye!\n");
            }
            else {
                printf("Goodbye!\n");
            }
            break;
        }
    }

    return 0;
}