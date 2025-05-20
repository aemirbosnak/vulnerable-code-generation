//FormAI DATASET v1.0 Category: Product Inventory System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

void addProduct(struct product* inventory, int* count, int id, char name[], float price, int quantity) {
    inventory[*count].id = id;
    strcpy(inventory[*count].name, name);
    inventory[*count].price = price;
    inventory[*count].quantity = quantity;
    (*count)++;
}

void removeProduct(struct product* inventory, int* count, int id) {
    int i, j;
    for (i = 0; i < *count; i++) {
        if (inventory[i].id == id) {
            for (j = i; j < *count - 1; j++) {
                inventory[j].id = inventory[j + 1].id;
                strcpy(inventory[j].name, inventory[j + 1].name);
                inventory[j].price = inventory[j + 1].price;
                inventory[j].quantity = inventory[j + 1].quantity;
            }
            (*count)--;
            break;
        }
    }
}

void displayInventory(struct product* inventory, int count) {
    int i;
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (i = 0; i < count; i++) {
        printf("%d\t%-16s%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    struct product inventory[50];
    int count = 0;
    int choice, id, quantity;
    char name[50];
    float price;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product price: ");
                scanf("%f", &price);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                addProduct(inventory, &count, id, name, price, quantity);
                printf("Product added successfully!\n");
                break;

            case 2:
                printf("Enter product ID: ");
                scanf("%d", &id);
                removeProduct(inventory, &count, id);
                printf("Product removed successfully!\n");
                break;

            case 3:
                displayInventory(inventory, count);
                break;

            case 4:
                printf("Thank you for using the Product Inventory System!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}