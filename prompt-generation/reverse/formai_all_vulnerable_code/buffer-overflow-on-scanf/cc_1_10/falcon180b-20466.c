//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

struct entry {
    char date[20];
    char time[10];
    char text[ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    time_t now;

    diary = fopen("diary.txt", "a+");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("-------------------\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter your entry:\n");
            fflush(stdin);
            fgets(entries[num_entries].text, ENTRY_LENGTH, stdin);
            time(&now);
            strftime(entries[num_entries].date, 20, "%Y-%m-%d", localtime(&now));
            strftime(entries[num_entries].time, 10, "%H:%M:%S", localtime(&now));
            num_entries++;
            fprintf(diary, "%s %s: %s\n", entries[num_entries-1].date, entries[num_entries-1].time, entries[num_entries-1].text);
            break;
        case '2':
            rewind(diary);
            printf("Diary Entries:\n");
            while (fscanf(diary, "%s %s: %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].text)!= EOF) {
                printf("%s %s: %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].text);
                num_entries++;
            }
            break;
        case '3':
            printf("Enter the keyword to search: ");
            scanf("%s", entries[num_entries].text);
            rewind(diary);
            while (fscanf(diary, "%s %s: %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].text)!= EOF) {
                if (strstr(entries[num_entries].text, entries[num_entries-1].text)!= NULL) {
                    printf("%s %s: %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].text);
                }
                num_entries++;
            }
            break;
        case '4':
            fclose(diary);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}