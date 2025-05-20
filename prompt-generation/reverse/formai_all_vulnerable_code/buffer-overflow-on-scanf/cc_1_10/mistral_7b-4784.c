//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10
#define ENTRY_SIZE (sizeof(struct Entry) + 16) // 16 bytes for title

typedef struct Entry {
    char title[32];
    char content[128];
    time_t timestamp;
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void print_entry(const Entry *entry) {
    printf("%s (%s):\n", entry->title, ctime(&entry->timestamp));
    printf("%s\n", entry->content);
    printf("\n");
}

int add_entry(const char *title, const char *content) {
    if (num_entries >= MAX_ENTRIES) {
        fprintf(stderr, "Diary is full.\n");
        return -1;
    }

    Entry *entry = &diary[num_entries];
    strncpy(entry->title, title, sizeof(entry->title) - 1);
    strncpy(entry->content, content, sizeof(entry->content) - 1);
    entry->timestamp = time(NULL);
    num_entries++;

    return 0;
}

void list_entries() {
    for (int i = 0; i < num_entries; i++) {
        print_entry(&diary[i]);
    }
}

int main() {
    char title[32];
    char content[128];

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n");
        printf("2. List entries\n");
        printf("3. Quit\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Title: ");
                scanf("%s", title);
                printf("Content: ");
                scanf("%[^\n]s", content);
                add_entry(title, content);
                break;
            case 2:
                list_entries();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}