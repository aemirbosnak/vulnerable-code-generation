//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIZZA_SIZE 10
#define TOPPINGS 5
#define CUSTOMERS 10

typedef struct {
    char name[20];
    int age;
} customer_t;

typedef struct {
    char topping[20];
    int quantity;
} pizza_t;

customer_t customers[CUSTOMERS] = {
    {"Alice", 25},
    {"Bob", 30},
    {"Charlie", 20},
    {"David", 35},
    {"Eve", 25}
};

pizza_t pizzas[PIZZA_SIZE] = {
    {"Margherita", 2, 30},
    {"Pepperoni", 3, 25},
    {"Hawaiian", 1, 20},
    {"Meat Lover's", 4, 35},
    {"Veggie", 5, 20}
};

void take_order(int customer_idx, int pizza_idx) {
    printf("Welcome, %s! Today's special is our Margherita pizza for $15.99. Would you like to try it? (y/n)\n", customers[customer_idx].name);
    char input;
    scanf("%c", &input);
    if (input == 'y') {
        pizzas[pizza_idx].quantity++;
        printf("Great choice! Your total is $15.99. Would you like to add any toppings? (y/n)\n");
        input = getchar();
        if (input == 'y') {
            printf("Excellent! Would you like to try our Pepperoni, Hawaiian, or Meat Lover's pizza instead? (type 'm' for Margherita, 'p' for Pepperoni, 'h' for Hawaiian, or 'ml' for Meat Lover's)\n");
            char topping_choice = getchar();
            if (topping_choice == 'm') {
                pizzas[pizza_idx].topping[0] = 'M';
            } else if (topping_choice == 'p') {
                pizzas[pizza_idx].topping[0] = 'P';
            } else if (topping_choice == 'h') {
                pizzas[pizza_idx].topping[0] = 'H';
            } else if (topping_choice == 'ml') {
                pizzas[pizza_idx].topping[0] = 'M';
                pizzas[pizza_idx].quantity++;
            }
            printf("Great choice! Your total is now $%.2f. Your pizza will be ready in 10 minutes. Please come back to pick it up!\n", pizzas[pizza_idx].quantity * 15.99);
        } else {
            printf("No problem! Your total is still $15.99. Your pizza will be ready in 10 minutes. Please come back to pick it up!\n");
        }
    } else {
        printf("No worries! Our Margherita pizza is still available for $15.99. Would you like to try it now? (y/n)\n");
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < CUSTOMERS; i++) {
        for (int j = 0; j < PIZZA_SIZE; j++) {
            take_order(i, j);
        }
    }
    return 0;
}