//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, m, i, j, k, min_cost = 0, count = 0 ;
    int nodes[100], weights[100][100], selected[100] = {0} ;

    printf("Enter the number of nodes: ") ;
    scanf("%d", &n) ;

    printf("\nEnter the cost matrix:\n") ;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &weights[i][j]) ;
        }
        nodes[i] = i+1 ;
    }

    selected[0] = 1 ;
    printf("\n") ;
    while(count < n-1)
    {
        int x = 0, y = 0, min = 9999 ;
        for(i=0; i<n; i++)
        {
            if(selected[i] == 1)
            {
                for(j=0; j<n; j++)
                {
                    if(selected[j] == 0 && weights[i][j])
                    {
                        if(min > weights[i][j])
                        {
                            min = weights[i][j] ;
                            x = i ;
                            y = j ;
                        }
                    }
                }
            }
        }
        printf("(%d,%d) cost = %d\n", nodes[x], nodes[y], min) ;
        count++ ;
        min_cost += min ;
        selected[y] = 1 ;
    }
    printf("\nTotal cost of MST is %d.", min_cost) ;

    return 0 ;
}