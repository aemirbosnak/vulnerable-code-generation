//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000
#define FILE_NAME "inventory.dat"
typedef struct {
    char name[MAX_NAME_LEN];
    int stock;
    float price;
} Product;
Product inventory[MAX_PRODUCTS];
int num_products = 0;
void load_inventory() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("Error loading inventory file.\n");
        exit(1);
    }
    fread(inventory, sizeof(Product), MAX_PRODUCTS, file);
    fclose(file);
    num_products = sizeof(inventory) / sizeof(Product);
}
void save_inventory() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("Error saving inventory file.\n");
        exit(1);
    }
    fwrite(inventory, sizeof(Product), num_products, file);
    fclose(file);
}
void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }
    printf("Enter product name: ");
    fgets(inventory[num_products].name, MAX_NAME_LEN, stdin);
    inventory[num_products].name[strcspn(inventory[num_products].name, "\n")] = '\0';
    printf("Enter stock level: ");
    scanf("%d", &inventory[num_products].stock);
    printf("Enter price: ");
    scanf("%f", &inventory[num_products].price);
    num_products++;
    save_inventory();
}
void remove_product() {
    if (num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("Enter product name to remove: ");
    char name[MAX_NAME_LEN];
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            save_inventory();
            printf("Product removed successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}
void list_inventory() {
    if (num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("\nProduct Name\tStock\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
    }
}
void search_product() {
    if (num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("Enter product name to search: ");
    char name[MAX_NAME_LEN];
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product Name: %s\n", inventory[i].name);
            printf("Stock: %d\n", inventory[i].stock);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}
int main() {
    load_inventory();
    int choice;
    while (1) {
        printf("\n1. Add Product\n2. Remove Product\n3. List Inventory\n4. Search Product\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                list_inventory();
                break;
            case 4:
                search_product();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}