//FormAI DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {

    float input, output;
    int choice;

    printf("\nWelcome to the Unit Converter!\n");

    while(1) {

        printf("\nPlease select an Option: \n");
        printf("1. Kilometers to Miles\n");
        printf("2. Pounds to Kilograms\n");
        printf("3. Fahrenheit to Celsius\n");
        printf("4. Feet to Meters\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        if(choice == 5) {
            printf("\nThank you for using Unit Converter!\n");
            break;
        }
        else if(choice < 1 || choice > 5) {
            printf("\nInvalid Selection. Please try again.\n");
            continue;
        }

        printf("\nPlease enter the value you wish to convert: ");

        scanf("%f", &input);

        switch(choice) {

            case 1:
                output = input * 0.621371;
                printf("%.2f Kilometers is equal to %.2f Miles.\n", input, output);
                break;

            case 2:
                output = input * 0.453592;
                printf("%.2f Pounds is equal to %.2f Kilograms.\n", input, output);
                break;

            case 3:
                output = (input - 32) * (5.0/9.0);
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", input, output);
                break;

            case 4:
                output = input * 0.3048;
                printf("%.2f Feet is equal to %.2f Meters.\n", input, output);
                break;

        }
    }

    return 0;
}