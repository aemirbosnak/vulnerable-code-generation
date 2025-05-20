//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10

struct expense {
    char name[100];
    float amount;
    struct expense* next;
};

struct expense* head = NULL;

void add_expense(char* name, float amount) {
    struct expense* new_expense = (struct expense*) malloc(sizeof(struct expense));
    if (new_expense == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(new_expense->name, name);
    new_expense->amount = amount;
    new_expense->next = NULL;

    if (head == NULL) {
        head = new_expense;
    } else {
        struct expense* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_expense;
    }
}

void remove_expense(char* name) {
    struct expense* current = head;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current == head) {
                head = current->next;
            } else {
                struct expense* prev = current;
                while (prev->next!= current) {
                    prev = prev->next;
                }
                prev->next = current->next;
                free(current);
                break;
            }
            return;
        }
        current = current->next;
    }
    printf("Expense not found!\n");
}

void view_expenses() {
    struct expense* current = head;
    while (current!= NULL) {
        printf("%s: %.2f\n", current->name, current->amount);
        current = current->next;
    }
}

int main() {
    char name[100];
    float amount;

    while (1) {
        printf("Enter expense name (or 'q' to quit): ");
        fgets(name, sizeof(name), stdin);

        if (strcmp(name, "q") == 0) {
            break;
        }

        printf("Enter expense amount: ");
        fgets(name, sizeof(name), stdin);

        sscanf(name, "%f", &amount);

        add_expense(name, amount);
    }

    view_expenses();

    return 0;
}