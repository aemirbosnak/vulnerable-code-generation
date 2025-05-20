//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIARY_ENTRIES 100

typedef struct {
    char date[11];
    char time[9];
    char content[256];
} diary_entry;

void print_diary_entry(diary_entry* entry) {
    printf("%s %s\n%s\n\n", entry->date, entry->time, entry->content);
}

void add_diary_entry(diary_entry* entry, char* date, char* time, char* content) {
    strcpy(entry->date, date);
    strcpy(entry->time, time);
    strcpy(entry->content, content);
}

int main() {
    diary_entry entries[MAX_DIARY_ENTRIES];
    int num_entries = 0;

    char command;
    char date[11];
    char time[9];
    char content[256];

    while (1) {
        printf("Enter command (A for add, D for delete, Q for quit): ");
        scanf("%c", &command);

        if (command == 'A') {
            printf("Enter date (mm/dd/yyyy): ");
            scanf("%s", date);
            printf("Enter time (hh:mm): ");
            scanf("%s", time);
            printf("Enter content: ");
            scanf("%s", content);

            add_diary_entry(&entries[num_entries], date, time, content);
            num_entries++;
        } else if (command == 'D') {
            printf("Enter entry number to delete: ");
            scanf("%d", &num_entries);
            if (num_entries < 0 || num_entries >= MAX_DIARY_ENTRIES) {
                printf("Invalid entry number\n");
                continue;
            }

            for (int i = num_entries; i < MAX_DIARY_ENTRIES - 1; i++) {
                entries[i] = entries[i + 1];
            }
            num_entries--;
        } else if (command == 'Q') {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        print_diary_entry(&entries[i]);
    }

    return 0;
}