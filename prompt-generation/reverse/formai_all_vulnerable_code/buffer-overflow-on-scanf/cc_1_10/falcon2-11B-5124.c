//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    float price;
    int quantity;
} Item;

void display_menu() {
    printf("1. Add item\n2. Update item\n3. Delete item\n4. View inventory\n5. Exit\n");
}

int main() {
    Item inventory[100]; // Array to hold items
    int choice, index;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add item
                printf("Enter item ID: ");
                scanf("%d", &index);
                scanf("Enter item name: ");
                fgets(inventory[index].name, sizeof(inventory[index].name), stdin);
                scanf("Enter item price: ");
                scanf("Enter item quantity: ");
                break;
            case 2: // Update item
                printf("Enter item ID: ");
                scanf("%d", &index);
                printf("Enter new item name: ");
                fgets(inventory[index].name, sizeof(inventory[index].name), stdin);
                printf("Enter new item price: ");
                scanf("Enter new item quantity: ");
                break;
            case 3: // Delete item
                printf("Enter item ID: ");
                scanf("%d", &index);
                break;
            case 4: // View inventory
                for (int i = 0; i < 100; i++) {
                    printf("Item %d: %s - $%.2f - %d\n", i+1, inventory[i].name, inventory[i].price, inventory[i].quantity);
                }
                break;
            case 5: // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}