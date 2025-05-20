//FormAI DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

typedef struct {
    char date[11];
    char entry[1000];
} diaryEntry;

void newEntry(diaryEntry*, int*);
void displayEntries(diaryEntry*, int);

int main()
{
    diaryEntry entries[MAX_SIZE];
    int numOfEntries = 0;
    int choice = 0;

    do{
        printf("\nDigital Diary\n");
        printf("1. New Entry\n");
        printf("2. Display Entries\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                newEntry(entries, &numOfEntries);
                break;
            case 2:
                displayEntries(entries, numOfEntries);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice! Try again!\n");
        }
    }while(choice != 3);

    return 0;
}

void newEntry(diaryEntry* entries, int* numOfEntries)
{
    printf("\nEnter today's date (dd/mm/yyyy): ");
    scanf("%s", entries[*numOfEntries].date);

    printf("Enter your entry: ");
    scanf(" %[^\n]s", entries[*numOfEntries].entry);

    (*numOfEntries)++;
}

void displayEntries(diaryEntry* entries, int numOfEntries)
{
    if(numOfEntries == 0)
    {
        printf("\nNo entries to display!\n");
    }
    else
    {
        printf("\nDiary Entries:\n");
        for(int i=0; i<numOfEntries; i++)
        {
            printf("\n%s:\n", entries[i].date);
            printf("%s\n", entries[i].entry);
        }
    }
}