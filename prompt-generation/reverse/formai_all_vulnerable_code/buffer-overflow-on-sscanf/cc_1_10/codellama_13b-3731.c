//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: complex
// Digital Diary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
    char* entry;
} DiaryEntry;

void addEntry(DiaryEntry* entry) {
    FILE* diary = fopen("diary.txt", "a");
    fprintf(diary, "%d/%d/%d: %s\n", entry->day, entry->month, entry->year, entry->entry);
    fclose(diary);
}

void readEntry(int day, int month, int year) {
    FILE* diary = fopen("diary.txt", "r");
    if (diary == NULL) {
        printf("No diary file found.\n");
        return;
    }

    char line[256];
    while (fgets(line, 256, diary) != NULL) {
        if (line[0] == ' ') {
            int d, m, y;
            sscanf(line, "%d/%d/%d: %s", &d, &m, &y, line);
            if (d == day && m == month && y == year) {
                printf("%s\n", line);
                break;
            }
        }
    }
    fclose(diary);
}

int main() {
    DiaryEntry entry;
    entry.day = 1;
    entry.month = 1;
    entry.year = 2023;
    entry.entry = "Hello, World!";
    addEntry(&entry);

    entry.day = 2;
    entry.month = 1;
    entry.year = 2023;
    entry.entry = "This is my second entry.";
    addEntry(&entry);

    readEntry(1, 1, 2023);
    readEntry(2, 1, 2023);
    return 0;
}