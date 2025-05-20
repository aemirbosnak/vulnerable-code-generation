//FormAI DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char name[50];
    float amount;
    struct Expense *next;
};

void addExpense(struct Expense **head, char *name, float amount) {
    struct Expense *newExpense = (struct Expense*) malloc(sizeof(struct Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if(*head == NULL) {
        *head = newExpense;
        return;
    }

    struct Expense *temp = *head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newExpense;
}

void printExpenses(struct Expense *head) {
    if(head == NULL) {
        printf("No expenses to show!\n");
        return;
    }

    printf("Expenses:\n\n");
    printf("%-30s%-10s\n", "Name", "Amount");

    while(head != NULL) {
        printf("%-30s%-10.2f\n", head->name, head->amount);
        head = head->next;
    }
}

void deleteExpense(struct Expense **head, char *name) {
    struct Expense *temp = *head;
    struct Expense *prev = NULL;

    if(temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Expense not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    struct Expense *head = NULL;
    int choice;
    char name[50];
    float amount;

    while(1) {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Delete expense\n");
        printf("4. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(&head, name, amount);
                printf("Expense added successfully!\n");
                break;
            case 2:
                printExpenses(head);
                break;
            case 3:
                printf("\nEnter expense name to delete: ");
                scanf("%s", name);
                deleteExpense(&head, name);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice, try again!\n");
        }
    }

    return 0;
}