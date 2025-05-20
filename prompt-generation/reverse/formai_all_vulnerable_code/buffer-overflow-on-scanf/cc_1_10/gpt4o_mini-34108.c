//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50
#define FILE_NAME "inventory.txt"

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

void add_item(Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[*count].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[*count].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*count].price);
    (*count)++;

    printf("Item added successfully!\n");
}

void view_items(const Item items[], int count) {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\nInventory Items:\n");
    printf("%-20s %-10s %-10s\n", "Item Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d $%-9.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void save_to_file(const Item items[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    fclose(file);
    printf("Inventory saved to %s successfully!\n", FILE_NAME);
}

void load_from_file(Item items[], int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading. It may not exist yet.\n");
        return;
    }

    while (fscanf(file, "%s %d %f", items[*count].name, &items[*count].quantity, &items[*count].price) != EOF) {
        (*count)++;
    }

    fclose(file);
    printf("Inventory loaded successfully! Total items: %d\n", *count);
}

void search_item(const Item items[], int count) {
    char searchName[ITEM_NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            printf("Item found: %s, Quantity: %d, Price: $%.2f\n", items[i].name, items[i].quantity, items[i].price);
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

void delete_item(Item items[], int *count) {
    char deleteName[ITEM_NAME_LENGTH];
    printf("Enter item name to delete: ");
    scanf("%s", deleteName);

    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(items[i].name, deleteName) == 0) {
            break;
        }
    }

    if (i < *count) {
        for (int j = i; j < *count - 1; j++) {
            items[j] = items[j + 1];
        }
        (*count)--;
        printf("Item '%s' deleted successfully!\n", deleteName);
    } else {
        printf("Item not found in inventory.\n");
    }
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    load_from_file(items, &count);

    while (1) {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Search Item\n");
        printf("6. Delete Item\n");
        printf("7. Exit\n");
        printf("Choose an option (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &count);
                break;
            case 2:
                view_items(items, count);
                break;
            case 3:
                save_to_file(items, count);
                break;
            case 4:
                load_from_file(items, &count);
                break;
            case 5:
                search_item(items, count);
                break;
            case 6:
                delete_item(items, &count);
                break;
            case 7:
                save_to_file(items, count);
                printf("Exiting program. All changes saved.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}