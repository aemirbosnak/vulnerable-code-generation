//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50

struct item {
    char name[MAX_NAME_LEN];
    float price;
};

struct order {
    int num_items;
    struct item items[MAX_ITEMS];
};

int main() {
    struct order order;
    int i, j, choice, num_items = 0;
    float total_price = 0.0;

    printf("Welcome to Cafe Billing System!\n");

    while(1) {
        printf("\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. View order\n");
        printf("4. Calculate total\n");
        printf("5. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_items >= MAX_ITEMS) {
                    printf("Order is full. Please remove an item first.\n");
                } else {
                    printf("Enter item name: ");
                    scanf("%s", order.items[num_items].name);
                    printf("Enter item price: ");
                    scanf("%f", &order.items[num_items].price);
                    num_items++;
                }
                break;

            case 2:
                if(num_items == 0) {
                    printf("Order is empty.\n");
                } else {
                    printf("Enter item number to remove: ");
                    scanf("%d", &j);
                    if(j >= 0 && j < num_items) {
                        num_items--;
                        for(i = j; i < num_items; i++) {
                            order.items[i] = order.items[i+1];
                        }
                    } else {
                        printf("Invalid item number.\n");
                    }
                }
                break;

            case 3:
                printf("Order:\n");
                for(i = 0; i < num_items; i++) {
                    printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
                }
                break;

            case 4:
                total_price = 0.0;
                for(i = 0; i < num_items; i++) {
                    total_price += order.items[i].price;
                }
                printf("Total price: $%.2f\n", total_price);
                break;

            case 5:
                printf("Thank you for using Cafe Billing System!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}