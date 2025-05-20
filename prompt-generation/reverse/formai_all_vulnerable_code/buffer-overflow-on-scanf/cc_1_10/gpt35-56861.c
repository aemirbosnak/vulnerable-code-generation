//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to display the menu
void display_menu() {
    printf("\n--------------------------------------------------------\n");
    printf("                          MENU                          \n");
    printf("--------------------------------------------------------\n\n");
    printf(" Item Name            | Price (Rs.)\n");
    printf("----------------------|------------------\n");
    printf("Coffee                | 50\n");
    printf("Tea                   | 30\n");
    printf("Cold Drinks           | 60\n");
    printf("Sandwich              | 80\n");
    printf("Burger                | 100\n");
    printf("Pizza                 | 150\n");
    printf("--------------------------------------------------------\n");
}

//Function to get the user's choice
int get_user_choice() {
    int choice;
    printf("\nEnter your choice (1-6): ");
    scanf("%d", &choice);
    return choice;
}

//Function to calculate the bill
float calculate_bill(int item_price, int item_quantity) {
    float total_price = item_price * item_quantity;
    return total_price;
}

//Main function
int main() {
    int choice, item_quantity, item_price, i, j = 0;
    float bill_total = 0;
    char item_name[20];

    //Display the menu
    display_menu();

    //Get the user's choice
    choice = get_user_choice();

    //Loop for ordering multiple items
    while (choice >= 1 && choice <= 6) {
        switch (choice) {
            case 1:
                strcpy(item_name, "Coffee");
                item_price = 50;
                break;
            case 2:
                strcpy(item_name, "Tea");
                item_price = 30;
                break;
            case 3:
                strcpy(item_name, "Cold Drinks");
                item_price = 60;
                break;
            case 4:
                strcpy(item_name, "Sandwich");
                item_price = 80;
                break;
            case 5:
                strcpy(item_name, "Burger");
                item_price = 100;
                break;
            case 6:
                strcpy(item_name, "Pizza");
                item_price = 150;
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }

        //Ask for the quantity
        printf("\nEnter the quantity: ");
        scanf("%d", &item_quantity);

        //Calculate the bill and add to the total bill
        float total_price = calculate_bill(item_price, item_quantity);
        bill_total += total_price;

        //Print the item details
        printf("\n%s - %d x %d - Rs. %.2f\n", item_name, item_quantity, item_price, total_price);

        //Ask for another item or exit
        printf("\nDo you want to order another item? (Y/N): ");
        char option;
        scanf(" %c", &option);

        //If user doesn't want to order any more items, print the total bill and exit
        if (option == 'N' || option == 'n')
            break;

        //Otherwise, display the menu again
        if (option == 'Y' || option == 'y') {
            display_menu();
            choice = get_user_choice();
        }
    }

    //Print the bill total
    printf("\n\nTotal Bill: Rs. %.2f. Thank you for your visit.\n\n", bill_total);

    return 0;
}