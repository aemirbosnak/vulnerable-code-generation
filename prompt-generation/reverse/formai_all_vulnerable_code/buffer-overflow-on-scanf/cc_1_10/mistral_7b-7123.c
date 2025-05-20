//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[20];
    double conversion_factor;
} Unit;

Unit units[] = {
    {"Miles", 1609.34},
    {"Kilometers", 0.000621371},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Degrees Fahrenheit", 0.55556},
    {"Degrees Celsius", 1.8},
    {"Liters", 0.001},
    {"Gallons", 3.78541},
    {"Seconds", 1},
    {"Minutes", 60},
    {"Hours", 3600},
    {"Days", 86400},
    {"Years", 31536000.0},
    {""}
};

int find_unit_index(char *name) {
    int i = 0;
    while (units[i].name[0] != '\0') {
        if (strcasecmp(units[i].name, name) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

double convert_unit(char *from_unit, double value, char *to_unit) {
    int from_index = find_unit_index(from_unit);
    int to_index = find_unit_index(to_unit);

    if (from_index < 0 || to_index < 0) {
        fprintf(stderr, "Invalid unit name\n");
        return 0;
    }

    double result = value * (units[to_index].conversion_factor / units[from_index].conversion_factor);

    return result;
}

int main() {
    char from_unit[20], to_unit[20];
    double value, result;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value (e.g. Miles, Kilograms, etc.): ");
    scanf("%s", from_unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    result = convert_unit(from_unit, value, to_unit);

    if (result != 0) {
        printf("The result is: %.2f %s\n", result, to_unit);
    }

    return 0;
}