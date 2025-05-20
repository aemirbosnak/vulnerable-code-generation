//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort_weight(int weight[], int profit[], int n)
{
    int i, j, max_id;
    double p[MAX], w[MAX];

    for(i=0;i<n;i++)
    {
        p[i] = (double)profit[i] / (double)weight[i];
        w[i] = weight[i];
    }

    for(i=0;i<n-1;i++)
    {
        max_id = i;
        for(j=i+1;j<n;j++)
        {
            if(p[j]>p[max_id])
                max_id=j;
        }

        swap(&p[i], &p[max_id]);
        swap(&w[i], &w[max_id]);
    }

    for(i=0;i<n;i++)
    {
        weight[i] = w[i];
        profit[i] = p[i];
    }
}

int knapsack(int n, int W, int w[], int p[])
{
    int i, tot_weight=0, tot_profit=0;
    float x[MAX] = {0.0};

    for(i=0;i<n;i++)
    {
        if(w[i]+tot_weight<=W)
        {
            x[i] = 1.0;
            tot_weight += w[i];
            tot_profit += p[i];
        }
        else
        {
            x[i] = (W-tot_weight) / (float)w[i];
            tot_profit += x[i] * p[i];
            tot_weight = W;
            break;
        }
    }

    return tot_profit;
}

int main()
{
    int n, W, w[MAX], p[MAX], i, j;
    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter %d weights and profits:\n", n);
    for(i=0;i<n;i++)
        scanf("%d %d",&w[i],&p[i]);

    printf("Enter maximum knapsack weight: ");
    scanf("%d",&W);

    sort_weight(w, p, n);

    printf("\nFraction of knapsack items selected: ");
    for(i=0;i<n;i++)
        printf("%.1f ",w[i]);

    printf("\nMaximum profit: %d", knapsack(n, W, w, p));

    return 0;
}