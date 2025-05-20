//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define NUM_ITEMS 5
#define MIN_COINS 5

typedef struct {
    int id;
    char name[20];
    float price;
} Item;

Item items[NUM_ITEMS] = {
    {1, "Coke", 1.25},
    {2, "Pepsi", 1.35},
    {3, "Chips", 0.75},
    {4, "Chocolate", 1.50},
    {5, "Gum", 0.65}
};

int main() {
    int choice, coins[MIN_COINS];
    int total_coins = 0;
    float change;

    printf("Welcome to the vending machine!\n");

    for (int i = 0; i < MIN_COINS; i++) {
        printf("Please insert coin %d: ", i + 1);
        scanf("%d", &coins[i]);
        total_coins += coins[i];
    }

    do {
        printf("\nSelect an item by entering its ID:\n");
        for (int i = 0; i < NUM_ITEMS; i++) {
            printf("ID %d: %s - $%.2f\n", items[i].id, items[i].name, items[i].price);
        }

        scanf("%d", &choice);

        if (choice >= 1 && choice <= NUM_ITEMS) {
            if (total_coins >= items[choice - 1].price) {
                total_coins -= items[choice - 1].price;
                printf("\nYou bought %s.\n", items[choice - 1].name);
                change = total_coins;
                total_coins = 0;

                printf("Your change is: $%.2f\n", change);
            } else {
                printf("\nInsufficient funds. Please insert more coins.\n");
            }
        } else {
            printf("\nInvalid selection. Please try again.\n");
        }

    } while (choice < 1 || choice > NUM_ITEMS || total_coins < items[choice - 1].price);

    return 0;
}