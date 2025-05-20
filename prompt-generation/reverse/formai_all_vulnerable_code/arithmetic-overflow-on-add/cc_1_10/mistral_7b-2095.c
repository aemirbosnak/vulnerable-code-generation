//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float amount;
} Expense;

void main() {
    int i, choice;
    float totalIncome, totalExpenses, savings;
    Expense expenses[10];
    FILE *fp;

    printf("Welcome, my dear!\nThis program is here to help us manage our finances, just for you and me.\n\n");

    do {
        printf("1. Add an expense\n2. View expenses\n3. Calculate our savings\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the expense: ");
                scanf("%s", expenses[i].name);
                printf("Enter the amount spent: $");
                scanf("%f", &expenses[i].amount);
                i++;
                break;

            case 2:
                fp = fopen("expenses.txt", "w");
                for(i = 0; i < 10; i++) {
                    if(expenses[i].amount != 0.0) {
                        fprintf(fp, "%s: $%.2f\n", expenses[i].name, expenses[i].amount);
                    }
                }
                fclose(fp);
                printf("Your expenses for this month are:\n");
                system("cat expenses.txt");
                break;

            case 3:
                totalIncome = 0.0;
                totalExpenses = 0.0;
                for(i = 0; i < 10; i++) {
                    if(expenses[i].amount != 0.0) {
                        totalExpenses += expenses[i].amount;
                    }
                    totalIncome += 1000.0; // Assuming a monthly income of $1000
                }
                savings = totalIncome - totalExpenses;
                printf("Our total income for this month is $%.2f.\n", totalIncome);
                printf("Our total expenses for this month are $%.2f.\n", totalExpenses);
                printf("Our savings for this month are $%.2f.\n", savings);
                break;

            case 4:
                printf("Goodbye, my love.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);
}