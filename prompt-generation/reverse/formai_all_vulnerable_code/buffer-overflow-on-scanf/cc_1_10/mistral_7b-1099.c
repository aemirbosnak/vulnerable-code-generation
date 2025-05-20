//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10
#define ENTRY_SIZE 256

typedef struct {
    char title[ENTRY_SIZE];
    char content[ENTRY_SIZE];
    time_t timestamp;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int num_entries = 0;

void save_entry(char* title, char* content) {
    if (num_entries >= MAX_ENTRIES) {
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("Shocked! The diary is full!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        return;
    }

    strcpy(entries[num_entries].title, title);
    strcpy(entries[num_entries].content, content);
    entries[num_entries].timestamp = time(NULL);

    num_entries++;
}

void load_entry(int index) {
    if (index >= 0 && index < num_entries) {
        printf("--------------------------------------------------------\n");
        printf("| Entry #%d |\n", index + 1);
        printf("--------------------------------------------------------\n");
        printf("| Title: %s |\n", entries[index].title);
        printf("| Content: %s |\n", entries[index].content);
        printf("| Timestamp: %s |\n", ctime(&entries[index].timestamp));
        printf("--------------------------------------------------------\n");
    } else {
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("Shocked! The index is out of bounds!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
}

int main() {
    int choice;
    char title[ENTRY_SIZE], content[ENTRY_SIZE];

    while (1) {
        printf("\n--- Digital Diary ---\n");
        printf("1. Save an entry\n");
        printf("2. Load an entry\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the title of the entry: ");
                scanf("%s", title);
                printf("Enter the content of the entry: ");
                scanf("%[^\n]s", content);

                save_entry(title, content);
                break;
            case 2:
                printf("Enter the index of the entry to load: ");
                scanf("%d", &choice);
                load_entry(choice - 1);
                break;
            case 3:
                exit(0);
            default:
                printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                printf("Shocked! The choice is invalid!\n");
                printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                break;
        }
    }

    return 0;
}