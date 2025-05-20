//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>

void display_menu();
void calculate_total_cost(int items[], int quantities[], int n);
void calculate_average_cost(int items[], int quantities[], int n);
void calculate_discounted_price(int total_cost);

int main() {
    int items[5] = {100, 200, 150, 300, 250}; // Prices of items
    int quantities[5] = {0, 0, 0, 0, 0}; // Quantities to be purchased
    int choice;
    int n = 5; // Number of items

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 5) {
            printf("Exiting the program.\n");
            break;
        }
        
        printf("Enter the quantity for item %d: ", choice);
        scanf("%d", &quantities[choice - 1]);

        printf("You selected item %d at price %d with quantity %d.\n", choice, items[choice - 1], quantities[choice - 1]);

        int total_cost = 0;
        for (int i = 0; i < n; i++) {
            total_cost += items[i] * quantities[i];
        }

        printf("Total Cost: %d\n", total_cost);
        calculate_discounted_price(total_cost);
    }
    
    // Calculation of average cost per item
    calculate_average_cost(items, quantities, n);

    return 0;
}

void display_menu() {
    printf("\n--- Grocery Store Menu ---\n");
    printf("1. Apples ($100)\n");
    printf("2. Bananas ($200)\n");
    printf("3. Cherries ($150)\n");
    printf("4. Dates ($300)\n");
    printf("5. Elderberries ($250)\n");
    printf("Please choose an item (1-5) or any other number to exit: ");
}

void calculate_total_cost(int items[], int quantities[], int n) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += items[i] * quantities[i];
    }
    printf("Total Cost: %d\n", total_cost);
}

void calculate_average_cost(int items[], int quantities[], int n) {
    int total_cost = 0;
    int total_items = 0;

    for (int i = 0; i < n; i++) {
        total_cost += items[i] * quantities[i];
        total_items += quantities[i];
    }

    if (total_items > 0) {
        float average_cost = (float) total_cost / total_items;
        printf("Average Cost per Item: %.2f\n", average_cost);
    } else {
        printf("No items purchased to calculate average cost.\n");
    }
}

void calculate_discounted_price(int total_cost) {
    float discount = 0.0;

    if (total_cost > 500) {
        discount = 0.15; // 15% discount
    } else if (total_cost > 300) {
        discount = 0.10; // 10% discount
    } else if (total_cost > 100) {
        discount = 0.05; // 5% discount
    }

    float discounted_price = total_cost * (1 - discount);
    
    if (discount > 0) {
        printf("A discount of %.2f%% is applied.\n", discount * 100);
    }
    printf("Final Price after discount: %.2f\n", discounted_price);
}