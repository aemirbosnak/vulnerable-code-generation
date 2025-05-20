//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 80
#define MAX_KEY_LENGTH 20
#define MAX_VALUE_LENGTH 80
#define MAX_TEMP_UNITS 20

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValue;

typedef struct {
    char name[MAX_LINE_LENGTH];
    KeyValue kv[MAX_TEMP_UNITS];
} TempUnit;

void load_temp_units(TempUnit *units, int num_units) {
    for (int i = 0; i < num_units; i++) {
        printf("Enter name of temperature unit %d: ", i);
        scanf("%s", units[i].name);
        printf("Enter key-value pairs for %s:\n", units[i].name);
        int num_pairs = 0;
        while (num_pairs < MAX_TEMP_UNITS && scanf("%s %s", units[i].kv[num_pairs].key, units[i].kv[num_pairs].value) == 2) {
            num_pairs++;
        }
    }
}

void convert_temp(TempUnit *units, double temp, char *result, int result_size) {
    for (int i = 0; i < MAX_TEMP_UNITS; i++) {
        if (units[i].kv[i].key[0]!= '\0' && units[i].kv[i].value[0]!= '\0') {
            double factor = strtod(units[i].kv[i].value, NULL);
            double offset = strtod(units[i].kv[i].key, NULL);
            double converted_temp = (temp * factor) + offset;
            if (converted_temp > 0) {
                snprintf(result, result_size, "%.2f %s", converted_temp, units[i].name);
                return;
            }
        }
    }
    snprintf(result, result_size, "Invalid temperature unit");
}

int main() {
    TempUnit units[MAX_TEMP_UNITS];
    int num_units;

    printf("Enter number of temperature units: ");
    scanf("%d", &num_units);
    load_temp_units(units, num_units);

    char input[MAX_LINE_LENGTH];
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        char result[MAX_LINE_LENGTH];
        double temp;
        if (sscanf(input, "%lf %s", &temp, units[0].name) == 2) {
            convert_temp(units, temp, result, MAX_LINE_LENGTH);
            printf("%s\n", result);
        } else {
            printf("Invalid input\n");
        }
    }

    return 0;
}