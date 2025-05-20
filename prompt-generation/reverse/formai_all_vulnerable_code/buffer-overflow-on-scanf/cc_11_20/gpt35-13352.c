//FormAI DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store diary entry
struct DiaryEntry
{
    char date[11]; // in YYYY-MM-DD format
    char entry[1000];
};

int main()
{
    int option = -1;
    int numEntries = 0;
    struct DiaryEntry* entries = NULL;
    
    printf("Welcome to your Digital Diary!\n");
    
    while(option != 0)
    {
        printf("\nPlease select an option:\n");
        printf("1. Add an Entry\n");
        printf("2. Search for an Entry\n");
        printf("3. Display all Entries\n");
        printf("4. Modify an Entry\n");
        printf("0. Exit\n");
        
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
            {
                // Allocate memory for new entry
                if(entries == NULL)
                {
                    entries = (struct DiaryEntry*) malloc(sizeof(struct DiaryEntry));
                }
                else
                {
                    entries = (struct DiaryEntry*) realloc(entries, (numEntries+1)*sizeof(struct DiaryEntry));
                }
                
                // Add new entry details
                printf("Enter today's date in YYYY-MM-DD format: ");
                scanf("%s", entries[numEntries].date);
                
                printf("Enter your diary entry (max 1000 characters): ");
                scanf(" %[^\n]s", entries[numEntries].entry);
                
                numEntries++;
                
                printf("Entry added successfully!\n");
                break;
            }
            case 2:
            {
                char searchDate[11];
                printf("Enter the date to search in YYYY-MM-DD format: ");
                scanf("%s", searchDate);
                
                int found = 0;
                // Search for entry
                for(int i=0; i<numEntries; i++)
                {
                    if(strcmp(entries[i].date, searchDate) == 0)
                    {
                        printf("Entry found for %s:\n%s\n", searchDate, entries[i].entry);
                        found = 1;
                        break;
                    }
                }
                
                if(!found)
                {
                    printf("No entry found for %s\n", searchDate);
                }
                
                break;
            }
            case 3:
            {
                if(numEntries == 0)
                {
                    printf("No entries found!\n");
                    break;
                }
                
                printf("Your entries:\n");
                for(int i=0; i<numEntries; i++)
                {
                    printf("%s:\n%s\n", entries[i].date, entries[i].entry);
                }
                
                break;
            }
            case 4:
            {
                if(numEntries == 0)
                {
                    printf("No entries found!\n");
                    break;
                }
                
                char modifyDate[11];
                printf("Enter the date to modify in YYYY-MM-DD format: ");
                scanf("%s", modifyDate);
                
                int found = 0;
                // Search for entry
                for(int i=0; i<numEntries; i++)
                {
                    if(strcmp(entries[i].date, modifyDate) == 0)
                    {
                        printf("%s:\n%s\n\nEnter modified diary entry (max 1000 characters): ", entries[i].date, entries[i].entry);
                        scanf(" %[^\n]s", entries[i].entry);
                        found = 1;
                        printf("Entry modified successfully!\n");
                        break;
                    }
                }
                
                if(!found)
                {
                    printf("No entry found for %s\n", modifyDate);
                }
                
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                printf("Invalid option. Please try again.\n");
                break;
            }
        }
    }
    
    // Free the memory allocated for entries
    free(entries);
    
    printf("Thank you for using Digital Diary!\n");
    return 0;
}