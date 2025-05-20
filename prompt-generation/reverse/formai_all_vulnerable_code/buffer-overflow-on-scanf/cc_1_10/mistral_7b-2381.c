//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define PRODUCT_COUNT 100

typedef struct Product {
    int code;
    char name[50];
    int reorder_level;
    int qty_in_stock;
} Product;

void display_product(const Product *product) {
    printf("\nProduct Code: %d", product->code);
    printf("\nName: %s", product->name);
    printf("\nReorder Level: %d", product->reorder_level);
    printf("\nQuantity in Stock: %d\n", product->qty_in_stock);
}

void update_reorder_level(Product *product, int new_level) {
    product->reorder_level = new_level;
    printf("\nReorder level for product %d updated to %d.\n", product->code, new_level);
}

bool is_below_reorder_level(const Product *product) {
    if (product->qty_in_stock < product->reorder_level) {
        return true;
    }
    return false;
}

int main() {
    Product warehouse[PRODUCT_COUNT];

    printf("\n----- Warehouse Management System -----\n");

    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("\nProduct %d details:\n", i + 1);
        printf("Enter product code: ");
        scanf("%d", &warehouse[i].code);
        fflush(stdin);
        printf("Enter product name: ");
        fgets(warehouse[i].name, sizeof(warehouse[i].name), stdin);
        strtok(warehouse[i].name, "\n");
        printf("Enter reorder level: ");
        scanf("%d", &warehouse[i].reorder_level);
        printf("Enter quantity in stock: ");
        scanf("%d", &warehouse[i].qty_in_stock);

        display_product(&warehouse[i]);

        if (is_below_reorder_level(&warehouse[i])) {
            printf("Product %d is below reorder level!\n", i + 1);
        }

        int choice;
        printf("\nDo you want to update the reorder level for product %d (1 - Yes, 0 - No)? ", i + 1);
        scanf("%d", &choice);

        if (choice == 1) {
            int new_level;
            printf("Enter new reorder level: ");
            scanf("%d", &new_level);
            update_reorder_level(&warehouse[i], new_level);
        }
    }

    return 0;
}