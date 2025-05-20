//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    int price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int total_items;
    int total_price;
} Order;

void print_bill(Order order);
void add_item(Order *order, char *name, int price);
void clear_order(Order *order);

int main()
{
    Order order;
    char input[10];
    char name[NAME_LEN];
    int price;

    clear_order(&order);

    printf("Welcome to the Medieval Cafe!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1) Add item\n");
        printf("2) Print bill\n");
        printf("3) Exit\n");
        printf("> ");

        fgets(input, 10, stdin);

        switch (atoi(input)) {
            case 1:
                printf("Enter item name: ");
                fgets(name, NAME_LEN, stdin);
                name[strlen(name) - 1] = '\0';
                printf("Enter item price: ");
                scanf("%d", &price);
                getchar(); // clear input buffer
                add_item(&order, name, price);
                printf("%s added to your order!\n", name);
                break;
            case 2:
                print_bill(order);
                break;
            case 3:
                printf("Thank you for visiting the Medieval Cafe!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

void print_bill(Order order)
{
    int i;

    printf("Medieval Cafe - Your bill:\n");
    printf("------------------------------\n");

    for (i = 0; i < order.total_items; i++) {
        printf("%s\t%d gold coins\n", order.items[i].name, order.items[i].price);
    }

    printf("------------------------------\n");
    printf("Total:\t\t%d gold coins\n", order.total_price);
}

void add_item(Order *order, char *name, int price)
{
    if (order->total_items == MAX_ITEMS) {
        printf("Sorry, you cannot add more items to your order!\n");
        return;
    }

    Item item;

    strcpy(item.name, name);
    item.price = price;

    order->items[order->total_items] = item;
    order->total_items++;
    order->total_price += price;
}

void clear_order(Order *order)
{
    order->total_items = 0;
    order->total_price = 0;
}