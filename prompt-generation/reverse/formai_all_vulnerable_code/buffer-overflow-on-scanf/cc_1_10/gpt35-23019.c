//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Define struct for menu items
struct MenuItem {
    char item_name[50];
    int item_price;
};

// Define function to add menu items to the database
// Takes in an array of menu items and the number of items currently in the array
// Returns the new number of items in the array
int addMenuItem(struct MenuItem menu[], int num_items) {
    printf("Enter name of item: ");
    scanf("%s", menu[num_items].item_name);
    printf("Enter price of item: ");
    scanf("%d", &menu[num_items].item_price);
    num_items++;
    return num_items;
}

// Define function to display the menu
// Takes in an array of menu items and the number of items currently in the array
void displayMenu(struct MenuItem menu[], int num_items) {
    printf("\nMenu\n");
    printf("---------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%d\n", menu[i].item_name, menu[i].item_price);
    }
    printf("\n");
}

// Define function to print the bill
// Takes in an array of the items ordered and the number of items ordered
void printBill(struct MenuItem menu[], int order[], int num_order) {
    int total = 0;
    printf("\n\nYour Bill\n");
    printf("---------------\n");
    for (int i = 0; i < num_order; i++) {
        printf("%s - $%d\n", menu[order[i]].item_name, menu[order[i]].item_price);
        total += menu[order[i]].item_price;
    }
    printf("---------------\n");
    printf("Total: $%d\n", total);
}

int main() {
    struct MenuItem menu[50];
    int num_items = 0;
    int order[50];
    int num_order = 0;
    int option = 0;

    // Loop to display menu and ask for user input
    while (option != 4) {
        printf("Welcome to C Cafe!\n");
        printf("1. Add new item to menu\n");
        printf("2. Display menu\n");
        printf("3. Place order\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                num_items = addMenuItem(menu, num_items);
                break;
            case 2:
                displayMenu(menu, num_items);
                break;
            case 3:
                displayMenu(menu, num_items);
                printf("Enter item numbers to order (separated by space): ");
                int input;
                while ((scanf("%d", &input) == 1) && (input != -1)) {
                    if (input < 0 || input >= num_items) {
                        printf("Invalid input\n");
                        continue;
                    }
                    order[num_order] = input;
                    num_order++;
                }
                printBill(menu, order, num_order);
                break;
            case 4:
                break;  
            default:
                printf("Invalid option.\n");
        }
    }

    printf("Thank you for visiting C Cafe!");
    return 0;
}