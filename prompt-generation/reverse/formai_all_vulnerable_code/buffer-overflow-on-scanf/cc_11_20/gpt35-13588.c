//FormAI DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include<stdio.h>

int main()
{
    int n, i, choice;

    printf("Enter number of companies: ");
    scanf("%d", &n);

    float prices[n], increase_percentage[n], decrease_percentage[n];
    char names[n][20];

    for(i=0; i<n; i++)
    {
        printf("\nEnter Name of company %d: ", i+1);
        scanf("%s", &names[i]);

        printf("Enter price for company %d: ", i+1);
        scanf("%f", &prices[i]);
    }

    do
    {
        printf("\nEnter choice:\n");
        printf("1. View company name and current stock prices\n");
        printf("2. View companies with stock prices increased\n");
        printf("3. View companies with stock prices decreased\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                printf("\nCompany Name\tCurrent Price\n");
                for(i=0; i<n; i++)
                {
                    printf("%s\t\t%.2f\n", names[i], prices[i]);
                }
                break;

            case 2: 
                for(i=0; i<n; i++)
                {
                    increase_percentage[i] = ((prices[i] - (prices[i]*0.1))/prices[i]) * 100;
                    if(increase_percentage[i] > 0)
                    {
                        printf("\nCompany Name: %s has increased by %.2f%%\n", names[i], increase_percentage[i]);
                    }
                }
                break;

            case 3: 
                for(i=0; i<n; i++)
                {
                    decrease_percentage[i] = ((prices[i]*0.1 - prices[i])/prices[i]) * 100;
                    if(decrease_percentage[i] > 0)
                    {
                        printf("\nCompany Name: %s has decreased by %.2f%%\n", names[i], decrease_percentage[i]);
                    }
                }
                break;

            case 4: 
                printf("\nExiting...\n");
                break;

            default: 
                printf("\nInvalid choice!\n");
                break;
        }

    }while(choice != 4);

    return 0;
}