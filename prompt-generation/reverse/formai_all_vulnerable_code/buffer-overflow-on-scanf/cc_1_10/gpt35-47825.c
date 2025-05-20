//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
    int montague_money = 500;
    int capulet_money = 700;
    int romeo_spending = 0;
    int juliet_spending = 0;

    printf("Romeo: Oh, my dear Juliet, I wish we could be together forever. But we must also ensure we have the finances to support our love.\n\n");

    printf("Juliet: You are right, my love. Let us create a personal finance planner to manage our expenses.\n\n");

    while (montague_money > 0 && capulet_money > 0)
    {
        printf("Enter Romeo's spending for this month: ");
        scanf("%d", &romeo_spending);

        if (romeo_spending > montague_money)
        {
            printf("Romeo: Oh no! We do not have enough money to cover my expenses.\n");
            printf("Juliet: Fear not, my love. We will cut back on our spending to manage our money more wisely.\n\n");
        }
        else
        {
            printf("Juliet: Well done, my love. We still have %d dollars left for this month.\n\n", montague_money - romeo_spending);
            montague_money -= romeo_spending;
        }

        printf("Enter Juliet's spending for this month: ");
        scanf("%d", &juliet_spending);

        if (juliet_spending > capulet_money)
        {
            printf("Juliet: Oh no! We do not have enough money to cover my expenses.\n");
            printf("Romeo: Fear not, my love. We will cut back on our spending to manage our money more wisely.\n\n");
        }
        else
        {
            printf("Romeo: Well done, my love. We still have %d dollars left for this month.\n\n", capulet_money - juliet_spending);
            capulet_money -= juliet_spending;
        }
    }

    if (montague_money < 0)
    {
        printf("Romeo: Oh no! We have overspent and are now in debt. We must cut back on our spending immediately.\n");
        printf("Juliet: Fear not, my love. We will work hard to pay off our debts and manage our finances more effectively.\n");
    }
    else if (capulet_money < 0)
    {
        printf("Juliet: Oh no! We have overspent and are now in debt. We must cut back on our spending immediately.\n");
        printf("Romeo: Fear not, my love. We will work hard to pay off our debts and manage our finances more effectively.\n");
    }
    else
    {
        printf("Romeo: Congratulations, my love. We have successfully managed our finances and have money left over.\n");
        printf("Juliet: Well done, my love. We will save this money for our future together.\n");
    }

    return 0;
}