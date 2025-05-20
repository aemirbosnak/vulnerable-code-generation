//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    float factor;
} Scale;

Scale scales[] = {
    {"Celsius", 1.0},
    {"Fahrenheit", 1.8},
    {"Kelvin", 1.0},
    {"Rankine", 1.8},
    {NULL, 0.0}
};

void print_menu() {
    int i = 0;
    printf("\nTemperature Converter Menu:\n");
    printf("----------------------------------------\n");
    while (scales[i].name != NULL) {
        printf("%s %s\n", scales[i].name, (i == 0) ? " [Current Scale]" : "");
        i++;
    }
    printf("\n0. Exit\n");
}

float convert(float temperature, Scale from_scale, Scale to_scale) {
    return to_scale.factor * temperature + to_scale.factor * (from_scale.factor - 1.0);
}

int main() {
    char input[100];
    float current_temperature, target_temperature;
    Scale from_scale = {NULL, 0.0}, to_scale = {NULL, 0.0};

    while (1) {
        print_menu();
        scanf("%s", input);

        if (input[0] >= '0' && input[0] <= '9') {
            // Exit
            break;
        }

        int i = 0;
        while (scales[i].name != NULL && strcmp(input, scales[i].name)) {
            i++;
        }

        if (scales[i].name == NULL) {
            printf("Invalid selection.\n");
            continue;
        }

        from_scale = scales[i];
        printf("Current temperature scale: %s\n", from_scale.name);
        scanf("%f", &current_temperature);

        print_menu();
        scanf("%s", input);

        int j = 0;
        while (scales[j].name != NULL && strcmp(input, scales[j].name)) {
            j++;
        }

        if (scales[j].name == NULL) {
            printf("Invalid selection.\n");
            continue;
        }

        to_scale = scales[j];
        printf("Target temperature scale: %s\n", to_scale.name);
        scanf("%f", &target_temperature);

        float converted_temperature = convert(current_temperature, from_scale, to_scale);
        printf("Converted temperature: %.2f %s\n", converted_temperature, to_scale.name);
    }

    return 0;
}