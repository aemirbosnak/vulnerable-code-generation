//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the menu items
struct item {
    char name[20];
    int price;
    int quantity;
};

// Create an array of menu items
struct item items[] = {
    {"The Last Burger", 15, 0},
    {"The Fallout Sandwich", 12, 0},
    {"The Zombie Chow", 10, 0},
    {"The Radicant Wrap", 8, 0}
};

// Define the total cost function
int total_cost(int num_items) {
    int total = 0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price * items[i].quantity;
    }
    return total;
}

// Define the billing function
void billing(int num_items) {
    int total_cost_ = total_cost(num_items);
    printf("----------------------------------------\n");
    printf("The Last Cafe\n");
    printf("----------------------------------------\n");
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %d units - $%d\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("Total Cost: $%d\n", total_cost_);
    printf("----------------------------------------\n");
    printf("Thank you for your visit!\n");
    printf("----------------------------------------\n\n");
}

int main() {
    int num_items = 0;
    printf("Welcome to The Last Cafe!\n");
    printf("Please select an item from the menu:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, items[i].name);
    }
    printf("Enter the number of the item you want to order: ");
    scanf("%d", &num_items);

    if (num_items > 0 && num_items <= 4) {
        items[num_items - 1].quantity++;
        billing(num_items);
    } else {
        printf("Invalid item number.\n");
    }

    return 0;
}