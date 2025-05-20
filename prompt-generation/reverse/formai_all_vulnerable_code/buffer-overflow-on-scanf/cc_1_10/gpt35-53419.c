//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[25];
    int quantity;
    float price;
};

struct warehouse {
    char name[25];
    struct item inventory[50];
};

void print_inventory(struct warehouse w) {
    printf("Warehouse Name: %s\n", w.name);
    printf("Inventory:\n");
    printf("%-25s %-10s %-10s\n", "Item Name", "Quantity", "Price");
    for (int i = 0; i < 50; i++) {
        if (strlen(w.inventory[i].name) > 0) {
            printf("%-25s %-10d $%-9.2f\n", w.inventory[i].name, w.inventory[i].quantity, w.inventory[i].price);
        }
    }
}

void update_inventory(struct warehouse *w, char item_name[], int quantity, float price) {
    for (int i = 0; i < 50; i++) {
        if (strcmp(w->inventory[i].name, item_name) == 0) {
            w->inventory[i].quantity += quantity;
            w->inventory[i].price = price;
            return;
        }
        else if (strlen(w->inventory[i].name) == 0) {
            strcpy(w->inventory[i].name, item_name);
            w->inventory[i].quantity = quantity;
            w->inventory[i].price = price;
            return;
        }
    }
    printf("Inventory full. Unable to add new item.\n");
}

void remove_item(struct warehouse *w, char item_name[]) {
    for (int i = 0; i < 50; i++) {
        if (strcmp(w->inventory[i].name, item_name) == 0) {
            memset(&w->inventory[i], 0, sizeof(w->inventory[i]));
            printf("Item removed from inventory.\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void modify_item(struct warehouse *w, char item_name[], int quantity, float price) {
    for (int i = 0; i < 50; i++) {
        if (strcmp(w->inventory[i].name, item_name) == 0) {
            w->inventory[i].quantity = quantity;
            w->inventory[i].price = price;
            printf("Item modified in inventory.\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

int main() {
    struct warehouse w = {"Dystopian Supply Co.", {{"Energy Drink", 100, 5.99}, {"Painkillers", 50, 12.99}, {"Handgun", 10, 199.99}}};
    
    printf("\nWelcome to %s's Warehouse Management System.\n", w.name);
    printf("What would you like to do?\n");

    while (1) {
        printf("\n1. View Inventory\n");
        printf("2. Add Item\n");
        printf("3. Remove Item\n");
        printf("4. Modify Item\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            print_inventory(w);
        }
        else if (choice == 2) {
            char item_name[25];
            int quantity;
            float price;

            printf("Enter item name: ");
            scanf("%s", item_name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%f", &price);

            update_inventory(&w, item_name, quantity, price);
        }
        else if (choice == 3) {
            char item_name[25];

            printf("Enter item name: ");
            scanf("%s", item_name);

            remove_item(&w, item_name);
        }
        else if (choice == 4) {
            char item_name[25];
            int quantity;
            float price;

            printf("Enter item name: ");
            scanf("%s", item_name);
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            printf("Enter new price: ");
            scanf("%f", &price);

            modify_item(&w, item_name, quantity, price);
        }
        else if (choice == 5) {
            printf("Thank you for using %s's Warehouse Management System.\n", w.name);
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}