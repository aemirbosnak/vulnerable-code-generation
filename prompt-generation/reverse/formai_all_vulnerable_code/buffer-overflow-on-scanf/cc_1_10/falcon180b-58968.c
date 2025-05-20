//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 100

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", inventory[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &inventory[num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &inventory[num_items].price);

    num_items++;
}

void delete_item() {
    int i;
    char name[MAX_NAME_LEN];

    printf("Enter item name to delete: ");
    scanf("%s", name);

    for (i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Item %s deleted.\n", name);
            memmove(&inventory[i], &inventory[i + 1], sizeof(Item) * (num_items - i - 1));
            num_items--;
            break;
        }
    }
}

void display_items() {
    int i;

    printf("Item\tQuantity\tPrice\n");
    for (i = 0; i < num_items; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;

    do {
        printf("Product Inventory System\n");
        printf("1. Add item\n");
        printf("2. Delete item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            delete_item();
            break;
        case 3:
            display_items();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}