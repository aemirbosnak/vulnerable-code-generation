//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    // Introductory message
    printf("Greetings, dear friend. I am the renowned detective, Holmes.\n");
    printf("It is my pleasure to assist you in organizing your personal finances.\n\n");

    // Initialization of variables
    float income = 0;
    float expenses = 0;
    float balance = 0;
    char choice[30];

    // Gathering information
    printf("Please tell me your monthly income: ");
    scanf("%f", &income);
    printf("Thank you. Now please tell me your monthly expenses: ");
    scanf("%f", &expenses);

    // Calculating balance
    balance = income - expenses;

    // Describing the situation
    printf("\nI see, your monthly income is %.2f and your expenses are %.2f.\n", income, expenses);
    printf("This leaves you with a balance of %.2f.\n\n", balance);
    printf("Now, tell me, what is your goal? Would you like to save money, pay off debt, or invest?\n");
    printf("Type your choice and press Enter: ");
    scanf("%s", choice);

    // Interpreting the choice
    if (strcmp(choice, "save") == 0)
    {
        printf("\nAn admirable goal, my dear friend. How much would you like to save each month?\n");
        float saveAmount = 0;
        scanf("%f", &saveAmount);

        // Determining whether goal is achievable
        if (saveAmount <= balance)
        {
            printf("\nExcellent. You may save %.2f each month.\n", saveAmount);
            printf("This will leave you with a new balance of %.2f.\n", balance - saveAmount);
        }
        else
        {
            printf("\nI am sorry, but your goal is not currently feasible.\n");
            printf("You may need to re-evaluate your expenses or seek additional income.\n");
        }
    }
    else if (strcmp(choice, "pay off debt") == 0)
    {
        printf("\nA wise decision. How much debt must you pay off each month?\n");
        float debtAmount = 0;
        scanf("%f", &debtAmount);

        // Determining whether goal is achievable
        if (debtAmount <= balance)
        {
            printf("\nVery good. You may pay off %.2f each month.\n", debtAmount);
            printf("This will leave you with a new balance of %.2f.\n", balance - debtAmount);
        }
        else
        {
            printf("\nI am sorry, but your goal is not currently feasible.\n");
            printf("You may need to re-evaluate your expenses or seek additional income.\n");
        }
    }
    else if (strcmp(choice, "invest") == 0)
    {
        printf("\nAn intriguing choice. How much would you like to invest each month?\n");
        float investAmount = 0;
        scanf("%f", &investAmount);

        // Determining whether goal is achievable
        if (investAmount <= balance)
        {
            printf("\nVery well. You may invest %.2f each month.\n", investAmount);
            printf("This will leave you with a new balance of %.2f.\n", balance - investAmount);
        }
        else
        {
            printf("\nI am sorry, but your goal is not currently feasible.\n");
            printf("You may need to re-evaluate your expenses or seek additional income.\n");
        }
    }
    else
    {
        printf("\nI apologize, but I did not understand your choice.\n");
        printf("Please choose to save, pay off debt, or invest.\n");
    }

    // Farewell message
    printf("\nThank you for allowing me to assist you in your financial endeavours.\n");
    printf("I wish you the best of luck in achieving your goals.\n");
    printf("Until we meet again, dear friend.\n");

    return 0;
}