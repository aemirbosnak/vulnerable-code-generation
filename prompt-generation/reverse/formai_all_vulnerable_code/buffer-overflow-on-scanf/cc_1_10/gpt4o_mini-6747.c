//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
    char type[10]; // "income" or "expense"
} Entry;

Entry entries[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Oops! You've reached the maximum number of entries!\n");
        return;
    }

    Entry new_entry;
    printf("Let's add a new entry! 🌟\n");
    printf("Enter the name of the entry: ");
    scanf(" %[^\n]", new_entry.name);
    printf("Enter the amount: ");
    scanf("%f", &new_entry.amount);
    printf("Is this an income or expense? (type 'income' or 'expense'): ");
    scanf("%s", new_entry.type);

    entries[entry_count] = new_entry;
    entry_count++;
    printf("Hooray! Your entry was added successfully! 🎉\n");
}

void view_entries() {
    printf("\nHere are your financial entries: 📋\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%d. %s: %.2f (%s)\n", i + 1, entries[i].name, entries[i].amount, entries[i].type);
    }
    if (entry_count == 0) {
        printf("No entries to show! Let's add some! 😊\n");
    }
}

void calculate_balance() {
    float total_income = 0;
    float total_expense = 0;

    for (int i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].type, "income") == 0) {
            total_income += entries[i].amount;
        } else if (strcmp(entries[i].type, "expense") == 0) {
            total_expense += entries[i].amount;
        }
    }

    float balance = total_income - total_expense;
    printf("\nYour total income: %.2f\n", total_income);
    printf("Your total expenses: %.2f\n", total_expense);
    printf("Your current balance is: %.2f\n", balance);
}

void display_menu() {
    printf("\nWelcome to your Personal Finance Planner! 🎈\n");
    printf("Please choose an option:\n");
    printf("1. Add an entry\n");
    printf("2. View entries\n");
    printf("3. Calculate balance\n");
    printf("4. Exit\n");
}

int main() {
    int choice = 0;

    while (choice != 4) {
        display_menu();
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                calculate_balance();
                break;
            case 4:
                printf("Thank you for using the Personal Finance Planner! Have a wonderful day! 🌞\n");
                break;
            default:
                printf("Hmm, I didn't quite catch that! Please choose a valid option. 😊\n");
        }
    }

    return 0;
}