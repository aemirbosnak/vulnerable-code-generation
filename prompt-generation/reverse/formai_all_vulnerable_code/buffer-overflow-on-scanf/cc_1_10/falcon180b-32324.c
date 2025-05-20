//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item category: ");
    scanf("%s", items[num_items].category);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);

    num_items++;
}

void remove_item() {
    printf("Enter item name to remove: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            memmove(items + i, items + i + 1, sizeof(Item) * (num_items - i - 1));
            num_items--;
            break;
        }
    }
}

void display_items() {
    printf("Item Name\tItem Category\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%d\t%.2f\n", items[i].name, items[i].category, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}