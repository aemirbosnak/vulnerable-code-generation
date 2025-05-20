//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int quantity;
    float unit_cost;
} Supply;

typedef struct {
    char name[NAME_LEN];
    int quantity_spent;
    float total_cost;
} ExpenseLog;

Supply supplies[MAX_ITEMS];
ExpenseLog expenses[MAX_ITEMS];
int supply_count = 0;
int expense_count = 0;

void add_supply() {
    if (supply_count == MAX_ITEMS) {
        printf("Cannot add more supplies, inventory full.\n");
        return;
    }
    
    printf("Enter supply name: ");
    scanf("%s", supplies[supply_count].name);
    printf("Enter quantity: ");
    scanf("%d", &supplies[supply_count].quantity);
    printf("Enter unit cost: ");
    scanf("%f", &supplies[supply_count].unit_cost);
    
    supply_count++;
    printf("Supply added successfully.\n");
}

void log_expense() {
    if (expense_count == MAX_ITEMS) {
        printf("Cannot log more expenses, log full.\n");
        return;
    }

    printf("Enter supply name spent: ");
    char name[NAME_LEN];
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < supply_count; i++) {
        if (strcmp(supplies[i].name, name) == 0) {
            found = 1;
            printf("Enter quantity spent: ");
            int quantity;
            scanf("%d", &quantity);
            
            if (quantity > supplies[i].quantity) {
                printf("Not enough supply left. Only %d available.\n", supplies[i].quantity);
                return;
            }
            
            supplies[i].quantity -= quantity;
            expenses[expense_count].quantity_spent = quantity;
            strcpy(expenses[expense_count].name, name);
            expenses[expense_count].total_cost = quantity * supplies[i].unit_cost;
            expense_count++;
            printf("Expense logged successfully.\n");
            return;
        }
    }
    
    if (!found) {
        printf("Supply not found in inventory.\n");
    }
}

void display_log() {
    printf("\n***** Expense Log *****\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Supply: %s, Quantity Spent: %d, Total Cost: %.2f\n", 
               expenses[i].name, 
               expenses[i].quantity_spent, 
               expenses[i].total_cost);
    }
    printf("************************\n");
}

void display_supplies() {
    printf("\n***** Supply Inventory *****\n");
    for (int i = 0; i < supply_count; i++) {
        printf("Supply: %s, Quantity: %d, Unit Cost: %.2f\n", 
               supplies[i].name, 
               supplies[i].quantity, 
               supplies[i].unit_cost);
    }
    printf("*******************************\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n*** Post-Apocalyptic Expense Tracker ***\n");
        printf("1. Add Supply\n");
        printf("2. Log Expense\n");
        printf("3. Display Expenses Log\n");
        printf("4. Display Supplies\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_supply();
                break;
            case 2:
                log_expense();
                break;
            case 3:
                display_log();
                break;
            case 4:
                display_supplies();
                break;
            case 5:
                printf("Survivorship is key. Take care!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}