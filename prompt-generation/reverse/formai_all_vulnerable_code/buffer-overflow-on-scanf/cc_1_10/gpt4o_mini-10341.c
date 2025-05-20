//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

void initialize_inventory(Product inventory[], int *count);
void add_product(Product inventory[], int *count);
void list_products(Product inventory[], int count);
void save_inventory(Product inventory[], int count);
void load_inventory(Product inventory[], int *count);
void update_product(Product inventory[], int count);
void delete_product(Product inventory[], int *count);

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    load_inventory(inventory, &count);

    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_product(inventory, &count); break;
            case 2: list_products(inventory, count); break;
            case 3: update_product(inventory, count); break;
            case 4: delete_product(inventory, &count); break;
            case 5: save_inventory(inventory, count); break;
            case 6: break;
            default: printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

void initialize_inventory(Product inventory[], int *count) {
    *count = 0;
}

void add_product(Product inventory[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product p;
    p.id = *count + 1;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);

    inventory[*count] = p;
    (*count)++;
}

void list_products(Product inventory[], int count) {
    printf("\n--- Product List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                inventory[i].id, inventory[i].name, 
                inventory[i].quantity, inventory[i].price);
    }
}

void save_inventory(Product inventory[], int count) {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n",
                inventory[i].id, inventory[i].name, 
                inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved successfully.\n");
}

void load_inventory(Product inventory[], int *count) {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No existing inventory found. Starting fresh.\n");
        initialize_inventory(inventory, count);
        return;
    }
    
    while (fscanf(file, "%d,%49[^,],%d,%f\n", 
                  &inventory[*count].id, 
                  inventory[*count].name, 
                  &inventory[*count].quantity, 
                  &inventory[*count].price) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Inventory loaded successfully.\n");
}

void update_product(Product inventory[], int count) {
    int id;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("Invalid product ID!\n");
        return;
    }

    Product *p = &inventory[id - 1];
    printf("Updating Product ID: %d\n", p->id);
    printf("Current Name: %s\n", p->name);
    printf("Enter new name (leave empty for no change): ");
    char new_name[NAME_LENGTH];
    scanf("%s", new_name);
    if (strlen(new_name) > 0) {
        strcpy(p->name, new_name);
    }

    printf("Current Quantity: %d\n", p->quantity);
    printf("Enter new quantity (-1 for no change): ");
    int new_quantity;
    scanf("%d", &new_quantity);
    if (new_quantity != -1) {
        p->quantity = new_quantity;
    }

    printf("Current Price: %.2f\n", p->price);
    printf("Enter new price (-1 for no change): ");
    float new_price;
    scanf("%f", &new_price);
    if (new_price != -1) {
        p->price = new_price;
    }
}

void delete_product(Product inventory[], int *count) {
    int id;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > *count) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    (*count)--;
    printf("Product ID: %d deleted successfully.\n", id);
}