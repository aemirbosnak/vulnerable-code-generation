//FormAI DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11]; // format: yyyy-mm-dd (10 chars) + null terminator
    char entry[101]; // maximum 100 characters + null terminator
} DiaryEntry;

int main() {
    char input[5];
    DiaryEntry *diary = NULL;
    int diarySize = 0;

    while (1) {
        printf("What do you want to do?\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Delete an entry\n");
        printf("4. Exit\n");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            diarySize++;
            diary = realloc(diary, diarySize * sizeof(DiaryEntry));
            DiaryEntry *newEntry = &diary[diarySize-1];
            printf("Enter today's date (yyyy-mm-dd): ");
            scanf("%s", newEntry->date);
            printf("Enter your entry: ");
            scanf(" %[^\n]s", newEntry->entry);
            printf("Entry added!\n");
        }
        else if (strcmp(input, "2") == 0) {
            printf("All entries:\n");
            for (int i = 0; i < diarySize; i++) {
                printf("Date: %s\nEntry: %s\n", diary[i].date, diary[i].entry);
            }
        }
        else if (strcmp(input, "3") == 0) {
            printf("Enter the index of the entry you want to delete: ");
            int index;
            scanf("%d", &index);
            if (index >= 1 && index <= diarySize) {
                for (int i = index-1; i < diarySize-1; i++) {
                    diary[i] = diary[i+1];
                }
                diarySize--;
                diary = realloc(diary, diarySize * sizeof(DiaryEntry));
                printf("Entry deleted.\n");
            }
            else {
                printf("Invalid index!\n");
            }
        }
        else if (strcmp(input, "4") == 0) {
            free(diary);
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid input! Please try again.\n");
        }
    }

    return 0;
}