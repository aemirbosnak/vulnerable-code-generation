//FormAI DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 100

struct Entry 
{
    char date[20];
    char text[500];
};

void printMenu() 
{
    printf("\n\n================== MEDIEVAL DIGITAL DIARY ==================\n");
    printf("1. View Previous Entries\n");
    printf("2. Add New Entry\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void viewEntries(struct Entry *entries, int count) 
{
    printf("\n\n================== PREVIOUS ENTRIES ==================\n");
    for (int i = 0; i < count; i++) 
    {
        printf("Date: %s\n", entries[i].date);
        printf("Entry: %s\n", entries[i].text);
        printf("------------------------------------------------------\n");
    }
}

void addEntry(struct Entry *entries, int *count) 
{
    printf("\n\n================== NEW ENTRY ==================\n");
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", entries[*count].date);
    printf("Enter the text (max 500 characters): ");
    scanf(" %[^\n]s", entries[*count].text);
    (*count)++;
}

int main() 
{
    struct Entry entries[MAX_ENTRY];
    int count = 0;
    int choice;

    do 
    {
        printMenu();
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                viewEntries(entries, count);
                break;
            case 2:
                addEntry(entries, &count);
                break;
            case 3:
                printf("\n\nFarewell, dear diary. Until we meet again.\n");
                return 0;
            default:
                printf("\n\nI know not of such tasks, my lord. Please choose again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}