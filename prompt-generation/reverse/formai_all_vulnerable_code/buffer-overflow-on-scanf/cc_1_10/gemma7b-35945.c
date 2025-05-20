//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void display_menu()
{
    printf("------------------------\n");
    printf("1. View Account Balance\n");
    printf("2. Transfer Funds\n");
    printf("3. Pay Bills\n");
    printf("4. Set Budget\n");
    printf("5. View Expenses\n");
    printf("6. Exit\n");
    printf("------------------------\n");
}

int main()
{
    int choice;

    while (1)
    {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Your current account balance is $10,000.\n");
                break;
            case 2:
                printf("Enter the amount you want to transfer: ");
                int transfer_amount;
                scanf("%d", &transfer_amount);
                printf("You have transferred $%d to your recipient.\n", transfer_amount);
                break;
            case 3:
                printf("Enter the name of the bill you want to pay: ");
                char bill_name[20];
                scanf("%s", bill_name);
                printf("Enter the amount you want to pay: ");
                int bill_amount;
                scanf("%d", &bill_amount);
                printf("You have paid $%d for %s.\n", bill_amount, bill_name);
                break;
            case 4:
                printf("Enter your budget category: ");
                char category[20];
                scanf("%s", category);
                printf("Enter your budget amount: ");
                int budget_amount;
                scanf("%d", &budget_amount);
                printf("You have set a budget of $%d for %s.\n", budget_amount, category);
                break;
            case 5:
                printf("Enter the name of the expense you want to record: ");
                char expense_name[20];
                scanf("%s", expense_name);
                printf("Enter the amount of the expense: ");
                int expense_amount;
                scanf("%d", &expense_amount);
                printf("You have recorded an expense of $%d for %s.\n", expense_amount, expense_name);
                break;
            case 6:
                printf("Thank you for using the Personal Finance Planner. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}