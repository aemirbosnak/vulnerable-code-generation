//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM_ITEMS 1000

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Warehouse {
    struct Item items[MAX_NUM_ITEMS];
    int num_items;
};

void print_items(struct Warehouse *w) {
    printf("----- Items -----\n");
    printf("%-5s%-20s%-10s%-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < w->num_items; i++) {
        printf("%-5d%-20s%-10d%-10.2f\n", w->items[i].id, w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

void add_item(struct Warehouse *w, int id, char *name, int quantity, float price) {
    if (w->num_items >= MAX_NUM_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }
    struct Item item = { id, "", 0, 0 };
    strcpy(item.name, name);
    item.quantity = quantity;
    item.price = price;
    w->items[w->num_items] = item;
    w->num_items++;
    printf("Item added successfully!\n");
}

bool remove_item(struct Warehouse *w, int id) {
    for (int i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            for (int j = i; j < w->num_items - 1; j++) {
                w->items[j] = w->items[j + 1];
            }
            w->num_items--;
            printf("Item removed successfully!\n");
            return true;
        }
    }
    printf("Item not found!\n");
    return false;
}

void update_item(struct Warehouse *w, int id, int quantity, float price) {
    for (int i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            w->items[i].quantity = quantity;
            w->items[i].price = price;
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void search_item(struct Warehouse *w, int id) {
    for (int i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            printf("----- Search Results -----\n");
            printf("%-5s%-20s%-10s%-10s\n", "ID", "Name", "Quantity", "Price");
            printf("%-5d%-20s%-10d%-10.2f\n", w->items[i].id, w->items[i].name, w->items[i].quantity, w->items[i].price);
            return;
        }
    }
    printf("Item not found!\n");
}

int main() {
    struct Warehouse warehouse = { { { 1, "Apple", 10, 0.5 }, { 2, "Banana", 20, 0.3 }, { 3, "Carrot", 15, 0.2 } }, 3 };
    int choice;
    printf("***** Warehouse Management System *****\n");
    do {
        printf("\n1. View Items\n2. Add Item\n3. Remove Item\n4. Update Item\n5. Search Item\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_items(&warehouse);
                break;
            case 2:
                {
                    int id, quantity;
                    float price;
                    char name[50];
                    printf("Enter item ID: ");
                    scanf("%d", &id);
                    printf("Enter item name: ");
                    scanf("%s", name);
                    printf("Enter item quantity: ");
                    scanf("%d", &quantity);
                    printf("Enter item price: ");
                    scanf("%f", &price);
                    add_item(&warehouse, id, name, quantity, price);
                    break;
                }
            case 3:
                {
                    int id;
                    printf("Enter item ID: ");
                    scanf("%d", &id);
                    remove_item(&warehouse, id);
                    break;
                }
            case 4:
                {
                    int id, quantity;
                    float price;
                    printf("Enter item ID: ");
                    scanf("%d", &id);
                    printf("Enter new quantity: ");
                    scanf("%d", &quantity);
                    printf("Enter new price: ");
                    scanf("%f", &price);
                    update_item(&warehouse, id, quantity, price);
                    break;
                }
            case 5:
                {
                    int id;
                    printf("Enter item ID: ");
                    scanf("%d", &id);
                    search_item(&warehouse, id);
                    break;
                }
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}