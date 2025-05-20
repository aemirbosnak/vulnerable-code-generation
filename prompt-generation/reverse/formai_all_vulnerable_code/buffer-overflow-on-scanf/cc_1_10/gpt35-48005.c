//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include<stdio.h>
#define max 100001

int arr[max], ans[max], diff[max];

int main()
{
    int i, j, n, m, q, x, y, z;
    scanf("%d%d%d", &n, &m, &q);
  
    for(i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(i=1; i<=m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        diff[x] += z;
        diff[y+1] -= z;
    }
    
    // cumulative sum of differences
    for(i=1; i<=n; i++)
    {
        diff[i] += diff[i-1];
    }
    
    // sort the differences
    for(i=n; i>=1; i--)
    {
        for(j=1; j<i; j++)
        {
            if(diff[j] < diff[j+1])
            {
                int temp = diff[j];
                diff[j] = diff[j+1];
                diff[j+1] = temp;
                
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    // get the answer
    for(i=1; i<=n; i++)
    {
        ans[i] = ans[i-1] + diff[i];
    }
    
    // handle queries
    while(q--)
    {
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    
    return 0;
}