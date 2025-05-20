//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: configurable

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int n,i,j,k,n1,dif;
    float x,y,temp,min;
    float arr[1000];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%f %f",&x,&y);
        arr[i]=x+y*i;
    }
    printf("Enter the number of clusters: ");
    scanf("%d",&n1);
    float **centroids;
    centroids= (float **)malloc(n1*sizeof(float*));
    for(i=0;i<n1;i++)
    {
        centroids[i]= (float *)malloc(n*sizeof(float));
    }
    int cluster=0;
    int clustercount[1000];
    for(i=0;i<n;i++)
    {
        clustercount[i]=0;
    }
    for(i=0;i<n1;i++)
    {
        min=10000;
        for(j=0;j<n;j++)
        {
            temp=sqrt(pow(arr[j]-centroids[i][j],2));
            if(temp<min)
            {
                min=temp;
                cluster=j;
            }
        }
        centroids[i][cluster]=arr[cluster];
        for(j=0;j<n;j++)
        {
            if(arr[j]==centroids[i][cluster])
            {
                clustercount[j]++;
            }
        }
    }
    for(i=0;i<n1;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d ",clustercount[j]);
        }
        printf("\n");
    }
    free(centroids);
    return 0;
}