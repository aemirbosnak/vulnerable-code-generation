//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, celsius, fahrenheit;
    char cont;
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Initialize the temperature converter
    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose a conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    
    // Convert Celsius to Fahrenheit
    if (choice == 1) {
        celsius = rand() % 100;
        fahrenheit = (celsius * 9/5) + 32;
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
        printf("Do you want to convert another temperature? (y/n): ");
        scanf(" %c", &cont);
        if (cont == 'y' || cont == 'Y') {
            main();
        } else {
            exit(0);
        }
    }
    
    // Convert Fahrenheit to Celsius
    else if (choice == 2) {
        fahrenheit = rand() % 100;
        celsius = (fahrenheit - 32) * 5/9;
        printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", fahrenheit, celsius);
        printf("Do you want to convert another temperature? (y/n): ");
        scanf(" %c", &cont);
        if (cont == 'y' || cont == 'Y') {
            main();
        } else {
            exit(0);
        }
    }
    
    // Invalid choice
    else {
        printf("Invalid choice. Exiting program.\n");
        exit(1);
    }
    
    return 0;
}