//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    char type[10]; // "income" or "expense"
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int entry_count;
} PersonalFinancePlanner;

void add_entry(PersonalFinancePlanner *planner) {
    if (planner->entry_count >= MAX_ENTRIES) {
        printf("Cannot add more entries. Maximum limit reached.\n");
        return;
    }

    Entry new_entry;
    printf("Enter entry name: ");
    scanf("%s", new_entry.name);
    printf("Enter amount: ");
    scanf("%lf", &new_entry.amount);
    printf("Enter type (income/expense): ");
    scanf("%s", new_entry.type);

    planner->entries[planner->entry_count] = new_entry;
    planner->entry_count++;
    printf("Entry added successfully!\n");
}

void display_entries(PersonalFinancePlanner *planner) {
    if (planner->entry_count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\n--- Personal Finance Entries ---\n");
    for (int i = 0; i < planner->entry_count; i++) {
        printf("Entry %d: Name: %s, Amount: %.2f, Type: %s\n",
               i + 1, planner->entries[i].name,
               planner->entries[i].amount,
               planner->entries[i].type);
    }
    printf("---------------------------------\n");
}

double calculate_total(PersonalFinancePlanner *planner, const char *type) {
    double total = 0.0;
    for (int i = 0; i < planner->entry_count; i++) {
        if (strcmp(planner->entries[i].type, type) == 0) {
            total += planner->entries[i].amount;
        }
    }
    return total;
}

void display_summary(PersonalFinancePlanner *planner) {
    double total_income = calculate_total(planner, "income");
    double total_expense = calculate_total(planner, "expense");
    double balance = total_income - total_expense;

    printf("\n--- Personal Finance Summary ---\n");
    printf("Total Income: %.2f\n", total_income);
    printf("Total Expense: %.2f\n", total_expense);
    printf("Balance: %.2f\n", balance);
    printf("---------------------------------\n");
}

void show_menu() {
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Display Summary\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    PersonalFinancePlanner planner;
    planner.entry_count = 0;

    int choice;
    do {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(&planner);
                break;
            case 2:
                display_entries(&planner);
                break;
            case 3:
                display_summary(&planner);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}