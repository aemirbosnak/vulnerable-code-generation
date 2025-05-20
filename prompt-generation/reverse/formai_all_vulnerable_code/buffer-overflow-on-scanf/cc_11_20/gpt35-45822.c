//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define structure for medicine
typedef struct Medicine {
    char name[50];
    char manufacturer[50];
    float price;
} Medicine;

int main() {
    // Declare variables
    int choice, count = 0, i;
    float total = 0;
    char search[50];
    Medicine inventory[100];

    // Print menu for user to select from
    while (1) {
        printf("\nChoose an option:");
        printf("\n1. Add medicine to inventory");
        printf("\n2. Search for a medicine");
        printf("\n3. Display inventory");
        printf("\n4. Total sales");
        printf("\n5. Exit");

        // Take input from user for choice
        scanf("%d", &choice);

        // Perform actions based on user choice
        switch(choice) {
            case 1:
                // Add a medicine to inventory
                printf("\nEnter details of medicine: ");
                printf("\nName: ");
                scanf("%s", inventory[count].name);
                printf("Manufacturer: ");
                scanf("%s", inventory[count].manufacturer);
                printf("Price: ");
                scanf("%f", &inventory[count].price);
                count++;
                break;

            case 2:
                // Search for a medicine in inventory
                printf("\nEnter name of medicine: ");
                scanf("%s", search);
                for (i = 0; i < count; i++) {
                    if (strcmp(search, inventory[i].name) == 0) {
                        printf("\nMedicine found!");
                        printf("\nName: %s", inventory[i].name);
                        printf("\nManufacturer: %s", inventory[i].manufacturer);
                        printf("\nPrice: %.2f", inventory[i].price);
                        break;
                    }
                }
                if (i == count) {
                    printf("\nMedicine not found!");
                }
                break;

            case 3:
                // Display all medicines in inventory
                printf("\nMedicine inventory: ");
                for (i = 0; i < count; i++) {
                    printf("\nName: %s", inventory[i].name);
                    printf("\nManufacturer: %s", inventory[i].manufacturer);
                    printf("\nPrice: %.2f", inventory[i].price);
                    printf("\n");
                }
                break;

            case 4:
                // Total sales calculation
                printf("\nCalculating total sales...");
                for (i = 0; i < count; i++) {
                    total += inventory[i].price;
                }
                printf("\nTotal Sales: %.2f", total);
                break;

            case 5:
                // Exit program
                printf("\nExiting program...\n");
                exit(0);
                break;

            default:
                // Error message for invalid choice
                printf("\nInvalid choice! Please try again.");
        }
    }

    return 0;
}