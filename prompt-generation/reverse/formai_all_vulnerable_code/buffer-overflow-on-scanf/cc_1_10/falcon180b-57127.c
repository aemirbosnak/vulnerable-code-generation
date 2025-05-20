//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct Temperature {
    float value;
    char unit[10];
};

void convert(struct Temperature *temp) {
    char fromUnit[10], toUnit[10];
    float factor = 0.0;
    printf("Enter the current temperature and its unit: ");
    scanf("%f %s", &temp->value, temp->unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", fromUnit);
    printf("Enter the unit to convert from: ");
    scanf("%s", toUnit);
    if (strcmp(fromUnit, "C") == 0 && strcmp(toUnit, "F") == 0) {
        factor = 9.0 / 5.0;
        temp->value += 32.0;
        strcpy(temp->unit, "F");
    } else if (strcmp(fromUnit, "F") == 0 && strcmp(toUnit, "C") == 0) {
        factor = 5.0 / 9.0;
        temp->value -= 32.0;
        strcpy(temp->unit, "C");
    } else {
        printf("Invalid unit conversion.\n");
    }
    temp->value *= factor;
}

int main() {
    struct Temperature temp;
    int choice;

    do {
        printf("1. Convert temperature\n2. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            convert(&temp);
            printf("The converted temperature is %.2f %s.\n", temp.value, temp.unit);
            break;
        case 2:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 2);

    return 0;
}