//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define SHAPE_SHIFT 0

typedef struct {
    float fahrenheit;
    float celsius;
    void (*convert)(struct Temperature *temp);
} Temperature;

void convert_f_to_c(Temperature *temp) {
    temp->celsius = (temp->fahrenheit - 32) * 5.0 / 9.0;
}

void convert_c_to_f(Temperature *temp) {
    temp->fahrenheit = temp->celsius * 9.0 / 5.0 + 32;
}

void shape_shift_simple() {
    Temperature temp = {0};
    float fahrenheit;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    temp.fahrenheit = fahrenheit;
    convert_f_to_c(&temp);

    printf("Temperature in Celsius: %.2f°C\n", temp.celsius);
}

void shape_shift_complex() {
    Temperature temp = {0};
    float fahrenheit, choice;
    int i;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    temp.fahrenheit = fahrenheit;

    do {
        printf("\nChoose temperature conversion type:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Exit\n");
        scanf("%d", &i);

        switch(i) {
            case 1:
                convert_f_to_c(&temp);
                printf("Temperature in Celsius: %.2f°C\n", temp.celsius);
                break;
            case 2:
                convert_c_to_f(&temp);
                printf("Temperature in Fahrenheit: %.2f°F\n", temp.fahrenheit);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to convert another temperature? (y/n): ");
        scanf("%c", &choice);
    } while(choice == 'y');
}

int main() {
    switch(SHAPE_SHIFT) {
        case 0:
            shape_shift_simple();
            break;
        case 1:
            shape_shift_complex();
            break;
        default:
            printf("Invalid shape shift mode!\n");
    }

    return 0;
}