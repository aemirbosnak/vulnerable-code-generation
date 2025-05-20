//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define NUM_CONVERSION_PAIRS 18

typedef struct {
    char *from_unit;
    char *to_unit;
    double conversion_factor;
} ConversionPair;

void print_menu();
void process_input(char *input, ConversionPair conversion_pairs[NUM_CONVERSION_PAIRS]);
double get_conversion_factor(char *from_unit, ConversionPair conversion_pairs[NUM_CONVERSION_PAIRS]);

int main() {
    ConversionPair conversion_pairs[NUM_CONVERSION_PAIRS] = {
            {"m", "km", 0.001},
            {"m", "ft", 3.28084},
            {"m", "yd", 1.0936},
            {"kg", "lbs", 2.20462},
            {"l", "gal", 0.00378541},
            {"l", "ft³", 0.0353147},
            {"gal", "l", 3.78541},
            {"ft³", "l", 264.172},
            {"m/s²", "ft/s²", 0.3048},
            {"l/min", "gal/min", 0.0264172},
            {"km/h", "mph", 0.621371},
            {"lb/ft²", "kg/m²", 0.0453592},
            {"m³", "ft³", 35.3147},
            {"lbs", "tonnes", 0.000984252},
            {"tonnes", "lbs", 1016.047},
            {"kmol", "lb-mol", 22.4809},
            {"lb-mol", "kmol", 0.0000453592}
    };

    char input[MAX_INPUT_SIZE];
    int choice;

    do {
        print_menu();
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';
        process_input(input, conversion_pairs);
        printf("Enter another conversion (Y/N): ");
        scanf("%c", &choice);
        getchar();
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

void print_menu() {
    printf("\nUnit Converter\n");
    printf("-------------\n");
    printf("1. Length: m to km, ft, or yd\n");
    printf("2. Mass: kg to lbs\n");
    printf("3. Volume: l to gal, ft³, or m³\n");
    printf("4. Speed: m/s² to ft/s²\n");
    printf("5. Flow rate: l/min to gal/min\n");
    printf("6. Velocity: km/h to mph\n");
    printf("7. Density: lb/ft² to kg/m²\n");
    printf("8. Volume: m³ to ft³\n");
    printf("9. Mass: lbs to tonnes\n");
    printf("10. Mass: tonnes to lbs\n");
    printf("11. Amount of substance: kmol to lb-mol\n");
    printf("12. Amount of substance: lb-mol to kmol\n");
    printf("Enter your choice: ");
}

void process_input(char *input, ConversionPair conversion_pairs[NUM_CONVERSION_PAIRS]) {
    char from_unit[MAX_INPUT_SIZE], to_unit[MAX_INPUT_SIZE];
    double value, conversion_factor, result;

    sscanf(input, "%lf %s %s", &value, from_unit, to_unit);

    conversion_factor = get_conversion_factor(from_unit, conversion_pairs);

    if (conversion_factor <= 0.0) {
        printf("Invalid input: %s to %s\n", from_unit, to_unit);
        return;
    }

    conversion_factor *= get_conversion_factor(to_unit, conversion_pairs);

    result = value * conversion_factor;

    printf("%.2f %s is equal to %.2f %s\n", value, from_unit, result, to_unit);
}

double get_conversion_factor(char *unit, ConversionPair conversion_pairs[NUM_CONVERSION_PAIRS]) {
    for (int i = 0; i < NUM_CONVERSION_PAIRS; ++i) {
        if (strcmp(unit, conversion_pairs[i].from_unit) == 0) {
            return conversion_pairs[i].conversion_factor;
        }
    }

    return -1.0;
}