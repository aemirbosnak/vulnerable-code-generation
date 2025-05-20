//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_TEMP_UNITS 10
#define MAX_UNITS_NAME_LEN 10

typedef struct {
    char name[MAX_UNITS_NAME_LEN];
    double factor;
} TempUnit;

void initTempUnits() {
    TempUnit tempUnits[MAX_TEMP_UNITS] = {{"Celsius", 1}, {"Fahrenheit", 1.8}, {"Kelvin", 1}, {"Rankine", 1.8}, {"Delisle", 2.4}, {"Newton", 0.33}, {"Reaumur", 4}, {"Romer", 7.5}, {"Simmon", 0.1}, {"Svedberg", -1}};
    int i;
    for (i = 0; i < MAX_TEMP_UNITS; i++) {
        strcpy(tempUnits[i].name, "");
        tempUnits[i].factor = 0;
    }
    for (i = 0; i < MAX_TEMP_UNITS; i++) {
        strcpy(tempUnits[i].name, tempUnits[i * 2].name);
        tempUnits[i].factor = tempUnits[i * 2].factor;
    }
}

int main() {
    int choice;
    double temperature, convertedTemp;
    char input[50];
    TempUnit tempUnits[MAX_TEMP_UNITS];

    initTempUnits();

    printf("Enter a temperature value: ");
    scanf("%lf", &temperature);

    printf("Enter a temperature unit (Celsius, Fahrenheit, Kelvin, Rankine, Delisle, Newton, Reaumur, Romer, Simmon, Svedberg): ");
    scanf("%s", input);

    choice = -1;
    for (int i = 0; i < MAX_TEMP_UNITS; i++) {
        if (strcmp(input, tempUnits[i].name) == 0) {
            choice = i;
            break;
        }
    }

    if (choice == -1) {
        printf("Invalid temperature unit!\n");
        exit(1);
    }

    convertedTemp = temperature * tempUnits[choice].factor;

    printf("The temperature %.2lf %s is equal to %.2lf %s.\n", temperature, input, convertedTemp, tempUnits[choice].name);

    return 0;
}