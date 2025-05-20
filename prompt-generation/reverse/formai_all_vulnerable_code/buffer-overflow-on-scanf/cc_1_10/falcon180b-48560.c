//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define structure for menu items
struct menu_item {
    char name[50];
    float price;
};

// Function to display menu
void display_menu(struct menu_item menu[], int size) {
    printf("Cafe Menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to get user's choice
int get_choice(struct menu_item menu[], int size) {
    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= size) {
            break;
        }
        printf("Invalid choice. Please try again.\n");
    }
    return choice;
}

// Function to calculate total amount
float calculate_total(struct menu_item menu[], int size, int choice) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        if (i + 1 == choice) {
            total += menu[i].price;
        }
    }
    return total;
}

// Function to print receipt
void print_receipt(struct menu_item menu[], int size, int choice, float total) {
    printf("\nReceipt:\n");
    printf("Item ordered: %s\nPrice: $%.2f\nTotal: $%.2f\n", menu[choice - 1].name, menu[choice - 1].price, total);
}

int main() {
    // Define menu items
    struct menu_item menu[] = {{"Coffee", 2.50}, {"Tea", 1.50}, {"Coke", 1.00}, {"Pepsi", 1.50}};
    int size = sizeof(menu) / sizeof(menu[0]);

    // Display menu
    display_menu(menu, size);

    // Get user's choice
    int choice = get_choice(menu, size);

    // Calculate total amount
    float total = calculate_total(menu, size, choice);

    // Print receipt
    print_receipt(menu, size, choice, total);

    return 0;
}