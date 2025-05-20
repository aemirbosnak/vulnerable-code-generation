//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define DIARY_MAX_ENTRIES 100
#define ENTRY_MAX_LENGTH 150
#define DATE_FORMAT "%Y-%m-%d"

typedef struct {
    char title[ENTRY_MAX_LENGTH];
    char content[ENTRY_MAX_LENGTH];
    time_t timestamp;
} DiaryEntry;

void print_date(time_t timestamp) {
    struct tm *date;
    char date_str[20];

    date = localtime(&timestamp);
    strftime(date_str, sizeof(date_str), DATE_FORMAT, date);
    printf("%s: ", date_str);
}

int find_empty_entry(DiaryEntry *diary) {
    for (int i = 0; i < DIARY_MAX_ENTRIES; i++) {
        if (diary[i].timestamp == 0) {
            return i;
        }
    }
    return -1;
}

void save_entry(DiaryEntry *diary, int index, char *title, char *content) {
    diary[index].timestamp = time(NULL);
    strcpy(diary[index].title, title);
    strcpy(diary[index].content, content);
}

int main() {
    DiaryEntry diary[DIARY_MAX_ENTRIES];
    int index;
    char title[ENTRY_MAX_LENGTH];
    char content[ENTRY_MAX_LENGTH];

    while (1) {
        print_date(time(NULL));
        printf("> ");
        fgets(content, ENTRY_MAX_LENGTH, stdin);
        content[strcspn(content, "\n")] = 0; // remove newline character

        if (strtok(content, " ") != NULL) {
            sscanf(content, "%s %s", title, content + strlen(title) + 1);
            index = find_empty_entry(diary);

            if (index >= 0) {
                save_entry(diary, index, title, content);
                printf("Saved: %s\n", title);
            } else {
                printf("Failed to save entry.\n");
            }
        }
    }

    return 0;
}