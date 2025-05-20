//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i,j,k,n,m;
    float x[100],y[100],z[100];
    float sum=0.0,avg=0.0;
    int count=0;
    
    printf("Enter the number of samples: ");
    scanf("%d",&n);
    
    printf("Enter the samples:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }
    
    printf("Enter the window size: ");
    scanf("%d",&m);
    
    for(i=0;i<n-m;i++)
    {
        sum=0.0;
        for(j=i;j<i+m;j++)
        {
            sum+=x[j];
        }
        avg=sum/m;
        y[i]=avg;
    }
    
    printf("Filtered samples:\n");
    for(i=0;i<n-m;i++)
    {
        printf("%f\n",y[i]);
    }
    
    for(i=0;i<n;i++)
    {
        sum=0.0;
        for(j=0;j<n;j++)
        {
            sum+=x[j]*y[j];
        }
        z[i]=sum;
    }
    
    printf("Correlation coefficients:\n");
    for(i=0;i<n;i++)
    {
        printf("%f\n",z[i]);
    }
    
    return 0;
}