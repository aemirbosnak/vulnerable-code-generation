//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct
{
    char name[30];
    char number[15];
}PhoneBook;

PhoneBook *book;
int count=0;

void addEntry()
{
    PhoneBook *newBook;
    int i;

    if(count>=100)
    {
        printf("\nPhone book is full");
        return;
    }

    newBook=(PhoneBook*)malloc(sizeof(PhoneBook));

    printf("\nEnter name: ");
    scanf("%s",newBook->name);
    printf("Enter number: ");
    scanf("%s",newBook->number);

    for(i=0;i<count;i++)
    {
        if(strcmp(newBook->name,book[i].name)==0)
        {
            printf("\nDuplicate entry! Please enter a different name");
            free(newBook);
            return;
        }
    }

    book[count]=*newBook;
    count++;
    printf("\nEntry added successfully");
}

void searchEntry()
{
    char name[30];

    printf("\nEnter name to search: ");
    scanf("%s",name);

    for(int i=0;i<count;i++)
    {
        if(strcmp(name,book[i].name)==0)
        {
            printf("\nName: %s",book[i].name);
            printf("\nNumber: %s",book[i].number);
        }
    }
}

void deleteEntry()
{
    char name[30];

    printf("\nEnter name to delete: ");
    scanf("%s",name);

    for(int i=0;i<count;i++)
    {
        if(strcmp(name,book[i].name)==0)
        {
            for(int j=i;j<count-1;j++)
            {
                strcpy(book[j].name,book[j+1].name);
                strcpy(book[j].number,book[j+1].number);
            }
            count--;
            printf("\nEntry deleted successfully");
            return;
        }
    }

    printf("\nName not found in the phone book");
}

void displayEntries()
{
    for(int i=0;i<count;i++)
    {
        printf("\nName: %s",book[i].name);
        printf("\nNumber: %s",book[i].number);
    }
}

int main()
{
    book=(PhoneBook*)malloc(sizeof(PhoneBook));
    count=0;

    while(1)
    {
        printf("\n1. Add entry");
        printf("\n2. Search entry");
        printf("\n3. Delete entry");
        printf("\n4. Display all entries");
        printf("\n5. Exit");

        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addEntry();
                break;

            case 2:
                searchEntry();
                break;

            case 3:
                deleteEntry();
                break;

            case 4:
                displayEntries();
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}