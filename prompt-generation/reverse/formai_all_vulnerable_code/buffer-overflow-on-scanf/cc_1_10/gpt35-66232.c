//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 8

struct item {
    char name[MAX_NAME_LEN];
    float price;
};

struct customer {
    char name[MAX_NAME_LEN];
    float total;
    struct item items[MAX_ITEMS];
};

void add_item(struct customer *c, char *name, float price) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (c->items[i].price == 0) {
            strncpy(c->items[i].name, name, MAX_NAME_LEN);
            c->items[i].price = price;
            break;
        }
    }
}

void print_menu() {
    printf("\tMENU\n");
    printf("1. Add an item\n");
    printf("2. Print bill\n");
    printf("3. Exit\n");
}

int main() {
    struct customer c;
    c.total = 0;
    int choice;
    char name[MAX_NAME_LEN];
    float price;
    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item price: ");
                scanf("%f", &price);
                add_item(&c, name, price);
                printf("\nItem \"%s\" added!\n\n", name);
                break;
            case 2:
                printf("\n\nBILL\n\n");
                printf("Customer name: %s\n", c.name);
                printf("Item\t\tPrice\n");
                int i;
                for (i = 0; i < MAX_ITEMS; i++) {
                    if (c.items[i].price != 0) {
                        printf("%s\t\t%.2f\n", c.items[i].name, c.items[i].price);
                        c.total += c.items[i].price;
                    }
                }
                printf("\nTotal: %.2f\n\n", c.total);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n\n");
                break;
        }
    } while (choice != 3);
    return 0; 
}