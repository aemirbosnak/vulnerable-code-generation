//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct phonebook
{
    char name[MAX];
    char number[MAX];
}phone;

void addentry(phone *book, int n)
{
    int i;
    char name[MAX];
    char number[MAX];
    printf("\n Enter name:");
    scanf("%s",name);
    printf("\n Enter phone number:");
    scanf("%s",number);
    for(i=0;i<n;i++)
    {
        if(strcmp(book[i].name,"")==0)
        {
            strcpy(book[i].name,name);
            strcpy(book[i].number,number);
            printf("\n Entry added successfully");
            break;
        }
    }
}

void deleteentry(phone *book, int n)
{
    int i;
    char name[MAX];
    printf("\n Enter name to delete:");
    scanf("%s",name);
    for(i=0;i<n;i++)
    {
        if(strcmp(book[i].name,name)==0)
        {
            strcpy(book[i].name,"");
            strcpy(book[i].number,"");
            printf("\n Entry deleted successfully");
            break;
        }
    }
}

void searchentry(phone *book, int n)
{
    int i;
    char name[MAX];
    printf("\n Enter name to search:");
    scanf("%s",name);
    for(i=0;i<n;i++)
    {
        if(strcmp(book[i].name,name)==0)
        {
            printf("\n Name found");
            printf("\n Phone number: %s",book[i].number);
            break;
        }
    }
}

void displayentries(phone *book, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(book[i].name,"")!=0)
        {
            printf("\n Name: %s",book[i].name);
            printf("\n Phone number: %s",book[i].number);
            printf("\n");
        }
    }
}

int main()
{
    int choice,n;
    phone book[MAX];
    do
    {
        printf("\n Phone book menu");
        printf("\n 1. Add entry");
        printf("\n 2. Delete entry");
        printf("\n 3. Search entry");
        printf("\n 4. Display entries");
        printf("\n 5. Exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\n Enter number of entries:");
                scanf("%d",&n);
                addentry(book,n);
                break;
            case 2:
                deleteentry(book,n);
                break;
            case 3:
                searchentry(book,n);
                break;
            case 4:
                displayentries(book,n);
                break;
            case 5:
                printf("\n Exiting...");
                break;
            default:
                printf("\n Invalid choice");
        }
    }while(choice!=5);
    return 0;
}