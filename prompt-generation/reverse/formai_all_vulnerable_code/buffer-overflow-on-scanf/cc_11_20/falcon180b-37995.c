//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 50

typedef struct {
    char name[50];
    int price;
} Item;

int main() {
    char choice;
    int numItems = 0, totalPrice = 0;
    Item items[MAX_ITEMS];

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please enter your name: ");
    scanf("%s", items[numItems].name);

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Modify item\n");
        printf("4. View items\n");
        printf("5. Calculate total price\n");
        printf("6. Exit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                if(numItems >= MAX_ITEMS) {
                    printf("Sorry, you've reached the maximum number of items allowed.\n");
                } else {
                    printf("Enter the name of the item: ");
                    scanf("%s", items[numItems].name);
                    printf("Enter the price of the item: ");
                    scanf("%d", &items[numItems].price);
                    numItems++;
                    printf("\nItem added successfully!\n");
                }
                break;

            case '2':
                printf("Enter the name of the item you want to remove: ");
                scanf("%s", items[numItems-1].name);
                numItems--;
                printf("\nItem removed successfully!\n");
                break;

            case '3':
                printf("Enter the name of the item you want to modify: ");
                scanf("%s", items[numItems-1].name);
                printf("Enter the new price of the item: ");
                scanf("%d", &items[numItems-1].price);
                printf("\nItem modified successfully!\n");
                break;

            case '4':
                printf("\nList of items:\n");
                for(int i=0; i<numItems; i++) {
                    printf("%s: $%d\n", items[i].name, items[i].price);
                }
                break;

            case '5':
                totalPrice = 0;
                for(int i=0; i<numItems; i++) {
                    totalPrice += items[i].price;
                }
                printf("\nTotal price: $%d\n", totalPrice);
                break;

            case '6':
                printf("Thank you for using the Cafe Billing System!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '6');

    return 0;
}