//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_CODE 10

typedef struct {
    char name[MAX_NAME];
    char code[MAX_CODE];
    int quantity;
    float price;
} item;

void create_item(item *i) {
    printf("Enter item name (max %d characters): ", MAX_NAME);
    scanf("%s", i->name);
    printf("Enter item code (max %d characters): ", MAX_CODE);
    scanf("%s", i->code);
    printf("Enter item quantity: ");
    scanf("%d", &i->quantity);
    printf("Enter item price: ");
    scanf("%f", &i->price);
}

void display_item(item i) {
    printf("\nItem Name: %s\n", i.name);
    printf("Item Code: %s\n", i.code);
    printf("Item Quantity: %d\n", i.quantity);
    printf("Item Price: $%.2f\n\n", i.price);
}

void main() {
    item inventory[MAX_ITEMS];
    int choice, i = 0;

    do {
        printf("\n*** Product Inventory System ***\n");
        printf("1. Create Item\n2. Display Item\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(i >= MAX_ITEMS) {
                    printf("Inventory is full.\n");
                } else {
                    create_item(&inventory[i]);
                    i++;
                }
                break;
            case 2:
                if(i == 0) {
                    printf("Inventory is empty.\n");
                } else {
                    printf("Enter item index to display (0 to %d): ", i-1);
                    scanf("%d", &choice);
                    display_item(inventory[choice]);
                }
                break;
            case 3:
                printf("Thank you for using the Product Inventory System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);
}