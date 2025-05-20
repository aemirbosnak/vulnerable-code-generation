//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

struct product inventory[100];
int inventory_count = 0;

void add_product() {
    char name[50];
    int quantity;
    float price;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    printf("Enter product price: ");
    scanf("%f", &price);

    strcpy(inventory[inventory_count].name, name);
    inventory[inventory_count].quantity = quantity;
    inventory[inventory_count].price = price;

    inventory_count++;
}

void remove_product() {
    char name[50];

    printf("Enter product name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < inventory_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < inventory_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            inventory_count--;
            break;
        }
    }
}

void update_product() {
    char name[50];
    int quantity;
    float price;

    printf("Enter product name to update: ");
    scanf("%s", name);

    for (int i = 0; i < inventory_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new product quantity: ");
            scanf("%d", &quantity);

            printf("Enter new product price: ");
            scanf("%f", &price);

            inventory[i].quantity = quantity;
            inventory[i].price = price;
            break;
        }
    }
}

void list_products() {
    for (int i = 0; i < inventory_count; i++) {
        printf("%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. List products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                update_product();
                break;
            case 4:
                list_products();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}