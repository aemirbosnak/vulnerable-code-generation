//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double to_meters;
} LengthUnit;

typedef struct {
    char *name;
    double to_grams;
} WeightUnit;

void display_length_units(LengthUnit units[], int size);
void display_weight_units(WeightUnit units[], int size);
double convert_length(double value, LengthUnit from_unit, LengthUnit to_unit);
double convert_weight(double value, WeightUnit from_unit, WeightUnit to_unit);

int main() {
    LengthUnit length_units[] = {
        {"Meters", 1.0},
        {"Kilometers", 1000.0},
        {"Centimeters", 0.01},
        {"Millimeters", 0.001},
        {"Feet", 0.3048},
        {"Inches", 0.0254}
    };
    
    WeightUnit weight_units[] = {
        {"Grams", 1.0},
        {"Kilograms", 1000.0},
        {"Pounds", 453.592},
        {"Ounces", 28.3495}
    };

    int length_size = sizeof(length_units) / sizeof(length_units[0]);
    int weight_size = sizeof(weight_units) / sizeof(weight_units[0]);

    int choice;
    do {
        printf("\nUnit Converter\n");
        printf("1. Length Conversion\n");
        printf("2. Weight Conversion\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                double value;
                int from_index, to_index;

                printf("\nLength Conversion:\n");
                display_length_units(length_units, length_size);
                printf("Enter value to convert: ");
                scanf("%lf", &value);
                printf("Select from unit (index): ");
                scanf("%d", &from_index);
                printf("Select to unit (index): ");
                scanf("%d", &to_index);
                if (from_index >= 0 && from_index < length_size && to_index >= 0 && to_index < length_size) {
                    double result = convert_length(value, length_units[from_index], length_units[to_index]);
                    printf("%.2lf %s = %.2lf %s\n", value, length_units[from_index].name, result, length_units[to_index].name);
                } else {
                    printf("Invalid unit selection.\n");
                }
                break;
            }
            case 2: {
                double value;
                int from_index, to_index;

                printf("\nWeight Conversion:\n");
                display_weight_units(weight_units, weight_size);
                printf("Enter value to convert: ");
                scanf("%lf", &value);
                printf("Select from unit (index): ");
                scanf("%d", &from_index);
                printf("Select to unit (index): ");
                scanf("%d", &to_index);
                if (from_index >= 0 && from_index < weight_size && to_index >= 0 && to_index < weight_size) {
                    double result = convert_weight(value, weight_units[from_index], weight_units[to_index]);
                    printf("%.2lf %s = %.2lf %s\n", value, weight_units[from_index].name, result, weight_units[to_index].name);
                } else {
                    printf("Invalid unit selection.\n");
                }
                break;
            }
            case 3:
                printf("Exiting the converter.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

void display_length_units(LengthUnit units[], int size) {
    printf("Available length units:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i, units[i].name);
    }
}

void display_weight_units(WeightUnit units[], int size) {
    printf("Available weight units:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i, units[i].name);
    }
}

double convert_length(double value, LengthUnit from_unit, LengthUnit to_unit) {
    return (value * from_unit.to_meters) / to_unit.to_meters;
}

double convert_weight(double value, WeightUnit from_unit, WeightUnit to_unit) {
    return (value * from_unit.to_grams) / to_unit.to_grams;
}