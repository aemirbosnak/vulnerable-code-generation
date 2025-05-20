//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item(void) {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;

    printf("Enter the name of the item: ");
    scanf("%s", name);

    printf("Enter the price of the item: ");
    scanf("%f", &price);

    printf("Enter the quantity of the item: ");
    scanf("%d", &quantity);

    strncpy(items[num_items].name, name, MAX_NAME_LENGTH);
    items[num_items].price = price;
    items[num_items].quantity = quantity;

    num_items++;
}

void display_items(void) {
    printf("Item\tPrice\tQuantity\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total(void) {
    float total = 0.0;

    for (int i = 0; i < num_items; i++) {
        total += (items[i].price * items[i].quantity);
    }

    printf("Total cost: $%.2f\n", total);
}

int main(void) {
    int choice;

    do {
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            display_items();
            break;
        case 3:
            calculate_total();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}