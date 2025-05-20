//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to calculate the area of a circle
float area_of_circle(float radius) {
    return PI * radius * radius;
}

int main() {
    float celsius, fahrenheit, radius;
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Calculate the area of a circle\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, celsius_to_fahrenheit(celsius));
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, fahrenheit_to_celsius(fahrenheit));
                break;

            case 3:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                printf("The area of the circle with radius %.2f is %.2f.\n", radius, area_of_circle(radius));
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 4);

    return 0;
}