//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} medicine;

int main() {
    int num_meds, choice;
    printf("Enter the number of medicines in inventory: ");
    scanf("%d", &num_meds);

    // Allocate memory for array of medicines
    medicine *meds = (medicine*) malloc(num_meds * sizeof(medicine));

    // Initialize medicines in inventory
    for (int i = 0; i < num_meds; i++) {
        printf("\nEnter details for medicine %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &(meds[i].id));
        printf("Name: ");
        scanf("%s", &(meds[i].name));
        printf("Quantity: ");
        scanf("%d", &(meds[i].quantity));
        printf("Price: ");
        scanf("%f", &(meds[i].price));
    }

    // Menu driven program
    do {
        printf("\n");
        printf("1. Display all medicines in inventory\n");
        printf("2. Search for a medicine by ID\n");
        printf("3. Add a new medicine to inventory\n");
        printf("4. Update details of a medicine\n");
        printf("5. Delete a medicine from inventory\n");
        printf("6. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Display all medicines in inventory
                printf("\nMedicine Inventory:\n");
                printf("ID\tName\t\tQuantity\tPrice\n");
                for (int i = 0; i < num_meds; i++) {
                    printf("%d\t%-10s\t%d\t\t%.2f\n", meds[i].id, meds[i].name, meds[i].quantity, meds[i].price);
                }
                break;

            case 2: { // Search for a medicine by ID
                int search_id, found = 0;
                printf("\nEnter ID of medicine to search: ");
                scanf("%d", &search_id);
                for (int i = 0; i < num_meds; i++) {
                    if (meds[i].id == search_id) {
                        printf("\nMedicine with ID %d found:\n", search_id);
                        printf("Name: %s\n", meds[i].name);
                        printf("Quantity: %d\n", meds[i].quantity);
                        printf("Price: %.2f\n", meds[i].price);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nMedicine with ID %d not found!\n", search_id);
                }
                break;
            }

            case 3: { // Add a new medicine to inventory
                num_meds++;
                // Resize memory for array of medicines
                meds = (medicine*) realloc(meds, num_meds * sizeof(medicine));
                printf("\nEnter details for new medicine:\n");
                printf("ID: ");
                scanf("%d", &(meds[num_meds - 1].id));
                printf("Name: ");
                scanf("%s", &(meds[num_meds - 1].name));
                printf("Quantity: ");
                scanf("%d", &(meds[num_meds - 1].quantity));
                printf("Price: ");
                scanf("%f", &(meds[num_meds - 1].price));
                printf("\nNew medicine added to inventory!\n");
                break;
            }

            case 4: { // Update details of a medicine
                int update_id, found = 0;
                printf("\nEnter ID of medicine to update: ");
                scanf("%d", &update_id);
                for (int i = 0; i < num_meds; i++) {
                    if (meds[i].id == update_id) {
                        printf("\nEnter new details for medicine with ID %d:\n", update_id);
                        printf("Name: ");
                        scanf("%s", &(meds[i].name));
                        printf("Quantity: ");
                        scanf("%d", &(meds[i].quantity));
                        printf("Price: ");
                        scanf("%f", &(meds[i].price));
                        printf("\nDetails for medicine with ID %d updated!\n", update_id);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nMedicine with ID %d not found!\n", update_id);
                }
                break;
            }

            case 5: { // Delete a medicine from inventory
                int delete_id, found = 0;
                printf("\nEnter ID of medicine to delete: ");
                scanf("%d", &delete_id);
                for (int i = 0; i < num_meds; i++) {
                    if (meds[i].id == delete_id) {
                        for (int j = i; j < num_meds - 1; j++) {
                            // Shift elements to fill gap
                            meds[j] = meds[j + 1];
                        }
                        num_meds--;
                        // Resize memory for array of medicines
                        meds = (medicine*) realloc(meds, num_meds * sizeof(medicine));
                        printf("\nMedicine with ID %d deleted from inventory!\n", delete_id);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nMedicine with ID %d not found!\n", delete_id);
                }
                break;
            }

            case 6: // Exit program
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
        }
    } while (choice != 6);

    // Free memory for array of medicines
    free(meds);

    return 0;
}