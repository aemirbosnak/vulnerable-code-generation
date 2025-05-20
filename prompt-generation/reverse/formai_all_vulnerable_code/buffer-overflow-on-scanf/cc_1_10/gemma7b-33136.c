//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CoffeeCup {
    char name[20];
    int quantity;
    float price;
} CoffeeCup;

CoffeeCup cups[] = {
    {"Cappuccino", 2, 5.0},
    {"Latte", 1, 4.0},
    {"Americano", 3, 3.0},
    {"Macchiato", 0, 6.0}
};

int main() {
    system("clear");
    int i = 0;
    int choice;
    float total_price = 0.0;
    char customer_name[20];

    printf("Welcome to the Coffee Cafe!\n");
    printf("Please select a coffee:**\n");

    for (i = 0; i < 4; i++) {
        printf("%d. %s - %d cups - $%.2f\n", i + 1, cups[i].name, cups[i].quantity, cups[i].price);
    }

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= 4) {
        CoffeeCup selected_cup = cups[choice - 1];
        selected_cup.quantity--;
        total_price += selected_cup.price * selected_cup.quantity;
        printf("Selected: %s - %d cups\n", selected_cup.name, selected_cup.quantity);
    } else {
        printf("Invalid choice.\n");
    }

    printf("Please enter your name: ");
    scanf("%s", customer_name);

    printf("Thank you, %s, for your order. Your total price is $%.2f.\n", customer_name, total_price);

    return 0;
}