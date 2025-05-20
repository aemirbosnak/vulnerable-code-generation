//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining a struct to hold medicine details
typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
} Medicine;

// function to add new medicine to inventory
void addMedicine(Medicine *med, int *invCount) {
    printf("Enter the name of the medicine: ");
    scanf("%s", med[*invCount].name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &med[*invCount].quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &med[*invCount].price);

    (*invCount)++;  // incrementing inventory count
    printf("Medicine added successfully!\n");
}

// function to search for a medicine in the inventory
void searchMedicine(Medicine *med, int invCount) {
    char searchName[50];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", searchName);

    for (int i = 0; i < invCount; i++) {
        if (strcmp(searchName, med[i].name) == 0) {
            printf("Found medicine in inventory!\n");
            printf("Medicine name: %s\nQuantity: %d\nPrice: %.2f\n", med[i].name, med[i].quantity, med[i].price);
            return;
        }
    }
    printf("Medicine not found in inventory.\n");
}

// function to update the details of a medicine in the inventory
void updateMedicine(Medicine *med, int invCount) {
    char updateName[50];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", updateName);

    for (int i = 0; i < invCount; i++) {
        if (strcmp(updateName, med[i].name) == 0) {
            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &med[i].quantity);

            printf("Enter the new price of the medicine: ");
            scanf("%f", &med[i].price);

            printf("Medicine details updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found in inventory.\n");
}

// function to display the entire inventory
void showInventory(Medicine *med, int invCount) {
    printf("Current inventory:\n");

    for (int i = 0; i < invCount; i++) {
        printf("Medicine name: %s\nQuantity: %d\nPrice: %.2f\n\n", med[i].name, med[i].quantity, med[i].price);
    }
}

int main() {
    Medicine inventory[100];  // array to hold medicine inventory
    int invCount = 0;  // variable to hold count of medicines in inventory
    int choice;

    printf("Welcome to Grateful Medical Store Management System!\n");

    do {
        printf("\nMENU:\n");
        printf("1. Add new medicine to inventory\n");
        printf("2. Search for a medicine in inventory\n");
        printf("3. Update medicine details in inventory\n");
        printf("4. Display entire inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(inventory, &invCount);
                break;
            case 2:
                searchMedicine(inventory, invCount);
                break;
            case 3:
                updateMedicine(inventory, invCount);
                break;
            case 4:
                showInventory(inventory, invCount);
                break;
            case 5:
                printf("Thank you for using Grateful Medical Store Management System!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}