//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME 20
#define MAX_PRICE 10
#define MAX_QUANTITY 10

struct item {
    char name[MAX_NAME];
    char code[MAX_PRICE];
    int price;
    int quantity;
};

void addItem(struct item *items, int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);

    printf("Enter item code: ");
    scanf("%s", items[*numItems].code);

    printf("Enter item price: ");
    scanf("%d", &items[*numItems].price);

    printf("Enter item quantity: ");
    scanf("%d", &items[*numItems].quantity);

    (*numItems)++;
}

void displayItems(struct item *items, int numItems) {
    printf("Item Name\t\tItem Code\t\tPrice\t\tQuantity\n");
    for(int i=0; i<numItems; i++) {
        printf("%s\t\t%s\t\t%d\t\t%d\n", items[i].name, items[i].code, items[i].price, items[i].quantity);
    }
}

void generateBill(struct item *items, int numItems, float *total) {
    printf("Item Name\t\tItem Code\t\tPrice\t\tQuantity\t\tAmount\n");
    for(int i=0; i<numItems; i++) {
        float amount = items[i].price * items[i].quantity;
        printf("%s\t\t%s\t\t%d\t\t%d\t\t%.2f\n", items[i].name, items[i].code, items[i].price, items[i].quantity, amount);
        *total += amount;
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int numItems = 0;

    printf("Welcome to the Cafe Billing System!\n");

    while(numItems < MAX_ITEMS) {
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Generate bill\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem(items, &numItems);
                break;

            case 2:
                if(numItems == 0) {
                    printf("No items added yet.\n");
                } else {
                    displayItems(items, numItems);
                }
                break;

            case 3:
                if(numItems == 0) {
                    printf("No items added yet.\n");
                } else {
                    float total = 0;
                    generateBill(items, numItems, &total);
                    printf("Total amount: %.2f\n", total);
                }
                break;

            case 4:
                printf("Thank you for using the Cafe Billing System!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}