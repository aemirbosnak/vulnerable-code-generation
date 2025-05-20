//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
    char name[50];
    char company[50];
    float price;
    int quantity;
} medicine;

void addMedicine(medicine *inventory, int *size) {
    printf("Enter medicine name: ");
    scanf("%s", inventory[*size].name);
    printf("Enter medicine company: ");
    scanf("%s", inventory[*size].company);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[*size].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[*size].quantity);
    (*size)++;
}

void sellMedicine(medicine *inventory, int *size) {
    char name[50];
    int quantity;
    printf("Enter medicine name to sell: ");
    scanf("%s", name);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Medicine sold successfully!\n");
                return;
            } else {
                printf("Insufficient quantity!\n");
                return;
            }
        }
    }
    printf("Medicine not found!\n");
}

void displayInventory(medicine *inventory, int size) {
    printf("%-20s%-20s%-10s%-10s\n", "Name", "Company", "Price", "Quantity");
    for (int i = 0; i < size; i++) {
        printf("%-20s%-20s%-10.2f%-10d\n", inventory[i].name, inventory[i].company, inventory[i].price, inventory[i].quantity);
    }
}

void searchMedicine(medicine *inventory, int size) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Company: %s\n", inventory[i].company);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("Medicine not found!\n");
}

int main() {
    medicine inventory[100];
    int size = 0;
    int choice;
    do {
        printf("1. Add medicine\n");
        printf("2. Sell medicine\n");
        printf("3. Display inventory\n");
        printf("4. Search medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(inventory, &size);
                break;
            case 2:
                sellMedicine(inventory, &size);
                break;
            case 3:
                displayInventory(inventory, size);
                break;
            case 4:
                searchMedicine(inventory, size);
                break;
            case 5:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}