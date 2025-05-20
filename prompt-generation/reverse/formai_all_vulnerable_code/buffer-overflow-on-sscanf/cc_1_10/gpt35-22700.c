//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct item {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

typedef struct warehouse {
    Item stock[MAX_ITEMS];
    int num_items;
} Warehouse;

void add_item(Warehouse *wh);
void remove_item(Warehouse *wh);
void update_item(Warehouse *wh);
void print_warehouse(Warehouse *wh);
void save_warehouse(Warehouse *wh, char *filename);
void load_warehouse(Warehouse *wh, char *filename);

int main() {
    Warehouse wh = { .num_items = 0 };
    char filename[MAX_NAME_LEN];
    int choice;

    // initial prompt
    printf("Welcome to Warehouse Management System\n");
    printf("What would you like to do?\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Update item\n");
    printf("4. View stock\n");
    printf("5. Save stock to file\n");
    printf("6. Load stock from file\n");
    printf("7. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&wh);
                break;
            case 2:
                remove_item(&wh);
                break;
            case 3:
                update_item(&wh);
                break;
            case 4:
                print_warehouse(&wh);
                break;
            case 5:
                printf("Enter filename: ");
                scanf("%s", filename);
                save_warehouse(&wh, filename);
                break;
            case 6:
                printf("Enter filename: ");
                scanf("%s", filename);
                load_warehouse(&wh, filename);
                break;
            case 7:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

void add_item(Warehouse *wh) {
    Item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);
    printf("Enter item price: ");
    scanf("%f", &new_item.price);

    if (wh->num_items == MAX_ITEMS) {
        printf("Warehouse is full\n");
        return;
    }

    wh->stock[wh->num_items] = new_item;
    wh->num_items++;
    printf("Item added to warehouse\n");
}

void remove_item(Warehouse *wh) {
    char item_name[MAX_NAME_LEN];
    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < wh->num_items; i++) {
        if (strcmp(wh->stock[i].name, item_name) == 0) {
            // remove item by shifting all elements on the right to the left
            for (int j = i; j < wh->num_items - 1; j++) {
                wh->stock[j] = wh->stock[j+1];
            }
            wh->num_items--;
            printf("Item removed from warehouse\n");
            return;
        }
    }

    printf("Item not found in warehouse\n");
}

void update_item(Warehouse *wh) {
    char item_name[MAX_NAME_LEN];
    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < wh->num_items; i++) {
        if (strcmp(wh->stock[i].name, item_name) == 0) {
            Item updated_item;
            printf("Enter new quantity: ");
            scanf("%d", &updated_item.quantity);
            printf("Enter new price: ");
            scanf("%f", &updated_item.price);
            wh->stock[i] = updated_item;
            printf("Item updated in warehouse\n");
            return;
        }
    }

    printf("Item not found in warehouse\n");
}

void print_warehouse(Warehouse *wh) {
    printf("Warehouse stock:\n");
    printf("Name\t\tQuantity\tPrice\n");
    for (int i = 0; i < wh->num_items; i++) {
        printf("%-15s\t%-8d\t$%.2f\n", wh->stock[i].name, wh->stock[i].quantity, wh->stock[i].price);
    }
}

void save_warehouse(Warehouse *wh, char *filename) {
    FILE *fptr = fopen(filename, "w");

    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < wh->num_items; i++) {
        fprintf(fptr, "%s %d %.2f\n", wh->stock[i].name, wh->stock[i].quantity, wh->stock[i].price);
    }

    printf("Warehouse stock saved to file\n");
    fclose(fptr);
}

void load_warehouse(Warehouse *wh, char *filename) {
    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    char line[MAX_NAME_LEN + 20]; // maximum possible length of a line in file
    Item item;
    wh->num_items = 0;

    while (fgets(line, sizeof(line), fptr) != NULL) {
        sscanf(line, "%s %d %f", item.name, &item.quantity, &item.price);
        wh->stock[wh->num_items] = item;
        wh->num_items++;
    }

    printf("Warehouse stock loaded from file\n");
    fclose(fptr);
}