//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP_UNITS 5

typedef struct {
    char *name;
    double (*convert)(double);
} TempUnit;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double celsius_to_rankine(double celsius) {
    return celsius + 459.67;
}

double celsius_to_delisle(double celsius) {
    return (100.0 - celsius) * 3.0 / 2.0;
}

double celsius_to_newton(double celsius) {
    return celsius * 33.0 / 100.0;
}

TempUnit temp_units[] = {
    {"Celsius", celsius_to_fahrenheit},
    {"Celsius", celsius_to_kelvin},
    {"Celsius", celsius_to_rankine},
    {"Celsius", celsius_to_delisle},
    {"Celsius", celsius_to_newton}
};

int main() {
    srand(time(NULL));
    int num_units = rand() % MAX_TEMP_UNITS + 1;
    TempUnit *selected_units[num_units];

    for (int i = 0; i < num_units; i++) {
        int j;
        for (j = 0; j < MAX_TEMP_UNITS; j++) {
            if (i == 0 || rand() % 2) {
                selected_units[i] = &temp_units[j];
                break;
            }
        }
    }

    double temperature;
    printf("Enter a temperature in Celsius: ");
    scanf("%lf", &temperature);

    printf("The temperature in ");
    for (int i = 0; i < num_units; i++) {
        printf("%s ", selected_units[i]->name);
    }
    printf("is ");

    for (int i = 0; i < num_units; i++) {
        printf("%s %.2lf\t", selected_units[i]->name, selected_units[i]->convert(temperature));
    }

    return 0;
}