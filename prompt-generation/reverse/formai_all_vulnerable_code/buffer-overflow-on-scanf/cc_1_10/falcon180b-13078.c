//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_SIZE 50
#define MAX_AMOUNT_SIZE 10

typedef struct {
    char name[MAX_NAME_SIZE];
    char amount[MAX_AMOUNT_SIZE];
} Item;

Item items[MAX_ITEMS];
int num_items;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item amount: ");
    scanf("%s", items[num_items].amount);
    num_items++;
}

void remove_item() {
    if (num_items == 0) {
        printf("No items to remove.\n");
        return;
    }
    printf("Enter item name to remove: ");
    scanf("%s", items[num_items - 1].name);
    for (int i = 0; i < num_items - 1; i++) {
        strcpy(items[i].name, items[i + 1].name);
        strcpy(items[i].amount, items[i + 1].amount);
    }
    num_items--;
}

void display_items() {
    printf("Item Name\tAmount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\n", items[i].name, items[i].amount);
    }
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    for (int i = 0; i < num_items; i++) {
        add_item();
    }
    int choice;
    while (1) {
        printf("1. Add item\n2. Remove item\n3. Display items\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_items();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}