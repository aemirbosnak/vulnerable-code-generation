//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char content[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char input[MAX_ENTRY_LENGTH];
    printf("Enter your diary entry:\n");
    fgets(input, MAX_ENTRY_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    char timestamp_str[26];
    strftime(timestamp_str, 26, "%Y-%m-%d %H:%M:%S", tm_now);

    strcpy(entries[num_entries].content, input);
    entries[num_entries].timestamp = now;
    num_entries++;

    printf("Entry added successfully at %s.\n", timestamp_str);
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries yet.\n");
        return;
    }

    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].content);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter a keyword to search for:\n");
    scanf("%s", keyword);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].content, keyword)) {
            printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].content);
        }
    }
}

int main() {
    setbuf(stdout, NULL);

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}