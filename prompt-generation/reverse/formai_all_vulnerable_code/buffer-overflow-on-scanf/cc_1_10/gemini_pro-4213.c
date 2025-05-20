//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
    char *text;
} DiaryEntry;

DiaryEntry *create_entry(int day, int month, int year, char *text) {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    entry->day = day;
    entry->month = month;
    entry->year = year;
    entry->text = strdup(text);
    return entry;
}

void free_entry(DiaryEntry *entry) {
    free(entry->text);
    free(entry);
}

DiaryEntry *read_entry(FILE *fp) {
    int day, month, year;
    char *text;
    fscanf(fp, "%d %d %d\n", &day, &month, &year);
    text = malloc(100);
    fgets(text, 100, fp);
    return create_entry(day, month, year, text);
}

void write_entry(FILE *fp, DiaryEntry *entry) {
    fprintf(fp, "%d %d %d\n", entry->day, entry->month, entry->year);
    fprintf(fp, "%s", entry->text);
}

int main() {
    FILE *fp = fopen("diary.txt", "r+");
    if (fp == NULL) {
        fp = fopen("diary.txt", "w+");
    }
    int choice;
    while (1) {
        printf("1. Write an entry\n");
        printf("2. Read an entry\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int day, month, year;
                char *text;
                printf("Enter the date (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                printf("Enter the text: ");
                text = malloc(100);
                fgets(text, 100, stdin);
                DiaryEntry *entry = create_entry(day, month, year, text);
                write_entry(fp, entry);
                free_entry(entry);
                break;
            }
            case 2: {
                int day, month, year;
                printf("Enter the date (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                fseek(fp, 0, SEEK_SET);
                DiaryEntry *entry = read_entry(fp);
                if (entry->day == day && entry->month == month && entry->year == year) {
                    printf("Text: %s", entry->text);
                } else {
                    printf("No entry found for the given date.");
                }
                free_entry(entry);
                break;
            }
            case 3:
                fclose(fp);
                exit(0);
        }
    }
    return 0;
}