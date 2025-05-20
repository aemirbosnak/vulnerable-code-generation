//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    char date[20];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

FILE *journal;

void init_journal() {
    journal = fopen("journal.txt", "w");
    if (journal == NULL) {
        printf("Error creating journal file.\n");
        exit(1);
    }
}

void write_entry(char *date, char *time, char *content) {
    struct entry entry;
    strcpy(entry.date, date);
    strcpy(entry.time, time);
    strcpy(entry.content, content);

    fprintf(journal, "%s %s:\n%s\n\n", entry.date, entry.time, entry.content);
}

void read_entries() {
    char line[MAX_ENTRY_LENGTH];
    while (fgets(line, MAX_ENTRY_LENGTH, journal)!= NULL) {
        printf("%s", line);
    }
}

int main() {
    init_journal();

    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char date[20];
    strftime(date, 20, "%Y-%m-%d", tm);
    char time[10];
    strftime(time, 10, "%H:%M:%S", tm);

    char content[MAX_ENTRY_LENGTH];
    printf("Welcome to your digital diary!\n");
    printf("Enter your first entry:\n");
    fgets(content, MAX_ENTRY_LENGTH, stdin);
    write_entry(date, time, content);

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your entry:\n");
                fgets(content, MAX_ENTRY_LENGTH, stdin);
                write_entry(date, time, content);
                break;
            case 2:
                read_entries();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    fclose(journal);
    return 0;
}