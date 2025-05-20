//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void print_menu();
void add_item();
void remove_item();
void view_inventory();
void search_item();

int inventory[100];
int count = 0;

int main() {
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                view_inventory();
                break;
            case 4:
                search_item();
                break;
            case 5:
                printf("Bye bye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void print_menu() {
    printf("\nWelcome to the Warehouse Management System!\n\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Inventory\n");
    printf("4. Search Item\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
}

void add_item() {
    int item;
    printf("Enter the item to add: ");
    scanf("%d", &item);

    if (count < 100) {
        inventory[count] = item;
        count++;
        printf("%d added to the inventory!\n", item);
    } else {
        printf("Inventory is full! Cannot add more items!\n");
    }
}

void remove_item() {
    int item, i, j, found = 0;
    printf("Enter the item to remove: ");
    scanf("%d", &item);

    for (i = 0; i < count; i++) {
        if (inventory[i] == item) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (j = i; j < count - 1; j++) {
            inventory[j] = inventory[j+1];
        }
        count--;
        printf("%d removed from the inventory!\n", item);
    } else {
        printf("%d not found in the inventory!\n", item);
    }
}

void view_inventory() {
    int i;
    if (count > 0) {
        printf("Current inventory: ");
        for (i = 0; i < count; i++) {
            printf("%d ", inventory[i]);
        }
        printf("\n");
    } else {
        printf("Inventory is empty!\n");
    }
}

void search_item() {
    int item, i, found = 0;
    printf("Enter the item to search for: ");
    scanf("%d", &item);

    for (i = 0; i < count; i++) {
        if (inventory[i] == item) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("%d found in the inventory at position %d!\n", item, i+1);
    } else {
        printf("%d not found in the inventory!\n", item);
    }
}