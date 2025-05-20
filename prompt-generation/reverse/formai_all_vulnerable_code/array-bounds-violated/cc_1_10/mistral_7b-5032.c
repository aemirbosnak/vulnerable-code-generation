//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 100
#define ENTRY_SIZE 256

typedef struct {
    char title[ENTRY_SIZE];
    char content[ENTRY_SIZE];
    time_t timestamp;
} Entry;

Entry diary[DIARY_SIZE];
int current_entry = 0;

void create_entry() {
    time_t now = time(NULL);
    if (current_entry >= DIARY_SIZE) {
        printf("Diary is full.\n");
        return;
    }
    printf("Enter title for your entry: ");
    fgets(diary[current_entry].title, ENTRY_SIZE, stdin);
    diary[current_entry].title[strlen(diary[current_entry].title) - 1] = '\0';
    printf("Enter content for your entry: ");
    fgets(diary[current_entry].content, ENTRY_SIZE, stdin);
    diary[current_entry].timestamp = now;
    current_entry++;
}

void display_entry(int index) {
    if (index < 0 || index >= current_entry) {
        printf("Invalid entry index.\n");
        return;
    }
    printf("\nTitle: %s\n", diary[index].title);
    printf("Content: %s\n", diary[index].content);
    printf("Timestamp: %s", ctime(&diary[index].timestamp));
}

void list_entries() {
    if (current_entry == 0) {
        printf("No entries in the diary.\n");
        return;
    }
    int i;
    for (i = 0; i < current_entry; i++) {
        printf("\n%d. ", i + 1);
        display_entry(i);
    }
}

int main() {
    int choice;

    printf("\nWelcome to your Digital Diary.\n");
    printf("-----------------------------------\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Create a new entry\n");
        printf("2. Display an entry\n");
        printf("3. List all entries\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_entry();
                break;
            case 2: {
                int index;
                printf("Enter the index of the entry you want to display: ");
                scanf("%d", &index);
                display_entry(index);
                break;
            }
            case 3:
                list_entries();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}