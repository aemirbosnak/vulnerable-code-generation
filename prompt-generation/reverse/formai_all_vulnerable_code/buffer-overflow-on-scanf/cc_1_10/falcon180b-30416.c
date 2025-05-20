//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    int quantity;
    float price;
};

struct customer {
    char name[50];
    int id;
};

void add_item(struct item* inventory, int n) {
    printf("Enter item name: ");
    scanf("%s", inventory[n].name);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[n].quantity);
    printf("Enter item price: ");
    scanf("%f", &inventory[n].price);
}

void display_items(struct item inventory[], int n) {
    printf("\nItem List:\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s - %d in stock - $%.2f\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void purchase_item(struct item inventory[], int n, struct customer customer) {
    int choice;
    printf("\nWelcome, %s!\n", customer.name);
    printf("Please choose an item to purchase:\n");
    display_items(inventory, n);
    scanf("%d", &choice);
    if(choice >= 1 && choice <= n) {
        if(inventory[choice-1].quantity > 0) {
            inventory[choice-1].quantity--;
            printf("\nYou purchased %s for $%.2f.\n", inventory[choice-1].name, inventory[choice-1].price);
        } else {
            printf("\nSorry, %s is out of stock.\n", inventory[choice-1].name);
        }
    } else {
        printf("\nInvalid choice.\n");
    }
}

void main() {
    struct item inventory[MAX_ITEMS];
    int n;
    printf("Enter number of items in inventory (up to %d): ", MAX_ITEMS);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        add_item(inventory, i);
    }
    struct customer customer;
    printf("\nEnter customer name: ");
    scanf("%s", customer.name);
    printf("Enter customer ID: ");
    scanf("%d", &customer.id);
    purchase_item(inventory, n, customer);
}