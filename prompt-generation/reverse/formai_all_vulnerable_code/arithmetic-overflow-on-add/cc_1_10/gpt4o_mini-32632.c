//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
    float price;
} MenuItem;

void displayMenu(MenuItem menu[], int count) {
    printf("\n--- Welcome to the Happy Cafe! ---\n");
    printf("Here’s our delightful menu:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("-----------------------------------\n");
}

float calculateTotal(int selections[], MenuItem menu[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        if (selections[i] > 0) {
            total += selections[i] * menu[i].price;
        }
    }
    return total;
}

void printBill(int selections[], MenuItem menu[], int count) {
    printf("\n--- Your Happy Cafe Bill ---\n");
    for (int i = 0; i < count; i++) {
        if (selections[i] > 0) {
            printf("%s x %d - $%.2f\n", menu[i].name, selections[i], menu[i].price * selections[i]);
        }
    }
    printf("---------------------------\n");
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50},
        {"Tea", 1.80},
        {"Sandwich", 3.00},
        {"Cake", 2.20},
        {"Juice", 1.50},
        {"Pasta", 4.00}
    };
    
    int selections[MAX_ITEMS] = {0};
    int itemCount = 6;
    char choice;
    
    while (1) {
        displayMenu(menu, itemCount);
        
        printf("Please select an item (1-%d) or 0 to finish: ", itemCount);
        int selection;
        scanf("%d", &selection);
        
        if (selection == 0) {
            break;
        } else if (selection < 1 || selection > itemCount) {
            printf("Oops! That's not a valid option. Please try again!\n");
            continue;
        }
        
        printf("How many %s would you like? ", menu[selection - 1].name);
        int quantity;
        scanf("%d", &quantity);
        
        if (quantity < 0) {
            printf("Oh no! Negative quantities are not allowed.\n");
            continue;
        }
        
        selections[selection - 1] += quantity;
        printf("Great! You've added %d %s to your order.\n\n", quantity, menu[selection - 1].name);
    }
    
    float total = calculateTotal(selections, menu, itemCount);
    
    printBill(selections, menu, itemCount);
    printf("Total Amount: $%.2f\n", total);
    printf("Thank you for visiting the Happy Cafe! Have a wonderful day!\n");
    
    return 0;
}