//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Define structures for different dish types
typedef struct {
    char name[20];
    float base_price;
    char* options[5];
    int num_options;
} Sandwich;

typedef struct {
    char name[20];
    float base_price;
    char* options[3];
    int num_options;
} Burger;

typedef struct {
    char name[20];
    float base_price;
    int size;
    char* toppings[5];
    int num_toppings;
} Pizza;

// Define a menu with different dish types and their options
Sandwich sandwiches[] = {
    {"Classic Sandwich", 3.50, {"White", "Brown", "Multigrain"}, 3},
    {"Grilled Sandwich", 4.25, {"Cheese", "Chicken Tikka", "Egg"}, 3}
};

Burger burgers[] = {
    {"Veg Burger", 4.00, {"Cheese", "Mayo", "Tomato"}, 3},
    {"Chicken Burger", 5.50, {"Onion Rings", "Fries", "Coleslaw"}, 3}
};

Pizza pizzas[] = {
    {"Small Pizza", 7.50, 12, {"Pepperoni", "Mushroom", "Olives"}, 3},
    {"Large Pizza", 10.50, 16, {"Pepperoni", "Mushroom", "Sausage"}, 4}
};

// Function to display the menu and take user input
void takeOrder(void) {
    int choice, i, j;
    char option[20];
    float total = 0.0;
    printf("\n---- MENU ----\n");
    printf("1. Sandwiches\n2. Burgers\n3. Pizzas\n4. Bill\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < 2; i++) {
                printf("\n%s (Base Price: %.2f)", sandwiches[i].name, sandwiches[i].base_price);
                for (j = 0; j < sandwiches[i].num_options; j++) {
                    printf("\n\t%s: %.2f", sandwiches[i].options[j], sandwiches[i].base_price + j * 0.5);
                }
                printf("\nEnter your choice: ");
                scanf("%s", option);
                for (j = 0; j < sandwiches[i].num_options; j++) {
                    if (strcmp(option, sandwiches[i].options[j]) == 0) {
                        total += sandwiches[i].base_price + j * 0.5;
                        break;
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < 2; i++) {
                printf("\n%s (Base Price: %.2f)", burgers[i].name, burgers[i].base_price);
                for (j = 0; j < burgers[i].num_options; j++) {
                    printf("\n\t%s: %.2f", burgers[i].options[j], burgers[i].base_price + j * 0.75);
                }
                printf("\nEnter your choice: ");
                scanf("%s", option);
                for (j = 0; j < burgers[i].num_options; j++) {
                    if (strcmp(option, burgers[i].options[j]) == 0) {
                        total += burgers[i].base_price + j * 0.75;
                        break;
                    }
                }
            }
            break;
        case 3:
            for (i = 0; i < 2; i++) {
                printf("\n%s (Base Price: %.2f, Size: %d)", pizzas[i].name, pizzas[i].base_price, pizzas[i].size);
                printf("\nEnter the number of toppings: ");
                int num_toppings;
                scanf("%d", &num_toppings);
                for (j = 0; j < num_toppings; j++) {
                    printf("\nEnter topping %d: ", j + 1);
                    scanf("%s", option);
                    for (int k = 0; k < pizzas[i].num_toppings; k++) {
                        if (strcmp(option, pizzas[i].toppings[k]) == 0) {
                            total += pizzas[i].base_price + 2 * (pizzas[i].size + (j + 1));
                            break;
                        }
                    }
                }
            }
            break;
        case 4:
            printf("\nYour total bill is: %.2f", total);
            break;
        default:
            printf("\nInvalid choice!");
    }
}

int main() {
    takeOrder();
    return 0;
}