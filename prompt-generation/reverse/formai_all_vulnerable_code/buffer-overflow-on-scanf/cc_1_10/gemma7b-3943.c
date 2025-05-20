//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void display_items() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity > 0) {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void add_item() {
    Item new_item;

    printf("Enter item name: ");
    scanf("%s", new_item.name);

    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);

    printf("Enter item price: ");
    scanf("%f", &new_item.price);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity == 0) {
            items[i] = new_item;
            break;
        }
    }

    printf("Item added successfully!\n");
}

void update_item() {
    char item_name[20];

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            printf("Enter updated quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter updated price: ");
            scanf("%f", &items[i].price);

            printf("Item updated successfully!\n");
            break;
        }
    }

    printf("Item not found.\n");
}

void delete_item() {
    char item_name[20];

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            items[i].quantity = 0;

            printf("Item deleted successfully!\n");
            break;
        }
    }

    printf("Item not found.\n");
}

int main() {
    int choice;

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("1. Display Items\n");
        printf("2. Add Item\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_items();
                break;
            case 2:
                add_item();
                break;
            case 3:
                update_item();
                break;
            case 4:
                delete_item();
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Do you want to continue? (Y/N): ");
        char continue_yn;
        scanf("%c", &continue_yn);

        if (continue_yn == 'N') {
            break;
        }
    }

    printf("Thank you for using the Medical Store Management System!\n");

    return 0;
}