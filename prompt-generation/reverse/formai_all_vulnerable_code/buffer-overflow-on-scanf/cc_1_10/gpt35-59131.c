//FormAI DATASET v1.0 Category: Digital Diary ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void add_entry();
void view_entries();

int main()
{
    int choice;
    do
    {
        printf("\n ~~~~~~ DIGITAL DIARY ~~~~~~\n");
        printf("\n 1. Add Entry");
        printf("\n 2. View Entries");
        printf("\n 3. Exit");

        printf("\n\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: add_entry(); break;
            case 2: view_entries(); break;
            case 3: exit(0);
            default: printf("\n Invalid choice. Try again.");
        }
    }while(1);
    return 0;
}

void add_entry()
{
    FILE *f;
    char date[20], entry[500];

    f = fopen("diary.txt", "a");

    if(f == NULL)
    {
        printf("\n Error: Unable to open diary file.");
        return;
    }
    printf("\n Enter the date (dd-mm-yyyy): ");
    scanf("%s", date);

    printf("\n Start typing your entry. Press Ctrl + Z to save.\n");
    printf(" -----------------------------------------\n");

    while(getchar() != EOF);
    
    while(gets(entry))
    {
        fprintf(f, "[%s]: %s\n", date, entry);
    }
    printf("\n Entry added successfully.\n");
    fclose(f);
}

void view_entries()
{   
    FILE *f;
    char entry[500];
    f = fopen("diary.txt", "r");

    if(f == NULL)
    {
        printf("\n Error: Unable to open diary file.");
        return;
    }
    
    printf("\n ~~~~~~ ENTRIES ~~~~~~");
    while(fgets(entry, 500, f) != NULL)
    {
        printf("\n %s", entry);
    }
    fclose(f);
}