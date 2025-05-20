//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    float value;
} Temperature;

void print_temperature(Temperature temp) {
    char *unit;

    if (temp.value > 273.15) {
        unit = "Kelvin";
        temp.value -= 273.15;
    } else {
        unit = "Celsius";
    }

    if (temp.value >= 0) {
        printf("%s %.2f%s above zero\n", temp.name, temp.value, unit);
    } else {
        printf("%s %.2f%s below zero\n", temp.name, -temp.value, unit);
    }
}

int main() {
    srand(time(NULL));
    Temperature temp1 = {"Fahrenheit", 0.0}, temp2 = {"Kelvin", 0.0};
    float fahrenheit, celcius, kelvin;

    do {
        printf("Enter a temperature in Fahrenheit (-1 to quit): ");
        scanf("%f", &fahrenheit);

        if (fahrenheit >= 0.0) {
            celcius = (fahrenheit - 32.0) * 5.0 / 9.0;
            kelvin = celcius + 273.15;

            strcpy(temp1.name, "Fahrenheit");
            temp1.value = fahrenheit;
            print_temperature(temp1);

            strcpy(temp2.name, "Celsius");
            temp2.value = celcius;
            print_temperature(temp2);

            strcpy(temp2.name, "Kelvin");
            temp2.value = kelvin;
            print_temperature(temp2);

            printf("\n");
        }

    } while (fahrenheit != -1.0);

    return 0;
}