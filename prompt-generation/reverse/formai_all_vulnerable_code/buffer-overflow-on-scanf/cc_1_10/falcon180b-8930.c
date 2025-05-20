//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} item;

int main() {
    int num_items, i, j, choice, total_cost = 0;
    char order[MAX_ITEMS][MAX_NAME_LEN];
    item menu[MAX_ITEMS];

    printf("Welcome to the Cafe Billing System!\n");

    // Load menu items
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("Enter item %d name: ", i+1);
        scanf("%s", menu[i].name);
        printf("Enter item %d price: ", i+1);
        scanf("%s", menu[i].price);
    }

    // Display menu
    printf("\nMenu:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - $%s\n", i+1, menu[i].name, menu[i].price);
    }

    // Take customer order
    printf("\nEnter your order (item number, quantity): ");
    scanf("%s", order[0]);
    num_items = 1;
    while (strcmp(order[num_items-1], "done")!= 0) {
        printf("\nEnter your order (item number, quantity): ");
        scanf("%s", order[num_items]);
        num_items++;
    }

    // Calculate total cost
    for (i = 0; i < num_items; i++) {
        for (j = 0; j < MAX_ITEMS; j++) {
            if (strcmp(menu[j].name, order[i]) == 0) {
                total_cost += atoi(menu[j].price);
                break;
            }
        }
    }

    // Display total cost
    printf("\nTotal cost: $%d\n", total_cost);

    // Print receipt
    printf("\nReceipt:\n");
    for (i = 0; i < num_items; i++) {
        for (j = 0; j < MAX_ITEMS; j++) {
            if (strcmp(menu[j].name, order[i]) == 0) {
                printf("%s - $%s\n", menu[j].name, menu[j].price);
                break;
            }
        }
    }

    return 0;
}