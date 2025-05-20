//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 100

typedef struct Entry
{
    int day;
    int month;
    int year;
    char title[50];
    char message[1000];
} Entry;

void addEntry(Entry *diary, int *entries);
void viewEntry(Entry *diary, int entries);
void searchEntry(Entry *diary, int entries);
void deleteEntry(Entry *diary, int *entries);

int main()
{
    int choice = 0, entries = 0;
    Entry diary[MAX_ENTRY];

    printf("Welcome to your Digital Diary\n");

    while (choice != 5)
    {
        printf("Choose an option:\n");
        printf("1. Add new entry \n2. View entries for a specific date \n3. Search entries by keyword \n4. Delete an entry \n5. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEntry(diary, &entries);
                break;
            case 2:
                viewEntry(diary, entries);
                break;
            case 3:
                searchEntry(diary, entries);
                break;
            case 4:
                deleteEntry(diary, &entries);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    return 0;
}

void addEntry(Entry *diary, int *entries)
{
    if (*entries >= MAX_ENTRY)
    {
        printf("Your diary is full, cannot add any more entries.\n");
        return;
    }

    printf("Enter the date in the format of day/month/year (for example, 4/9/2022): ");
    fflush(stdin);
    scanf("%d/%d/%d", &diary[*entries].day, &diary[*entries].month, &diary[*entries].year);

    printf("Enter the title of the entry: ");
    fflush(stdin);
    fgets(diary[*entries].title, 50, stdin);
    diary[*entries].title[strcspn(diary[*entries].title, "\n")] = 0;

    printf("Enter your message (max 1000 characters): ");
    fflush(stdin);
    fgets(diary[*entries].message, 1000, stdin);

    printf("Entry added successfully!\n");

    (*entries)++;
}

void viewEntry(Entry *diary, int entries)
{
    int day, month, year;
    int found = 0;

    printf("Enter the date you want to view in the format of day/month/year (for example, 4/9/2022): ");
    fflush(stdin);
    scanf("%d/%d/%d", &day, &month, &year);

    for (int i = 0; i < entries; i++)
    {
        if (diary[i].day == day && diary[i].month == month && diary[i].year == year)
        {
            printf("Entry found:\n");
            printf("Date: %d/%d/%d\nTitle: %s\nMessage: %s", diary[i].day, diary[i].month, diary[i].year, diary[i].title, diary[i].message);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("No entries found for that date.\n");
    }
}

void searchEntry(Entry *diary, int entries)
{
    char keyword[50];
    int found = 0;

    printf("Enter a keyword to search for (max 50 characters): ");
    fflush(stdin);
    fgets(keyword, 50, stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    for (int i = 0; i < entries; i++)
    {
        if (strstr(diary[i].message, keyword) != NULL || strstr(diary[i].title, keyword) != NULL)
        {
            printf("Entry found:\n");
            printf("Date: %d/%d/%d\nTitle: %s\nMessage: %s", diary[i].day, diary[i].month, diary[i].year, diary[i].title, diary[i].message);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No entries found containing that keyword.\n");
    }
}

void deleteEntry(Entry *diary, int *entries)
{
    int day, month, year;
    int found = 0;

    printf("Enter the date of the entry you want to delete in the format of day/month/year (for example, 4/9/2022): ");
    fflush(stdin);
    scanf("%d/%d/%d", &day, &month, &year);

    for (int i = 0; i < *entries; i++)
    {
        if (diary[i].day == day && diary[i].month == month && diary[i].year == year)
        {
            found = 1;

            for (int j = i; j < *entries - 1; j++)
            {
                diary[j] = diary[j + 1];
            }

            (*entries)--;
            printf("Entry deleted successfully.\n");

            break;
        }
    }

    if (!found)
    {
        printf("No entries found for that date.\n");
    }
}