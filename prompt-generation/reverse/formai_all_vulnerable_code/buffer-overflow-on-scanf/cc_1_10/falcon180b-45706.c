//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[100];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int numItems = 0;

void addItem() {
    printf("Enter item ID: ");
    scanf("%d", &items[numItems].id);

    printf("Enter item name: ");
    scanf("%s", items[numItems].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);

    numItems++;
}

void displayItems() {
    printf("\nItem ID\tItem Name\tQuantity\tPrice\n");

    for (int i = 0; i < numItems; i++) {
        printf("%d\t%s\t%d\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

void searchItem() {
    printf("Enter item ID to search: ");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < numItems; i++) {
        if (items[i].id == id) {
            printf("\nItem ID\tItem Name\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
            return;
        }
    }

    printf("Item not found.\n");
}

void updateItem() {
    printf("Enter item ID to update: ");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < numItems; i++) {
        if (items[i].id == id) {
            printf("\nEnter new item name: ");
            scanf("%s", items[i].name);

            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter new item price: ");
            scanf("%f", &items[i].price);

            printf("\nItem updated successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

void deleteItem() {
    printf("Enter item ID to delete: ");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < numItems; i++) {
        if (items[i].id == id) {
            for (int j = i; j < numItems - 1; j++) {
                items[j] = items[j + 1];
            }

            numItems--;

            printf("\nItem deleted successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("\n1. Add item\n2. Display items\n3. Search item\n4. Update item\n5. Delete item\n6. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem();
            break;
        case 2:
            displayItems();
            break;
        case 3:
            searchItem();
            break;
        case 4:
            updateItem();
            break;
        case 5:
            deleteItem();
            break;
        case 6:
            printf("\nExiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}