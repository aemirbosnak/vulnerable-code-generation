//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    int condition; // 0: destroyed, 1: damaged, 2: new
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

void initialize_inventory(Inventory *inv) {
    inv->count = 0;
}

void add_item(Inventory *inv, const char *name, int quantity, int condition) {
    if (inv->count >= MAX_ITEMS) {
        printf("Cannot add more items. Inventory full!\n");
        return;
    }
    strncpy(inv->items[inv->count].name, name, NAME_LENGTH);
    inv->items[inv->count].quantity = quantity;
    inv->items[inv->count].condition = condition;
    inv->count++;
}

void display_inventory(const Inventory *inv) {
    printf("\n=== Post-Apocalyptic Inventory ===\n");
    for (int i = 0; i < inv->count; i++) {
        printf("Item %d: %s (Quantity: %d, Condition: %s)\n", 
            i + 1, 
            inv->items[i].name, 
            inv->items[i].quantity, 
            inv->items[i].condition == 2 ? "New" : (inv->items[i].condition == 1 ? "Damaged" : "Destroyed"));
    }
}

void remove_item(Inventory *inv, const char *name) {
    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            inv->items[i] = inv->items[inv->count - 1]; // Swap with last item
            inv->count--;
            printf("Removed item: %s\n", name);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

void update_item_quantity(Inventory *inv, const char *name, int quantity) {
    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            inv->items[i].quantity = quantity;
            printf("Updated %s to quantity: %d\n", name, quantity);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

void save_inventory_to_file(const Inventory *inv, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < inv->count; i++) {
        fprintf(file, "%s,%d,%d\n", inv->items[i].name, inv->items[i].quantity, inv->items[i].condition);
    }
    fclose(file);
    printf("Inventory saved to %s\n", filename);
}

void load_inventory_from_file(Inventory *inv, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) && inv->count < MAX_ITEMS) {
        char name[NAME_LENGTH];
        int quantity, condition;
        sscanf(buffer, "%49[^,],%d,%d", name, &quantity, &condition);
        add_item(inv, name, quantity, condition);
    }
    fclose(file);
    printf("Inventory loaded from %s\n", filename);
}

int main() {
    Inventory inv;
    initialize_inventory(&inv);

    char choice[10];
    char name[NAME_LENGTH];
    int quantity, condition;

    while (1) {
        printf("\nChoose an action: (1) Add (2) Remove (3) Display (4) Update Quantity (5) Save to File (6) Load from File (7) Exit\n");
        fgets(choice, sizeof(choice), stdin);
        
        switch (choice[0]) {
            case '1':
                printf("Enter item name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove trailing newline
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter condition (0: destroyed, 1: damaged, 2: new): ");
                scanf("%d", &condition);
                getchar(); // Remove newline after reading an integer
                add_item(&inv, name, quantity, condition);
                break;
            case '2':
                printf("Enter item name to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove trailing newline
                remove_item(&inv, name);
                break;
            case '3':
                display_inventory(&inv);
                break;
            case '4':
                printf("Enter item name to update: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove trailing newline
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                getchar(); // Remove newline
                update_item_quantity(&inv, name, quantity);
                break;
            case '5':
                save_inventory_to_file(&inv, "inventory.txt");
                break;
            case '6':
                load_inventory_from_file(&inv, "inventory.txt");
                break;
            case '7':
                printf("Survival of the fittest!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}