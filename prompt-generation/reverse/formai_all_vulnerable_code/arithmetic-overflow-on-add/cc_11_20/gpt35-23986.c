//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE_NAME 50
#define MAX_MEDICINE_DESCRIPTION 100
#define MAX_MEDICINE_QUANTITY 100

struct Medicine {
    char name[MAX_MEDICINE_NAME];
    char description[MAX_MEDICINE_DESCRIPTION];
    int quantity;
};

int main() {
    int choice, i, j, index, quantity;
    char searchName[MAX_MEDICINE_NAME];
    struct Medicine medicineList[MAX_MEDICINE_QUANTITY];

    do {
        // Welcome message
        printf("Welcome to the Medical Store Management System!\n");
        printf("Please choose from the following options:\n");
        printf("1. Add a new medicine\n");
        printf("2. View medicine list\n");
        printf("3. Search for a medicine\n");
        printf("4. Update medicine quantity\n");
        printf("5. Exit\n");

        // User input
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch(choice) {
            case 1: // Add a new medicine
                printf("Enter the name of the medicine: ");
                scanf("%s", medicineList[i].name);
                printf("Enter a description of the medicine: ");
                scanf("%s", medicineList[i].description);
                printf("Enter the quantity of the medicine: ");
                scanf("%d", &medicineList[i].quantity);
                printf("Medicine added successfully!\n");
                i++;
                break;

            case 2: // View medicine list
                printf("Medicine List:\n");
                for (j = 0; j < i; j++) {
                    printf("%d. Name: %s, Description: %s, Quantity: %d\n", j+1, medicineList[j].name, medicineList[j].description, medicineList[j].quantity);
                }
                break;

            case 3: // Search for a medicine
                printf("Enter the name of the medicine: ");
                scanf("%s", searchName);
                for (j = 0; j < i; j++) {
                    if (strcmp(searchName, medicineList[j].name) == 0) {
                        printf("Search result: Name: %s, Description: %s, Quantity: %d\n", medicineList[j].name, medicineList[j].description, medicineList[j].quantity);
                        break;
                    }
                }
                if (j == i) {
                    printf("Sorry, the medicine you are searching for is not in the list.\n");
                }
                break;

            case 4: // Update medicine quantity
                printf("Enter the name of the medicine you want to update the quantity for: ");
                scanf("%s", searchName);
                for (j = 0; j < i; j++) {
                    if (strcmp(searchName, medicineList[j].name) == 0) {
                        index = j;
                        break;
                    }
                }
                if (j == i) {
                    printf("Sorry, the medicine you want to update the quantity for is not in the list.\n");
                }
                else {
                    printf("Enter the new quantity of the medicine: ");
                    scanf("%d", &quantity);
                    medicineList[index].quantity = quantity;
                    printf("Medicine quantity updated successfully!\n");
                }
                break;

            case 5: // Exit
                printf("Thank you for using the Medical Store Management System.\n");
                exit(0);
                break;

            default: // Invalid choice
                printf("Invalid choice, please try again.\n");
                break;
        }

    } while(choice != 5);

    return 0;
}