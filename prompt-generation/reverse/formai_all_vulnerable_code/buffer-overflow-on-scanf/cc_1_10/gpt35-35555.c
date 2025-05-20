//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: authentic
#include<stdio.h>
#define MAX 100
int main()
{
    int n,i,j,temp,count=0,sum=0;
    int w[MAX],p[MAX],r[MAX];

    printf("Enter the number of items : ");
    scanf("%d",&n);

    printf("Enter the weights of items : ");
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }

    printf("Enter the profit of the items : ");
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }

    float rpw[n];
    for(i=1;i<=n;i++){
        rpw[i]=p[i]/(float)w[i];
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            if(rpw[j]<rpw[j+1]){
                temp=rpw[j];
                rpw[j]=rpw[j+1];
                rpw[j+1]=temp;

                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    int m;
    printf("Enter the capacity of the bag : ");
    scanf("%d",&m);

    for(i=1;i<=n;i++){
        if(w[i]>m){
            break;
        }
        else{
            sum+=p[i];
            m-=w[i];
        }
    }

    if(i<=n){
        sum+=rpw[i]*m;
    }

    printf("Maximum profit : %d",sum);
    return 0;
}