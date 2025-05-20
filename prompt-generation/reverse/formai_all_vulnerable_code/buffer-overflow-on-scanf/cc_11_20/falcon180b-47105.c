//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_LENGTH 500

struct entry {
    char date[20];
    char time[20];
    char content[ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int entry_count = 0;
    int choice;

    diary = fopen("diary.txt", "a+");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Search for a specific entry\n");
        printf("4. Save changes and exit\n");
        printf("0. Exit without saving\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (entry_count >= MAX_ENTRIES) {
                printf("Error: Maximum number of entries reached.\n");
            } else {
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", entries[entry_count].date);
                printf("Enter time (HH:MM:SS): ");
                scanf("%s", entries[entry_count].time);
                printf("Enter your entry:\n");
                fgets(entries[entry_count].content, ENTRY_LENGTH, stdin);
                entry_count++;
                printf("Entry saved.\n");
            }
            break;
        case 2:
            printf("Previous entries:\n");
            rewind(diary);
            while (fscanf(diary, "%s %s %s", entries[0].date, entries[0].time, entries[0].content)!= EOF) {
                printf("%s %s\n%s\n", entries[0].date, entries[0].time, entries[0].content);
            }
            break;
        case 3:
            printf("Enter keyword to search: ");
            scanf("%s", entries[0].content);
            rewind(diary);
            while (fscanf(diary, "%s %s %s", entries[0].date, entries[0].time, entries[0].content)!= EOF) {
                if (strstr(entries[0].content, entries[0].content)!= NULL) {
                    printf("%s %s\n%s\n", entries[0].date, entries[0].time, entries[0].content);
                }
            }
            break;
        case 4:
            fclose(diary);
            diary = fopen("diary.txt", "w");
            for (int i = 0; i < entry_count; i++) {
                fprintf(diary, "%s %s %s\n", entries[i].date, entries[i].time, entries[i].content);
            }
            fclose(diary);
            printf("Changes saved and program exited.\n");
            break;
        case 0:
            printf("Program exited without saving changes.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}