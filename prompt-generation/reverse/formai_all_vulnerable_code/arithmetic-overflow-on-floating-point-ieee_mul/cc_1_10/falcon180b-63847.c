//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char choice;
    float fahrenheit, celsius, kelvin;

    //Prompt user for input
    printf("Enter 'F' for Fahrenheit to Celsius/Kelvin conversion\n");
    printf("Enter 'C' for Celsius to Fahrenheit/Kelvin conversion\n");
    printf("Enter 'K' for Kelvin to Celsius/Fahrenheit conversion\n");
    scanf("%c", &choice);

    //Input validation
    if(choice!= 'F' && choice!= 'C' && choice!= 'K') {
        printf("Invalid choice.\n");
        return 0;
    }

    //Prompt user for input
    if(choice == 'F') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        //Convert Fahrenheit to Celsius
        celsius = (fahrenheit - 32) * 5/9;

        //Convert Fahrenheit to Kelvin
        kelvin = celsius + 273.15;

        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius or %.2f Kelvin.\n", fahrenheit, celsius, kelvin);
    }
    else if(choice == 'C') {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);

        //Convert Celsius to Fahrenheit
        fahrenheit = celsius * 9/5 + 32;

        //Convert Celsius to Kelvin
        kelvin = celsius + 273.15;

        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit or %.2f Kelvin.\n", celsius, fahrenheit, kelvin);
    }
    else if(choice == 'K') {
        printf("Enter temperature in Kelvin: ");
        scanf("%f", &kelvin);

        //Convert Kelvin to Celsius
        celsius = kelvin - 273.15;

        //Convert Kelvin to Fahrenheit
        fahrenheit = celsius * 9/5 + 32;

        printf("%.2f Kelvin is equal to %.2f degrees Celsius or %.2f degrees Fahrenheit.\n", kelvin, celsius, fahrenheit);
    }

    return 0;
}