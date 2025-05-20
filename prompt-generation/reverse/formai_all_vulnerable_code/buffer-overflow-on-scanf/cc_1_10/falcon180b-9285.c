//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
};

void add_item(struct item* items, int count, char name[], int quantity, double price) {
    if(count >= MAX_ITEMS) {
        printf("Error: Cannot add more items. Maximum limit reached.\n");
        return;
    }
    strcpy(items[count].name, name);
    items[count].quantity = quantity;
    items[count].price = price;
    count++;
}

void display_items(struct item* items, int count) {
    printf("Item Name\tQuantity\tPrice\n");
    for(int i=0; i<count; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int count = 0;
    char choice;

    printf("Welcome to the Capulet Medical Store Management System\n");
    do {
        printf("\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter item name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                printf("Enter quantity: ");
                int quantity;
                scanf("%d", &quantity);
                printf("Enter price: ");
                double price;
                scanf("%lf", &price);
                add_item(items, count, name, quantity, price);
                break;
            case '2':
                display_items(items, count);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= '3');

    return 0;
}