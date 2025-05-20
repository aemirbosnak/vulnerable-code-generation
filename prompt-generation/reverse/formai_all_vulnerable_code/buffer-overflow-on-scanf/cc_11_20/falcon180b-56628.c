//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n,i,j,k,l,c=0,d;
    int a[10],b[10],sum[20];
    char s[100];
    printf("Enter the number of elements in first array: ");
    scanf("%d",&n);
    printf("Enter the elements of first array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number of elements in second array: ");
    scanf("%d",&n);
    printf("Enter the elements of second array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    printf("Enter the operation(+,-,*,/): ");
    scanf("%s",s);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[0]=='+')
            {
                sum[c]=a[i]+b[j];
                c++;
            }
            else if(s[0]=='-')
            {
                sum[c]=a[i]-b[j];
                c++;
            }
            else if(s[0]=='*')
            {
                sum[c]=a[i]*b[j];
                c++;
            }
            else if(s[0]=='/')
            {
                if(b[j]!=0)
                {
                    sum[c]=a[i]/b[j];
                    c++;
                }
                else
                {
                    printf("Error! Division by zero is not allowed.\n");
                    exit(0);
                }
            }
        }
    }
    printf("The result of %c is:\n",s[0]);
    for(k=0;k<c;k++)
    {
        printf("%d ",sum[k]);
    }
    return 0;
}