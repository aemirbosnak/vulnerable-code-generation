//FormAI DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    float value;
    char unit[20], from[20], to[20];

    printf("\n-----------------------------------\n");
    printf(" CRYPTIC UNIT CONVERTER ");
    printf("\n-----------------------------------\n");

    printf("\nEnter the value to be converted: ");
    scanf("%f", &value);

    printf("\nChoose the type of input unit:");
    printf("\n1. Time \n2. Temperature \n3. Distance");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: strcpy(from, "seconds"); break;
        case 2: strcpy(from, "degrees"); break;
        case 3: strcpy(from, "meters"); break;
        default: strcpy(from, "units");
    }

    printf("\nSelect the type of output unit:");
    printf("\n1. Time \n2. Temperature \n3. Distance");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: strcpy(to, "minutes"); break;
        case 2: strcpy(to, "fahrenheit"); break;
        case 3: strcpy(to, "feet"); break;
        default: strcpy(to, "units");
    }

    printf("\nEnter the unit of input: ");
    scanf("%s", unit);

    if(choice == 1) {
        if(strcmp(unit, "seconds") == 0)
            value /= 60;
        else if(strcmp(unit, "minutes") == 0)
            value *= 60;
        else if(strcmp(unit, "hours") == 0)
            value *= 3600;
        else if(strcmp(unit, "days") == 0)
            value *= 86400;
        else
            printf("Invalid input unit for Time!\n");
    }
    else if(choice == 2) {
        if(strcmp(unit, "celsius") == 0)
            value = (value * 9/5) + 32;
        else if(strcmp(unit, "fahrenheit") == 0)
            value = (value - 32) * 5/9;
        else if(strcmp(unit, "kelvin") == 0)
            value = (value - 273.15) * 9/5 + 32;
        else
            printf("Invalid input unit for Temperature!\n");
    }
    else if(choice == 3) {
        if(strcmp(unit, "meters") == 0)
            value *= 3.281;
        else if(strcmp(unit, "feet") == 0)
            value /= 3.281;
        else if(strcmp(unit, "yards") == 0)
            value *= 3;
        else if(strcmp(unit, "kilometers") == 0)
            value *= 3281;
        else
            printf("Invalid input unit for Distance!\n");
    }

    printf("\nResult: %.2f %s = %.2f %s\n", value, from, value, to);

    return 0;
}