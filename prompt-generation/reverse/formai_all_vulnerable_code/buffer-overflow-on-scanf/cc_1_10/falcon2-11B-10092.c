//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char name[50];
    double amount;
    char category[50];
};

int main() {
    struct Expense expenses[100];

    int i, j, n, choice;

    printf("Enter the number of expenses: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter expense name: ");
        scanf("%s", expenses[i].name);

        printf("Enter expense amount: ");
        scanf("%lf", &expenses[i].amount);

        printf("Enter expense category: ");
        scanf("%s", expenses[i].category);
    }

    printf("1. Add expense\n2. View expenses\n3. Delete expense\n4. Quit\n");

    choice = 0;

    while (choice!= 4) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", expenses[i].name);

                printf("Enter expense amount: ");
                scanf("%lf", &expenses[i].amount);

                printf("Enter expense category: ");
                scanf("%s", expenses[i].category);

                break;

            case 2:
                for (j = 0; j < n; j++) {
                    printf("%s | %.2lf | %s\n", expenses[j].name, expenses[j].amount, expenses[j].category);
                }

                break;

            case 3:
                printf("Enter expense name to delete: ");
                scanf("%s", expenses[i].name);

                for (j = 0; j < n; j++) {
                    if (strcmp(expenses[j].name, expenses[i].name) == 0) {
                        strcpy(expenses[j].name, expenses[j+1].name);
                        strcpy(expenses[j+1].name, expenses[j].name);
                        n--;
                        break;
                    }
                }

                break;

            case 4:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}