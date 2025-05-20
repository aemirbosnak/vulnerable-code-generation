//FormAI DATASET v1.0 Category: Expense Tracker ; Style: synchronous
// C Expense Tracker program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold expense information
struct expense {
    char name[50];
    float amount;
};

// Function to display menu and prompt for user input
int display_menu() {
    int choice;
    printf("Expense Tracker Program\n");
    printf("-----------------------\n\n");
    printf("1. Add Expense\n");
    printf("2. View All Expenses\n");
    printf("3. Exit\n\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    return choice;
}

// Function to add an expense to the list
void add_expense(struct expense *list, int *counter) {
    char name[50];
    float amount;
    printf("Enter expense name: ");
    scanf("%s", name);
    printf("Enter expense amount: ");
    scanf("%f", &amount);
    strcpy(list[*counter].name, name);
    list[*counter].amount = amount;
    (*counter)++;
    printf("Expense added successfully!\n\n");
}

// Function to view all expenses
void view_expenses(struct expense *list, int counter) {
    if (counter == 0) {
        printf("No expenses to display!\n\n");
    } else {
        printf("All Expenses:\n");
        for (int i = 0; i < counter; i++) {
            printf("%d. %s - %.2f\n", i + 1, list[i].name, list[i].amount);
        }
        printf("\n");
    }
}

int main() {
    // Initialize variables
    int choice, counter = 0, running = 1;
    struct expense *list = malloc(sizeof(struct expense) * 100);
    
    // Loop until user chooses to exit
    while (running) {
        choice = display_menu();
        switch (choice) {
            case 1:
                add_expense(list, &counter);
                break;
            case 2:
                view_expenses(list, counter);
                break;
            case 3:
                printf("Exiting program...\n");
                running = 0;
                break;
            default:
                printf("Invalid choice, please try again.\n\n");
                break;
        }
    }
    
    // Free dynamically allocated memory
    free(list);
    
    return 0;
}