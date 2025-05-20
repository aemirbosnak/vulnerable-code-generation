//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[50];
    char time[50];
    char content[MAX_ENTRY_LENGTH];
};

FILE *diary;

void init() {
    diary = fopen("diary.txt", "a+");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }
}

void write_entry(char *date, char *time, char *content) {
    struct entry entry;
    strcpy(entry.date, date);
    strcpy(entry.time, time);
    strcpy(entry.content, content);

    fseek(diary, 0L, SEEK_END);
    fprintf(diary, "%s\n%s\n%s\n", entry.date, entry.time, entry.content);
}

void read_entries() {
    char line[MAX_ENTRY_LENGTH];
    while (fgets(line, MAX_ENTRY_LENGTH, diary)!= NULL) {
        printf("%s", line);
    }
}

int main() {
    init();

    char date[50];
    char time[50];
    char content[MAX_ENTRY_LENGTH];

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter time (HH:MM:SS): ");
        scanf("%s", time);

        printf("Enter content:\n");
        fgets(content, MAX_ENTRY_LENGTH, stdin);
        content[strcspn(content, "\n")] = '\0';

        write_entry(date, time, content);

        printf("Do you want to read your entries? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            read_entries();
        }
    }

    return 0;
}