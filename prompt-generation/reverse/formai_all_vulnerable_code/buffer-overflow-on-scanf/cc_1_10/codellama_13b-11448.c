//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: real-life
/*
 * Unit Converter Example Program
 */

#include <stdio.h>
#include <stdlib.h>

// Define the units
#define LENGTH 1
#define WEIGHT 2
#define VOLUME 3

// Define the conversion factors
#define CM_TO_IN 2.54
#define KG_TO_LB 2.2046
#define L_TO_GAL 3.785

// Define the user interface
void print_menu();
void convert_units(int choice);

int main() {
    int choice;

    // Print the menu
    print_menu();

    // Get the user's choice
    scanf("%d", &choice);

    // Convert the units
    convert_units(choice);

    return 0;
}

void print_menu() {
    printf("Please select a unit to convert:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Volume\n");
}

void convert_units(int choice) {
    switch (choice) {
        case LENGTH:
            printf("Enter the length in cm: ");
            float cm;
            scanf("%f", &cm);
            printf("The length is %.2f inches.\n", cm * CM_TO_IN);
            break;
        case WEIGHT:
            printf("Enter the weight in kg: ");
            float kg;
            scanf("%f", &kg);
            printf("The weight is %.2f pounds.\n", kg * KG_TO_LB);
            break;
        case VOLUME:
            printf("Enter the volume in liters: ");
            float l;
            scanf("%f", &l);
            printf("The volume is %.2f gallons.\n", l * L_TO_GAL);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}