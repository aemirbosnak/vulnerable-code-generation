//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

struct item {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
    time_t purchase_date;
};

void add_item(struct item* items, int count, char* name, float price, int quantity) {
    if(count >= MAX_ITEMS) {
        printf("Error: Cannot add more items.\n");
        return;
    }

    strncpy(items[count].name, name, MAX_NAME_LENGTH);
    items[count].price = price;
    items[count].quantity = quantity;
    items[count].purchase_date = time(NULL);

    printf("Item added: %s\n", items[count].name);
}

void display_items(struct item* items, int count) {
    printf("Items:\n");
    for(int i=0; i<count; i++) {
        printf("%s - $%.2f (x %d) - %s\n", items[i].name, items[i].price, items[i].quantity, ctime(&items[i].purchase_date));
    }
}

void main() {
    struct item items[MAX_ITEMS];
    int count = 0;

    while(1) {
        printf("1. Add item\n2. Display items\n3. Exit\n");
        int choice = 0;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                float price;
                int quantity;

                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item price: ");
                scanf("%f", &price);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);

                add_item(items, count, name, price, quantity);
                break;
            }
            case 2: {
                display_items(items, count);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }
}