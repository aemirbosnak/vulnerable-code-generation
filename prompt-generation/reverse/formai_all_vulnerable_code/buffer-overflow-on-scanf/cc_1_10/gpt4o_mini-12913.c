//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_ITEMS 10

struct MenuItem {
    char name[30];
    float price;
};

struct MenuItem menu[MAX_ITEMS] = {
    {"Coffee", 2.5},
    {"Tea", 1.5},
    {"Sandwich", 4.0},
    {"Burger", 5.0},
    {"Pasta", 6.5},
    {"Salad", 3.0},
    {"Juice", 2.0},
    {"Pizza", 8.0},
    {"Ice Cream", 4.5},
    {"Cake", 3.5}
};

void displayMenu() {
    printf("\nCafe Menu:\n");
    printf("-------------\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

float calculateBill(int quantities[]) {
    float total = 0.0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        total += quantities[i] * menu[i].price;
    }
    return total;
}

void takeOrder(int quantities[]) {
    int itemNumber, quantity;

    while (1) {
        printf("\nEnter item number (1-%d) or 0 to finish: ", MAX_ITEMS);
        scanf("%d", &itemNumber);
        
        if (itemNumber == 0) {
            break;
        }

        if (itemNumber < 1 || itemNumber > MAX_ITEMS) {
            printf("Invalid item number. Please try again.\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[itemNumber - 1].name);
        scanf("%d", &quantity);
        
        if (quantity < 0) {
            printf("Quantity cannot be negative. Please enter again.\n");
            continue;
        }

        quantities[itemNumber - 1] += quantity;
    }
}

void printBill(int quantities[]) {
    printf("\nYour Bill:\n");
    printf("-------------\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (quantities[i] > 0) {
            printf("%s x%d - $%.2f\n", menu[i].name, quantities[i], quantities[i] * menu[i].price);
        }
    }
    
    float total = calculateBill(quantities);
    printf("-------------\n");
    printf("Total Bill: $%.2f\n", total);
}

int main() {
    int quantities[MAX_ITEMS] = {0};

    displayMenu();
    takeOrder(quantities);
    printBill(quantities);

    return 0;
}