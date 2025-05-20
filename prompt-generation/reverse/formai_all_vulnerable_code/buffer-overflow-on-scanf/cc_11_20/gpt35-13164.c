//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include<stdio.h>

#define MAX_POINTS 10
#define MIN_DISTANCE 5

int main()
{
    int n;
    printf("Enter the number of Points : ");
    scanf("%d",&n);

    if(n<2)
    {
        printf("Insufficient Number of Points!!\n");
        return -1;
    }

    int x[MAX_POINTS],y[MAX_POINTS];

    printf("Enter the %d Points (x,y) : \n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }

    int cluster[MAX_POINTS];
    int cluster_count=1;
    for(int i=0;i<n;i++)
    {
        if(cluster[i]==0)
        {
            cluster[i]=cluster_count;
            for(int j=i+1;j<n;j++)
            {
                if(cluster[j]==0 && hypot(x[i]-x[j],y[i]-y[j]) <= MIN_DISTANCE)
                {
                    cluster[j]=cluster_count;
                }
            }
            cluster_count++;
        }
    }

    printf("Clusters formed :\n");

    for(int i=1;i<cluster_count;i++)
    {
        printf("Cluster %d : ",i);
        for(int j=0;j<n;j++)
        {
            if(cluster[j]==i)
            {
                printf("(%d,%d) ",x[j],y[j]);
            }
        }
        printf("\n");
    }
    return 0;
}