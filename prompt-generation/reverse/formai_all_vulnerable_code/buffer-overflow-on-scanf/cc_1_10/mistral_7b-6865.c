//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *name;
    double conversion_factor;
} Unit;

Unit units[] = {
    {"Inch", 0.0254},
    {"Foot", 0.3048},
    {"Centimeter", 1.0},
    {"Meter", 10.0},
    {"Kilometer", 1000.0},
};

int main() {
    int input_index = 0;
    int output_index = 0;
    double value;

    while (1) {
        printf("\nUnit Converter Menu:\n");
        printf("-----------------------\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s\n", i + 1, units[i].name);
        }
        printf("Enter the index of the input unit: ");
        scanf("%d", &input_index);
        printf("Enter the value in that unit: ");
        scanf("%lf", &value);

        printf("\nAvailable output units:\n");
        for (int i = 0; i < 5; i++) {
            if (i != input_index) {
                printf("%d. %s\n", i + 1, units[i].name);
            }
        }
        printf("Enter the index of the output unit: ");
        scanf("%d", &output_index);

        double result = value * units[output_index].conversion_factor / units[input_index].conversion_factor;
        printf("\n%0.2lf %s is equal to %0.2lf %s\n", value, units[input_index].name, result, units[output_index].name);

        system("pause");
        system("cls");
    }

    return 0;
}