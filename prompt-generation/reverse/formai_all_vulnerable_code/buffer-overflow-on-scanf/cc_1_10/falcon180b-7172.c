//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 100

typedef struct {
    char name[50];
    int age;
    char address[100];
} Customer;

typedef struct {
    char name[50];
    double price;
} Item;

Customer customers[MAX_CUSTOMERS];
Item items[MAX_ITEMS];

int num_customers = 0;
int num_items = 0;

void add_customer(Customer* c) {
    strcpy(customers[num_customers].name, c->name);
    customers[num_customers].age = c->age;
    strcpy(customers[num_customers].address, c->address);
    num_customers++;
}

void add_item(Item* i) {
    strcpy(items[num_items].name, i->name);
    items[num_items].price = i->price;
    num_items++;
}

int main() {
    Customer customer;
    Item item;

    printf("Enter customer name: ");
    scanf("%s", customer.name);
    printf("Enter customer age: ");
    scanf("%d", &customer.age);
    printf("Enter customer address: ");
    scanf("%s", customer.address);
    add_customer(&customer);

    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item price: ");
    scanf("%lf", &item.price);
    add_item(&item);

    printf("Customer list:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s %d %s\n", customers[i].name, customers[i].age, customers[i].address);
    }

    printf("\nItem list:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s $%.2f\n", items[i].name, items[i].price);
    }

    return 0;
}