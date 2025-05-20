//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PIZZAS 5

typedef struct {
    char name[20];
    int stock;
} Pizza;

void displayMenu(Pizza pizzas[], int count) {
    printf("\n🍕 Pizza Delivery Menu 🍕\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Available: %d)\n", i + 1, pizzas[i].name, pizzas[i].stock);
    }
    printf("Please choose your pizza (1 to %d): ", count);
}

bool isValidChoice(int choice, int count) {
    return choice > 0 && choice <= count;
}

void orderPizza(Pizza pizzas[], int *stockCount) {
    int choice;

    displayMenu(pizzas, *stockCount);

    if (scanf("%d", &choice) != 1) {
        printf("🎉 Oops! Please enter a valid number! 🎉\n");
        while(getchar() != '\n'); // clear input buffer
        return;
    }

    if (!isValidChoice(choice, *stockCount)) {
        printf("🎉 Sorry, that’s not a valid pizza choice! Please try again! 🎉\n");
        return;
    }

    choice--; // adjust for zero-indexing
    if (pizzas[choice].stock > 0) {
        printf("🎉 Hooray! You've successfully ordered a %s! 🎉\n", pizzas[choice].name);
        pizzas[choice].stock--;
    } else {
        printf("🌟 Oh no! The %s is out of stock! 🌟\n", pizzas[choice].name);
    }
}

void displayAvailablePizzas(Pizza pizzas[], int count) {
    printf("\nHere’s what we have in stock:\n");
    for (int i = 0; i < count; i++) {
        printf("- %s (%d available)\n", pizzas[i].name, pizzas[i].stock);
    }
}

int main() {
    Pizza pizzas[MAX_PIZZAS] = {
        {"Margherita", 5},
        {"Pepperoni", 2},
        {"Veggie", 10},
        {"BBQ Chicken", 0},
        {"Hawaiian", 3}
    };

    int pizzaCount = MAX_PIZZAS;
    int continueOrdering = 1;

    printf("🌈 Welcome to Happy Pizza Delivery! 🌈\n");

    while (continueOrdering) {
        orderPizza(pizzas, &pizzaCount);
        printf("\nWould you like to order another pizza? (1 for Yes / 0 for No): ");
        
        if (scanf("%d", &continueOrdering) != 1) {
            printf("🎊 Please enter 1 or 0! 🎊\n");
            while (getchar() != '\n'); // clear input buffer
            continueOrdering = 1; // default to continue ordering
        }

        if (continueOrdering == 0) {
            printf("🎉 Thank you for using Happy Pizza Delivery! Come back soon! 🎉\n");
            break;
        }

        displayAvailablePizzas(pizzas, pizzaCount);
    }

    return 0;
}