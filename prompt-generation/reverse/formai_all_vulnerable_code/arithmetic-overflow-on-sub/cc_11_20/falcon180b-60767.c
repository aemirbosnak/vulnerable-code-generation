//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

int main() {
    int choice, quantity;
    float total = 0.0;
    char ch;
    item menu[MAX_ITEMS];

    printf("Welcome to Cafe Billing System!\n");
    printf("Please choose an option:\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Modify item\n");
    printf("4. Display menu\n");
    printf("5. Place order\n");
    printf("6. View bill\n");
    printf("7. Exit\n");

    do {
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", menu[0].name);
                printf("Enter item price: ");
                scanf("%f", &menu[0].price);
                printf("Enter item quantity: ");
                scanf("%d", &menu[0].quantity);
                break;

            case 2:
                printf("Enter item index to remove: ");
                scanf("%d", &quantity);
                for(int i=0; i<MAX_ITEMS; i++) {
                    if(i == quantity-1) {
                        menu[i] = menu[MAX_ITEMS-1];
                    } else {
                        menu[i] = menu[i+1];
                    }
                }
                break;

            case 3:
                printf("Enter item index to modify: ");
                scanf("%d", &quantity);
                printf("Enter new item name: ");
                scanf("%s", menu[quantity].name);
                printf("Enter new item price: ");
                scanf("%f", &menu[quantity].price);
                printf("Enter new item quantity: ");
                scanf("%d", &menu[quantity].quantity);
                break;

            case 4:
                printf("Menu:\n");
                for(int i=0; i<MAX_ITEMS; i++) {
                    printf("%d. %s - $%.2f - %d\n", i+1, menu[i].name, menu[i].price, menu[i].quantity);
                }
                break;

            case 5:
                printf("Enter item index to order: ");
                scanf("%d", &quantity);
                total += menu[quantity-1].price * menu[quantity-1].quantity;
                menu[quantity-1].quantity -= menu[quantity-1].quantity;
                break;

            case 6:
                printf("Bill:\n");
                printf("Total: $%.2f\n", total);
                break;

            case 7:
                printf("Thank you for using Cafe Billing System!");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 7);

    return 0;
}