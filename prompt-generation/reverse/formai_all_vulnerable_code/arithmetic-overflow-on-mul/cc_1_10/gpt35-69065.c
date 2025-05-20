//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global variables for menu and prices
char menu[5][20] = {"Coffee", "Tea", "Sandwich", "Pastry", "Juice"};
int price[5] = {50, 40, 70, 60, 30};

//Function to print menu
void printMenu() {
    printf("Menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s  - Rs %d\n", i+1, menu[i], price[i]);
    }
}

//Function to calculate bill
int calculateBill(int quantities[]) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += quantities[i] * price[i];
    }
    return total;
}

int main() {
    //Array to store quantities of items ordered
    int quantities[5] = {0, 0, 0, 0, 0};

    printf("Welcome to C Cafe!\n");

    //Loop to take orders
    while (1) {
        printMenu();
        printf("Enter the item number you want to order (0 to exit): ");
        int choice;
        scanf("%d", &choice);

        if (choice < 0 || choice > 5) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        if (choice == 0) {
            printf("Thanks for visiting C Cafe. Your bill amount is Rs %d. Please come again!\n", calculateBill(quantities));
            break;
        }

        printf("Enter the quantity: ");
        int quantity;
        scanf("%d", &quantity);

        quantities[choice-1] += quantity;

        printf("Your order of %d %s has been added to the cart.\n", quantity, menu[choice-1]);
    }
    return 0;
}