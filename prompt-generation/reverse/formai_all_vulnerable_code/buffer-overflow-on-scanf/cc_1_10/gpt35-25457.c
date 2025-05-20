//FormAI DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h> 
#include <stdlib.h>

int main() {
    float celsius, fahrenheit; 
    int choice;

    printf("\n\n########################################################\n");
    printf("##          Post-Apocalyptic Temperature Converter     ##\n");
    printf("########################################################\n\n");

    do {
        printf("Select an operation to perform:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                if (celsius < -273.15) {
                    printf("\n\nError: Temperature below absolute zero!\n");
                } else {
                    fahrenheit = (celsius * 9 / 5) + 32;
                    printf("\n%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
                }
                break;
            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                if (fahrenheit < -459.67) {
                    printf("\n\nError: Temperature below absolute zero!\n");
                } else {
                    celsius = (fahrenheit - 32) * 5 / 9;
                    printf("\n%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
                }
                break;
            case 3:
                printf("\nExiting the program...\n");
                exit(0);
                break;
            default:
                printf("\n\nInvalid choice! Please enter a valid choice between 1 and 3.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}