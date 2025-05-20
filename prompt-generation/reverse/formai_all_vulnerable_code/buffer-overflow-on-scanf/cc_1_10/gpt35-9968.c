//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

struct product {
    char name[20];
    int quantity;
    float price;
};

struct product items[MAX_ITEMS];

int num_items = 0;

void add_item() {
    char name[20];
    int quantity;
    float price;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: ");
    scanf("%f", &price);

    struct product new_item = {0};
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;

    items[num_items++] = new_item;

    printf("Item added successfully!");
}

void find_item() {
    char name[20];
    printf("Enter item name to search: ");
    scanf("%s", name);

    int found = 0;
    for(int i = 0; i < num_items; i++) {
        if(strcmp(name, items[i].name) == 0) {
            printf("Item found: %s, Quantity: %d, Price: %f\n", items[i].name, items[i].quantity, items[i].price);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Item not found!");
    }
}

void display_inventory() {
    if(num_items == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Item Name\tQuantity\tPrice\n");
    printf("----------------------------------------------\n");
    for(int i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t\t%f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;
    
    do {
        printf("\n------------------ Product Inventory System ------------------\n");
        printf("1. Add Item\n");
        printf("2. Find Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_item();
                break;

            case 2:
                find_item();
                break;

            case 3:
                display_inventory();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.");
                break;
        }
    } while(choice != 4);

    return 0;
}