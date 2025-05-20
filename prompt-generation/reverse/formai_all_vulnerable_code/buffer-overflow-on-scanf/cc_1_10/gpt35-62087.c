//FormAI DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of entry and filename
#define MAX_ENTRY_LEN 1000
#define MAX_FILENAME_LEN 50

// Declare functions
int showMenu(void);
void addEntry(char *filename);
void viewEntries(char *filename);
void searchEntries(char *filename);

int main()
{
    char filename[MAX_FILENAME_LEN];

    // Get the filename from the user
    printf("Enter filename for diary: ");
    fgets(filename, MAX_FILENAME_LEN, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove '\n' from filename

    int choice;
    while ((choice = showMenu()) != 4)
    {
        switch (choice)
        {
            case 1: addEntry(filename);
                    break;
            case 2: viewEntries(filename);
                    break;
            case 3: searchEntries(filename);
                    break;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to display the menu
int showMenu(void)
{
    printf("\nDigital Diary\n");
    printf("1. Add entry\n");
    printf("2. View entries\n");
    printf("3. Search entries\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n'); // Discard the '\n' entered after the int input
    return choice;
}

// Function to add a new diary entry
void addEntry(char *filename)
{
    char entry[MAX_ENTRY_LEN];

    // Get the entry from the user
    printf("\nEnter entry (maximum %d characters):\n", MAX_ENTRY_LEN);
    fgets(entry, MAX_ENTRY_LEN, stdin);
    entry[strcspn(entry, "\n")] = '\0'; // Remove '\n' from entry

    // Get the current date and time
    time_t now;
    time(&now);
    char date_time[MAX_ENTRY_LEN];
    strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Open file in append mode and write the entry
    FILE *fp;
    fp = fopen(filename, "a");
    fprintf(fp, "%s %s\n", date_time, entry);
    fclose(fp);

    printf("Entry added successfully!\n");
}

// Function to view all diary entries
void viewEntries(char *filename)
{
    char entry[MAX_ENTRY_LEN];

    // Open file in read mode and print all entries
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    printf("\nDiary entries:\n");
    while (fgets(entry, MAX_ENTRY_LEN, fp) != NULL)
    {
        printf("%s", entry);    
    }

    fclose(fp);
}

// Function to search for a diary entry
void searchEntries(char *filename)
{
    char search_string[MAX_ENTRY_LEN];
    printf("\nEnter search string: ");
    fgets(search_string, MAX_ENTRY_LEN, stdin);
    search_string[strcspn(search_string, "\n")] = '\0'; // Remove '\n' from search_string

    char entry[MAX_ENTRY_LEN];

    // Open file in read mode and search for the search_string
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    printf("\nSearch results:\n");
    while (fgets(entry, MAX_ENTRY_LEN, fp) != NULL)
    {
        if (strstr(entry, search_string))
        {
            printf("%s", entry);
        }
    }

    fclose(fp);
}