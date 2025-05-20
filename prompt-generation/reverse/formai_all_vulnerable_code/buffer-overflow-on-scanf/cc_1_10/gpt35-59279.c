//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct medicine {
    char name[20];
    int quantity;
    float price;
};

void addMedicine(struct medicine inventory[], int* itemCount);
void removeMedicine(struct medicine inventory[], int* itemCount);
void displayInventory(struct medicine inventory[], int itemCount);

int main() {
    struct medicine inventory[MAX_SIZE];
    int itemCount = 0;
    int choice;

    printf("Welcome to the Future Medical Store Management System!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Display Inventory\n");
        printf("4. Exit Program\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(inventory, &itemCount);
                break;
            case 2:
                removeMedicine(inventory, &itemCount);
                break;
            case 3:
                displayInventory(inventory, itemCount);
                break;
            case 4:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addMedicine(struct medicine inventory[], int* itemCount) {
    char name[20];
    int quantity;
    float price;

    printf("\nEnter Medicine Name: ");
    scanf("%s", name);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Price: ");
    scanf("%f", &price);

    struct medicine newMed = {0};
    strncpy(newMed.name, name, sizeof(newMed.name) - 1);
    newMed.quantity = quantity;
    newMed.price = price;

    inventory[(*itemCount)] = newMed;
    (*itemCount)++;

    printf("%s added to Inventory successfully.\n", name);
}

void removeMedicine(struct medicine inventory[], int* itemCount) {
    char name[20];

    printf("\nEnter Medicine Name: ");
    scanf("%s", name);

    for (int i = 0; i < (*itemCount); i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < (*itemCount); j++) {
                inventory[j] = inventory[j+1];
            }
            (*itemCount)--;
            printf("%s removed from Inventory successfully.\n", name);
            return;
        }
    }

    printf("%s was not found in Inventory.\n", name);
}

void displayInventory(struct medicine inventory[], int itemCount) {
    printf("\nMedicine Inventory:\n");

    if (itemCount == 0) {
        printf("No items in inventory.\n");
    }

    for (int i = 0; i < itemCount; i++) {
        printf("%s - Quantity: %d - Price: Rs.%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}