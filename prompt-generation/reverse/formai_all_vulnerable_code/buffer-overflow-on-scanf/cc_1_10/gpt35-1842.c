//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct inventory {
    struct product products[MAX_PRODUCTS];
    int num_products;
};

void display_menu();
void add_product(struct inventory *inv);
void remove_product(struct inventory *inv);
void update_product(struct inventory *inv);
void search_product(struct inventory *inv);
void display_inventory(struct inventory *inv);
void load_inventory(struct inventory *inv);
void save_inventory(struct inventory *inv);

void display_menu() {
    printf("\n");
    printf("1: Add a new product\n");
    printf("2: Remove an existing product\n");
    printf("3: Update an existing product\n");
    printf("4: Search for a product\n");
    printf("5: Display all products\n");
    printf("6: Load inventory from file\n");
    printf("7: Save inventory to file\n");
    printf("8: Exit\n");
    printf("\n");
    printf("Enter your choice: ");
}

void add_product(struct inventory *inv) {
    int id;
    char name[50];
    float price;
    int quantity;
    
    printf("Enter product ID: ");
    scanf("%d", &id);
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    inv->products[inv->num_products].id = id;
    strcpy(inv->products[inv->num_products].name, name);
    inv->products[inv->num_products].price = price;
    inv->products[inv->num_products].quantity = quantity;
    inv->num_products++;
    
    printf("Product added successfully!\n");
}

void remove_product(struct inventory *inv) {
    int id;
    int i, j;
    int found = 0;
    
    printf("Enter product ID: ");
    scanf("%d", &id);
    
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            found = 1;
            for (j = i; j < inv->num_products - 1; j++) {
                inv->products[j] = inv->products[j+1];
            }
            inv->num_products--;
            printf("Product removed successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void update_product(struct inventory *inv) {
    int id;
    int i;
    int found = 0;
    
    printf("Enter product ID: ");
    scanf("%d", &id);
    
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            found = 1;
            printf("Enter new product name (Enter to keep existing name): ");
            scanf("\n");
            fgets(inv->products[i].name, 50, stdin);
            inv->products[i].name[strcspn(inv->products[i].name, "\n")] = 0;
            printf("Enter new product price (Enter 0 to keep existing price): ");
            scanf("%f", &inv->products[i].price);
            printf("Enter new product quantity (Enter 0 to keep existing quantity): ");
            scanf("%d", &inv->products[i].quantity);
            printf("Product updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void search_product(struct inventory *inv) {
    int id;
    int i;
    int found = 0;
    
    printf("Enter product ID: ");
    scanf("%d", &id);
    
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            found = 1;
            printf("Product found!\n");
            printf("ID: %d\n", inv->products[i].id);
            printf("Name: %s\n", inv->products[i].name);
            printf("Price: %.2f\n", inv->products[i].price);
            printf("Quantity: %d\n", inv->products[i].quantity);
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void display_inventory(struct inventory *inv) {
    int i;
    
    printf("Product Inventory:\n");
    
    for (i = 0; i < inv->num_products; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", inv->products[i].id, inv->products[i].name, inv->products[i].price, inv->products[i].quantity);
    }
}

void load_inventory(struct inventory *inv) {
    FILE *fp;
    fp = fopen("inventory.dat", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        return;
    }
    fread(inv, sizeof(struct inventory), 1, fp);
    fclose(fp);
    printf("Inventory loaded from file successfully!\n");
}

void save_inventory(struct inventory *inv) {
    FILE *fp;
    fp = fopen("inventory.dat", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        return;
    }
    fwrite(inv, sizeof(struct inventory), 1, fp);
    fclose(fp);
    printf("Inventory saved to file successfully!\n");
}

int main() {
    struct inventory inv;
    inv.num_products = 0;
    int choice;
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_product(&inv);
                break;
            case 2:
                remove_product(&inv);
                break;
            case 3:
                update_product(&inv);
                break;
            case 4:
                search_product(&inv);
                break;
            case 5:
                display_inventory(&inv);
                break;
            case 6:
                load_inventory(&inv);
                break;
            case 7:
                save_inventory(&inv);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}