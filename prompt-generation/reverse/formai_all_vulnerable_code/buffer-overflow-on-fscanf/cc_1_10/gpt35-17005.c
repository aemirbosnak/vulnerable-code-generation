//FormAI DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char text[500];
} DiaryEntry;

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int entryCount = 0;

    // Load existing entries from file
    FILE *file = fopen("diary.txt", "r");
    if (file) {
        while (fscanf(file, "%s", diary[entryCount].date) != EOF) {
            fgets(diary[entryCount].text, 500, file);
            entryCount++;
        }
        fclose(file);
    }

    // Get current date
    time_t now = time(NULL);
    struct tm *time = localtime(&now);
    char date[20];
    strftime(date, 20, "%x", time);

    // Get user input
    char text[500];
    printf("Enter your diary entry for today (%s):\n", date);
    fgets(text, 500, stdin);

    // Add new entry
    strcpy(diary[entryCount].date, date);
    strcpy(diary[entryCount].text, text);
    entryCount++;

    // Save entries to file
    file = fopen("diary.txt", "w");
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %s", diary[i].date, diary[i].text);
    }
    fclose(file);

    printf("Your entry has been saved to the diary.\n");

    return 0;
}