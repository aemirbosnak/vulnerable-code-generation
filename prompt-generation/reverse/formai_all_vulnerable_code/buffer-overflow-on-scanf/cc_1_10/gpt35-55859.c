//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY 10

typedef struct {
    char date[11];
    char time[10];
    char entry[100];
} DiaryEntry;

char* get_date() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char *date = (char*) malloc(sizeof(char) * 11);
    sprintf(date, "%02d/%02d/%d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);

    return date;
}

char* get_time() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char *time = (char*) malloc(sizeof(char) * 10);
    sprintf(time, "%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);

    return time;
}

void log_entry(DiaryEntry diary[], int *entry_count) {
    char *date = get_date();
    char *time = get_time();

    printf("\nEnter your entry for today (Max 100 chars):\n");
    char c, entry[100];
    int i = 0;

    while ((c = getchar()) != '\n' && i < 100) {
        entry[i++] = c;
    }
    entry[i] = '\0';

    DiaryEntry new_entry;
    strcpy(new_entry.date, date);
    strcpy(new_entry.time, time);
    strcpy(new_entry.entry, entry);

    diary[*entry_count] = new_entry;
    (*entry_count)++;

    free(date);
    free(time);

    if (*entry_count >= MAX_ENTRY) {
        printf("You have reached the maximum number of entries!\n");
    }
}

void print_diary(DiaryEntry diary[], int entry_count) {
    printf("\n-----------------------------------------\n");
    printf("| Date\t\t| Time\t\t| Entry\t\t|\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < entry_count; i++) {
        printf("| %s\t| %s\t", diary[i].date, diary[i].time);

        int len = strlen(diary[i].entry);
        int spaces = 20 - len;

        printf("| %s%*s|\n", diary[i].entry, spaces, "");
    }
    printf("-----------------------------------------\n");
}

int main() {
    DiaryEntry diary[MAX_ENTRY];
    int entry_count = 0;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Log a new entry\n");
        printf("2. View previous entries\n");
        printf("3. Exit\n\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                log_entry(diary, &entry_count);
                break;
            case 2:
                if (entry_count == 0) {
                    printf("\nYou haven't written anything yet.\n");
                } else {
                    print_diary(diary, entry_count);
                }
                break;
            case 3:
                printf("\nGoodbye!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}