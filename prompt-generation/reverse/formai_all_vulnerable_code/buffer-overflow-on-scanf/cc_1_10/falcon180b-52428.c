//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for customer details
struct customer {
    char name[50];
    char address[100];
    int phone;
};

// Define a structure for item details
struct item {
    char name[50];
    float price;
};

// Define a structure for billing details
struct bill {
    int num_items;
    struct item items[10];
    float total_cost;
    struct customer customer;
};

// Function to add an item to the bill
void add_item(struct bill* b) {
    int i;
    for(i=0; i<b->num_items; i++) {
        if(strcmp(b->items[i].name, "") == 0) {
            printf("Enter item name: ");
            scanf("%s", b->items[i].name);
            printf("Enter item price: ");
            scanf("%f", &b->items[i].price);
            b->num_items++;
            return;
        }
    }
    printf("Maximum number of items reached.\n");
}

// Function to calculate the total cost of the bill
float calc_total_cost(struct bill b) {
    float cost = 0.0;
    int i;
    for(i=0; i<b.num_items; i++) {
        cost += b.items[i].price;
    }
    return cost;
}

// Function to print the bill
void print_bill(struct bill b) {
    printf("\nBill\n");
    printf("Name: %s\n", b.customer.name);
    printf("Address: %s\n", b.customer.address);
    printf("Phone: %d\n", b.customer.phone);
    printf("Items:\n");
    int i;
    for(i=0; i<b.num_items; i++) {
        printf("%s - $%.2f\n", b.items[i].name, b.items[i].price);
    }
    printf("Total Cost: $%.2f\n", calc_total_cost(b));
}

int main() {
    struct bill b;
    memset(&b, 0, sizeof(b));
    printf("Enter customer name: ");
    scanf("%s", b.customer.name);
    printf("Enter customer address: ");
    scanf("%s", b.customer.address);
    printf("Enter customer phone number: ");
    scanf("%d", &b.customer.phone);
    while(1) {
        printf("\n1. Add item\n2. Print bill\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item(&b);
                break;
            case 2:
                print_bill(b);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}