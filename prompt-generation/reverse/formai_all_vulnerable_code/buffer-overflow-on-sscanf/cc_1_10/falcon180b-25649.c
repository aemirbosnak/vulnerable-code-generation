//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE_LENGTH 100

int main() {
    char line[MAX_LINE_LENGTH];
    double celsius, fahrenheit;
    int choice;

    printf("Enter 'C' to convert Celsius to Fahrenheit or 'F' to convert Fahrenheit to Celsius: ");
    scanf("%c", &choice);

    while (toupper(choice)!= 'C' && toupper(choice)!= 'F') {
        printf("Invalid input. Please enter 'C' or 'F': ");
        scanf("%c", &choice);
    }

    while (TRUE) {
        printf("Enter a temperature to convert: ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        if (sscanf(line, "%lf %c", &celsius, &choice)!= 2) {
            printf("Invalid input. Please enter a temperature followed by 'C' or 'F': ");
            continue;
        }

        if (toupper(choice) == 'C') {
            fahrenheit = (celsius * 1.8) + 32;
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
        } else if (toupper(choice) == 'F') {
            celsius = (fahrenheit - 32) / 1.8;
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
        } else {
            printf("Invalid input. Please enter 'C' or 'F': ");
            continue;
        }

        printf("Would you like to convert another temperature? (Y/N): ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        if (toupper(line[0])!= 'Y') {
            break;
        }
    }

    return 0;
}