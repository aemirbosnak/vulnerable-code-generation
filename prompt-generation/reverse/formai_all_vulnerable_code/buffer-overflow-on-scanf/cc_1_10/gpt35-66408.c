//FormAI DATASET v1.0 Category: Digital Diary ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 1000

// global variable declaration
char record[MAX], temp[MAX], date[MAX];

// function prototype
void add_entry();
void view_entry();
void search_entry();
void delete_entry();

int main()
{
    int choice;
    printf("\n\n\t\tWelcome to My Gratitude Journal\n");
    printf("\t\t------------------------------\n");

    while(1)
    {
        printf("\n1. Add Entry\n");
        printf("2. View Entry\n");
        printf("3. Search Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: add_entry();
                    break;

            case 2: view_entry();
                    break;

            case 3: search_entry();
                    break;

            case 4: delete_entry();
                    break;

            case 5: printf("\nClosing the Diary!\n\n");
                    exit(0);

            default: printf("\nInvalid Choice!\n\n");
        }
    }
    return 0;
}

void add_entry()
{
    printf("\nEnter the date (dd.mm.yyyy): ");
    scanf("%s", date);

    FILE *fp;
    fp = fopen(date, "a");

    if(fp == NULL)
    {
        printf("\nError Opening Diary!");
        exit(1);
    }
    printf("\nEnter your Entry for %s: ", date);
    fflush(stdin);
    scanf("%[^\n]", record);

    fprintf(fp, "%s\n", record);
    fclose(fp);

    printf("\nEntry Successfully Added!\n\n");
}

void view_entry()
{
    printf("\nEnter the date (dd.mm.yyyy): ");
    scanf("%s", date);

    FILE *fp;
    fp = fopen(date, "r");

    if(fp == NULL)
    {
        printf("\nNo Entry Found for %s!", date);
        return;
    }

    printf("\nEntries for %s\n", date);
    printf("\n------------------\n");

    while(fgets(temp, MAX, fp) != NULL)
    {
        printf("%s", temp);
    }

    printf("\n\n");
    fclose(fp);
}

void search_entry()
{
    int found = 0;
    char search[MAX];

    printf("\nEnter the date (dd.mm.yyyy): ");
    scanf("%s", date);

    FILE *fp;
    fp = fopen(date, "r");

    if(fp == NULL)
    {
        printf("\nNo Entry Found for %s!", date);
        return;
    }

    printf("\nEnter the phrase to search: ");
    fflush(stdin);
    scanf("%[^\n]", search);

    while(fgets(temp, MAX, fp) != NULL)
    {
        if(strstr(temp, search) != NULL)
        {
            printf("%s\n", temp);
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nNo Match Found for '%s' in %s\n\n", search, date);
    }

    fclose(fp);
}

void delete_entry()
{
    char confirm;
    printf("\nEnter the date (dd.mm.yyyy): ");
    scanf("%s", date);

    FILE *fp;
    fp = fopen(date, "r");

    if(fp == NULL)
    {
        printf("\nNo Entry Found for %s!", date);
        return;
    }

    printf("\nAre you sure you want to delete the entry for %s? (y/n): ", date);
    scanf(" %c", &confirm);

    if(confirm == 'y' || confirm == 'Y')
    {
        fclose(fp);
        remove(date);
        printf("\nEntry Deleted Successfully!\n\n");
    }
    else
    {
        printf("\nDeletion Canceled!\n\n");
        fclose(fp);
    }
}