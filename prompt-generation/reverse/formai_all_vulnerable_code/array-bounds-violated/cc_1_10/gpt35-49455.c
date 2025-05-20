//FormAI DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the main menu
void mainMenu();

// Function to add an entry to the diary file
void addEntry();

// Function to show all entries from the diary file
void viewEntries();

// Function to search for a specific entry from the diary file
void searchEntries();

int main()
{
    mainMenu();
    return 0;
}

void mainMenu()
{
    int option;
    printf("\n\n");
    printf("       -----------------------------\n");
    printf("      | Welcome to your Digital Diary |\n");
    printf("       -----------------------------\n\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entries\n");
    printf("4. Exit\n");
    printf("\nSelect an option: ");
    scanf("%d", &option);
    fflush(stdin); // Clear input buffer

    switch (option)
    {
        case 1:
            addEntry();
            mainMenu();
            break;
        case 2:
            viewEntries();
            mainMenu();
            break;
        case 3:
            searchEntries();
            mainMenu();
            break;
        case 4:
            printf("\nThank you for using your Digital Diary!\n");
            break;
        default:
            printf("\n Invalid option, please try again.\n");
            mainMenu();
    }
}

void addEntry()
{
    char date[10];
    char time[10];
    char entry[200];
    char fileName[15];

    printf("\nEnter date (MM/DD/YYYY): ");
    fgets(date, 10, stdin);
    printf("Enter time (HH:MM): ");
    fgets(time, 10, stdin);

    // Remove new line character from input buffer
    if (date[strlen(date)-1] == '\n')
        date[strlen(date)-1] = '\0';
    if (time[strlen(time)-1] == '\n')
        time[strlen(time)-1] = '\0';

    printf("Enter your diary entry (max 200 characters):\n");
    fgets(entry, 200, stdin);

    // Remove new line character from input buffer
    if (entry[strlen(entry)-1] == '\n')
        entry[strlen(entry)-1] = '\0';

    // Create file name with date and time
    sprintf(fileName, "%s_%s.txt", date, time);

    // Open file for writing
    FILE *fp;
    fp = fopen(fileName, "w+");
    if (fp == NULL)
    {
        printf("\nError: Failed to create diary entry.\n");
        return;
    }

    // Write entry to file
    fprintf(fp, "%s\n\n%s", date, entry);

    // Close file
    fclose(fp);

    // Success message
    printf("\nDiary entry successfully added!\n");
}

void viewEntries()
{
    char fileName[15];
    FILE *fp;

    printf("\n\n=====================\n");
    printf("  --- ALL ENTRIES ---\n");
    printf("=====================\n\n");

    // Open all diary files and print their content
    for (int i = 1; i <= 31; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            sprintf(fileName, "%02d/%02d/2022_%02d:00.txt", i, i, j);
            fp = fopen(fileName, "r");
            if (fp != NULL)
            {
                char ch;
                printf("%s:\n", fileName);
                while ((ch = fgetc(fp)) != EOF)
                {
                    printf("%c", ch);
                }
                printf("\n-------------------------\n");
                fclose(fp);
            }
        }
    }

    // If no files were found
    if (fp == NULL)
    {
        printf("\nNo diary entries found.\n");
    }
}

void searchEntries()
{
    char searchQuery[50];
    char fileName[15];
    FILE *fp;
    int searchHits = 0;

    printf("\nEnter search query (max 50 characters): ");
    fgets(searchQuery, 50, stdin);

    // Remove new line character from input buffer
    if (searchQuery[strlen(searchQuery)-1] == '\n')
        searchQuery[strlen(searchQuery)-1] = '\0';

    // Search all diary files for the query
    for (int i = 1; i <= 31; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            sprintf(fileName, "%02d/%02d/2022_%02d:00.txt", i, i, j);
            fp = fopen(fileName, "r");
            if (fp != NULL)
            {
                char line[201];
                while (fgets(line, 201, fp) != NULL)
                {
                    if (strstr(line, searchQuery) != NULL)
                    {
                        printf("%s:\n%s", fileName, line);
                        searchHits++;
                    }
                }
                fclose(fp);
            }
        }
    }

    if (searchHits == 0)
    {
        printf("\nNo matches found for search query.\n");
        return;
    }

    printf("Matching entries found: %d\n", searchHits);
}