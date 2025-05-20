//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct {
    char name[30];
    float price;
} MenuItem;

MenuItem menu[MAX_ITEMS] = {
    {"Coffee", 2.5},
    {"Tea", 2.0},
    {"Sandwich", 5.0},
    {"Cake", 3.5},
    {"Salad", 4.0},
    {"Juice", 3.0},
    {"Soda", 1.5},
    {"Pizza", 6.0},
    {"Pasta", 5.5},
    {"Ice Cream", 3.0}
};

void displayMenu() {
    printf("Welcome to the Cafe! Here's our menu:\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("-------------------------------------\n");
}

float calculateBill(int order[MAX_ITEMS], int quantities[MAX_ITEMS]) {
    float total = 0.0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (order[i] > 0) {
            total += menu[i].price * quantities[i];
        }
    }
    return total;
}

void printBill(int order[MAX_ITEMS], int quantities[MAX_ITEMS], float total) {
    printf("\nYour Bill:\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (order[i] > 0) {
            printf("%s x%d = $%.2f\n", menu[i].name, quantities[i], menu[i].price * quantities[i]);
        }
    }
    printf("-------------------------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("-------------------------------------\n");
}

int main() {
    int order[MAX_ITEMS] = {0};
    int quantities[MAX_ITEMS] = {0};
    int choice;
    char opt;

    do {
        displayMenu();
        
        printf("Select an item to order (1-%d) or 0 to finish your order: ", MAX_ITEMS);
        scanf("%d", &choice);

        if (choice < 0 || choice > MAX_ITEMS) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        if (choice == 0) {
            break; // Finish the order
        }
        
        printf("Enter quantity for %s: ", menu[choice - 1].name);
        scanf("%d", &quantities[choice - 1]);
        order[choice - 1] += quantities[choice - 1]; // Record the order

        printf("Do you want to order another item? (y/n): ");
        getchar(); // To consume the newline character
        scanf("%c", &opt);
    } while (opt == 'y' || opt == 'Y');

    // Calculate the total bill
    float total = calculateBill(order, quantities);
    printBill(order, quantities, total);

    printf("Thank you for visiting our Cafe!\n");
    return 0;
}