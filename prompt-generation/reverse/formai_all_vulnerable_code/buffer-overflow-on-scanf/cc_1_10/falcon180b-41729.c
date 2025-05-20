//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

void add_item(struct item* inventory, int count) {
    printf("Enter item name: ");
    scanf("%s", inventory[count].name);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[count].quantity);
    printf("Enter item price: ");
    scanf("%f", &inventory[count].price);
}

void display_items(struct item* inventory) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i].name[0]!= '\0') {
            printf("%s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: $%.2f\n\n", inventory[i].price);
        }
    }
}

int main() {
    struct item inventory[MAX_ITEMS];
    int count = 0;

    while (count < MAX_ITEMS) {
        printf("Do you want to add an item? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            add_item(inventory, count);
            count++;
        } else if (choice == 'n' || choice == 'N') {
            display_items(inventory);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}