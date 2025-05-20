//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printPattern(int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void main()
{
    int n,m;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    printf("Enter the number of columns:");
    scanf("%d",&m);
    srand(time(0));
    int a=rand()%3;
    switch(a)
    {
        case 0:
            printPattern(n,m);
            break;
        case 1:
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    printf("%c",rand()%2==0?'*':' ');
                }
                printf("\n");
            }
            break;
        case 2:
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    printf("%c",rand()%3==0?'*':rand()%2==0?'#':' ');
                }
                printf("\n");
            }
            break;
    }
}