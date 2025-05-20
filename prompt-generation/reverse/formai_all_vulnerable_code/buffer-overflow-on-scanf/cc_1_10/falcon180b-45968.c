//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    FILE *diary;
    char filename[30] = "diary.txt";
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    time_t now;
    struct tm *tm;

    diary = fopen(filename, "a");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("-------------------\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Save and exit\n");
        printf("4. Exit without saving\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nEnter your entry:\n");
                fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                time(&now);
                tm = localtime(&now);
                strftime(entries[num_entries].date, 20, "%d/%m/%Y", tm);
                strftime(entries[num_entries].time, 20, "%H:%M:%S", tm);
                num_entries++;
                break;
            case '2':
                printf("\nPrevious entries:\n\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
                }
                break;
            case '3':
                fclose(diary);
                remove(filename);
                diary = fopen(filename, "w");
                for (int i = 0; i < num_entries; i++) {
                    fprintf(diary, "%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
                }
                fclose(diary);
                printf("\nEntries saved successfully.\n");
                exit(0);
            case '4':
                printf("\nExiting without saving...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}