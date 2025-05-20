//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    char title[51];
    char content[501];
} DiaryEntry;

void print_diary_entry(DiaryEntry entry) {
    printf("%s: %s\n%s\n\n", entry.date, entry.title, entry.content);
}

void print_diary(DiaryEntry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        print_diary_entry(entries[i]);
    }
}

void add_diary_entry(DiaryEntry entries[], int *num_entries, char *date, char *title, char *content) {
    if (*num_entries >= MAX_ENTRIES) {
        printf("Error: Diary is full.\n");
        return;
    }

    strcpy(entries[*num_entries].date, date);
    strcpy(entries[*num_entries].title, title);
    strcpy(entries[*num_entries].content, content);
    (*num_entries)++;
}

void remove_diary_entry(DiaryEntry entries[], int *num_entries, char *date) {
    int i;
    for (i = 0; i < *num_entries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            break;
        }
    }

    if (i == *num_entries) {
        printf("Error: No entry found for date %s.\n", date);
        return;
    }

    for (int j = i; j < *num_entries - 1; j++) {
        entries[j] = entries[j + 1];
    }

    (*num_entries)--;
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;

    char command[20];
    char date[11];
    char title[51];
    char content[501];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter date: ");
            scanf("%s", date);
            printf("Enter title: ");
            scanf("%s", title);
            printf("Enter content: ");
            scanf("%s", content);
            add_diary_entry(entries, &num_entries, date, title, content);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter date: ");
            scanf("%s", date);
            remove_diary_entry(entries, &num_entries, date);
        } else if (strcmp(command, "print") == 0) {
            print_diary(entries, num_entries);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}