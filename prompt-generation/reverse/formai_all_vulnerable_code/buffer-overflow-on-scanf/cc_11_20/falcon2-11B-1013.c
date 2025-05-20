//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    double income;
    double expenses;
    double savings;
} account;

int main() {
    srand(time(NULL));
    char choice;
    int num;
    account accounts[3];
    int i;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your name:\n");
    fgets(accounts[0].name, sizeof(accounts[0].name), stdin);
    accounts[0].name[strcspn(accounts[0].name, "\n")] = '\0';

    printf("Please enter your income:\n");
    scanf("%lf", &accounts[0].income);

    printf("Please enter your expenses:\n");
    scanf("%lf", &accounts[0].expenses);

    printf("Please enter your savings:\n");
    scanf("%lf", &accounts[0].savings);

    printf("\n");

    for (i = 1; i < 3; i++) {
        accounts[i].name[strcspn(accounts[i].name, "\n")] = '\0';
        accounts[i].income = rand() % 1000 + 1000;
        accounts[i].expenses = rand() % 1000 + 1000;
        accounts[i].savings = rand() % 1000 + 1000;

        printf("Account %d: %s\n", i + 1, accounts[i].name);
        printf("Income: %.2lf\n", accounts[i].income);
        printf("Expenses: %.2lf\n", accounts[i].expenses);
        printf("Savings: %.2lf\n\n", accounts[i].savings);
    }

    printf("\n");

    printf("What would you like to do?\n");
    printf("1. View all accounts\n");
    printf("2. Add a new account\n");
    printf("3. Remove an account\n");
    printf("4. Update an account\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%c", &choice);

    switch (choice) {
        case '1':
            printf("Viewing all accounts:\n");
            for (i = 0; i < 3; i++) {
                printf("%d. %s\n", i + 1, accounts[i].name);
                printf("Income: %.2lf\n", accounts[i].income);
                printf("Expenses: %.2lf\n", accounts[i].expenses);
                printf("Savings: %.2lf\n\n", accounts[i].savings);
            }
            break;
        case '2':
            printf("Adding a new account:\n");
            printf("Enter your name:\n");
            fgets(accounts[i + 1].name, sizeof(accounts[i + 1].name), stdin);
            accounts[i + 1].name[strcspn(accounts[i + 1].name, "\n")] = '\0';

            printf("Enter your income:\n");
            scanf("%lf", &accounts[i + 1].income);

            printf("Enter your expenses:\n");
            scanf("%lf", &accounts[i + 1].expenses);

            printf("Enter your savings:\n");
            scanf("%lf", &accounts[i + 1].savings);

            printf("\n");
            for (i = 0; i < 3; i++) {
                printf("%d. %s\n", i + 1, accounts[i].name);
                printf("Income: %.2lf\n", accounts[i].income);
                printf("Expenses: %.2lf\n", accounts[i].expenses);
                printf("Savings: %.2lf\n\n", accounts[i].savings);
            }
            break;
        case '3':
            printf("Removing an account:\n");
            printf("Enter the number of the account to remove:\n");
            scanf("%d", &num);

            for (i = num; i < 3; i++) {
                accounts[i].name[strcspn(accounts[i].name, "\n")] = '\0';
                accounts[i].income = rand() % 1000 + 1000;
                accounts[i].expenses = rand() % 1000 + 1000;
                accounts[i].savings = rand() % 1000 + 1000;

                printf("Account %d: %s\n", i + 1, accounts[i].name);
                printf("Income: %.2lf\n", accounts[i].income);
                printf("Expenses: %.2lf\n", accounts[i].expenses);
                printf("Savings: %.2lf\n\n", accounts[i].savings);
            }
            break;
        case '4':
            printf("Updating an account:\n");
            printf("Enter the number of the account to update:\n");
            scanf("%d", &num);

            printf("Enter the new name for the account:\n");
            fgets(accounts[num].name, sizeof(accounts[num].name), stdin);
            accounts[num].name[strcspn(accounts[num].name, "\n")] = '\0';

            printf("Enter the new income for the account:\n");
            scanf("%lf", &accounts[num].income);

            printf("Enter the new expenses for the account:\n");
            scanf("%lf", &accounts[num].expenses);

            printf("Enter the new savings for the account:\n");
            scanf("%lf", &accounts[num].savings);

            printf("\n");
            for (i = 0; i < 3; i++) {
                printf("%d. %s\n", i + 1, accounts[i].name);
                printf("Income: %.2lf\n", accounts[i].income);
                printf("Expenses: %.2lf\n", accounts[i].expenses);
                printf("Savings: %.2lf\n\n", accounts[i].savings);
            }
            break;
        case '5':
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}