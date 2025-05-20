//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <string.h>

// Function to clear the console
void clear() {
    printf("\033[H\033[J");
}

// Structure to store menu items
typedef struct MenuItem {
    char name[50];
    int price;
} MenuItem;

// Function to display the menu
void displayMenu(MenuItem* menu, int size) {
    printf("====== Menu ======\n");
    for(int i=0; i<size; i++) {
        printf("%s\t$%d\n", menu[i].name, menu[i].price);
    }
    printf("==================\n");
}

// Function to calculate the total bill
int calculateBill(MenuItem* order, int size) {
    int total = 0;
    for(int i=0; i<size; i++) {
        total += order[i].price;
    }
    return total;
}

// Function to display the bill
void displayBill(MenuItem* order, int size, int total) {
    printf("\n====== Bill ======\n");
    for(int i=0; i<size; i++) {
        printf("%s\t$%d\n", order[i].name, order[i].price);
    }
    printf("------------------\n");
    printf("Total\t$%d\n", total);
    printf("==================\n");
}

int main() {
    // Initialize the menu items
    MenuItem menu[] = {
        {"Espresso", 2},
        {"Cappuccino", 3},
        {"Latte", 4},
        {"Muffin", 2},
        {"Croissant", 2},
        {"Bagel", 2}
    };
    int menuSize = sizeof(menu)/sizeof(MenuItem);

    // Welcome message
    printf("Welcome to Happy Cafe!\n");

    // Display the menu
    displayMenu(menu, menuSize);

    // Take the order
    MenuItem order[50];
    int orderSize = 0;
    char choice[50];
    while(1) {
        printf("Enter an item to order (or 'done' to finish): ");
        scanf("%s", choice);
        if(strcmp(choice, "done") == 0) {
            break;
        }
        // Find the item in the menu
        int found = 0;
        for(int i=0; i<menuSize; i++) {
            if(strcmp(choice, menu[i].name) == 0) {
                order[orderSize] = menu[i];
                orderSize++;
                found = 1;
                break;
            }
        }
        if(!found) {
            printf("Sorry, we don't have that item. Please try again.\n");
        }
    }

    // Calculate the total bill
    int total = calculateBill(order, orderSize);

    // Display the bill
    displayBill(order, orderSize, total);

    // Thank you message
    printf("Thank you for visiting Happy Cafe! Have a nice day!\n");

    return 0;
}