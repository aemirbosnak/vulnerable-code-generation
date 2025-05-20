//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct item {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} Item;

Item items[MAX_ITEMS];
int num_items;

void add_item(void) {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item amount: ");
    scanf("%s", items[num_items].amount);
    num_items++;
}

void remove_item(void) {
    if (num_items == 0) {
        printf("No items to remove.\n");
        return;
    }
    printf("Enter item number to remove: ");
    int item_num;
    scanf("%d", &item_num);
    if (item_num >= 0 && item_num < num_items) {
        memmove(&items[item_num], &items[item_num + 1], (num_items - item_num - 1) * sizeof(Item));
        num_items--;
        printf("Item removed.\n");
    } else {
        printf("Invalid item number.\n");
    }
}

void display_items(void) {
    printf("Item\tAmount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\n", items[i].name, items[i].amount);
    }
}

void total_amount(void) {
    double total = 0.0;
    for (int i = 0; i < num_items; i++) {
        total += atof(items[i].amount);
    }
    printf("Total amount: $%.2f\n", total);
}

int main(void) {
    num_items = 0;
    printf("Personal Finance Planner\n");
    while (1) {
        printf("\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Total amount\n");
        printf("5. Exit\n");
        printf("\n");
        int choice;
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
            total_amount();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}