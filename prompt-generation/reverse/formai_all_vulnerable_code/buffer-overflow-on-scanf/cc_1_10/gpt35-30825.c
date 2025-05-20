//FormAI DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[20];
    float price;
    int quantity;
} item;

item inventory[MAX_ITEMS];
int num_items = 0;

void add_item() {
    item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter item price: ");
    scanf("%f", &new_item.price);
    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);
    inventory[num_items++] = new_item;
    printf("Item added to inventory.\n");
}

void remove_item() {
    int index;
    printf("Enter index of item to be removed: ");
    scanf("%d", &index);
    if (index < 0 || index >= num_items) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < num_items-1; i++) {
        inventory[i] = inventory[i+1];
    }
    num_items--;
    printf("Item removed from inventory.\n");
}

void display_inventory() {
    printf("Inventory:\n");
    printf("========================================\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d)\t%s\t\t$%.2f\t%d\n", i, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("========================================\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1) Add item to inventory\n");
        printf("2) Remove item from inventory\n");
        printf("3) Display inventory\n");
        printf("4) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}