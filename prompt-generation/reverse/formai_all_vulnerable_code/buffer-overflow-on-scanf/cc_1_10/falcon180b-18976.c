//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[100];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[100];
    int quantity;
    float price;
} Order;

void addItem(Item items[], int *size, char name[], int quantity, float price) {
    strcpy(items[*size].name, name);
    items[*size].quantity = quantity;
    items[*size].price = price;
    (*size)++;
}

void displayItems(Item items[], int size) {
    printf("\n%s\n", "Menu");
    for(int i=0; i<size; i++) {
        printf("%d. %s - %.2f gold\n", i+1, items[i].name, items[i].price);
    }
}

void addOrder(Order order[], int *size) {
    (*size)++;
}

void displayOrder(Order order[], int size) {
    printf("\n%s's order:\n", "Sir");
    for(int i=0; i<size; i++) {
        printf("%d. %s - %d quantity - %.2f gold\n", i+1, order[i].name, order[i].quantity, order[i].price*order[i].quantity);
    }
    printf("\nTotal cost: %.2f gold\n", order[0].price*order[0].quantity);
}

int main() {
    int choice, size=0;
    char ch;
    Item items[100];
    Order order[100];

    addItem(items, &size, "Ale", 1, 1.50);
    addItem(items, &size, "Bread", 1, 0.25);
    addItem(items, &size, "Stew", 1, 3.00);

    while(1) {
        system("clear");
        printf("\n%s\n", "Welcome to the Medieval Cafe!");
        printf("\n%s\n", "What would you like to do?");
        printf("\n1. View menu\n2. Place an order\n3. Exit");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayItems(items, size);
                break;
            case 2:
                addOrder(order, &size);
                system("clear");
                printf("\n%s's order:\n", "Sir");
                displayOrder(order, size);
                break;
            case 3:
                exit(0);
            default:
                printf("\n%s\n", "Invalid choice. Please try again.");
        }

        printf("\nPress any key to continue...");
        scanf(" %c", &ch);
    }

    return 0;
}