//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 100

typedef struct {
    char name[50];
    int age;
    char address[100];
} Customer;

typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
    int numCustomers;
    Customer customers[MAX_CUSTOMERS];
} Cafe;

void addItem(Cafe* cafe) {
    if (cafe->numItems == MAX_ITEMS) {
        printf("Sorry, we cannot add any more items.\n");
        return;
    }

    printf("Enter the name of the item: ");
    scanf("%s", cafe->items[cafe->numItems].name);
    printf("Enter the price of the item: ");
    scanf("%f", &cafe->items[cafe->numItems].price);
    cafe->numItems++;
}

void addCustomer(Cafe* cafe) {
    if (cafe->numCustomers == MAX_CUSTOMERS) {
        printf("Sorry, we cannot add any more customers.\n");
        return;
    }

    printf("Enter the name of the customer: ");
    scanf("%s", cafe->customers[cafe->numCustomers].name);
    printf("Enter the age of the customer: ");
    scanf("%d", &cafe->customers[cafe->numCustomers].age);
    printf("Enter the address of the customer: ");
    scanf("%s", cafe->customers[cafe->numCustomers].address);
    cafe->numCustomers++;
}

void displayMenu(Cafe* cafe) {
    printf("Welcome to our cafe!\n");
    printf("Here are the items we have:\n");

    for (int i = 0; i < cafe->numItems; i++) {
        printf("%s - $%.2f\n", cafe->items[i].name, cafe->items[i].price);
    }
}

void order(Cafe* cafe) {
    printf("What would you like to order?\n");
    char order[50];
    scanf("%s", order);

    int found = 0;
    for (int i = 0; i < cafe->numItems; i++) {
        if (strcmp(cafe->items[i].name, order) == 0) {
            found = 1;
            printf("You ordered %s for $%.2f.\n", cafe->items[i].name, cafe->items[i].price);
            break;
        }
    }

    if (!found) {
        printf("Sorry, we don't have that item.\n");
    }
}

void checkout(Cafe* cafe) {
    printf("Total bill: $%.2f\n", cafe->items[0].price);
}

int main() {
    Cafe cafe;

    cafe.numItems = 0;
    cafe.numCustomers = 0;

    addItem(&cafe);
    addItem(&cafe);
    addItem(&cafe);
    addCustomer(&cafe);
    addCustomer(&cafe);

    displayMenu(&cafe);
    order(&cafe);

    checkout(&cafe);

    return 0;
}