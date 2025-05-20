//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_ITEMS 1000

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

int get_choice() {
    int choice = 0;
    char input[10];
    printf("Enter choice: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &choice) != 1) {
        choice = 0;
    }
    return choice;
}

void add_item() {
    if (num_items == MAX_ITEMS) {
        printf("Warehouse capacity reached.\n");
        return;
    }

    Item item;
    item.id = num_items + 1;

    printf("Enter item name: ");
    fgets(item.name, MAX_NAME_LENGTH, stdin);
    item.name[strcspn(item.name, "\n")] = '\0';

    printf("Enter item quantity: ");
    char input[10];
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &item.quantity) != 1) {
        printf("Invalid quantity.\n");
        return;
    }

    printf("Enter item price: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%f", &item.price) != 1) {
        printf("Invalid price.\n");
        return;
    }

    items[num_items++] = item;
    printf("Item added.\n");
}

void list_items() {
    if (num_items == 0) {
        printf("Warehouse is empty.\n");
        return;
    }

    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-5d %-20s %-10d %-10.2f\n",
            items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

void search_item() {
    if (num_items == 0) {
        printf("Warehouse is empty.\n");
        return;
    }

    printf("Enter search term: ");
    char term[MAX_NAME_LENGTH];
    fgets(term, MAX_NAME_LENGTH, stdin);
    term[strcspn(term, "\n")] = '\0';
    for (int i = 0; i < strlen(term); i++) {
        term[i] = tolower(term[i]);
    }

    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        char name_lower[MAX_NAME_LENGTH];
        strcpy(name_lower, items[i].name);
        for (int j = 0; j < strlen(name_lower); j++) {
            name_lower[j] = tolower(name_lower[j]);
        }
        if (strstr(name_lower, term) != NULL) {
            printf("%-5d %-20s %-10d %-10.2f\n",
                items[i].id, items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    int choice = 1;
    while (choice != 0) {
        printf("Warehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add item\n");
        printf("2. List items\n");
        printf("3. Search item\n");
        printf("0. Exit\n");

        choice = get_choice();
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                list_items();
                break;
            case 3:
                search_item();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
    return 0;
}