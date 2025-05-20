//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 100

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float total_price;
} Order;

void add_item(Item items[], int num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the quantity: ");
    scanf("%d", &items[num_items].quantity);
    printf("Enter the price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void print_menu(Item items[], int num_items) {
    printf("\nMenu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f - %d in stock\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
}

void place_order(Order order[], Item items[], int num_items) {
    printf("\nEnter your order:\n");
    int choice;
    scanf("%d", &choice);
    if (choice >= 1 && choice <= num_items) {
        order[0].name[0] = '\0';
        strcpy(order[0].name, items[choice-1].name);
        order[0].quantity = items[choice-1].quantity;
        order[0].total_price = items[choice-1].price * order[0].quantity;
        printf("\nYou ordered %d %s(s) for a total of $%.2f.\n", order[0].quantity, order[0].name, order[0].total_price);
    } else {
        printf("\nInvalid choice.\n");
    }
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;
    add_item(items, num_items);
    add_item(items, num_items);
    add_item(items, num_items);

    Order order[1];
    place_order(order, items, num_items);

    return 0;
}