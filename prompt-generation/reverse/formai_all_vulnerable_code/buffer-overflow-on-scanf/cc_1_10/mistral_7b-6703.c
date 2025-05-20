//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct {
    char description[50];
    float amount;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;
float balance = 0.0;

void add_item(const char *desc, float amount) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Max number of items reached.\n");
        return;
    }
    strcpy(items[num_items].description, desc);
    items[num_items].amount = amount;
    num_items++;
    balance += amount;
}

void print_balance() {
    printf("\nCurrent Balance: $%.2f\n", balance);
}

int main() {
    char input_desc[50];
    float input_amount;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add income\n");
        printf("2. Add expense\n");
        printf("3. Print balance\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income description: ");
                scanf("%s", input_desc);
                printf("Enter income amount: $");
                scanf("%f", &input_amount);
                add_item(input_desc, input_amount);
                break;
            case 2:
                printf("Enter expense description: ");
                scanf("%s", input_desc);
                printf("Enter expense amount: $");
                scanf("%f", &input_amount);
                add_item(input_desc, -input_amount);
                break;
            case 3:
                print_balance();
                break;
            case 4:
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}