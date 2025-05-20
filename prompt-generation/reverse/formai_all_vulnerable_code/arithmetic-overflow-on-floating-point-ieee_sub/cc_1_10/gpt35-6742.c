//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 20
#define MAX_ITEMS 10
#define MAX_ITEM_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN+1];
    float balance;
    int num_items;
    char items[MAX_ITEMS][MAX_ITEM_NAME_LEN+1];
} account;

void print_header() {
    printf("*******************************\n");
    printf("* Personal Finance Planner    *\n");
    printf("*******************************\n");
}

void print_menu() {
    printf("\nMain Menu:\n\n");
    printf("1. Create account\n");
    printf("2. View account\n");
    printf("3. Add item to account\n");
    printf("4. Exit\n");
}

void create_account(account *acc) {
    printf("\nEnter account name: ");
    scanf("%s", acc->name);
    acc->balance = 0.0;
    acc->num_items = 0;
    printf("Account created successfully!\n");
}

void view_account(account *acc) {
    printf("\nAccount Name: %s\n", acc->name);
    printf("Balance: $%.2f\n", acc->balance);
    printf("Items:\n");
    for (int i = 0; i < acc->num_items; i++) {
        printf("- %s\n", acc->items[i]);
    }
}

void add_item(account *acc) {
    char item[MAX_ITEM_NAME_LEN+1];
    float cost;
    printf("\nEnter item name: ");
    scanf("%s", item);
    printf("Enter cost: $");
    scanf("%f", &cost);
    if (acc->balance < cost) {
        printf("You do not have enough money to purchase this item.\n");
    } else {
        acc->balance -= cost;
        strcpy(acc->items[acc->num_items++], item);
        printf("%s added to account for $%.2f\n", item, cost);
    }
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");
    print_header();

    account acc;
    int choice = 0;
    do {
        print_menu();
        printf("\nEnter choice (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_account(&acc);
                break;
            case 2:
                if (acc.name[0] == '\0') {
                    printf("\nNo account created yet. Please create account first.\n");
                } else {
                    view_account(&acc);
                }
                break;
            case 3:
                if (acc.name[0] == '\0') {
                    printf("\nNo account created yet. Please create account first.\n");
                } else {
                    add_item(&acc);
                }
                break;
            case 4:
                printf("\nExiting the Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please choose a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}