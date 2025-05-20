//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define LENGTH 3

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    char input[LENGTH];
    char *endptr;
    double celsius, fahrenheit;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter a temperature in Celsius or Fahrenheit and the program will convert it for you.\n");
    printf("Please enter your choice: \n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter temperature in Celsius: ");
        if(scanf("%s", input)!= 1) {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }
        celsius = strtod(input, &endptr);
        if(*endptr!= '\0') {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }
        fahrenheit = (celsius * 9/5) + 32;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
    }
    else if(choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        if(scanf("%s", input)!= 1) {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }
        fahrenheit = strtod(input, &endptr);
        if(*endptr!= '\0') {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }
        celsius = (fahrenheit - 32) * 5/9;
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
    }
    else {
        printf("Invalid choice. Please choose either 1 or 2.\n");
    }

    return 0;
}