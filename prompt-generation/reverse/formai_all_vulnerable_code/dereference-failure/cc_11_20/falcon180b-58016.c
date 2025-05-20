//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,k,l,count=0,ch,flag=0;
    char **c;
    int n;
    printf("Enter the number of Rows and Columns: ");
    scanf("%d%d",&n,&n);
    int **a=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        *(a+i)=(int *)malloc(n*sizeof(int));
    }
    srand(time(0));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            *(a+i+(j*n))=rand()%10;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",*(a+i+(j*n)));
        }
        printf("\n");
    }
    int **b=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        *(b+i)=(int *)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            *(b+i+(j*n))=0;
        }
    }
    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("1.Play\n2.Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnter Row: ");
            scanf("%d",&k);
            printf("Enter Column: ");
            scanf("%d",&l);
            if(*(a+k+(l*n))==*(b+k+(l*n)))
            {
                count++;
                *(b+k+(l*n))=*(a+k+(l*n))+10;
            }
            else
            {
                printf("\nSorry try again\n");
            }
        }
        else if(ch==2)
        {
            printf("\nThanks for playing\n");
            printf("Your score is %d\n",count);
            exit(0);
        }
        else
        {
            printf("\nInvalid choice\n");
        }
        if(count==n*n)
        {
            printf("\nCongratulations you won\n");
            exit(0);
        }
    }
}