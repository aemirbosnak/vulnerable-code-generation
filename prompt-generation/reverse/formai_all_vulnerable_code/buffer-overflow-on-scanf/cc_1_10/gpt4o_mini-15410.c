//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an expense record
typedef struct Expense {
    char name[50];
    float amount;
    char category[30];
    struct Expense* next;
} Expense;

// Function declarations
Expense* createExpense(char* name, float amount, char* category);
void addExpense(Expense** head, char* name, float amount, char* category);
void displayExpenses(Expense* head);
void freeExpenses(Expense* head);
void searchExpense(Expense* head, char* name);

int main() {
    Expense* expenses = NULL;
    char choice[10], name[50], category[30];
    float amount;

    printf("Welcome, fair traveler, to the Expense Tracker!\n");

    // In a gentle manner, charge the user to add expenses
    while (1) {
        printf("\nWhat dost thou desire to do?\n");
        printf("1. Add an expense\n2. View all expenses\n3. Search for an expense\n4. Exit\n");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            printf("Enter the name of the expense, oh noble spirit: ");
            scanf("%s", name);
            printf("Alas, what sum must thou declare for this? ");
            scanf("%f", &amount);
            printf("In what category shall this expense dwell? ");
            scanf("%s", category);
            addExpense(&expenses, name, amount, category);
            printf("The expense hath been added to the ledger!\n");
        } 
        else if (strcmp(choice, "2") == 0) {
            printf("\nLet us unveil the ledger of expenses:\n");
            displayExpenses(expenses);
        } 
        else if (strcmp(choice, "3") == 0) {
            printf("What expense dost thou seek, dear friend? ");
            scanf("%s", name);
            searchExpense(expenses, name);
        } 
        else if (strcmp(choice, "4") == 0) {
            printf("Goodbye, dear friend, 'til we meet again!\n");
            break;
        } 
        else {
            printf("Alas! Thy choice is unclear. Please choose again.\n");
        }
    }

    // Free the allocated memory for expenses
    freeExpenses(expenses);
    return 0;
}

// Create a new expense and return the pointer to it
Expense* createExpense(char* name, float amount, char* category) {
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    if (newExpense == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    strcpy(newExpense->category, category);
    newExpense->next = NULL;
    return newExpense;
}

// Add an expense to the linked list
void addExpense(Expense** head, char* name, float amount, char* category) {
    Expense* newExpense = createExpense(name, amount, category);
    newExpense->next = *head;
    *head = newExpense;
}

// Display all the expenses in the linked list
void displayExpenses(Expense* head) {
    if (head == NULL) {
        printf("Alas, there are no expenses recorded!\n");
        return;
    }
    printf("Name\tAmount\tCategory\n");
    printf("-------------------------\n");
    while (head != NULL) {
        printf("%s\t%.2f\t%s\n", head->name, head->amount, head->category);
        head = head->next;
    }
}

// Free all allocated memory for expenses
void freeExpenses(Expense* head) {
    Expense* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Search for an expense by name
void searchExpense(Expense* head, char* name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("Expense found! Name: %s, Amount: %.2f, Category: %s\n", head->name, head->amount, head->category);
            return;
        }
        head = head->next;
    }
    printf("Alas! No such expense hath been recorded.\n");
}