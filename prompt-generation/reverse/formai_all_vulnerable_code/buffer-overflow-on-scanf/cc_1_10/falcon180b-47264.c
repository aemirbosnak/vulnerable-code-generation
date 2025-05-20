//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 20
#define MAX_CATEGORY_LENGTH 20
#define MAX_AMOUNT_LENGTH 10
#define MAX_DATE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
    char date[MAX_DATE_LENGTH];
} expense;

int main() {
    char choice;
    int num_expenses = 0;
    expense expenses[MAX_EXPENSES];
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
    char date[MAX_DATE_LENGTH];
    int i;

    do {
        printf("\n\nWelcome to the Expense Tracker!\n");
        printf("What would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        scanf("%c", &choice);
        printf("\n");

        switch(choice) {
            case '1':
                printf("Enter the name of the expense: ");
                scanf("%s", name);
                printf("Enter the category of the expense: ");
                scanf("%s", category);
                printf("Enter the amount of the expense: ");
                scanf("%s", amount);
                printf("Enter the date of the expense: ");
                scanf("%s", date);

                if(num_expenses == MAX_EXPENSES) {
                    printf("Sorry, the maximum number of expenses has been reached.\n");
                } else {
                    strcpy(expenses[num_expenses].name, name);
                    strcpy(expenses[num_expenses].category, category);
                    strcpy(expenses[num_expenses].amount, amount);
                    strcpy(expenses[num_expenses].date, date);
                    num_expenses++;
                    printf("Expense added successfully.\n");
                }
                break;

            case '2':
                if(num_expenses == 0) {
                    printf("No expenses have been added yet.\n");
                } else {
                    printf("Name\tCategory\tAmount\tDate\n");
                    for(i=0; i<num_expenses; i++) {
                        printf("%s\t%s\t%s\t%s\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
                    }
                }
                break;

            case '3':
                printf("Thank you for using the Expense Tracker.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '3');

    return 0;
}