//FormAI DATASET v1.0 Category: Digital Diary ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* define constants */
#define MAX_ENTRIES 1000
#define MAX_CHARACTERS 2000
#define FILE_NAME "digital_diary.txt"

/* function prototypes */
void menu();
void add_entry();
void view_entries();
void search_entries();
void delete_entry();
void save_entries();
void load_entries();

/* global variables */
char entries[MAX_ENTRIES][MAX_CHARACTERS];
int entry_count = 0;

int main()
{
    /* load existing entries from file */
    load_entries();
    
    /* show main menu */
    menu();
    
    return 0;
}

void menu()
{
    int choice;
    
    while(1)
    {
        /* display menu options */
        printf("\n===========DIGITAL DIARY MENU============\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Search entries\n");
        printf("4. Delete entry\n");
        printf("5. Save entries\n");
        printf("6. Exit\n");
        printf("Enter your choice(1-6): ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                save_entries();
                break;
            case 6:
                printf("\nExiting Digital Diary...");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.");
        }
    }
}

void add_entry()
{
    /* check if maximum number of entries has been reached */
    if(entry_count == MAX_ENTRIES)
    {
        printf("\nMaximum limit of entries reached! Please delete some entries to add new ones.");
        return;
    }
    
    /* get current time */
    time_t now;
    time(&now);
    
    /* format time as string */
    char timestamp[MAX_CHARACTERS];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    
    /* get user input */
    printf("\nEntry timestamp: %s", timestamp);
    printf("\nEnter your entry:\n");
    getchar(); /* clear input buffer */
    fgets(entries[entry_count], MAX_CHARACTERS, stdin);
    
    /* increment entry count */
    entry_count++;
    
    printf("\nEntry added successfully!");
}

void view_entries()
{
    /* check if any entries exist */
    if(entry_count == 0)
    {
        printf("\nNo entries found!");
        return;
    }
    
    /* display all entries */
    printf("\n================DIARY ENTRIES================\n");
    for(int i=0; i<entry_count; i++)
    {
        printf("Entry %d:\n%s\n\n", i+1, entries[i]);
    }
}

void search_entries()
{
    /* get keyword to search */
    char keyword[MAX_CHARACTERS];
    printf("\nEnter keyword to search: ");
    getchar(); /* clear input buffer */
    fgets(keyword, MAX_CHARACTERS, stdin);
    
    /* search for keyword */
    int found = 0;
    printf("\n================SEARCH RESULTS================\n");
    for(int i=0; i<entry_count; i++)
    {
        if(strstr(entries[i], keyword) != NULL)
        {
            printf("Entry %d:\n%s\n\n", i+1, entries[i]);
            found = 1;
        }
    }
    if(!found)
    {
        printf("No matches found for \"%s\".\n", keyword);
    }
}

void delete_entry()
{
    /* check if any entries exist */
    if(entry_count == 0)
    {
        printf("\nNo entries found!");
        return;
    }
    
    /* get entry number to delete */
    int entry_number;
    printf("\nEnter entry number to delete(1-%d): ", entry_count);
    scanf("%d", &entry_number);
    
    /* validate input */
    if(entry_number < 1 || entry_number > entry_count)
    {
        printf("\nInvalid entry number! Try again.");
        return;
    }
    
    /* shift entries up to overwrite deleted entry */
    for(int i=entry_number-1; i<entry_count-1; i++)
    {
        strcpy(entries[i], entries[i+1]);
    }
    
    /* decrement entry count */
    entry_count--;
    
    printf("\nEntry deleted successfully!");
}

void save_entries()
{
    /* open file for writing */
    FILE* file = fopen(FILE_NAME, "w");
    
    /* write entries to file */
    for(int i=0; i<entry_count; i++)
    {
        fputs(entries[i], file);
    }
    
    /* close file */
    fclose(file);
    
    printf("\nEntries saved to file successfully!");
}

void load_entries()
{
    /* open file for reading */
    FILE* file = fopen(FILE_NAME, "r");
    
    /* read entries from file */
    if(file != NULL)
    {
        char entry[MAX_CHARACTERS];
        while(fgets(entry, sizeof(entry), file) != NULL)
        {
            /* remove newline character */
            entry[strcspn(entry, "\n")] = 0;
            
            /* copy entry to entries array */
            strcpy(entries[entry_count], entry);
            entry_count++;
        }
        
        /* close file */
        fclose(file);
    }
}