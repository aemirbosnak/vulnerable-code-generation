//FormAI DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    ERROR = -1,
    SUCCESS = 0
} Status;

typedef enum {
    DISTANCE,
    TEMPERATURE,
    WEIGHT
} ConversionType;

typedef struct {
    char * from_unit;
    char * to_unit;
    float conversion_factor;
} Conversion;

Conversion distance_conversions[] = {
    {"m", "km", 0.001},
    {"km", "m", 1000},
    {"m", "cm", 100},
    {"cm", "m", 0.01},
    {"m", "mm", 1000},
    {"mm", "m", 0.001},
    {"km", "cm", 100000},
    {"cm", "km", 0.00001},
    {"km", "mm", 1000000},
    {"mm", "km", 0.000001}
};

Conversion temperature_conversions[] = {
    {"c", "f", 1.8},
    {"f", "c", -0.555555}
};

Conversion weight_conversions[] = {
    {"kg", "lb", 2.20462},
    {"lb", "kg", 0.453592}
};

int get_array_length(ConversionType conversion_type);

Conversion get_conversion(ConversionType conversion_type, int index);

float convert_units(char * from_unit, char * to_unit, float value);

void display_menu();

int main() {
    int conversion_type_input, from_unit_input, to_unit_input;
    float value;
    Status status = SUCCESS;
    while (status == SUCCESS) {
        display_menu();
        scanf("%d", &conversion_type_input);
        if (conversion_type_input == 0) {
            printf("Exiting program!\n");
            break;
        }
        ConversionType conversion_type = (ConversionType) conversion_type_input;
        int conversion_count = get_array_length(conversion_type);
        printf("Choose the unit to convert from:\n");
        for (int i = 0; i < conversion_count; i++) {
            Conversion conversion = get_conversion(conversion_type, i);
            printf("%d. %s\n", i + 1, conversion.from_unit);
        }
        scanf("%d", &from_unit_input);
        printf("Choose the unit to convert to:\n");
        for (int i = 0; i < conversion_count; i++) {
            Conversion conversion = get_conversion(conversion_type, i);
            printf("%d. %s\n", i + 1, conversion.to_unit);
        }
        scanf("%d", &to_unit_input);
        printf("Enter the value to convert:\n");
        scanf("%f", &value);

        // Convert units and display result
        Conversion from_conversion = get_conversion(conversion_type, from_unit_input - 1);
        Conversion to_conversion = get_conversion(conversion_type, to_unit_input - 1);
        float converted_value = convert_units(from_conversion.from_unit, to_conversion.to_unit, value);
        printf("%f %s is equal to %f %s\n", value, from_conversion.from_unit, converted_value, to_conversion.to_unit);
    }
    return 0;
}

// Get length of conversion array based on conversion type
int get_array_length(ConversionType conversion_type) {
    switch (conversion_type) {
        case DISTANCE:
            return sizeof(distance_conversions) / sizeof(Conversion);
        case TEMPERATURE:
            return sizeof(temperature_conversions) / sizeof(Conversion);
        case WEIGHT:
            return sizeof(weight_conversions) / sizeof(Conversion);
        default:
            printf("Invalid conversion type!\n");
            return ERROR;
    }
}

// Get conversion object from conversion array based on conversion type and index
Conversion get_conversion(ConversionType conversion_type, int index) {
    switch (conversion_type) {
        case DISTANCE:
            return distance_conversions[index];
        case TEMPERATURE:
            return temperature_conversions[index];
        case WEIGHT:
            return weight_conversions[index];
        default:
            printf("Invalid conversion type!\n");
            Conversion invalid_conversion = {"invalid", "invalid", ERROR};
            return invalid_conversion;
    }
}

// Convert units based on conversion factor
float convert_units(char * from_unit, char * to_unit, float value) {
    if (strcmp(from_unit, to_unit) == 0) {
        return value;
    }
    else {
        if (strcmp(from_unit, "c") == 0 && strcmp(to_unit, "f") == 0) {
            return (value * 1.8) + 32;
        }
        else if (strcmp(from_unit, "f") == 0 && strcmp(to_unit, "c") == 0) {
            return (value - 32) * 0.555555;
        }
        else {
            int conversion_type_input;
            if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "km") == 0) {
                conversion_type_input = 1;
            }
            else if (strcmp(from_unit, "km") == 0 && strcmp(to_unit, "m") == 0) {
                conversion_type_input = 2;
            }
            else if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "cm") == 0) {
                conversion_type_input = 3;
            }
            else if (strcmp(from_unit, "cm") == 0 && strcmp(to_unit, "m") == 0) {
                conversion_type_input = 4;
            }
            else if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "mm") == 0) {
                conversion_type_input = 5;
            }
            else if (strcmp(from_unit, "mm") == 0 && strcmp(to_unit, "m") == 0) {
                conversion_type_input = 6;
            }
            else if (strcmp(from_unit, "km") == 0 && strcmp(to_unit, "cm") == 0) {
                conversion_type_input = 7;
            }
            else if (strcmp(from_unit, "cm") == 0 && strcmp(to_unit, "km") == 0) {
                conversion_type_input = 8;
            }
            else if (strcmp(from_unit, "km") == 0 && strcmp(to_unit, "mm") == 0) {
                conversion_type_input = 9;
            }
            else if (strcmp(from_unit, "mm") == 0 && strcmp(to_unit, "km") == 0) {
                conversion_type_input = 10;
            }
            float conversion_factor;
            switch (conversion_type_input) {
                case 1:
                    conversion_factor = distance_conversions[0].conversion_factor;
                    break;
                case 2:
                    conversion_factor = distance_conversions[1].conversion_factor;
                    break;
                case 3:
                    conversion_factor = distance_conversions[2].conversion_factor;
                    break;
                case 4:
                    conversion_factor = distance_conversions[3].conversion_factor;
                    break;
                case 5:
                    conversion_factor = distance_conversions[4].conversion_factor;
                    break;
                case 6:
                    conversion_factor = distance_conversions[5].conversion_factor;
                    break;
                case 7:
                    conversion_factor = distance_conversions[6].conversion_factor;
                    break;
                case 8:
                    conversion_factor = distance_conversions[7].conversion_factor;
                    break;
                case 9:
                    conversion_factor = distance_conversions[8].conversion_factor;
                    break;
                case 10:
                    conversion_factor = distance_conversions[9].conversion_factor;
                    break;
                default:
                    printf("Invalid conversion!\n");
                    return ERROR;
            }
            return value * conversion_factor;
        }
    }
}

// Display conversion menu
void display_menu() {
    printf("Choose the conversion:\n");
    printf("1. Distance\n");
    printf("2. Temperature\n");
    printf("3. Weight\n");
    printf("0. Exit\n");
}