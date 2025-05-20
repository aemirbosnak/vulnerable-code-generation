//FormAI DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRY_LENGTH 50
#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new entry\n");
        printf("2. View all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        printf("> ");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (numEntries >= MAX_ENTRIES) {
                    printf("Sorry, your diary is full. You cannot add any more entries.\n");
                    break;
                }
                printf("Enter the date in the format 'dd/mm/yyyy': ");
                scanf("%s", diary[numEntries].date);  // assume user enters date in correct format
                printf("Enter your diary entry (max %d characters):\n", MAX_ENTRY_LENGTH);
                getchar();  // consume the newline from the previous scanf
                fgets(diary[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
                numEntries++;
                printf("Your entry has been added.\n");
                break;

            case 2:
                printf("Here are all of your diary entries:\n");
                for (int i = 0; i < numEntries; i++) {
                    printf("%s: %s", diary[i].date, diary[i].entry);
                }
                break;

            case 3:
                printf("What date would you like to search for? (in the format 'dd/mm/yyyy')\n");
                char searchDate[11];
                scanf("%s", searchDate);
                for (int i = 0; i < numEntries; i++) {
                    if (strcmp(searchDate, diary[i].date) == 0) {
                        printf("%s: %s", diary[i].date, diary[i].entry);
                        break;
                    }
                    if (i == numEntries - 1) {
                        printf("Sorry, no entries found for that date.\n");
                    }
                }
                break;

            case 4:
                printf("Thanks for using your digital diary! Goodbye.\n");
                exit(0);

            default:
                printf("Sorry, please enter a valid option.\n");
        }
    }

    return 0;
}