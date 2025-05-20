//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ITEMS 100
#define TAX_RATE 0.05

// Declare structs
typedef struct {
    char name[20];
    double price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int num_items;
} Menu;

// Declare functions
void welcome();
void display_menu(Menu menu);
int get_user_choice(Menu menu);
double calculate_subtotal(Menu menu, int *choices, int count);
double calculate_tax(double subtotal);
void generate_receipt(Menu menu, int *choices, int count, double subtotal, double tax);

int main() {

    // Declare variables
    Menu menu;
    menu.num_items = 0;
    int choices[MAX_ITEMS];
    int count = 0;

    // Add items to the menu
    MenuItem item1 = {"Coffee", 2.5};
    MenuItem item2 = {"Croissant", 3.0};
    MenuItem item3 = {"Cinnamon Roll", 2.75};
    menu.items[0] = item1;
    menu.items[1] = item2;
    menu.items[2] = item3;
    menu.num_items = 3;

    // Display welcome message and menu
    welcome();
    display_menu(menu);

    // Get user's choices
    int choice;
    while (1) {
        choice = get_user_choice(menu);
        if (choice == -1) {
            break;
        }
        choices[count++] = choice;
    }

    // Calculate subtotal and tax
    double subtotal = calculate_subtotal(menu, choices, count);
    double tax = calculate_tax(subtotal);

    // Generate receipt
    generate_receipt(menu, choices, count, subtotal, tax);

    return 0;
}

void welcome() {
    printf("Welcome to Brave Cafe\n");
}

void display_menu(Menu menu) {
    printf("Menu: \n");
    for (int i = 0; i < menu.num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu.items[i].name, menu.items[i].price);
    }
    printf("Please enter the number next to the item you would like to order.\n");
    printf("Enter -1 to finish ordering.\n");
}

int get_user_choice(Menu menu) {
    int choice;
    scanf("%d", &choice);
    if (choice == -1) {
        return -1;
    }
    if (choice < 1 || choice > menu.num_items) {
        printf("Invalid choice. Please try again.\n");
        return get_user_choice(menu);
    }
    printf("You chose %s.\n", menu.items[choice-1].name);
    return choice-1;
}

double calculate_subtotal(Menu menu, int *choices, int count) {
    double subtotal = 0;
    for (int i = 0; i < count; i++) {
        subtotal += menu.items[choices[i]].price;
    }
    return subtotal;
}

double calculate_tax(double subtotal) {
    double tax = subtotal * TAX_RATE;
    return tax;
}

void generate_receipt(Menu menu, int *choices, int count, double subtotal, double tax) {
    printf("\n");
    printf("Receipt: \n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%.2f\n", menu.items[choices[i]].name, menu.items[choices[i]].price);
    }
    printf("\n");
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", tax);
    printf("Total: $%.2f\n", subtotal+tax);
    printf("Thank you for coming to Brave Cafe!\n");
}