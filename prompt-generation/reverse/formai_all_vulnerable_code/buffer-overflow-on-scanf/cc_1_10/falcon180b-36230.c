//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
} item;

item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the price of the item: ");
    scanf("%s", items[num_items].price);
    num_items++;
}

void remove_item(int index) {
    if (index >= 0 && index < num_items) {
        printf("Removing item %d:\n", index);
        printf("Name: %s\n", items[index].name);
        printf("Price: %s\n", items[index].price);
        for (int i = index; i < num_items - 1; i++) {
            strcpy(items[i].name, items[i + 1].name);
            strcpy(items[i].price, items[i + 1].price);
        }
        num_items--;
    } else {
        printf("Invalid index.\n");
    }
}

void list_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. Name: %s, Price: %s\n", i + 1, items[i].name, items[i].price);
    }
}

void main() {
    int choice;
    do {
        printf("Personal Finance Planner\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. List items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                printf("Enter the index of the item to remove: ");
                int index;
                scanf("%d", &index);
                remove_item(index);
                break;
            case 3:
                list_items();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
}