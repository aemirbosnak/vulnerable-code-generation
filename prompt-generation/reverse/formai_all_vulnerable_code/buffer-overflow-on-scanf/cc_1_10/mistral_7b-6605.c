//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>
#define MAX_ITEMS 10

typedef struct {
    char name[20];
    float price;
    int quantity;
} Item;

int main() {
    Item items[MAX_ITEMS];
    int choice, i, qty;
    float amount, payment;

    // Initialize items
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("Enter name of item %d: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter price of item %s: ", items[i].name);
        scanf("%f", &items[i].price);
        items[i].quantity = 10;
        printf("\n");
    }

    // Main loop
    while (1) {
        printf("\nWelcome to the Vending Machine!\n");
        printf("Available Items:\n");

        // Display items and their prices
        for (i = 0; i < MAX_ITEMS; i++) {
            printf("%d. %s ($%.2f)\n", i + 1, items[i].name, items[i].price);
        }

        printf("\nEnter the number of the item you want to buy: ");
        scanf("%d", &choice);

        if (choice > MAX_ITEMS || choice < 1) {
            printf("Invalid selection. Try again.\n");
            continue;
        }

        printf("Enter the amount you will pay: $");
        scanf("%f", &amount);

        // Calculate change
        payment = amount;
        payment -= items[choice - 1].price;

        if (items[choice - 1].price > amount) {
            printf("Insufficient funds.\n");
            continue;
        }

        // Deduct item from stock and return change
        items[choice - 1].quantity--;
        printf("You bought %s. Your change is $%.2f.\n", items[choice - 1].name, payment);

        printf("\nDo you want to buy another item? (1 for yes, 0 for no): ");
        scanf("%d", &qty);

        if (qty == 0) {
            break;
        }
    }

    return 0;
}