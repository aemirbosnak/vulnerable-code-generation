//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 10

typedef struct {
    char name[20];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS] = {
    {"Coke", 1.25, 5},
    {"Pepsi", 1.35, 3},
    {"Water", 0.75, 10},
    {"Chips", 0.85, 8},
    {"Chocolate", 1.5, 2},
    {"Gum", 0.5, 15},
    {"Candy", 0.65, 7},
    {"Soda", 1.15, 6},
    {"Muffin", 1.75, 4},
    {"Donut", 1.45, 9}
};

void print_menu() {
    printf("\n*** Vending Machine Menu ***\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
}

int main() {
    int selection, input, cash_inserted = 0;
    float change;

    print_menu();
    do {
        printf("\nSelect an item or enter 0 to insert cash: ");
        scanf("%d", &selection);

        if (selection >= 1 && selection <= MAX_ITEMS) {
            if (items[selection - 1].quantity > 0) {
                if (cash_inserted < items[selection - 1].price) {
                    printf("Insufficient funds. Insert more cash.\n");
                    continue;
                }

                cash_inserted -= items[selection - 1].price;
                items[selection - 1].quantity--;
                printf("Dispensing %s...\n", items[selection - 1].name);
            } else {
                printf("%s is out of stock.\n", items[selection - 1].name);
            }

            printf("Returning change: $%.2f\n", cash_inserted);
            cash_inserted = 0;
        } else if (selection == 0) {
            do {
                printf("Insert cash: $");
                scanf("%f", &input);
                cash_inserted += input;
            } while (input <= 0);
        } else {
            printf("Invalid selection. Please try again.\n");
        }

        print_menu();
    } while (1);

    return 0;
}