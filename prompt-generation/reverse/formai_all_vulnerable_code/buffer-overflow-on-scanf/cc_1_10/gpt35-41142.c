//FormAI DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

struct Entry {
    char date[11];
    char time[6];
    char content[200];
};

struct Diary {
    struct Entry entries[MAX_ENTRIES];
    int num_entries;
};

void add_entry(struct Diary* diary, char* date, char* time, char* content) {
    struct Entry new_entry;
    strcpy(new_entry.date, date);
    strcpy(new_entry.time, time);
    strcpy(new_entry.content, content);
    diary->entries[diary->num_entries++] = new_entry;
}

void print_entry(struct Entry* entry) {
    printf("%s %s: %s\n", entry->date, entry->time, entry->content);
}

void print_diary(struct Diary* diary) {
    printf("---- My Digital Diary ----\n");
    for (int i = 0; i < diary->num_entries; i++) {
        print_entry(&diary->entries[i]);
    }
}

void save_diary(struct Diary* diary) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char filename[20];
    sprintf(filename, "%d-%02d-%02d.txt", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    FILE* file = fopen(filename, "w");

    if (file) {
        fprintf(file, "---- My Digital Diary ----\n");
        for (int i = 0; i < diary->num_entries; i++) {
            fprintf(file, "%s %s: %s\n", diary->entries[i].date, diary->entries[i].time, diary->entries[i].content);
        }
        fclose(file);
        printf("Diary saved to file: %s\n", filename);
    } else {
        printf("Error saving diary to file: %s\n", filename);
        exit(1);
    }
}

int main() {
    struct Diary diary = { 0 };
    char date[11], time[6], content[200], action;

    printf("---- My Digital Diary ----\n");
    printf("Press 'a' to add an entry, 'p' to print the diary, or 's' to save the diary to file.\n");
    while (1) {
        scanf(" %c", &action);
        if (action == 'a') {
            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter the time (HH:MM): ");
            scanf("%s", time);
            printf("Enter the diary content: ");
            scanf(" %[^\n]s", content);
            add_entry(&diary, date, time, content);
        } else if (action == 'p') {
            print_diary(&diary);
        } else if (action == 's') {
            save_diary(&diary);
        } else {
            printf("Invalid action. Please enter 'a', 'p', or 's'.\n");
        }
    }
    return 0;
}