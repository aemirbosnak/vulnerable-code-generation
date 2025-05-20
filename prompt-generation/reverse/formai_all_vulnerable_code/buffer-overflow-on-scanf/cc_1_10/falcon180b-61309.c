//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    double price;
} item;

int main() {
    item inventory[MAX_ITEMS];
    int num_items = 0;
    char choice;

    do {
        printf("Product Inventory System\n");
        printf("-------------------------\n");
        printf("1. Add item\n");
        printf("2. View inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_items >= MAX_ITEMS) {
                    printf("Inventory is full.\n");
                } else {
                    printf("Enter item name: ");
                    scanf("%s", inventory[num_items].name);
                    printf("Enter item category: ");
                    scanf("%s", inventory[num_items].category);
                    printf("Enter item quantity: ");
                    scanf("%d", &inventory[num_items].quantity);
                    printf("Enter item price: ");
                    scanf("%lf", &inventory[num_items].price);
                    num_items++;
                    printf("Item added successfully.\n");
                }
                break;
            case '2':
                if(num_items == 0) {
                    printf("Inventory is empty.\n");
                } else {
                    printf("Inventory:\n");
                    for(int i=0; i<num_items; i++) {
                        printf("%d. %s - %s - %d units - $%.2f\n", i+1, inventory[i].name, inventory[i].category, inventory[i].quantity, inventory[i].price);
                    }
                }
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '3');

    return 0;
}