#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    double value;
    char from_unit[20], to_unit[20];
    printf("Enter the value: ");
    scanf("%lf", &value);
    printf("Enter the from unit (e.g., meters, kilometers, miles): ");
    scanf("%s", from_unit);
    printf("Enter the to unit (e.g., meters, kilometers, miles): ");
    scanf("%s", to_unit);

    if (strcmp(from_unit, "meters") == 0 && strcmp(to_unit, "kilometers") == 0) {
        value /= 1000;
    } else if (strcmp(from_unit, "meters") == 0 && strcmp(to_unit, "miles") == 0) {
        value *= 0.000621371;
    } else if (strcmp(from_unit, "kilometers") == 0 && strcmp(to_unit, "meters") == 0) {
        value *= 1000;
    } else if (strcmp(from_unit, "kilometers") == 0 && strcmp(to_unit, "miles") == 0) {
        value *= 0.621371;
    } else if (strcmp(from_unit, "miles") == 0 && strcmp(to_unit, "meters") == 0) {
        value /= 0.000621371;
    } else if (strcmp(from_unit, "miles") == 0 && strcmp(to_unit, "kilometers") == 0) {
        value /= 0.621371;
    }

    printf("%.2f %s is %.2f %s\n", value, from_unit, value, to_unit);

    return 0;
}
