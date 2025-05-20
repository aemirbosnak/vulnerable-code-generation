//FormAI DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRY_LENGTH 2000
#define MAX_DATE_LENGTH 20
#define MAX_ENTRIES 100

char entries[MAX_ENTRIES][MAX_ENTRY_LENGTH];
char dates[MAX_ENTRIES][MAX_DATE_LENGTH];
int num_entries = 0;

int main()
{
    int choice;
    char entry[MAX_ENTRY_LENGTH];
    char date[MAX_DATE_LENGTH];
    time_t now;

    printf("Welcome to your digital diary!\n");

    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. View previous entries\n");
        printf("2. Add a new entry\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        if (choice == 1)
        {
            if (num_entries == 0)
            {
                printf("\nThere are no previous entries.\n");
            }
            else
            {
                printf("\nPrevious Entries:\n");
                for (int i = 0; i < num_entries; i++)
                {
                    printf("%s\n", dates[i]);
                    printf("%s\n", entries[i]);
                }
            }
        }
        else if (choice == 2)
        {
            getchar(); // clear input buffer

            printf("\nEnter today's date (mm/dd/yyyy): ");
            fgets(date, MAX_DATE_LENGTH, stdin);
            date[strlen(date) - 1] = '\0'; // remove trailing newline

            printf("\nEnter your entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            entry[strlen(entry) - 1] = '\0'; // remove trailing newline

            strcpy(dates[num_entries], date);
            strcpy(entries[num_entries], entry);
            num_entries++;

            printf("\nEntry saved successfully!\n");
        }
        else if (choice == 3)
        {
            printf("\nExiting digital diary. Goodbye!\n");
            break;
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}