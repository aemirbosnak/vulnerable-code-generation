//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    double price;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void add_product();
void remove_product();
void update_product();
void list_products();
void save_inventory(const char *filename);
void load_inventory(const char *filename);
int find_product_index(int id);

int main() {
    int choice;
    const char *filename = "inventory.txt";
    load_inventory(filename);

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. List Products\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_product(); break;
            case 2: remove_product(); break;
            case 3: update_product(); break;
            case 4: list_products(); break;
            case 5: save_inventory(filename); break;
            case 6: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product p;
    p.id = product_count + 1;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%lf", &p.price);
    
    inventory[product_count++] = p;
    printf("Product added successfully: %s (ID: %d)\n", p.name, p.id);
}

void remove_product() {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    
    int index = find_product_index(id);
    if (index == -1) {
        printf("Product with ID %d not found.\n", id);
        return;
    }
    
    for (int i = index; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    product_count--;
    printf("Product removed successfully.\n");
}

void update_product() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    int index = find_product_index(id);
    if (index == -1) {
        printf("Product with ID %d not found.\n", id);
        return;
    }
    
    Product *p = &inventory[index];
    printf("Updating Product ID %d - Name: %s, Quantity: %d, Price: %.2f\n", 
           p->id, p->name, p->quantity, p->price);
    
    printf("Enter new name (leave blank to keep current): ");
    char new_name[MAX_NAME_LEN];
    scanf("%s", new_name);
    if (strcmp(new_name, "") != 0) {
        strcpy(p->name, new_name);
    }
    
    printf("Enter new quantity (-1 to keep current): ");
    int new_quantity;
    scanf("%d", &new_quantity);
    if (new_quantity != -1) {
        p->quantity = new_quantity;
    }
    
    printf("Enter new price (-1 to keep current): ");
    double new_price;
    scanf("%lf", &new_price);
    if (new_price != -1) {
        p->price = new_price;
    }
    
    printf("Product updated successfully: %s (ID: %d)\n", p->name, p->id);
}

void list_products() {
    printf("\nCurrent Inventory:\n");
    printf("%-5s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("%-5s %-30s %-10s %-10s\n", "--", "------------------------------", "--------", "----------");
    
    for (int i = 0; i < product_count; i++) {
        printf("%-5d %-30s %-10d $%-9.2f\n", 
               inventory[i].id,
               inventory[i].name,
               inventory[i].quantity,
               inventory[i].price);
    }
}

void save_inventory(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving inventory.\n");
        return;
    }
    
    for (int i = 0; i < product_count; i++) {
        fprintf(file, "%d %s %d %.2f\n", 
                inventory[i].id,
                inventory[i].name,
                inventory[i].quantity,
                inventory[i].price);
    }
    
    fclose(file);
    printf("Inventory saved successfully.\n");
}

void load_inventory(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No previous inventory found.\n");
        return;
    }
    
    while (fscanf(file, "%d %s %d %lf", 
                  &inventory[product_count].id,
                  inventory[product_count].name,
                  &inventory[product_count].quantity,
                  &inventory[product_count].price) == 4) {
        product_count++;
    }
    
    fclose(file);
    printf("Inventory loaded successfully.\n");
}

int find_product_index(int id) {
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}