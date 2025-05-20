//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} item;

item inventory[MAX_ITEMS];
int num_items = 0;

void add_item() {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: ");
    scanf("%f", &price);

    strcpy(inventory[num_items].name, name);
    inventory[num_items].quantity = quantity;
    inventory[num_items].price = price;

    num_items++;
}

void remove_item() {
    int index;

    printf("Enter item index to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_items) {
        num_items--;

        for (int i = index; i < num_items; i++) {
            strcpy(inventory[i].name, inventory[i+1].name);
            inventory[i].quantity = inventory[i+1].quantity;
            inventory[i].price = inventory[i+1].price;
        }
    } else {
        printf("Invalid item index.\n");
    }
}

void display_items() {
    for (int i = 0; i < num_items; i++) {
        printf("%s - Quantity: %d - Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add item\n2. Remove item\n3. Display items\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_items();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}