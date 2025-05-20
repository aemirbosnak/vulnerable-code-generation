//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} item;

void print_menu() {
    printf("----------------------------------------------------------------\n");
    printf("| Item | Quantity | Price | Total | \n");
    printf("----------------------------------------------------------------\n");
    printf("| Coffee | 1 | 1.50 | 1.50 | \n");
    printf("| Tea | 1 | 1.20 | 1.20 | \n");
    printf("| Cake | 1 | 2.00 | 2.00 | \n");
    printf("| Sandwich | 1 | 3.00 | 3.00 | \n");
    printf("|--------------------------------------------------------------\n");
}

void get_order(item *order, int *num_items) {
    printf("Enter the number of items you want to order: ");
    scanf("%d", num_items);

    for (int i = 0; i < *num_items; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", order[i].name);

        printf("Enter the quantity of item %d: ", i + 1);
        scanf("%d", &order[i].quantity);

        printf("Enter the price of item %d: ", i + 1);
        scanf("%f", &order[i].price);
    }
}

void print_order(item *order, int num_items) {
    float total = 0;

    for (int i = 0; i < num_items; i++) {
        printf("| %s | %d | %.2f | %.2f |\n", order[i].name, order[i].quantity, order[i].price, order[i].quantity * order[i].price);
        total += order[i].quantity * order[i].price;
    }

    printf("|--------------------------------------------------------------|\n");
    printf("| Total | | | %.2f |\n", total);
    printf("----------------------------------------------------------------\n");
}

int main() {
    item order[100];
    int num_items;

    print_menu();
    get_order(order, &num_items);
    print_order(order, num_items);

    return 0;
}