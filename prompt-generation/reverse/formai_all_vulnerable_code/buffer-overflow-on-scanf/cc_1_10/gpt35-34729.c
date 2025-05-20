//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

//Struct to store menu items and their prices
typedef struct {
    char item[20];
    float price;
} MenuItem;

//Function to display menu items
void displayMenu(MenuItem menu[], int size) {
    printf("\n      C CAFE MENU      \n");
    printf("----------------------\n");
    printf("| %-15s| %-5s |\n", "ITEM", "PRICE");
    printf("----------------------\n");
    for (int i = 0; i < size; i++) {
        printf("| %-15s| $%-4.2f |\n", menu[i].item, menu[i].price);
    }
    printf("----------------------\n");
}

//Function to total bill and display it
void displayBill(float bill) {
    printf("\nYOUR TOTAL BILL: $%.2f\n", bill);
}

int main() {
    //Declare and initialize menu items
    MenuItem menu[] = {{"Espresso", 2.50}, {"Cappuccino", 3.50}, {"Latte", 4.00},
                       {"Croissant", 2.00}, {"Bagel", 2.50}, {"Muffin", 2.25}};

    //Display menu items to the user
    displayMenu(menu, 6);

    //Initialize variables for user input and total bill
    int choice, quantity;
    float bill = 0;

    //Loop to allow user to order multiple items
    do {
        //Ask user for item choice and quantity
        printf("\nEnter item number (1-6) to order or 0 to calculate bill: ");
        scanf("%d", &choice);
        if (choice == 0) {
            //User has chosen to calculate bill, break out of loop
            break;
        }
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        //Check for valid item choice
        if (choice < 1 || choice > 6) {
            printf("Invalid item choice. Please try again.\n");
        } else {
            //Update total bill
            bill += menu[choice - 1].price * quantity;
            printf("%d %s(s) added to order.\n", quantity, menu[choice - 1].item);
        }
    } while (choice != 0);

    //Display final bill to the user
    displayBill(bill);

    return 0;
}