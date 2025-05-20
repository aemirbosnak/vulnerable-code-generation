//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    float price;
    int quantity;
};

int main() {

    struct item cafe_menu[100];
    int choice = 0, quantity = 0, item_index = 0;
    float total_cost = 0, tax = 0, sub_total = 0;

    printf("\n\nWelcome to C Cafe!\n\n");

    while(choice != 4) {
        printf("1. Add item to order\n2. Remove item from order\n3. View order\n4. Checkout and exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter item name: ");
                scanf("%s", cafe_menu[item_index].name);
                printf("Enter item price: ");
                scanf("%f", &cafe_menu[item_index].price);
                printf("Enter quantity: ");
                scanf("%d", &cafe_menu[item_index].quantity);

                total_cost += (cafe_menu[item_index].price * cafe_menu[item_index].quantity);
                item_index++;

                break;

            case 2:
                if(item_index == 0) {
                    printf("\nOrder is empty!\n");
                    break;
                }

                printf("\nCurrent Order:\n");
                for(int i=0; i<item_index; i++) {
                    printf("%s - $%.2f - %dx\n", cafe_menu[i].name, cafe_menu[i].price, cafe_menu[i].quantity);
                }

                printf("\nEnter item name to remove: ");
                char remove_item[50];
                scanf("%s", remove_item);

                for(int i=0; i<item_index; i++) {
                    if(strcmp(cafe_menu[i].name, remove_item) == 0) {
                        total_cost -= (cafe_menu[i].price * cafe_menu[i].quantity);
                        for(int j=i; j<item_index-1; j++) {
                            cafe_menu[j] = cafe_menu[j+1];
                        }
                        item_index--;
                        printf("\nItem removed!\n"); 
                    }
                }

                break;

            case 3:
                if(item_index == 0) {
                    printf("\nOrder is empty!\n");
                    break;
                }

                printf("\nCurrent Order:\n");
                for(int i=0; i<item_index; i++) {
                    printf("%s - $%.2f - %dx\n", cafe_menu[i].name, cafe_menu[i].price, cafe_menu[i].quantity);
                }

                break;

            case 4:
                sub_total = total_cost;
                tax = total_cost * 0.07;
                total_cost += tax;

                printf("\nSubtotal: $%.2f\nTax: $%.2f\nTotal: $%.2f\n", sub_total, tax, total_cost);
                printf("\nThank you for visiting C Cafe! Have a nice day!\n");

                break;

            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}