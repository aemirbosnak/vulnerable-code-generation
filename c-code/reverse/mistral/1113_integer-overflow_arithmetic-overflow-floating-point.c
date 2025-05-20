#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define C_TO_F 9.0/5.0 + 32
#define F_TO_C 5.0/9.0 * (C_TO_F - 32)

void temp_converter(void);
int main(void) {
    int choice;
    float temp;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 2)
        temp_converter();
    else
        printf("Invalid choice. Please try again.\n");

    return 0;
}

void temp_converter(void) {
    int choice;
    float temp;

    printf("Enter temperature: ");
    scanf("%f", &temp);

    if (choice == 1)
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temp, temp * C_TO_F);
    else
        printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temp, temp * F_TO_C);

    printf("1. Convert another temperature\n2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        temp_converter();
}
