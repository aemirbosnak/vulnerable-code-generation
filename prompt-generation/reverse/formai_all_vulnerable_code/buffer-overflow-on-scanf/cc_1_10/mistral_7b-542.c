//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char description[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void add_expense(char *desc, float amt) {
    Expense *new_expense = (Expense *)malloc(sizeof(Expense));
    strcpy(new_expense->description, desc);
    new_expense->amount = amt;
    new_expense->next = head;
    head = new_expense;
}

void print_receipts(int days) {
    Expense *current = head;
    int total = 0;
    printf("\n========== Galactic Journey Expenses ==========\n");
    printf("Day\tDescription\tAmount\n");
    for (int i = 1; i <= days && current != NULL; i++) {
        printf("%d\t%s\t%.2f\n", i, current->description, current->amount);
        total += current->amount;
        current = current->next;
    }
    printf("=======\nTotal Expenses for this Journey: %.2f Galactic Credits\n", total);
}

int main() {
    char desc[50];
    float amount;
    int days;

    printf("Welcome, Galactic Traveler!\n");
    printf("Enter the number of days for your journey: ");
    scanf("%d", &days);

    for (int i = 1; i <= days; i++) {
        printf("\nDay %d:\nEnter the description of your expense: ", i);
        scanf("%s", desc);
        printf("Enter the amount of the expense in Galactic Credits: ");
        scanf("%f", &amount);
        add_expense(desc, amount);
    }

    printf("\nYour expenses have been recorded.\n");
    print_receipts(days);

    return 0;
}