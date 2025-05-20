//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, m;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);

    int w[n], v[n], i, j;
    float r[n], p = 0;

    printf("\nEnter weight and value for each item:\n");
    for(i=0;i<n;i++)
    {
        printf("Item %d Weight: ", i+1);
        scanf("%d", &w[i]);
        printf("Item %d Value: ",i+1);
        scanf("%d", &v[i]);
        r[i] = (float)v[i]/w[i];
    }

    int maxIndex;
    float temp;
    //sorting items based on their ratios
    for(i = 0; i<n-1; i++)
        for(j=i+1; j<n;j++)
        {
            if(r[i]<r[j])
            {
                temp = r[j];
                r[j] = r[i];
                r[i] = temp;
                temp = w[j];
                w[j] = w[i];
                w[i] = temp;
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }
    //calculating max value in the knapsack
    for(int i=0; i<n; i++)
    {
        if(w[i]>m) break;
        else
        {
            m -= w[i];
            p += v[i]; 
        }
    }
    //if knapsack is not full
    if(m)
    {
        p += r[i] * m;
    }
    printf("\nThe maximum value in the knapsack is: %.2f", p);
    return 0;
}