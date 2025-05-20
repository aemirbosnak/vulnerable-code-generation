//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 100

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} item;

int main() {
    int num_items;
    item menu[MAX_ITEMS];

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please enter the number of items on the menu: ");
    scanf("%d", &num_items);

    printf("Enter the menu items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d name: ", i+1);
        scanf("%s", menu[i].name);
        printf("Item %d quantity: ", i+1);
        scanf("%d", &menu[i].quantity);
        printf("Item %d price: ", i+1);
        scanf("%f", &menu[i].price);
    }

    int choice;
    do {
        printf("\nSelect an option:\n1. View menu\n2. Place order\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMenu:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%d. %s - $%.2f (Quantity: %d)\n", i+1, menu[i].name, menu[i].price, menu[i].quantity);
                }
                break;
            case 2:
                printf("\nEnter the item number: ");
                scanf("%d", &choice);
                if (choice >= 1 && choice <= num_items) {
                    printf("\nEnter the quantity: ");
                    scanf("%d", &menu[choice-1].quantity);
                    printf("\nTotal price: $%.2f\n", menu[choice-1].price * menu[choice-1].quantity);
                } else {
                    printf("\nInvalid item number.\n");
                }
                break;
            case 3:
                printf("\nThank you for using our Cafe Billing System!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}