//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int expense_count;
} ExpenseTracker;

void display_welcome_message() {
    printf("Welcome to the Wacky Expense Tracker!\n");
    printf("Where we track your spending faster than your bank can catch on!\n\n");
}

void add_expense(ExpenseTracker* tracker) {
    if (tracker->expense_count >= MAX_EXPENSES) {
        printf("Oops! You can't squeeze in any more expenses! It's like trying to put a giraffe in a Mini Cooper!\n");
        return;
    }

    printf("Enter the description of your expense (be descriptive, like 'Dinner at the fancy place'):\n");
    getchar(); // To consume the leftover newline
    fgets(tracker->expenses[tracker->expense_count].description, MAX_DESC_LENGTH, stdin);
    tracker->expenses[tracker->expense_count].description[strcspn(tracker->expenses[tracker->expense_count].description, "\n")] = 0; // Remove trailing newline

    printf("Please enter the amount you spent on that:\n");
    scanf("%f", &tracker->expenses[tracker->expense_count].amount);
    
    printf("Added a zesty expense: '%s' for $%.2f! Your wallet thanks you...maybe.\n\n", 
           tracker->expenses[tracker->expense_count].description, 
           tracker->expenses[tracker->expense_count].amount);
    
    tracker->expense_count++;
}

void display_expenses(const ExpenseTracker* tracker) {
    if (tracker->expense_count == 0) {
        printf("You’ve been really great at saving money! No expenses to report!\n\n");
        return;
    }

    printf("Here's your expense list, proudly displaying each financial blunder:\n");
    for (int i = 0; i < tracker->expense_count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("\n");
}

float calculate_total_expenses(const ExpenseTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->expense_count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void exit_message(float total) {
    printf("Thank you for using the Wacky Expense Tracker, where misery meets curiosity!\n");
    printf("You've spent a total of $%.2f\n", total);
    if (total > 100) {
        printf("Yikes! Looks like you've been having a party that your wallet wasn't invited to!\n");
    } else {
        printf("You're doing alright! As they say, 'a penny saved is a penny earned'... or something like that, right?\n");
    }
}

int main() {
    ExpenseTracker tracker = { .expense_count = 0 };
    int choice;

    display_welcome_message();

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. Display all expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Exit\n");
        
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(&tracker);
                break;
            case 2:
                display_expenses(&tracker);
                break;
            case 3:
                printf("Total expenses so far: $%.2f\n\n", calculate_total_expenses(&tracker));
                break;
            case 4:
                exit_message(calculate_total_expenses(&tracker));
                printf("Goodbye! Remember, every penny counts... unless you lose it in the couch!\n");
                exit(0);
            default:
                printf("Invalid choice! Are you sure you’re not one of my expenses trying to sneak in?\n\n");
        }
    }

    return 0;
}