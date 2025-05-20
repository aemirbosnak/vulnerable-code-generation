//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing menu items
struct menu_item {
    char name[50];
    float price;
    int quantity;
};

// Function to display the menu
void display_menu() {
    printf("\n======MENU=======\n");
    printf("1. Coffee - $1.50\n");
    printf("2. Tea - $1.00\n");
    printf("3. Sandwich - $3.00\n");
    printf("4. Pasta - $4.00\n");
    printf("5. Cake - $2.50\n");
    printf("6. Juice - $2.00\n");
    printf("==================\n");
}

// Function to add an item to the order list
void add_to_order(struct menu_item menu[], int order[], int *num_items) {
    int choice;
    int quantity;

    display_menu();
    printf("Enter item number: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 6) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Check if the item is already in the order list
    int i;
    for (i = 0; i < *num_items; i++) {
        if (menu[choice - 1].name == menu[order[i]].name) {
            order[i] = choice - 1;
            menu[order[i]].quantity += quantity;
            return;
        }
    }

    order[*num_items] = choice - 1;
    menu[order[*num_items]].quantity = quantity;
    (*num_items)++;
}

// Function to calculate the total bill
float calculate_bill(struct menu_item menu[], int order[], int num_items) {
    float total = 0;

    int i;
    for (i = 0; i < num_items; i++) {
        total += menu[order[i]].price * menu[order[i]].quantity;
    }

    return total;
}

// Function to display the order list
void display_order(struct menu_item menu[], int order[], int num_items) {
    printf("\n=======ORDER=======\n");
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%s - $%.2f x %d\n", menu[order[i]].name, menu[order[i]].price, menu[order[i]].quantity);
    }
    printf("====================\n");
}

// Main function
int main() {
    struct menu_item menu[6] = {
        {"Coffee", 1.50},
        {"Tea", 1.00},
        {"Sandwich", 3.00},
        {"Pasta", 4.00},
        {"Cake", 2.50},
        {"Juice", 2.00}
    };

    int order[50];
    int num_items = 0;

    int choice;
    do {
        printf("\n1. Add item to order\n");
        printf("2. Calculate bill\n");
        printf("3. Display order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_to_order(menu, order, &num_items);
                break;
            case 2:
                printf("\nTotal bill: $%.2f\n", calculate_bill(menu, order, num_items));
                break;
            case 3:
                display_order(menu, order, num_items);
                break;
            case 4:
                printf("\nThank you for visiting. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}