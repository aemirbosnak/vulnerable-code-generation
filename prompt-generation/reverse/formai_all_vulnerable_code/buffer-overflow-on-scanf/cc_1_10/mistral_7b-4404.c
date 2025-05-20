//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define F_MIN (-459.67)
#define F_MAX 125
#define C_MIN (-273.15)
#define C_MAX 373.15

typedef struct {
    float celsius;
    float fahrenheit;
} Temperature;

void print_menu() {
    printf("\n------------- MENU --------------\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

void convert_c_to_f(Temperature *temp) {
    temp->fahrenheit = (temp->celsius * 1.8) + 32;
}

void convert_f_to_c(Temperature *temp) {
    temp->celsius = ((temp->fahrenheit - 32) * 5.0 / 9.0);
}

int main() {
    Temperature temp;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temp.celsius);
                convert_c_to_f(&temp);
                printf("Temperature in Fahrenheit: %.2f\n", temp.fahrenheit);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temp.fahrenheit);
                convert_f_to_c(&temp);
                printf("Temperature in Celsius: %.2f\n", temp.celsius);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}