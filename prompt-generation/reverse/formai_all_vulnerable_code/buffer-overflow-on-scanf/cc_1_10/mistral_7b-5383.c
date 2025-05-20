//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define FILE_NAME "expenses.txt"

struct Expense {
    char name[MAX_NAME_LEN];
    int amount;
    struct Expense *next;
};

typedef struct Expense Expense;
Expense *head = NULL;

void createExpense(char *name, int amount) {
    Expense *newExpense = (Expense *) malloc(sizeof(Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;
}

void saveExpenses() {
    int fd;
    Expense *current = head;
    char line[100];

    fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    while (current != NULL) {
        sprintf(line, "%s %d\n", current->name, current->amount);
        write(fd, line, strlen(line));
        current = current->next;
    }
    close(fd);
}

void loadExpenses() {
    int fd, i = 0;
    Expense *newExpense, *current = head;
    char line[100];

    fd = open(FILE_NAME, O_RDONLY);
    while (fgets(line, sizeof(line), fd) != NULL) {
        newExpense = (Expense *) malloc(sizeof(Expense));
        sscanf(line, "%s %d", newExpense->name, &newExpense->amount);
        if (i == 0) {
            head = newExpense;
            current = newExpense;
        } else {
            current->next = newExpense;
            current = newExpense;
        }
        i++;
        if (i >= MAX_EXPENSES)
            break;
    }
    close(fd);
}

void printExpenses() {
    Expense *current = head;
    printf("Expenses:\n");
    while (current != NULL) {
        printf("%s: %d\n", current->name, current->amount);
        current = current->next;
    }
}

int main() {
    char command[10];
    int amount;
    char name[MAX_NAME_LEN];

    while (1) {
        printf("> ");
        scanf("%s %s %d", command, name, &amount);
        if (strcmp(command, "exit") == 0)
            break;
        createExpense(name, amount);
        saveExpenses();
    }

    loadExpenses();
    printExpenses();

    while (head != NULL) {
        Expense *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}