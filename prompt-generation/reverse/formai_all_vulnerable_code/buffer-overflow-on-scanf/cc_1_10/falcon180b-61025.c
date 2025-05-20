//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *fp;
    char filename[20], entry[MAX_ENTRY_LENGTH];
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0, i;

    printf("Welcome to the Digital Diary!\n\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Create a new entry\n");
        printf("2. View existing entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");

        scanf("%d", &i);

        switch (i) {
        case 1:
            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", diary[num_entries].date);

            printf("Enter the time (HH:MM:SS): ");
            scanf("%s", diary[num_entries].time);

            printf("Enter your diary entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            strcpy(diary[num_entries].content, entry);

            num_entries++;
            break;

        case 2:
            if (num_entries == 0) {
                printf("No entries found.\n");
            } else {
                printf("\nDiary Entries:\n");
                for (i = 0; i < num_entries; i++) {
                    printf("%s %s - %s\n", diary[i].date, diary[i].time, diary[i].content);
                }
            }
            break;

        case 3:
            printf("Enter the date to search for (YYYY-MM-DD): ");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            if (fp == NULL) {
                printf("No entries found.\n");
            } else {
                while (fgets(entry, MAX_ENTRY_LENGTH, fp)!= NULL) {
                    printf("%s", entry);
                }
                fclose(fp);
            }

            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}