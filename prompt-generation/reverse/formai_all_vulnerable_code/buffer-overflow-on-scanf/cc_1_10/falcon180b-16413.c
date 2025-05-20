//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

struct account
{
    int acc_no;
    char name[50];
    char address[100];
    float balance;
};

void main()
{
    int choice,i;
    char ch;
    struct account a[MAX];
    int count=0;
    FILE *fp;

    fp=fopen("bank.dat","rb");
    if(fp==NULL)
    {
        printf("File does not exist\n");
        exit(0);
    }

    fseek(fp,0,2);
    count=ftell(fp)/sizeof(struct account);
    rewind(fp);

    printf("Enter the account number: ");
    scanf("%d",&choice);

    fread(&a[0],sizeof(struct account),count,fp);

    for(i=0;i<count;i++)
    {
        if(a[i].acc_no==choice)
        {
            printf("\nName: %s\n",a[i].name);
            printf("Address: %s\n",a[i].address);
            printf("Balance: %.2f\n",a[i].balance);
            break;
        }
    }

    if(i==count)
    {
        printf("\nAccount not found");
    }

    fclose(fp);
}