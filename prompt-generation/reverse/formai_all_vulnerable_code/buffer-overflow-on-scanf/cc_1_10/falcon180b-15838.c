//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

struct Unit {
    char *name;
    double factor;
};

int main() {
    struct Unit units[MAX_UNITS];
    int num_units;
    char input[100];
    char *token;
    double value;
    int i;

    printf("Welcome to the Cyberpunk Unit Converter!\n");
    printf("This program can convert between the following units:\n");
    printf("1. Nanometers\n2. Microseconds\n3. Bits\n4. Bytes\n5. Kilobytes\n6. Megabytes\n7. Gigabytes\n8. Terabytes\n9. Petabytes\n10. Exabytes\n\n");
    printf("Enter the number of units you want to convert: ");
    scanf("%d", &num_units);

    if (num_units > MAX_UNITS || num_units < 1) {
        printf("Invalid number of units. Exiting...\n");
        return 1;
    }

    printf("Enter the units you want to convert between:\n");
    for (i = 0; i < num_units; i++) {
        scanf("%s", input);
        units[i].name = strdup(input);
        printf("Enter the conversion factor for %s: ", units[i].name);
        scanf("%lf", &units[i].factor);
    }

    printf("Enter the value you want to convert: ");
    scanf("%s", input);

    token = strtok(input, " ");
    while (token!= NULL) {
        value = atof(token);
        for (i = 0; i < num_units; i++) {
            if (strcmp(units[i].name, token) == 0) {
                printf("%s = %.2lf %s\n", units[i].name, value / units[i].factor, units[i].name);
            }
        }
        token = strtok(NULL, " ");
    }

    return 0;
}