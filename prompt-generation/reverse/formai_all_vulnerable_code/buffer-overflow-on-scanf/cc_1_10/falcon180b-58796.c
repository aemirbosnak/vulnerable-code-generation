//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} item_t;

void add_item(item_t *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter price per unit: ");
    scanf("%f", &items[*num_items].price);
    printf("Enter quantity: ");
    scanf("%d", &items[*num_items].quantity);
    (*num_items)++;
}

void display_items(item_t *items, int num_items) {
    printf("\nItem\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total_expense(item_t *items, int num_items) {
    float total_expense = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_expense += items[i].price * items[i].quantity;
    }
    printf("\nTotal expense: $%.2f\n", total_expense);
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    char choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add item\n2. Display items\n3. Calculate total expense\n4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_item(items, &num_items);
                break;
            case '2':
                display_items(items, num_items);
                break;
            case '3':
                calculate_total_expense(items, num_items);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '4');

    return 0;
}