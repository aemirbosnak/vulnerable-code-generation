//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
    int quantity;
};

void addItem(struct item items[], int n, char name[], float price, int quantity) {
    strcpy(items[n].name, name);
    items[n].price = price;
    items[n].quantity = quantity;
}

void displayItems(struct item items[], int n) {
    printf("\nItem Name\tPrice\tQuantity\n");
    for(int i=0; i<n; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(struct item items[], int n) {
    float total = 0.0;
    for(int i=0; i<n; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal Expense: %.2f", total);
}

int main() {
    struct item items[MAX_ITEMS];
    int n = 0;

    while(n<MAX_ITEMS) {
        printf("\nEnter item name: ");
        scanf("%s", items[n].name);

        printf("Enter item price: ");
        scanf("%f", &items[n].price);

        printf("Enter item quantity: ");
        scanf("%d", &items[n].quantity);

        n++;
    }

    printf("\nItems added successfully!\n");

    displayItems(items, n);

    calculateTotal(items, n);

    return 0;
}