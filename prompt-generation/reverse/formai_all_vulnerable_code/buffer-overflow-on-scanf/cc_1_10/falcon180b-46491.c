//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    int price;
};

struct item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%d", &items[num_items].price);
    num_items++;
}

void display_items() {
    printf("Item Name\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\n", items[i].name, items[i].price);
    }
}

void sort_price() {
    for (int i = 0; i < num_items - 1; i++) {
        for (int j = i + 1; j < num_items; j++) {
            if (items[i].price > items[j].price) {
                struct item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    printf("Data Mining Example Program\n");
    int choice;
    do {
        printf("1. Add item\n2. Display items\n3. Sort by price\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                sort_price();
                printf("Items sorted by price:\n");
                display_items();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}