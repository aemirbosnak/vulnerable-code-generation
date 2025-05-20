//FormAI DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Structure to hold notes details
struct note
{
    char title[50];
    char content[200];
    char author[50];
    char date[20];
}n;

// Function to display all notes in the diary
void display_notes()
{
    FILE *fp;
    fp = fopen("Digital_Diary.txt","r");
    if(fp == NULL)
    {
        printf("Error: Unable to open file!");
        return;
    }
    printf("**********************************************************************************************************\n");
    printf("\t\t\t\t\t\tDigital Diary\n");
    printf("**********************************************************************************************************\n");
    printf("\n");
    printf("%-20s%-15s%-15s%s\n","Date","Title","Author","Content");
    printf("----------------------------------------------------------------------------------------------------------\n");
    while(fread(&n,sizeof(n),1,fp))
    {
        printf("%-20s%-15s%-15s%s\n",n.date,n.title,n.author,n.content);
    }
    printf("\n");
    fclose(fp);
}

// Function to add a new note to the diary
void add_note()
{
    FILE *fp;
    fp = fopen("Digital_Diary.txt","a");
    if(fp == NULL)
    {
        printf("Error: Unable to open file!");
        return;
    }
    printf("Enter Note Details:\n");
    printf("Title: ");
    fflush(stdin);
    gets(n.title);
    printf("Content: ");
    fflush(stdin);
    gets(n.content);
    printf("Author: ");
    fflush(stdin);
    gets(n.author);
    time_t currentTime;
    time(&currentTime);
    char *dt = ctime(&currentTime);
    int len = strlen(dt);
    dt[len-1] = '\0';
    strcpy(n.date,dt);
    fwrite(&n,sizeof(n),1,fp);
    printf("\nNote added successfully!\n");
    fclose(fp);
}

// Function to delete a note from the diary
void delete_note()
{
    FILE *fp, *temp_fp;
    char del_title[50];
    int found = 0;
    fp = fopen("Digital_Diary.txt","r");
    if(fp == NULL)
    {
        printf("Error: Unable to open file!");
        return;
    }
    temp_fp = fopen("temp.txt","w");
    if(temp_fp == NULL)
    {
        printf("Error: Unable to open file!");
        return;
    }
    printf("Enter Title of Note to be deleted: ");
    fflush(stdin);
    gets(del_title);
    while(fread(&n,sizeof(n),1,fp))
    {
        if(strcmp(n.title,del_title) == 0)
        {
            found = 1;
        }
        else
        {
            fwrite(&n,sizeof(n),1,temp_fp);
        }
    }
    if(found == 0)
    {
        printf("\nError: Note with title \"%s\" not found!\n",del_title);
    }
    else
    {
        printf("\nNote with title \"%s\" deleted successfully!\n",del_title);
    }
    fclose(fp);
    fclose(temp_fp);
    remove("Digital_Diary.txt");
    rename("temp.txt","Digital_Diary.txt");
}

// Main function
int main()
{
    int choice;
    while(1)
    {
        printf("\n****Digital Diary****\n");
        printf("1. View Notes\n");
        printf("2. Add Note\n");
        printf("3. Delete Note\n");
        printf("4. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                display_notes();
                break;
            case 2:
                add_note();
                break;
            case 3:
                delete_note();
                break;
            case 4:
                exit(0);
            default:
                printf("\nError: Invalid Choice!\n");
                break;
        }
    }
    return 0;
}