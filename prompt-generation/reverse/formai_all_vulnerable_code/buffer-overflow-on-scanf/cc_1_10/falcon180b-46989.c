//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1024

struct entry {
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    time_t timestamp;
};

int num_entries = 0;
struct entry diary[MAX_ENTRIES];

void add_entry(char *title, char *content) {
    struct entry e;
    strncpy(e.title, title, MAX_ENTRY_LENGTH);
    strncpy(e.content, content, MAX_ENTRY_LENGTH);
    e.timestamp = time(NULL);
    diary[num_entries++] = e;
}

void print_entries() {
    printf("Digital Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n\n", diary[i].title, diary[i].content);
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Digital Diary!\n\n");
    printf("Please enter a username:\n");
    char username[MAX_ENTRY_LENGTH];
    scanf("%s", username);

    printf("Welcome, %s! Your diary is now ready.\n\n", username);

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. Print entries\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("What is your entry title?\n");
                char title[MAX_ENTRY_LENGTH];
                scanf("%s", title);
                printf("What is your entry content?\n");
                char content[MAX_ENTRY_LENGTH];
                scanf("%s", content);
                add_entry(title, content);
                printf("Entry added successfully!\n\n");
                break;
            case 2:
                print_entries();
                break;
            case 3:
                printf("Goodbye, %s! Your diary will be saved.\n\n", username);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}