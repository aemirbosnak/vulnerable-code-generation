//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100

struct product {
    char name[100];
    int quantity;
    float price;
};

struct product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    struct product p;

    printf("Enter product name: ");
    fgets(p.name, 100, stdin);

    printf("Enter quantity: ");
    scanf("%d", &p.quantity);

    printf("Enter price: ");
    scanf("%f", &p.price);

    inventory[num_products] = p;
    num_products++;

    printf("Product added successfully!\n");
}

void view_inventory() {
    printf("Product name\tQuantity\tPrice\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_product() {
    char query[100];

    printf("Enter product name: ");
    fgets(query, 100, stdin);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, query) == 0) {
            printf("Product found!\n");
            printf("Product name: %s", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }

    printf("Product not found!\n");
}

int main() {
    int choice;

    do {
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Search Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_inventory();
                break;
            case 3:
                search_product();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid Choice!");
        }

        printf("Press Enter to continue...");
        getchar();
        system("clear");
    } while (1);

    return 0;
}