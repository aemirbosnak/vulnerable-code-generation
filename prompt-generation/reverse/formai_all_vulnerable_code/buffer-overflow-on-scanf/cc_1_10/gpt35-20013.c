//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include<stdio.h>

// function to implement greedy algorithm
void greedy(int n, int m, float p[], float v[])
{
    int i, j;
    float f[n];

    // initializing f[] array with 0
    for(i=0;i<n;i++) f[i]=0;

    // calculating fractional ratios for each item
    for(i=0;i<n;i++)
        f[i]=v[i]/p[i];

    // sorting items in decreasing order of their fractions
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(f[i]<f[j])
            {
                float temp=f[j];
                f[j]=f[i];
                f[i]=temp;

                temp=p[j];
                p[j]=p[i];
                p[i]=temp;

                temp=v[j];
                v[j]=v[i];
                v[i]=temp;
            }
    
    float weight=0, profit=0;

    // selecting items until weight exceeds the maximum capacity 
    for(i=0;i<n;i++)
        if(weight+p[i]<=m)
        {
            weight+=p[i];
            profit+=v[i];
        }
        else
            break;

    // printing the maximum profit obtained
    printf("Maximum profit possible = %.2f", profit);
}

// main program
int main()
{
    int n, m, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    float p[n], v[n];

    // taking input of item weights
    printf("Enter the weight of each item: ");
    for(i=0;i<n;i++) scanf("%f", &p[i]);

    // taking input of item values
    printf("Enter the value of each item: ");
    for(i=0;i<n;i++) scanf("%f", &v[i]);

    // taking input of maximum capacity of knapsack
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &m);

    // passing the input to greedy function to obtain maximum profit
    greedy(n, m, p, v);

    return 0;
}