//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

struct entry {
    char date[11];
    char mood[11];
    char content[1001];
};

void add_entry(struct entry entries[], int num_entries, char date[], char mood[], char content[]) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Digital diary is full!\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].mood, mood);
    strcpy(entries[num_entries].content, content);

    num_entries++;
}

void view_entries(struct entry entries[], int num_entries) {
    if (num_entries == 0) {
        printf("Digital diary is empty.\n");
        return;
    }

    printf("Digital diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s - %s\n", entries[i].date, entries[i].mood, entries[i].content);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case '1': {
                char date[11];
                char mood[11];
                char content[1001];

                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);

                printf("Enter mood: ");
                scanf("%s", mood);

                printf("Enter content:\n");
                fgets(content, 1001, stdin);
                content[strcspn(content, "\n")] = '\0';

                add_entry(entries, num_entries, date, mood, content);
                break;
            }

            case '2': {
                view_entries(entries, num_entries);
                break;
            }

            case '3': {
                exit(0);
            }

            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}