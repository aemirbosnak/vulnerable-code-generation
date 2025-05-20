//FormAI DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* max number of characters in the diary entry */
#define MAX_ENTRY_LEN 1024

/* max number of entries in the diary */
#define MAX_ENTRIES 100

/* structure to store the diary entry */
typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LEN];
} Entry;

/* function to add entry to the diary */
void addEntry(Entry *entries, int *numEntries)
{
    char date[20];
    char entry[MAX_ENTRY_LEN];

    printf("Enter date (mm/dd/yyyy): ");
    fgets(date, sizeof(date), stdin);
    date[strlen(date)-1] = '\0';

    printf("Enter diary entry: ");
    fgets(entry, sizeof(entry), stdin);
    entry[strlen(entry)-1] = '\0';

    strncpy(entries[*numEntries].date, date, sizeof(entries[*numEntries].date));
    strncpy(entries[*numEntries].entry, entry, sizeof(entries[*numEntries].entry));

    (*numEntries)++;
}

/* function to display all entries in the diary */
void displayEntries(Entry *entries, int numEntries)
{
    int i;

    for (i=0; i<numEntries; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("%s\n", entries[i].entry);
        printf("\n");
    }
}

/* main function */
int main()
{
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;
    int option;

    printf("Welcome to your Digital Diary\n");
    printf("============================\n\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add diary entry\n");
        printf("2. Display diary entries\n");
        printf("3. Exit\n");

        scanf("%d", &option);
        getchar(); /* consume the \n character */

        switch (option) {
            case 1:
                addEntry(entries, &numEntries);
                break;

            case 2:
                displayEntries(entries, numEntries);
                break;

            case 3:
                printf("Thank you for using Digital Diary\n");
                exit(0);

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}