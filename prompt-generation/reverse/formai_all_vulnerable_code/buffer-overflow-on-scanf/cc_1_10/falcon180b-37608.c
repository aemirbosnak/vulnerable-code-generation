//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
    int quantity;
};

void addItem(struct item *items, int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    numItems++;
}

void displayItems(struct item items[], int numItems) {
    printf("\nItem Name\tPrice\tQuantity\n");
    for(int i=0; i<numItems; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(struct item items[], int numItems) {
    float total = 0.0;
    for(int i=0; i<numItems; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal Expense: $%.2f", total);
}

int main() {
    struct item items[MAX_ITEMS];
    int numItems = 0;

    while(1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Item\n2. Display Items\n3. Calculate Total\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(numItems >= MAX_ITEMS) {
                    printf("Maximum items limit reached!\n");
                } else {
                    addItem(items, numItems);
                }
                break;

            case 2:
                displayItems(items, numItems);
                break;

            case 3:
                calculateTotal(items, numItems);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}