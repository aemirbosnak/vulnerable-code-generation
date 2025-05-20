//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n,*arr,i,j,k,l;
    while(~scanf("%d",&n))
    {
        arr=malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        qsort(arr,n,sizeof(int),cmp);
        i=n-1;
        for(j=i;j>=0;)
        {
            if(arr[j]==arr[i])
            {
                j--;
                if(j!=-1)
                {
                    k=arr[i];
                    l=arr[j];
                    arr[i]=arr[j];
                    arr[j]=k;
                }
                i=j;
            }
            else if(arr[j]<arr[i])
            {
                k=arr[i];
                l=arr[j];
                arr[i]=arr[j];
                arr[j]=k;
                i=j;
                j=i-1;
            }
            else
                break;
        }
        for(i=0;i<n;i++)
            printf("%d ",arr[i]);
        printf("\n");
        free(arr);
    }
    return 0;
}