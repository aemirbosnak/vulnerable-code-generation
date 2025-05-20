//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 20
#define MAX_NAME_LEN 20
#define MAX_QUANTITY 10
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    int price;
} item_t;

void add_item(item_t *items, int *num_items) {
    printf("Enter item name: ");
    fgets(items[*num_items].name, sizeof(items[*num_items].name), stdin);
    items[*num_items].name[strcspn(items[*num_items].name, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &items[*num_items].quantity);

    printf("Enter price: ");
    scanf("%d", &items[*num_items].price);

    (*num_items)++;
}

void print_items(item_t *items, int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %d x $%d\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int num_items = 0;
    item_t items[MAX_ITEMS];

    add_item(items, &num_items);

    while (num_items > 0) {
        print_items(items, num_items);

        printf("Enter 1 to add an item, 0 to proceed to checkout:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_item(items, &num_items);
        } else if (choice == 0) {
            printf("Total price: $%d\n", 0);
            break;
        } else {
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}