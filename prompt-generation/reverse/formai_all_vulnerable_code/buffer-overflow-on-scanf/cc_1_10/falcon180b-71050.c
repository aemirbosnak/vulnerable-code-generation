//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include<stdio.h>
#include<math.h>
#define N 12

int main()
{
    double budget[N],expense[N],saving[N],interest_rate=0.05,total_income=0,total_expense=0,total_saving=0;
    char choice;
    int i;

    for(i=0;i<N;i++)
    {
        printf("Enter the budget for month %d: ",i+1);
        scanf("%lf",&budget[i]);
        total_income+=budget[i];
    }

    for(i=0;i<N;i++)
    {
        printf("Enter the expense for month %d: ",i+1);
        scanf("%c",&choice);
        if(choice=='y')
        {
            printf("Enter the expense: ");
            scanf("%lf",&expense[i]);
            total_expense+=expense[i];
        }
        else
        {
            expense[i]=0;
        }
    }

    total_saving=total_income-total_expense;

    printf("Total Income: $%.2lf\n",total_income);
    printf("Total Expense: $%.2lf\n",total_expense);
    printf("Total Saving: $%.2lf\n",total_saving);

    if(total_saving>0)
    {
        printf("Enter the interest rate: ");
        scanf("%lf",&interest_rate);

        for(i=0;i<N;i++)
        {
            saving[i]=expense[i]-budget[i];

            if(saving[i]>0)
            {
                saving[i]*=pow(1+interest_rate,N-i-1);
            }
            else
            {
                saving[i]=0;
            }
        }

        printf("\nMonthly Savings after Interest:\n");
        for(i=0;i<N;i++)
        {
            printf("Month %d: $%.2lf\n",i+1,saving[i]);
        }
    }
    else
    {
        printf("\nNo Savings!");
    }

    return 0;
}