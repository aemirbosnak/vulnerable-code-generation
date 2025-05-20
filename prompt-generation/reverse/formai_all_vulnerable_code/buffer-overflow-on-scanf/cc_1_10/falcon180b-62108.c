//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME_LENGTH 20
#define MAX_ITEM_PRICE 1000

//Structure for each item
typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    float price;
} item;

//Structure for the order
typedef struct {
    int numItems;
    item items[MAX_ITEMS];
} order;

//Function to add an item to the order
void addItem(order* o) {
    int i;
    for(i=0; i<o->numItems; i++) {
        if(strcmp(o->items[i].name, "") == 0) {
            printf("Enter the name of the item: ");
            scanf("%s", o->items[i].name);
            printf("Enter the price of the item: ");
            scanf("%f", &o->items[i].price);
            return;
        }
    }
    printf("Order is full.\n");
}

//Function to display the order
void displayOrder(order o) {
    int i;
    printf("Order:\n");
    for(i=0; i<o.numItems; i++) {
        printf("%s - $%.2f\n", o.items[i].name, o.items[i].price);
    }
}

//Function to calculate the total price of the order
float calculateTotal(order o) {
    int i;
    float total = 0.0;
    for(i=0; i<o.numItems; i++) {
        total += o.items[i].price;
    }
    return total;
}

int main() {
    order o;
    o.numItems = 0;
    while(1) {
        printf("1. Add item\n2. Display order\n3. Calculate total\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addItem(&o);
                break;
            case 2:
                displayOrder(o);
                break;
            case 3:
                printf("Total price: $%.2f\n", calculateTotal(o));
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}