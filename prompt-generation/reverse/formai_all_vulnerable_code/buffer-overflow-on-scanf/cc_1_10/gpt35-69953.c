//FormAI DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>

/* Expense struct */
typedef struct Expense {
    char name[50];
    float amount;
    char date[15];
    struct Expense *next;   /* Pointer to next expense */
} Expense;

/* Function to add a new expense */
Expense *addExpense(Expense *head) {
    Expense *expense = malloc(sizeof(Expense));  /* Allocate memory for the new expense */
    printf("\nEnter expense name: ");
    scanf("%s", expense->name);
    printf("Enter expense amount: ");
    scanf("%f", &expense->amount);
    printf("Enter expense date (mm/dd/yyyy): ");
    scanf("%s", expense->date);
    expense->next = head;  /* Set the new expense as the head of the list */
    printf("\nExpense added successfully!\n");
    return expense;  /* Return the new head of the list */
}

/* Function to display all expenses */
void displayExpenses(Expense *head) {
    if (head == NULL) {  /* Base case: end of list */
        printf("\nEnd of expenses.\n");
        return;
    }
    printf("\nExpense name: %s\n", head->name);
    printf("Expense amount: %.2f\n", head->amount);
    printf("Expense date: %s\n", head->date);
    displayExpenses(head->next);  /* Recursive call to display the next expense */
}

int main() {
    Expense *head = NULL;  /* Initialize the head of the list to NULL */
    int choice;
    do {
        printf("\nEnter your choice:\n1. Add expense\n2. Display expenses\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = addExpense(head);  /* Update the head of the list with the new expense */
                break;
            case 2:
                displayExpenses(head);  /* Display all expenses in the list using recursion */
                break;
            case 3:
                printf("\nProgram terminated.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}