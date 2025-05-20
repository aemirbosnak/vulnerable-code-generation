//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items;

void add_item(void) {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void remove_item(void) {
    int index;
    printf("Enter item index to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_items) {
        num_items--;
        for (int i = index; i < num_items; i++) {
            strcpy(items[i].name, items[i+1].name);
            items[i].price = items[i+1].price;
        }
    }
}

void display_items(void) {
    printf("Item\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\n", items[i].name, items[i].price);
    }
}

void main() {
    num_items = 0;
    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);
}