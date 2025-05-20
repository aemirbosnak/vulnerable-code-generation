//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];
    char from_unit[10];
    char to_unit[10];
    double value, result;

    printf("Welcome to the Brave Unit Converter!\n");
    printf("Enter units separated by commas:\n");
    fgets(input, sizeof(input), stdin);

    // Parse input and add units to list
    char *token = strtok(input, ",");
    while (token!= NULL) {
        if (num_units >= MAX_UNITS) {
            printf("Too many units specified.\n");
            return 1;
        }
        strcpy(units[num_units].name, token);
        num_units++;
        token = strtok(NULL, ",");
    }

    // Get conversion details from user
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    // Find the indices of the input and output units in the list
    int from_index = -1;
    int to_index = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_index = i;
        } else if (strcmp(units[i].name, to_unit) == 0) {
            to_index = i;
        }
    }

    // Perform the conversion
    if (from_index == -1 || to_index == -1) {
        printf("Invalid units specified.\n");
        return 1;
    }
    result = value * units[from_index].factor / units[to_index].factor;

    // Print the result
    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}