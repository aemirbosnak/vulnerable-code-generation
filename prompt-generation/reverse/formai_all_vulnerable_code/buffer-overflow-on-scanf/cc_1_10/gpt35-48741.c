//FormAI DATASET v1.0 Category: Digital Diary ; Style: Claude Shannon
/* Digital Diary Program */
/* By: Your Name */
/* Date: Today's Date */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

/* Diary entry struct */
typedef struct {
    char date[12];
    char time[9];
    char content[1000];
} DiaryEntry;

/* Global variables */
DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

/* Function to add a new entry to the diary */
void addEntry(char *content) {
    time_t t;
    struct tm *now;
    char date[12], timestr[9];

    /* Get current time */
    t = time(NULL);
    now = localtime(&t);
    strftime(date, sizeof(date), "%m/%d/%Y", now);
    strftime(timestr, sizeof(timestr), "%H:%M:%S", now);

    /* Add new entry */
    strcpy(diary[numEntries].date, date);
    strcpy(diary[numEntries].time, timestr);
    strcpy(diary[numEntries].content, content);
    numEntries++;
}

/* Function to print all entries in the diary */
void printDiary() {
    int i;

    /* Print header */
    printf("\nDigital Diary\n");
    printf("Date\t\tTime\t\tContent\n");
    printf("--------------------------------------------\n");

    /* Print entries */
    for (i = 0; i < numEntries; i++) {
        printf("%s\t%s\t%s\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

int main() {
    int choice;
    char content[1000];

    while (1) {
        /* Print menu */
        printf("\nDigital Diary Menu\n");
        printf("1. Add entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        /* Get user input */
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter content: ");
                getchar();  /* Consume newline left over from scanf */
                fgets(content, 1000, stdin);
                addEntry(content);
                break;
            case 2:
                printDiary();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}