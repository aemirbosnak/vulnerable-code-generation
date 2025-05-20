//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#define INCH_TO_CM 2.54f
#define CM_TO_INCH 0.393701f

typedef struct {
    float value;
    char unit;
} Unit;

void print_unit(Unit unit) {
    switch (unit.unit) {
        case 'I':
            printf("inches\n");
            break;
        case 'C':
            printf("centimeters\n");
            break;
        default:
            printf("Invalid unit\n");
    }
}

Unit convert_inch_to_cm(Unit unit) {
    Unit result;
    result.value = unit.value * INCH_TO_CM;
    result.unit = 'C';
    return result;
}

Unit convert_cm_to_inch(Unit unit) {
    Unit result;
    result.value = unit.value * CM_TO_INCH;
    result.unit = 'I';
    return result;
}

int main() {
    Unit input;
    Unit output;
    char choice;

    printf("Enter value and unit (I for inches, C for centimeters):\n");
    scanf("%f %c", &input.value, &input.unit);

    while (1) {
        printf("\nChoose conversion type:\n");
        printf("1. Inches to Centimeters\n");
        printf("2. Centimeters to Inches\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                output = convert_inch_to_cm(input);
                printf("Converted value: %.2f centimeters\n", output.value);
                print_unit(output);
                break;
            case '2':
                output = convert_cm_to_inch(input);
                printf("Converted value: %.2f inches\n", output.value);
                print_unit(output);
                break;
            case '3':
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nEnter new value and unit (I for inches, C for centimeters):\n");
        scanf("%f %c", &input.value, &input.unit);
    }
}