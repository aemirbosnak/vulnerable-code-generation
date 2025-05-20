//FormAI DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>

// Function to convert Fahrenheit to Celsius
float fah_to_cel(float fahrenheit){
    float celsius = (fahrenheit - 32) * 5.0 / 9.0;
    return celsius;
}

// Function to convert Celsius to Fahrenheit
float cel_to_fah(float celsius){
    float fahrenheit = (celsius * 9.0 / 5.0) + 32;
    return fahrenheit;
}

// Function to get user input
float get_input(char from_unit[]){
    float input;
    printf("Enter temperature in %s: ", from_unit);
    scanf("%f", &input);
    return input;
}

// Function to print converted temperature
void print_output(char to_unit[], float converted){
    printf("Temperature in %s: %.2f%c\n", to_unit, converted, (to_unit[0] == 'C') ? ('C') : ('F'));
}

int main(){
    int choice;
    float input, converted;

    do{
        printf("Please choose an option:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                input = get_input("F");
                converted = fah_to_cel(input);
                print_output("C", converted);
                break;
            case 2:
                input = get_input("C");
                converted = cel_to_fah(input);
                print_output("F", converted);
                break;
            case 0:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        printf("\n");

    } while(choice != 0);

    return 0;
}