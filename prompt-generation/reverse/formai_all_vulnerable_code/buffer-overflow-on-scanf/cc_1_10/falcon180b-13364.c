//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 1000

typedef struct {
    char name[50];
    int age;
    int order_count;
} Customer;

typedef struct {
    char name[50];
    float price;
    int quantity;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    Customer customers[MAX_CUSTOMERS];
} Cafe;

Cafe cafe;

int main() {
    int choice, customer_index, item_index;
    char name[50];
    float total_price = 0;

    printf("Welcome to the Cafe!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    customer_index = add_customer(name, 0);

    while (1) {
        printf("\nMenu:\n");
        for (int i = 0; i < cafe.items[0].quantity; i++) {
            printf("%d. %s - $%.2f (x%d)\n", i+1, cafe.items[i].name, cafe.items[i].price, cafe.items[i].quantity);
        }
        printf("%d. Check out\n", cafe.items[0].quantity+1);

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == cafe.items[0].quantity+1) {
            break;
        } else if (choice >= 1 && choice <= cafe.items[0].quantity) {
            item_index = choice-1;
            total_price += cafe.items[item_index].price * cafe.items[item_index].quantity;
            printf("\nYou ordered %s - $%.2f (x%d)\n", cafe.items[item_index].name, cafe.items[item_index].price, cafe.items[item_index].quantity);
        } else {
            printf("\nInvalid choice.\n");
        }
    }

    printf("\nYour total price is $%.2f.\n", total_price);

    return 0;
}

int add_customer(char name[], int age) {
    int i;

    for (i = 0; i < MAX_CUSTOMERS; i++) {
        if (cafe.customers[i].order_count == 0) {
            strcpy(cafe.customers[i].name, name);
            cafe.customers[i].age = age;
            cafe.customers[i].order_count = 1;
            return i;
        }
    }

    printf("\nMaximum number of customers reached.\n");
    return -1;
}