//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_LENGTH 200

typedef struct {
    char date[20];
    char time[20];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

int main() {
    int choice, i;
    FILE *diary;
    DiaryEntry entry;
    time_t current_time;

    diary = fopen("diary.txt", "a+");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    printf("Welcome to the Digital Diary!\n");
    printf("Please choose an option:\n");
    printf("1. Write a new entry\n");
    printf("2. Read previous entries\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter your entry:\n");
            scanf("%[^\n]", entry.entry);

            current_time = time(NULL);
            strftime(entry.date, 20, "%Y-%m-%d", localtime(&current_time));
            strftime(entry.time, 20, "%H:%M:%S", localtime(&current_time));

            fprintf(diary, "Date: %s\nTime: %s\nEntry:\n%s\n\n", entry.date, entry.time, entry.entry);

            printf("Entry saved successfully!\n");

            break;

        case 2:
            rewind(diary);

            printf("Previous entries:\n");

            while (fscanf(diary, "Date: %[^\n]", entry.date)!= EOF) {
                fscanf(diary, "Time: %[^\n]", entry.time);
                fgets(entry.entry, ENTRY_LENGTH, diary);

                printf("Date: %s\nTime: %s\nEntry:\n%s\n\n", entry.date, entry.time, entry.entry);
            }

            break;

        case 3:
            printf("Thank you for using the Digital Diary!\n");

            fclose(diary);
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}