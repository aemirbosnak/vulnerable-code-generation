//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char time[10];
    char entry[500];
} DiaryEntry;

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    DiaryEntry diaryEntry;
    int numEntries = 0;
    int choice;

    diary = fopen(filename, "a");
    if (diary == NULL) {
        diary = fopen(filename, "w");
        fprintf(diary, "Welcome to your digital diary!\n\n");
    }

    while (1) {
        printf("1. Write a new entry\n2. Read previous entries\n3. Save and exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", diaryEntry.date);
            printf("Enter time (HH:MM:SS): ");
            scanf("%s", diaryEntry.time);
            printf("Enter your entry:\n");
            fgets(diaryEntry.entry, 500, stdin);
            fprintf(diary, "%s %s\n%s\n\n", diaryEntry.date, diaryEntry.time, diaryEntry.entry);
            break;
        case 2:
            rewind(diary);
            while (fscanf(diary, "%s %s\n%[^\n]", diaryEntry.date, diaryEntry.time, diaryEntry.entry)!= EOF) {
                printf("%s %s\n%s\n\n", diaryEntry.date, diaryEntry.time, diaryEntry.entry);
            }
            break;
        case 3:
            fclose(diary);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}