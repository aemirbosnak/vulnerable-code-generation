//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Item;

int main() {
    Item inventory[MAX_ITEMS];
    int numItems = 0;
    char choice;

    do {
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. View inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numItems >= MAX_ITEMS) {
                    printf("Inventory is full!\n");
                } else {
                    printf("Enter item name: ");
                    scanf("%s", inventory[numItems].name);
                    printf("Enter item description: ");
                    scanf("%s", inventory[numItems].description);
                    printf("Enter item quantity: ");
                    scanf("%d", &inventory[numItems].quantity);
                    printf("Enter item price: ");
                    scanf("%lf", &inventory[numItems].price);
                    numItems++;
                }
                break;
            case '2':
                if(numItems == 0) {
                    printf("Inventory is empty!\n");
                } else {
                    printf("Enter item name to remove: ");
                    scanf("%s", inventory[numItems - 1].name);
                    numItems--;
                }
                break;
            case '3':
                printf("Inventory:\n");
                for(int i = 0; i < numItems; i++) {
                    printf("%s\t%s\t%d\t$%.2f\n", inventory[i].name, inventory[i].description, inventory[i].quantity, inventory[i].price);
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= '4');

    return 0;
}