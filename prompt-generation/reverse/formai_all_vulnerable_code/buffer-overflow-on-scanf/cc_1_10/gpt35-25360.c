//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Structure to hold menu item information
typedef struct MenuItem {
    char item_name[50];
    int item_price;
} MenuItem;

// Function to display the menu
void display_menu(MenuItem menu[], int size) {
    printf("\n----------- MENU -----------\n");
    for(int i=0; i<size; i++) {
        printf("%d. %s - $%d\n", i+1, menu[i].item_name, menu[i].item_price);
    }
    printf("---------------------------\n");
}

int main() {
    // Create the menu
    MenuItem menu[] = {
        {"Coffee", 3},
        {"Tea", 2},
        {"Croissant", 2},
        {"Muffin", 2},
        {"Sandwich", 5}
    };

    int menu_size = sizeof(menu) / sizeof(MenuItem);

    // Display the menu
    display_menu(menu, menu_size);

    // Initialize variables
    int choice, quantity, total = 0;

    // Loop to take user inputs
    do {
        printf("Enter the item number (0 to exit): ");
        scanf("%d", &choice);

        // Check if choice is valid
        if(choice < 0 || choice > menu_size) {
            printf("Invalid choice! Please choose again.\n");
            continue;
        }

        // Check if the user has chosen to exit
        if(choice == 0) {
            printf("Thank you for using our system. Your total bill is $%d\n", total);
            break;
        }

        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        // Calculate the total price and add it to the total bill
        int price = menu[choice-1].item_price;
        int item_total = price * quantity;
        total += item_total;

        printf("Added %d %s(s) to your order. Total price: $%d\n", quantity, menu[choice-1].item_name, item_total);
    } while(choice != 0);

    return 0;
}