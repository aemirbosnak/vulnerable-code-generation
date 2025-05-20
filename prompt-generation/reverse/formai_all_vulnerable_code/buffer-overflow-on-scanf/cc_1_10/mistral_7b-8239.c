//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define EXPENSE_SIZE 100

typedef struct {
    char name[EXPENSE_SIZE];
    float amount;
    struct Expense* next;
} Expense;

Expense* head = NULL;
Expense* current = NULL;

void print_menu() {
    printf("\nExpense Tracker Menu\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Search Expense\n");
    printf("5. Quit\n");
}

void add_expense() {
    if (head == NULL) {
        head = (Expense*) malloc(sizeof(Expense));
        printf("Enter Expense Name: ");
        scanf("%s", head->name);
        printf("Enter Expense Amount: ");
        scanf("%f", &head->amount);
        head->next = NULL;
        current = head;
    } else {
        current->next = (Expense*) malloc(sizeof(Expense));
        current = current->next;
        printf("Enter Expense Name: ");
        scanf("%s", current->name);
        printf("Enter Expense Amount: ");
        scanf("%f", &current->amount);
        current->next = NULL;
    }
}

void view_expenses() {
    Expense* temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("\nExpense %d\n", i++);
        printf("Name: %s\n", temp->name);
        printf("Amount: %.2f\n", temp->amount);
        temp = temp->next;
    }
}

void delete_expense() {
    char name[EXPENSE_SIZE];
    Expense* temp = head;
    Expense* previous = NULL;

    printf("Enter Expense Name to Delete: ");
    scanf("%s", name);

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Expense Not Found!\n");
    } else {
        if (previous == NULL) {
            head = temp->next;
        } else {
            previous->next = temp->next;
        }
        free(temp);
        printf("Expense Deleted!\n");
    }
}

void search_expense() {
    char name[EXPENSE_SIZE];
    Expense* temp = head;

    printf("Enter Expense Name to Search: ");
    scanf("%s", name);

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Expense Not Found!\n");
    } else {
        printf("Expense Found!\n");
        printf("Name: %s\n", temp->name);
        printf("Amount: %.2f\n", temp->amount);
    }
}

int main() {
    int choice;

    while (1) {
        print_menu();
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                search_expense();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}