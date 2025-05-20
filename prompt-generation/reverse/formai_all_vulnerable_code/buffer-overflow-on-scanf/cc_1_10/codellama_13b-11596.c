//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: decentralized
// Decentralized C Unit Converter Example Program

#include <stdio.h>

// Struct for storing unit conversion data
typedef struct {
    char* name;
    float conversion_factor;
} unit_data;

// Array of unit data
unit_data units[] = {
    {"m", 1},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34},
    {"yd", 0.9144},
    {"ft", 0.3048},
    {"in", 0.0254}
};

// Function to convert units
float convert_units(float value, char* from, char* to) {
    // Find index of "from" unit in array
    int from_index = -1;
    for (int i = 0; i < sizeof(units) / sizeof(unit_data); i++) {
        if (strcmp(units[i].name, from) == 0) {
            from_index = i;
            break;
        }
    }

    // Find index of "to" unit in array
    int to_index = -1;
    for (int i = 0; i < sizeof(units) / sizeof(unit_data); i++) {
        if (strcmp(units[i].name, to) == 0) {
            to_index = i;
            break;
        }
    }

    // Check if both units are valid
    if (from_index == -1 || to_index == -1) {
        return 0.0;
    }

    // Calculate conversion factor
    float conversion_factor = units[to_index].conversion_factor / units[from_index].conversion_factor;

    // Perform conversion
    return value * conversion_factor;
}

// Main function
int main() {
    // Get input from user
    float value;
    char from[10];
    char to[10];
    printf("Enter value: ");
    scanf("%f", &value);
    printf("Enter from unit (e.g. m, cm, mm): ");
    scanf("%s", from);
    printf("Enter to unit (e.g. m, cm, mm): ");
    scanf("%s", to);

    // Convert units
    float result = convert_units(value, from, to);

    // Print output
    printf("Result: %f %s\n", result, to);

    return 0;
}