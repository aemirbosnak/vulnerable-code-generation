//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    METERS,
    FEET,
    INCHES,
    CENTIMETERS
} Unit;

float conversion_factor[] = {1.0, 3.28084, 39.3701, 0.01};

void print_menu() {
    printf("\nUnit Converter Menu:\n");
    printf("1. Convert from meters to...\n");
    printf("2. Convert from feet to...\n");
    printf("3. Convert from inches to...\n");
    printf("4. Convert from centimeters to...\n");
    printf("5. Quit\n");
}

Unit get_target_unit() {
    int choice;
    Unit target;
    print_menu();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            target = FEET;
            break;
        case 2:
            target = INCHES;
            break;
        case 3:
            target = CENTIMETERS;
            break;
        case 4:
            target = METERS;
            break;
        case 5:
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice! Please try again.\n");
            get_target_unit();
            break;
    }

    return target;
}

float convert(float value, Unit from, Unit to) {
    float result = value * conversion_factor[from] / conversion_factor[to];
    return result;
}

int main() {
    float value, converted_value;
    Unit from, to;

    while (1) {
        printf("Enter the value to convert: ");
        scanf("%f", &value);
        printf("Enter the starting unit (1-Meters, 2-Feet, 3-Inches, 4-Centimeters): ");
        from = get_target_unit();
        printf("Enter the target unit (1-Meters, 2-Feet, 3-Inches, 4-Centimeters): ");
        to = get_target_unit();

        converted_value = convert(value, from, to);
        printf("\nResult: %.2f %s\n", converted_value, (from == METERS && to == CENTIMETERS) ? "centimeters" :
                                                                                          (from == METERS && to == FEET) ? "feet" :
                                                                                          (from == METERS && to == INCHES) ? "inches" :
                                                                                          (from == CENTIMETERS && to == METERS) ? "meters" :
                                                                                          (from == CENTIMETERS && to == FEET) ? "feet" :
                                                                                          (from == CENTIMETERS && to == INCHES) ? "inches" :
                                                                                          "");
    }

    return EXIT_SUCCESS;
}