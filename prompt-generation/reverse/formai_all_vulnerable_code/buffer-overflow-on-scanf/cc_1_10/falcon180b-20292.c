//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct {
    char name[30];
    float price;
} Item;

typedef struct {
    char name[30];
    char address[50];
    int phone;
    float total;
} Customer;

void addItem(Item menu[], int *numItems) {
    printf("Enter the name of the item: ");
    scanf("%s", menu[*numItems].name);
    printf("Enter the price of the item: ");
    scanf("%f", &menu[*numItems].price);
    *numItems += 1;
}

void displayMenu(Item menu[], int numItems) {
    printf("\nMenu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void placeOrder(Item menu[], int numItems, Customer order[]) {
    int choice;
    float total = 0;

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= numItems) {
        strcpy(order[0].name, menu[choice-1].name);
        order[0].address[0] = '\0';
        printf("Enter your name: ");
        scanf("%s", order[0].name);
        printf("Enter your address: ");
        scanf("%s", order[0].address);
        printf("Enter your phone number: ");
        scanf("%d", &order[0].phone);
        total = menu[choice-1].price;
    } else {
        printf("Invalid choice.\n");
    }
}

void printReceipt(Customer order[], float total) {
    printf("\nReceipt:\n");
    printf("Name: %s\n", order[0].name);
    printf("Address: %s\n", order[0].address);
    printf("Phone: %d\n", order[0].phone);
    printf("Total: $%.2f\n", total);
}

int main() {
    Item menu[SIZE];
    int numItems = 0;
    Customer order[1];
    float total = 0;

    addItem(menu, &numItems);
    addItem(menu, &numItems);
    addItem(menu, &numItems);

    displayMenu(menu, numItems);

    placeOrder(menu, numItems, order);

    printReceipt(order, total);

    return 0;
}