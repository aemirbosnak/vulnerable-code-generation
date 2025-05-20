//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: medieval
// medieval_expense_tracker.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[30];
    float amount;
} Entry;

void print_header() {
    printf("Medieval Expense Tracker\n");
    printf("=======================\n");
}

void print_menu() {
    printf("1. Add new expense\n");
    printf("2. View all expenses\n");
    printf("3. View total expenses\n");
    printf("4. Exit\n");
}

void add_expense(Entry *entries, int *num_entries) {
    printf("Enter name of expense: ");
    fgets(entries[*num_entries].name, 30, stdin);
    printf("Enter amount of expense: ");
    scanf("%f", &entries[*num_entries].amount);
    (*num_entries)++;
}

void view_all_expenses(Entry *entries, int num_entries) {
    printf("Name\tAmount\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%f\n", entries[i].name, entries[i].amount);
    }
}

void view_total_expenses(Entry *entries, int num_entries) {
    float total = 0;
    for (int i = 0; i < num_entries; i++) {
        total += entries[i].amount;
    }
    printf("Total expenses: %f\n", total);
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice = 0;

    print_header();

    while (choice != 4) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(entries, &num_entries);
                break;
            case 2:
                view_all_expenses(entries, num_entries);
                break;
            case 3:
                view_total_expenses(entries, num_entries);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    printf("Goodbye!\n");

    return 0;
}