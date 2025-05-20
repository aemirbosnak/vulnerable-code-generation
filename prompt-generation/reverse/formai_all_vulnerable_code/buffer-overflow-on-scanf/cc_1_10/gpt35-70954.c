//FormAI DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct Expense {
    char category[20];
    float amount;
    char date[11];
} Expense;

void addExpense(Expense *arr[], int *size) {
    Expense *newExpense = malloc(sizeof(Expense));

    printf("Enter expense category: ");
    scanf("%s", newExpense->category);

    printf("Enter expense amount: ");
    scanf("%f", &newExpense->amount);

    printf("Enter expense date (MM/DD/YYYY): ");
    scanf("%s", newExpense->date);

    arr[*size] = newExpense;
    (*size)++;

    printf("Expense added successfully!\n");
}

void viewExpenses(Expense *arr[], int size) {
    if (size == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("Category | Amount | Date\n");

    for (int i = 0; i < size; i++) {
        printf("%s | %.2f | %s\n", arr[i]->category, arr[i]->amount, arr[i]->date);
    }
}

void deleteExpense(Expense *arr[], int *size) {
    if (*size == 0) {
        printf("No expenses found.\n");
        return;
    }

    char category[20];
    printf("Enter category of expense to delete: ");
    scanf("%s", category);

    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(arr[i]->category, category) == 0) {
            free(arr[i]);
            break;
        }
    }

    if (i == *size) {
        printf("Expense with category '%s' not found.\n", category);
    } else {
        for (int j = i; j < *size - 1; j++) {
            arr[j] = arr[j+1];
        }
        (*size)--;
        printf("Expense with category '%s' deleted successfully.\n", category);
    }
}

void printMenu() {
    printf("\nExpense Tracker\n\n");
    printf("1. Add expense\n");
    printf("2. View all expenses\n");
    printf("3. Delete expense by category\n");
    printf("4. Quit\n");
}

int main() {
    Expense *expenses[100];
    int size = 0;
    int choice;

    do {
        printMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &size);
                break;
            case 2:
                viewExpenses(expenses, size);
                break;
            case 3:
                deleteExpense(expenses, &size);
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please try again.");
        }
    } while (choice != 4);

    return 0;
}