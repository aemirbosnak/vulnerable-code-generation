//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char name[50];
    float amount;
    struct expense* next;
};

int main() {
    struct expense* head = NULL;
    struct expense* current = NULL;
    int choice;
    char name[50];
    float amount;

    while (1) {
        printf("Enter expense name: ");
        fgets(name, sizeof(name), stdin);
        sscanf(name, "%s %f", name, &amount);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        struct expense* newExpense = malloc(sizeof(struct expense));
        if (newExpense == NULL) {
            printf("Error allocating memory\n");
            exit(1);
        }

        strcpy(newExpense->name, name);
        newExpense->amount = amount;
        newExpense->next = NULL;

        if (head == NULL) {
            head = newExpense;
            current = head;
        } else {
            current->next = newExpense;
            current = current->next;
        }
    }

    struct expense* temp = head;
    while (temp!= NULL) {
        printf("%s : %f\n", temp->name, temp->amount);
        temp = temp->next;
    }

    free(head);
    return 0;
}