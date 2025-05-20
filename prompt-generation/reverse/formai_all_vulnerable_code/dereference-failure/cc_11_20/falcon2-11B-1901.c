//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 10
#define MAX_AMOUNT 1000

typedef struct {
    char name[50];
    int amount;
} Expense;

int main() {
    int choice = 1;
    Expense expenses[MAX_EXPENSES];
    char input[MAX_AMOUNT];
    int i, j;

    srand(time(NULL));

    printf("Welcome to the Expense Tracker\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Delete expense\n");
    printf("4. Edit expense\n");
    printf("5. Quit\n");

    while (choice!= 5) {
        printf("Please choose an option:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name:\n");
                scanf("%s", input);
                printf("Enter expense amount:\n");
                scanf("%d", &expenses[i].amount);
                strncpy(expenses[i].name, input, MAX_AMOUNT);
                i++;
                break;

            case 2:
                printf("List of expenses:\n");
                for (i = 0; i < MAX_EXPENSES; i++) {
                    printf("%d. %s - $%.2lf\n", i + 1, expenses[i].name, expenses[i].amount);
                }
                break;

            case 3:
                printf("Enter expense index to delete:\n");
                scanf("%d", &i);
                if (i >= 0 && i <= MAX_EXPENSES - 1) {
                    for (j = i; j < MAX_EXPENSES - 1; j++) {
                        strcpy(expenses[j].name, expenses[j + 1].name);
                        expenses[j].amount = expenses[j + 1].amount;
                    }
                    i = MAX_EXPENSES - 1;
                }
                break;

            case 4:
                printf("Enter expense index to edit:\n");
                scanf("%d", &i);
                if (i >= 0 && i <= MAX_EXPENSES - 1) {
                    printf("Enter new expense name:\n");
                    scanf("%s", input);
                    strncpy(expenses[i].name, input, MAX_AMOUNT);
                    printf("Enter new expense amount:\n");
                    scanf("%d", &expenses[i].amount);
                    break;
                }
                break;
        }
    }

    return 0;
}