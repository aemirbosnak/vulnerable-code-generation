//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10
#define ENTRY_SIZE 256
#define DAYS_IN_WEEK 7

typedef struct {
    char title[ENTRY_SIZE];
    char content[ENTRY_SIZE];
    time_t timestamp;
} Entry;

Entry diary[MAX_ENTRIES];
int current_entry = 0;

void print_menu() {
    printf("\n------------------\n");
    printf("| Starry Night Diary |\n");
    printf("------------------\n");
    printf("| Press 1 to Write |\n");
    printf("| Press 2 to Read  |\n");
    printf("| Press 3 to Quit  |\n");
    printf("------------------\n");
}

void write_entry() {
    if (current_entry >= MAX_ENTRIES) {
        printf("Diary is full. Please delete some entries to write new ones.\n");
        return;
    }

    printf("Title: ");
    fgets(diary[current_entry].title, ENTRY_SIZE, stdin);
    diary[current_entry].title[strcspn(diary[current_entry].title, "\n")] = 0;

    printf("Content: ");
    fgets(diary[current_entry].content, ENTRY_SIZE, stdin);
    diary[current_entry].content[strcspn(diary[current_entry].content, "\n")] = 0;

    diary[current_entry].timestamp = time(NULL);

    printf("Entry saved successfully.\n");
    current_entry++;
}

void read_entry() {
    if (current_entry == 0) {
        printf("No entries to read.\n");
        return;
    }

    printf("Title: %s\n", diary[current_entry - 1].title);
    printf("Content: %s\n", diary[current_entry - 1].content);
    printf("Timestamp: %s", ctime(&(diary[current_entry - 1].timestamp)));
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                write_entry();
                break;
            case 2:
                read_entry();
                break;
            case 3:
                printf("Goodbye! Have a nice day.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}