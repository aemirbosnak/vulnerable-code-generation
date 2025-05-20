//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_DESCRIPTION_LEN 500

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item description: ");
    scanf("%s", items[num_items].description);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);
    printf("Enter item price: ");
    scanf("%lf", &items[num_items].price);
    num_items++;
}

void remove_item() {
    printf("Enter item name to remove: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            num_items--;
            for (int j = i; j < num_items; j++) {
                items[j] = items[j+1];
            }
            break;
        }
    }
}

void view_items() {
    printf("Item Name\t\tItem Description\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%s\t\t%d\t\t$%.2lf\n", items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

void search_items() {
    printf("Enter item name to search: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Item Name: %s\nItem Description: %s\nQuantity: %d\nPrice: $%.2lf\n", items[i].name, items[i].description, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    printf("Welcome to the Post-Apocalyptic Product Inventory System!\n");
    printf("Enter 1 to add item\nEnter 2 to remove item\nEnter 3 to view items\nEnter 4 to search item\nEnter 0 to exit\n");
    int choice;
    scanf("%d", &choice);
    while (choice!= 0) {
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                view_items();
                break;
            case 4:
                search_items();
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("Enter 1 to add item\nEnter 2 to remove item\nEnter 3 to view items\nEnter 4 to search item\nEnter 0 to exit\n");
        scanf("%d", &choice);
    }
    return 0;
}