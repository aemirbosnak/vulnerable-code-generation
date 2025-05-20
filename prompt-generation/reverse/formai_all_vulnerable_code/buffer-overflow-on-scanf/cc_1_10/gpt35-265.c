//FormAI DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_LENGTH 200

struct DigitalDiary
{
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
};

void addEntry(struct DigitalDiary *diary, int *count)
{
    printf("Enter the date (MM/DD/YYYY): ");
    scanf("%s", diary[*count].date);

    printf("Enter your diary entry (max 200 characters):\n");
    scanf(" %[^\n]", diary[*count].entry);

    (*count)++;
}

void displayEntries(struct DigitalDiary *diary, int count)
{
    if(count == 0)
    {
        printf("No entries found. Add some first.\n");
        return;
    }

    printf("\n\n");

    for(int i = 0; i < count; i++)
    {
        printf("%s : %s\n", diary[i].date, diary[i].entry);
    }
}

int main()
{
    struct DigitalDiary diary[100];
    int count = 0;
    int choice;

    while(1)
    {
        printf("1. Add diary entry\n");
        printf("2. Display all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addEntry(diary, &count);
                break;
            case 2:
                displayEntries(diary, count);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try Again.\n");
                break;
        }

        printf("\n");
    }
    return 0;
}