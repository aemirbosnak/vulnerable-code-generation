//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void openFile(FILE *fp,char fname[])
{
    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        printf("Error opening the file!\n");
        exit(1);
    }
}

void closeFile(FILE *fp)
{
    fclose(fp);
}

void displayMenu()
{
    printf("Welcome to Happy Ebook Reader!\n");
    printf("==============================================\n");
    printf("Please select from the following options:\n");
    printf("\t1. Display book contents\n");
    printf("\t2. Go to a specific page\n");
    printf("\t3. Search for a keyword\n");
    printf("\t4. Exit Happy Ebook Reader\n");
    printf("==============================================\n");
}

void displayContents(FILE *fp)
{
    int ch;
    printf("\n\nThe contents of the book are:\n\n");
    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    printf("\n\n");
}

void goToPage(FILE *fp)
{
    int pgnum;
    printf("\n\nEnter the page number you want to go to:\n");
    scanf("%d",&pgnum);
    fseek(fp,(pgnum-1)*80,SEEK_SET);
    printf("\n\n");
    displayContents(fp);
}

void searchForKeyword(FILE *fp)
{
    char keyword[50];
    int flag=0;
    printf("\n\nEnter the keyword you want to search for:\n");
    scanf("%s",keyword);
    while(!feof(fp))
    {
        if(fscanf(fp,"%s",keyword)==1)
        {
            if(strcmp(keyword,keyword)==0)
            {
                flag=1;
                fseek(fp,-strlen(keyword),SEEK_CUR);
                printf("Found %s at position : %d\n\n",keyword,ftell(fp));
                break;
            }
        }
    }
    if(flag==0)
    {
        printf("Keyword not found!\n\n");
    }
    printf("\n\n");
}

void main()
{
    FILE *fp;
    char fname[20];
    int choice;
    openFile(fp,fname);
    displayMenu();
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: displayContents(fp);
                    break;
            case 2: goToPage(fp);
                    break;
            case 3: searchForKeyword(fp);
                    break;
            case 4: closeFile(fp);
                    exit(0);
            default: printf("Invalid choice entered! Please try again.\n\n");
        }
        displayMenu();
    }
}