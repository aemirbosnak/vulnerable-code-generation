//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

struct product {
    int id;
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    float price;
    int quantity;
};

struct product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    printf("Enter product name (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", inventory[num_products].name);

    printf("Enter product description (max %d characters): ", MAX_DESCRIPTION_LEN - 1);
    scanf("%s", inventory[num_products].description);

    printf("Enter product price: ");
    scanf("%f", &inventory[num_products].price);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_products].quantity);

    num_products++;
}

void remove_product() {
    if (num_products == 0) {
        printf("Error: Inventory is empty.\n");
        return;
    }

    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Product not found.\n");
        return;
    }

    num_products--;
}

void view_inventory() {
    if (num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("ID\tName\tDescription\tPrice\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].description, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    system("clear");

    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. View inventory\n");
        printf("4. Exit\n");
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
                view_inventory();
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