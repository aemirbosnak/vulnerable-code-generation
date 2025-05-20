//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("**************************************************************\n");
    printf("*                                                            *\n");
    printf("*              WELCOME TO THE PERSONAL FINANCE PLANNER         *\n");
    printf("*                                                            *\n");
    printf("**************************************************************\n\n");
    printf("How much money do you currently have in your bank account? ");
    float bank_account_balance;
    scanf("%f", &bank_account_balance);

    printf("\nGreat! Now, how much money do you have invested in stocks? ");
    float stock_balance;
    scanf("%f", &stock_balance);

    printf("\nHow much money do you owe on credit cards? ");
    float credit_card_debt;
    scanf("%f", &credit_card_debt);

    printf("\nAnd finally, how much money do you owe on loans? ");
    float loan_balance;
    scanf("%f", &loan_balance);

    printf("\n\n**************************************************************\n\n");
    printf("So, let's see where you stand financially:\n\n");

    float total_assets = bank_account_balance + stock_balance;

    printf("Your total assets are: $%.2f\n", total_assets);

    float total_liabilities = credit_card_debt + loan_balance;

    printf("Your total liabilities are: $%.2f\n\n", total_liabilities);

    float net_worth = total_assets - total_liabilities;

    if (net_worth < 0) {
        printf("Uh oh! It looks like your net worth is negative. You should work on paying off your debts and building up your savings.\n");
    }
    else if (net_worth == 0) {
        printf("Your net worth is exactly zero. It's time to start saving and investing to build wealth.\n");
    }
    else {
        printf("Congratulations! Your net worth is $%.2f. Keep up the good work!\n", net_worth);
    }

    return 0;
}