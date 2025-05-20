//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("Ah, my dear Watson! Welcome to the Unit Converter, where precision meets deduction.\n");
    printf("1. Convert Length\n");
    printf("2. Convert Weight\n");
    printf("3. Convert Temperature\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

void convertLength() {
    double meters, feet;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    printf("Conversion complete! %lf meters is equal to %lf feet.\n", meters, feet);
}

void convertWeight() {
    double kilograms, pounds;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462;
    printf("Conversion complete! %lf kilograms is equal to %lf pounds.\n", kilograms, pounds);
}

void convertTemperature() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("Conversion complete! %lf Celsius is equal to %lf Fahrenheit.\n", celsius, fahrenheit);
}

int main() {
    int choice;
    
    printf("Elementary, my dear Watson! Let us embark on the thrilling adventure of conversion!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Ah, the transformation of length! How fascinating!\n");
                convertLength();
                break;
            case 2:
                printf("Weight is but a curious matter. Let's proceed!\n");
                convertWeight();
                break;
            case 3:
                printf("Temperature conversions can be quite the mystery!\n");
                convertTemperature();
                break;
            case 4:
                printf("Ah, it appears our inquiry has reached its conclusion. Farewell, my friend.\n");
                exit(0);
            default:
                printf("A detective must always pay attention to detail! Please select a valid option.\n");
        }

        printf("\nWould you like to perform another conversion? (1 for Yes, 0 for No): ");
        int another;
        scanf("%d", &another);
        if (another != 1) {
            printf("Very well, the case is closed. Until next time!\n");
            break;
        }
    }

    return 0;
}