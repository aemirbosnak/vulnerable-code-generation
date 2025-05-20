//FormAI DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Diary {
    char entry[1000];
    char date[50];
};

int main() {
    struct Diary myDiary;
    char choice;
    time_t rawTime;
    struct tm* timeInfo;

    printf("Welcome to your Digital Diary!\n");

    while (1) {
        printf("\nWhat do you want to do today?\n");
        printf("A - Add a new entry\n");
        printf("D - Delete the last entry\n");
        printf("S - Show existing entries\n");
        printf("Q - Quit\n");
        printf("Choice: ");

        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
            case 'A':
                printf("\nGreat! Let's add a new entry!\n\n");

                printf("Enter the date (DD/MM/YYYY): ");
                scanf(" %[^\n]", myDiary.date);

                time(&rawTime);
                timeInfo = localtime(&rawTime);

                printf("\nEnter your entry (max 1000 characters):\n");
                scanf(" %[^\n]", myDiary.entry);

                printf("Successfully added entry on %d-%d-%d\n", timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900);
                break;

            case 'd':
            case 'D':
                printf("\nAre you sure you want to delete the last entry? Y/N\n");
                scanf(" %c", &choice);

                if (choice == 'y' || choice == 'Y') {
                    printf("Deleting last entry... Done!\n");
                } else {
                    printf("Phew, that was close!\n");
                }
                break;

            case 's':
            case 'S':
                printf("\nShowing existing entries:\n");

                // to be implemented in the next version, sorry!
                printf("Sorry, I'm too shy to show your secrets yet!\n");
                break;

            case 'q':
            case 'Q':
                printf("\nThanks for trusting me with your deepest thoughts. Bye!\n");
                exit(0);

            default:
                printf("\nSorry, I didn't get that. Can you repeat, please?\n");
                break;
        }
    }

    return 0;
}