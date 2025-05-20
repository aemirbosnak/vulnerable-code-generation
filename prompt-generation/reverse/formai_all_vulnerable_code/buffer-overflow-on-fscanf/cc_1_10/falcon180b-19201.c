//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct contact
{
    char name[30];
    char number[15];
    char email[30];
};

int main()
{
    int choice,i,j,n;
    char ch;
    FILE *fp;
    struct contact book[MAX];

    printf("Enter the number of contacts you want to store: ");
    scanf("%d",&n);

    fp=fopen("phonebook.txt","w");

    if(fp==NULL)
    {
        printf("Cannot create file");
        exit(0);
    }

    printf("\nEnter %d contacts:\n",n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter name: ");
        scanf("%s",book[i].name);

        printf("Enter phone number: ");
        scanf("%s",book[i].number);

        printf("Enter email: ");
        scanf("%s",book[i].email);

        fprintf(fp,"%s %s %s\n",book[i].name,book[i].number,book[i].email);
    }

    fclose(fp);

    printf("\nPhonebook created successfully!");

    printf("\nDo you want to search a contact? (y/n): ");
    scanf("%s",&ch);

    if(ch=='y'||ch=='Y')
    {
        printf("\nEnter the name to search: ");
        scanf("%s",book[0].name);

        fp=fopen("phonebook.txt","r");

        if(fp==NULL)
        {
            printf("Cannot open file");
            exit(0);
        }

        while((fscanf(fp,"%s %s %s",book[0].name,book[0].number,book[0].email))!=EOF)
        {
            if(strcmp(book[0].name,book[0].name)==0)
            {
                printf("\nName: %s",book[0].name);
                printf("\nPhone number: %s",book[0].number);
                printf("\nEmail: %s",book[0].email);
            }
        }

        fclose(fp);
    }

    return 0;
}