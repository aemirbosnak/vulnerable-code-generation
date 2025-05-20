//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERSIONS 10
#define MAX_UNITS_PER_CONVERSION 3

typedef struct {
    char *input_unit;
    char *output_unit;
    double conversion_factor;
} Conversion;

int main() {
    char input[50];
    char output_unit[50];
    char *token;
    Conversion conversions[MAX_CONVERSIONS];
    int num_conversions = 0;
    int choice;
    
    printf("Welcome to the Cyberpunk Unit Converter!\n");
    printf("Enter a unit to convert from: ");
    scanf("%s", input);
    
    while (num_conversions < MAX_CONVERSIONS) {
        printf("Enter a unit to convert to (or enter 'done' to finish): ");
        scanf("%s", output_unit);
        
        if (strcmp(output_unit, "done") == 0) {
            break;
        }
        
        num_conversions++;
        conversions[num_conversions - 1].input_unit = strdup(input);
        conversions[num_conversions - 1].output_unit = strdup(output_unit);
        
        printf("Enter the conversion factor between %s and %s: ", input, output_unit);
        if (scanf("%lf", &conversions[num_conversions - 1].conversion_factor)!= 1) {
            printf("Invalid input. Skipping this conversion.\n");
            num_conversions--;
        }
    }
    
    printf("Enter a value to convert: ");
    scanf("%lf", &conversions[0].conversion_factor);
    
    while (1) {
        printf("\nChoose a conversion:\n");
        for (int i = 0; i < num_conversions; i++) {
            printf("%d. %s to %s\n", i + 1, conversions[i].input_unit, conversions[i].output_unit);
        }
        
        printf("0. Exit\n");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        if (choice < 1 || choice > num_conversions) {
            printf("Invalid choice. Try again.\n");
            continue;
        }
        
        double result = conversions[choice - 1].conversion_factor * conversions[0].conversion_factor;
        printf("%s = %.2lf %s\n", conversions[0].input_unit, result, conversions[choice - 1].output_unit);
    }
    
    return 0;
}