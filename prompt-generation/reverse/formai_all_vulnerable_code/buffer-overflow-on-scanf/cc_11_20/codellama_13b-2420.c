//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DIARY_SIZE 1000

typedef struct {
    char date[11];
    char title[50];
    char content[MAX_DIARY_SIZE];
} DiaryEntry;

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;

    char command;
    char date[11];
    char title[50];
    char content[MAX_DIARY_SIZE];

    while (1) {
        printf("Enter command (a: add, d: delete, p: print, q: quit): ");
        scanf(" %c", &command);

        if (command == 'a') {
            printf("Enter date (YYYY-MM-DD): ");
            scanf(" %10s", date);
            printf("Enter title (max 50 characters): ");
            scanf(" %49s", title);
            printf("Enter content (max 1000 characters): ");
            scanf(" %999s", content);

            DiaryEntry entry = {date, title, content};
            entries[num_entries] = entry;
            num_entries++;
        } else if (command == 'd') {
            printf("Enter date to delete (YYYY-MM-DD): ");
            scanf(" %10s", date);

            for (int i = 0; i < num_entries; i++) {
                if (strcmp(entries[i].date, date) == 0) {
                    for (int j = i; j < num_entries - 1; j++) {
                        entries[j] = entries[j + 1];
                    }
                    num_entries--;
                    break;
                }
            }
        } else if (command == 'p') {
            printf("Enter date to print (YYYY-MM-DD): ");
            scanf(" %10s", date);

            for (int i = 0; i < num_entries; i++) {
                if (strcmp(entries[i].date, date) == 0) {
                    printf("%s - %s\n", entries[i].date, entries[i].title);
                    printf("%s\n", entries[i].content);
                    break;
                }
            }
        } else if (command == 'q') {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}