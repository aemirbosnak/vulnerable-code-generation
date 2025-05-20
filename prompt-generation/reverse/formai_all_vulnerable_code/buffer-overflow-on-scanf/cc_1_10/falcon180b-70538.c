//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    float celsius;
    float fahrenheit;
} Temperature;

Temperature* createTemperature(char* name, float celsius, float fahrenheit) {
    Temperature* temp = (Temperature*)malloc(sizeof(Temperature));
    strcpy(temp->name, name);
    temp->celsius = celsius;
    temp->fahrenheit = fahrenheit;
    return temp;
}

void printTemperature(Temperature* temp) {
    printf("Name: %s\n", temp->name);
    printf("Celsius: %.2f\n", temp->celsius);
    printf("Fahrenheit: %.2f\n", temp->fahrenheit);
}

void freeTemperature(Temperature* temp) {
    free(temp);
}

int main() {
    Temperature* temperatures[MAX_SIZE];
    int numTemperatures = 0;

    while (TRUE) {
        printf("Enter a temperature (name, celsius, fahrenheit): ");
        char name[MAX_SIZE];
        float celsius, fahrenheit;
        scanf("%s %f %f", name, &celsius, &fahrenheit);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        Temperature* temp = createTemperature(name, celsius, fahrenheit);
        temperatures[numTemperatures++] = temp;
    }

    printf("Temperatures:\n");
    for (int i = 0; i < numTemperatures; i++) {
        printTemperature(temperatures[i]);
    }

    for (int i = 0; i < numTemperatures; i++) {
        freeTemperature(temperatures[i]);
    }

    return 0;
}