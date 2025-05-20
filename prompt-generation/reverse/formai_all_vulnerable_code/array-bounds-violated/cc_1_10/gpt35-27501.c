//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define structure for menu items
typedef struct MenuItem {
    char name[20];
    int price;
} MenuItem;

// Function to print menu
void printMenu(MenuItem *menu, int size) {
    printf("\n================MENU=================\n");
    printf("Item Name\t\tPrice\n");
    for(int i=0; i<size; i++) {
        printf("%-20s\t%d\n", menu[i].name, menu[i].price);
    }
    printf("=====================================\n\n");
}

int main() {

    // Initialize menu items
    MenuItem menu[5];
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 50;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 30;
    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 70;
    strcpy(menu[3].name, "Burger");
    menu[3].price = 100;
    strcpy(menu[4].name, "Fries");
    menu[4].price = 40;
    
    // Declare variables
    int order[5] = {0, 0, 0, 0, 0};
    int total = 0;
    int choice = 0;
    int quantity = 0;

    // Print welcome message
    printf("Welcome to the Immersive Cafe Billing System!\n");
    
    while(choice < 6) {

        // Print menu
        printMenu(menu, 5);
        
        // Display options to the user
        printf("Please select an option:\n");
        printf("1. Add an item to the order.\n");
        printf("2. Remove an item from the order.\n");
        printf("3. Pay the bill.\n");
        printf("4. Cancel the order.\n");
        
        // Accept user choice
        scanf("%d", &choice);

        // Handle user choice
        switch(choice) {
            case 1:
                // Add item to the order
                printf("Please enter the item number:\n");
                scanf("%d", &choice);
                choice--;
                printf("Please enter the quantity:\n");
                scanf("%d", &quantity);
                order[choice] = quantity;
                printf("Item added to order successfully!\n");
                break;
            case 2:
                // Remove item from the order
                printf("Please enter the item number:\n");
                scanf("%d", &choice);
                choice--;
                order[choice] = 0;
                printf("Item removed from order successfully!\n");
                break;
            case 3:
                // Calculate total bill and print it
                total = 0;
                printf("\n=====================================\n");
                printf("Item Name\t\tQuantity\tPrice\n");
                for(int i=0; i<5; i++) {
                    if(order[i] > 0) {
                        printf("%-20s\t%d\t\t%d\n", menu[i].name, order[i], menu[i].price*order[i]);
                        total = total + menu[i].price*order[i];
                        order[i] = 0;
                    }
                }
                printf("\nTotal bill: %d\n", total);
                printf("Thank you for visiting Immersive Cafe! :)\n");
                printf("=====================================\n\n");
                choice = 6;
                break;
            case 4:
                // Cancel order and exit program
                printf("Order cancelled!\n");
                choice = 6;
                exit(0);
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}