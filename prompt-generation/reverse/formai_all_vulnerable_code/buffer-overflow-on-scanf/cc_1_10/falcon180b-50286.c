//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIARY_ENTRIES 100

struct DiaryEntry {
    char date[20];
    char mood[20];
    char event[200];
};

int main() {
    FILE *diaryFile = fopen("diary.txt", "a+");
    if (diaryFile == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    struct DiaryEntry diary[MAX_DIARY_ENTRIES];
    int numEntries = 0;

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numEntries >= MAX_DIARY_ENTRIES) {
                    printf("Error: Maximum number of entries reached.\n");
                    break;
                }

                printf("Enter Date (YYYY-MM-DD): ");
                scanf("%s", diary[numEntries].date);

                printf("Enter Mood: ");
                scanf("%s", diary[numEntries].mood);

                printf("Enter Event: ");
                scanf("%s", diary[numEntries].event);

                numEntries++;
                break;

            case 2:
                printf("\nDiary Entries:\n");
                for (int i = 0; i < numEntries; i++) {
                    fprintf(diaryFile, "%s - %s - %s\n", diary[i].date, diary[i].mood, diary[i].event);
                    printf("%s - %s - %s\n", diary[i].date, diary[i].mood, diary[i].event);
                }
                break;

            case 3:
                fclose(diaryFile);
                exit(0);

            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}