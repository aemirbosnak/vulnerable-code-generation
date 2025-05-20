//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Struct for item and its details
typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

// Struct for user's finance details
typedef struct {
    char name[50];
    float income;
    float expense;
    Item items[MAX_ITEMS];
    int num_items;
} User;

// Function to add an item to the user's list of items
void add_item(User* user) {
    if (user->num_items >= MAX_ITEMS) {
        printf("Cannot add more items. Maximum limit reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", user->items[user->num_items].name);

    printf("Enter item price: ");
    scanf("%f", &user->items[user->num_items].price);

    printf("Enter item quantity: ");
    scanf("%d", &user->items[user->num_items].quantity);

    user->num_items++;
}

// Function to display the user's list of items
void display_items(User* user) {
    printf("\nList of Items:\n");
    for (int i = 0; i < user->num_items; i++) {
        printf("%s - $%.2f - %d\n", user->items[i].name, user->items[i].price, user->items[i].quantity);
    }
}

// Function to calculate the total expense of the user
float calculate_expense(User* user) {
    float total_expense = 0.0;

    for (int i = 0; i < user->num_items; i++) {
        total_expense += user->items[i].price * user->items[i].quantity;
    }

    return total_expense;
}

// Main function
int main() {
    User user;

    printf("Enter your name: ");
    scanf("%s", user.name);

    printf("Enter your income: ");
    scanf("%f", &user.income);

    printf("Enter your expense: ");
    scanf("%f", &user.expense);

    // Add some sample items
    add_item(&user);
    add_item(&user);

    display_items(&user);

    float total_expense = calculate_expense(&user);

    printf("\nYour total expense is: $%.2f\n", total_expense);

    return 0;
}