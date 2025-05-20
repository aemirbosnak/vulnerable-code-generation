//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct DiaryEntry {
    int year;
    int month;
    int day;
    char* title;
    char* content;
};

struct DiaryEntry* createDiaryEntry(int year, int month, int day, char* title, char* content) {
    struct DiaryEntry* entry = malloc(sizeof(struct DiaryEntry));
    entry->year = year;
    entry->month = month;
    entry->day = day;
    entry->title = strdup(title);
    entry->content = strdup(content);
    return entry;
}

void addDiaryEntry(struct DiaryEntry* entry) {
    FILE* file = fopen("diary.txt", "a");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "%d-%d-%d %s %s\n", entry->year, entry->month, entry->day, entry->title, entry->content);
    fclose(file);
}

void deleteDiaryEntry(int year, int month, int day) {
    FILE* file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int y, m, d;
        char title[256], content[256];
        if (sscanf(line, "%d-%d-%d %s %s", &y, &m, &d, title, content) == 5) {
            if (y == year && m == month && d == day) {
                fprintf(file, "%d-%d-%d %s %s\n", y, m, d, title, content);
            }
        }
    }
    fclose(file);
}

void readDiaryEntry(int year, int month, int day) {
    FILE* file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int y, m, d;
        char title[256], content[256];
        if (sscanf(line, "%d-%d-%d %s %s", &y, &m, &d, title, content) == 5) {
            if (y == year && m == month && d == day) {
                printf("%s\n", content);
            }
        }
    }
    fclose(file);
}

int main() {
    struct DiaryEntry* entry = createDiaryEntry(2023, 1, 1, "New Year's Day", "Wish everyone a happy new year!");
    addDiaryEntry(entry);
    deleteDiaryEntry(2023, 1, 1);
    readDiaryEntry(2023, 1, 1);
    return 0;
}