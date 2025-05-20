//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100   // maximum size of inventory

struct Medicine {
    char name[50];
    int quantity;
    float price;
};

struct Medicine inventory[MAX];

int count = 0;

void addMedicine() {
    if (count == MAX) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    struct Medicine newMed;
    printf("Enter name of medicine: ");
    scanf("%s", newMed.name);
    printf("Enter quantity: ");
    scanf("%d", &newMed.quantity);
    printf("Enter price per unit: ");
    scanf("%f", &newMed.price);

    inventory[count] = newMed;
    count++;

    printf("Medicine added successfully!\n");
}

void displayMedicine() {
    printf("|%-25s|%-10s|%-10s|\n", "Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        printf("|%-25s|%-10d|%-10.2f|\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void removeMedicine() {
    int index;
    printf("Enter index of medicine to remove: ");
    scanf("%d", &index);
    if (index >= count) {
        printf("Index out of bounds.\n");
        return;
    }
    for (int i = index; i < count - 1; i++) {
        inventory[i] = inventory[i+1];
    }
    count--;
    printf("Medicine removed successfully!\n");
}

void updateMedicine() {
    int index;
    printf("Enter index of medicine to update: ");
    scanf("%d", &index);
    if (index >= count) {
        printf("Index out of bounds.\n");
        return;
    }
    printf("Enter new name of medicine (press enter to keep the old name): ");
    scanf("%s", inventory[index].name);
    printf("Enter new quantity (press 0 to keep the old quantity): ");
    scanf("%d", &inventory[index].quantity);
    printf("Enter new price per unit (press 0.00 to keep the old price): ");
    scanf("%f", &inventory[index].price);
    printf("Medicine updated successfully!\n");
}

void searchMedicine() {
    char keyword[50];
    printf("Enter keyword to search for: ");
    scanf("%s", keyword);
    printf("|%-25s|%-10s|%-10s|\n", "Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        if (strstr(inventory[i].name, keyword)) {
            printf("|%-25s|%-10d|%-10.2f|\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nWelcome to medical store management system.\n");
        printf(" 1. Add medicine\n");
        printf(" 2. Display medicine\n");
        printf(" 3. Remove medicine\n");
        printf(" 4. Update medicine\n");
        printf(" 5. Search medicine\n");
        printf(" 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicine();
                break;
            case 3:
                removeMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                searchMedicine();
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}