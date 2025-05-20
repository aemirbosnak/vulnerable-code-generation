//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_QTY 10

struct item {
    char name[MAX_NAME];
    int qty;
    float price;
};

void addItem(struct item* inventory, int count) {
    printf("Enter the item name: ");
    scanf("%s", inventory[count].name);
    printf("Enter the quantity: ");
    scanf("%d", &inventory[count].qty);
    printf("Enter the price: ");
    scanf("%f", &inventory[count].price);
}

void displayItems(struct item inventory[], int count) {
    printf("\nItem Name\tQuantity\tPrice\n");
    for(int i=0; i<count; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].qty, inventory[i].price);
    }
}

int main() {
    struct item inventory[MAX_ITEMS];
    int count = 0;

    printf("Product Inventory System\n");

    do {
        printf("\nEnter 1 to add an item\nEnter 2 to display items\nEnter 3 to exit\n");
        scanf("%d", &count);

        switch(count) {
            case 1:
                printf("\nEnter the number of items to add: ");
                scanf("%d", &count);
                for(int i=0; i<count; i++) {
                    addItem(inventory, i);
                }
                break;

            case 2:
                displayItems(inventory, count);
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    }while(count!= 3);

    return 0;
}