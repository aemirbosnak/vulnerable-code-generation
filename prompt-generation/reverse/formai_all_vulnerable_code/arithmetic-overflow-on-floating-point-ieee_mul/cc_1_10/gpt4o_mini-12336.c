//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Romeo and Juliet
#include <stdio.h>

void display_instructions() {
    printf("A Tempest in a Teapot: A Temperature Converter\n");
    printf("=======================================\n");
    printf("Oh, fairest friend, seek to know:\n");
    printf("To convert Celsius to Fahrenheit, use:\n");
    printf("F = (C * 9/5) + 32\n");
    printf("And lo, to transform Fahrenheit to Celsius:\n");
    printf("C = (F - 32) * 5/9\n\n");
    printf("Choose thy method of conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Leave, as the night doth call\n");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void perform_conversion(int choice) {
    float temperature, converted_temp;
    
    if (choice == 1) {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temperature);
        converted_temp = celsius_to_fahrenheit(temperature);
        printf("Ah, the temperature in Fahrenheit is: %.2f\n", converted_temp);
    } 
    else if (choice == 2) {
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        converted_temp = fahrenheit_to_celsius(temperature);
        printf("Ah, the temperature in Celsius is: %.2f\n", converted_temp);
    }
}

int main() {
    display_instructions();
    
    int choice;
    
    do {
        printf("\nEnter thy choice: ");
        scanf("%d", &choice);
        
        if (choice == 1 || choice == 2) {
            perform_conversion(choice);
        } 
        else if (choice == 3) {
            printf("Adieu, sweet user! The stars twinkle, and the night beckons.\n");
        } 
        else {
            printf("Alas! Thy choice is but folly. Choose again.\n");
        }

    } while (choice != 3);

    return 0;
}