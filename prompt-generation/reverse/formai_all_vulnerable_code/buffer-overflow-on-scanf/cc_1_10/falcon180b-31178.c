//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10
#define MAX_FACTOR 1000

struct unit_conversion {
    char from_unit[10];
    char to_unit[10];
    double factor;
};

void print_menu() {
    printf("\nUnit Converter Menu:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Volume\n");
    printf("4. Temperature\n");
    printf("5. Time\n");
    printf("6. Speed\n");
    printf("7. Power\n");
    printf("8. Energy\n");
    printf("9. Force\n");
    printf("10. Pressure\n");
}

void get_unit_conversion(struct unit_conversion *conversion) {
    printf("\nEnter the unit to convert from: ");
    scanf("%s", conversion->from_unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", conversion->to_unit);
    printf("Enter the conversion factor: ");
    scanf("%lf", &conversion->factor);
}

int main() {
    struct unit_conversion conversions[MAX_UNITS];
    int num_conversions = 0;
    int choice;

    printf("Welcome to the Unit Converter!\n");

    while(1) {
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            if(num_conversions >= MAX_UNITS) {
                printf("You have reached the maximum number of conversions.\n");
            } else {
                get_unit_conversion(&conversions[num_conversions]);
                num_conversions++;
                printf("\nConversion added successfully!\n");
            }
        } else if(choice == 2) {
            printf("\nExiting program...\n");
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}