//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine;

void displayMedicine(medicine m) {
    printf("Name: %s\n", m.name);
    printf("Price: %.2f\n", m.price);
    printf("Quantity: %d\n", m.quantity);
}

int main() {
    int choice;
    char name[50];
    float price;
    int quantity;

    // Create a medical store
    medicine store[100];
    int numMedicines = 0;

    // Main loop
    while (1) {
        // Display menu
        printf("1. Add medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Search for medicine\n");
        printf("4. Delete medicine\n");
        printf("5. Quit\n");

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on choice
        switch (choice) {
            case 1:
                // Add medicine
                printf("Enter medicine name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter medicine price: ");
                scanf("%f", &price);
                printf("Enter medicine quantity: ");
                scanf("%d", &quantity);

                strcpy(store[numMedicines].name, name);
                store[numMedicines].price = price;
                store[numMedicines].quantity = quantity;
                numMedicines++;
                break;
            case 2:
                // Display all medicines
                for (int i = 0; i < numMedicines; i++) {
                    displayMedicine(store[i]);
                    printf("\n");
                }
                break;
            case 3:
                // Search for medicine
                printf("Enter medicine name: ");
                scanf(" %[^\n]%*c", name);

                int found = 0;
                for (int i = 0; i < numMedicines; i++) {
                    if (strcmp(store[i].name, name) == 0) {
                        displayMedicine(store[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Medicine not found!\n");
                }
                break;
            case 4:
                // Delete medicine
                printf("Enter medicine name: ");
                scanf(" %[^\n]%*c", name);

                int deleted = 0;
                for (int i = 0; i < numMedicines; i++) {
                    if (strcmp(store[i].name, name) == 0) {
                        for (int j = i; j < numMedicines - 1; j++) {
                            store[j] = store[j + 1];
                        }
                        numMedicines--;
                        deleted = 1;
                        break;
                    }
                }

                if (!deleted) {
                    printf("Medicine not found!\n");
                }
                break;
            case 5:
                // Quit
                printf("Thank you for using the medical store management system!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}