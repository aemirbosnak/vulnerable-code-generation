//FormAI DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char name[50];
    float amount;
    int day;
    int month;
    int year;
};

void displayMenu();
void addExpense(struct Expense *, int *);
void viewExpenses(struct Expense *, int);
void deleteExpense(struct Expense *, int *);

int main() {
    int choice, numExpenses = 0;
    struct Expense expenses[100];

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                deleteExpense(expenses, &numExpenses);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);

    return 0;
}

void displayMenu() {
    printf("\n1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
}

void addExpense(struct Expense *expenses, int *numExpenses) {
    printf("\nEnter expense name: ");
    scanf("%s", (expenses + *numExpenses)->name);
    printf("Enter expense amount: ");
    scanf("%f", &(expenses + *numExpenses)->amount);
    printf("Enter expense date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &(expenses + *numExpenses)->day, &(expenses + *numExpenses)->month, &(expenses + *numExpenses)->year);

    printf("\nExpense added successfully!\n");
    *numExpenses += 1;
}

void viewExpenses(struct Expense *expenses, int numExpenses) {
    if (numExpenses == 0) {
        printf("\nNo expenses to display!\n");
    } else {
        printf("\nExpense List:\n");
        printf("------------------------------------------------------\n");
        printf("| %-15s | %-10s | %-15s |\n", "Name", "Amount", "Date");
        printf("------------------------------------------------------\n");

        for (int i = 0; i < numExpenses; i++) {
            printf("| %-15s | %10.2f | %02d/%02d/%04d |\n", (expenses + i)->name, (expenses + i)->amount, (expenses + i)->day, (expenses + i)->month, (expenses + i)->year);
        }

        printf("------------------------------------------------------\n");
    }
}

void deleteExpense(struct Expense *expenses, int *numExpenses) {
    char nameToDelete[50];
    int found = 0;

    if (*numExpenses == 0) {
        printf("\nNo expenses to delete!\n");
    } else {
        printf("\nEnter name of expense to delete: ");
        scanf("%s", nameToDelete);

        for (int i = 0; i < *numExpenses; i++) {
            if (strcmp((expenses + i)->name, nameToDelete) == 0) {
                found = 1;

                for (int j = i; j < *numExpenses - 1; j++) {
                    *(expenses + j) = *(expenses + j + 1);
                }

                printf("\nExpense deleted successfully!\n");

                *numExpenses -= 1;
                break;
            }
        }

        if (!found) {
            printf("\nExpense not found!\n");
        }
    }
}