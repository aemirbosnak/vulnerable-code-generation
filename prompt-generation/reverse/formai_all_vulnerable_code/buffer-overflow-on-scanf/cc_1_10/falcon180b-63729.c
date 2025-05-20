//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void draw_circle(int x, int y, int radius) {
    int i, j;
    for (i = 0; i < radius; i++) {
        for (j = 0; j < 2*radius; j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice;
    double celsius, fahrenheit;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
            draw_circle(0, 0, 30);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
            draw_circle(50, 0, 30);
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}