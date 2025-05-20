//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20

typedef struct item {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} item_t;

void add_item(item_t *inventory, int *num_items);
void remove_item(item_t *inventory, int *num_items);
void display_inventory(item_t *inventory, int num_items);
void save_inventory(item_t *inventory, int num_items);
void load_inventory(item_t *inventory, int *num_items);

int main() {
    item_t inventory[MAX_ITEMS];
    int num_items = 0;

    while (1) {
        char choice;
        printf("Choose an option:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Save inventory\n");
        printf("5. Load inventory\n");
        printf("6. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_item(inventory, &num_items);
                break;
            case '2':
                remove_item(inventory, &num_items);
                break;
            case '3':
                display_inventory(inventory, num_items);
                break;
            case '4':
                save_inventory(inventory, num_items);
                break;
            case '5':
                load_inventory(inventory, &num_items);
                break;
            case '6':
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }

        while ((getchar()) != '\n') {}
    }

    return 0;
}

void add_item(item_t *inventory, int *num_items) {
    if (*num_items == MAX_ITEMS) {
        printf("Inventory full\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", inventory[*num_items].name);

    printf("Enter quantity: ");
    scanf("%d", &inventory[*num_items].quantity);

    printf("Enter price: ");
    scanf("%f", &inventory[*num_items].price);

    (*num_items)++;
}

void remove_item(item_t *inventory, int *num_items) {
    if (*num_items == 0) {
        printf("Inventory empty\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("Enter name: ");
    scanf("%s", name);

    for (int i = 0; i < *num_items; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            for (int j = i + 1; j < *num_items; j++) {
                inventory[j - 1] = inventory[j];
            }
            (*num_items)--;
            printf("Item removed\n");
            return;
        }
    }

    printf("Item not found\n");
}

void display_inventory(item_t *inventory, int num_items) {
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s %-10d $%-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void save_inventory(item_t *inventory, int num_items) {
    FILE *fp = fopen("inventory.txt", "w");

    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    fwrite(inventory, sizeof(item_t), num_items, fp);
    fclose(fp);
    printf("Inventory saved\n");
}

void load_inventory(item_t *inventory, int *num_items) {
    FILE *fp = fopen("inventory.txt", "r");

    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    *num_items = 0;
    while (fread(&inventory[*num_items], sizeof(item_t), 1, fp)) {
        (*num_items)++;
    }

    fclose(fp);
    printf("Inventory loaded\n");
}