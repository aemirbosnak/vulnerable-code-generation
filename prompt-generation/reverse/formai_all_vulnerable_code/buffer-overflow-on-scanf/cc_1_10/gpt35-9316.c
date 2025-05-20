//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 200
#define MAX_NAME_LEN 50
#define MAX_DATE_LEN 10

struct Item {
    char name[MAX_NAME_LEN];
    char expiry_date[MAX_DATE_LEN];
    int quantity;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct Warehouse *warehouse);
void remove_item(struct Warehouse *warehouse);
void display_items(struct Warehouse warehouse);
void save_data(struct Warehouse warehouse);

int main() {
    struct Warehouse warehouse = {0};
    int option;

    printf("Welcome to the Warehouse Management System\n\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Save data\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                add_item(&warehouse);
                break;
            case 2:
                remove_item(&warehouse);
                break;
            case 3:
                display_items(warehouse);
                break;
            case 4:
                save_data(warehouse);
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}

void add_item(struct Warehouse *warehouse) {
    char name[MAX_NAME_LEN], expiry_date[MAX_DATE_LEN];
    int quantity;

    printf("Please enter the name of the item: ");
    scanf("%s", name);

    printf("Please enter the expiry date (yyyy-mm-dd): ");
    scanf("%s", expiry_date);

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    if (warehouse->num_items == MAX_ITEMS) {
        printf("Warehouse is full\n");
        return;
    }

    struct Item item = {0};
    strcpy(item.name, name);
    strcpy(item.expiry_date, expiry_date);
    item.quantity = quantity;

    warehouse->items[warehouse->num_items++] = item;

    printf("Item added successfully\n");
}

void remove_item(struct Warehouse *warehouse) {
    int index, i;

    printf("Please enter the index of the item to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= warehouse->num_items) {
        printf("Invalid index\n");
        return;
    }

    for (i = index; i < warehouse->num_items - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }

    warehouse->num_items--;

    printf("Item removed successfully\n");
}

void display_items(struct Warehouse warehouse) {
    int i;

    printf("Items in the warehouse:\n");
    printf("-----------------------\n");

    for (i = 0; i < warehouse.num_items; i++) {
        printf("%d. %s (%s) - %d\n", i, warehouse.items[i].name, warehouse.items[i].expiry_date, warehouse.items[i].quantity);
    }

    printf("-----------------------\n");
}

void save_data(struct Warehouse warehouse) {
    FILE *fp;
    char filename[MAX_NAME_LEN];

    printf("Please enter the filename: ");
    scanf("%s", filename);

    if ((fp = fopen(filename, "w")) == NULL) {
        printf("Error opening file\n");
        return;
    }

    fwrite(&warehouse, sizeof(struct Warehouse), 1, fp);

    fclose(fp);

    printf("Data saved successfully\n");
}