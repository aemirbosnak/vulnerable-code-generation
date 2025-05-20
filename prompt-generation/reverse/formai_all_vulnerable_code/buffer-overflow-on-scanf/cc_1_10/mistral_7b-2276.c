//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

struct Entry {
    char title[128];
    char content[128];
    time_t timestamp;
};

struct Entry diary[MAX_ENTRIES];
int currentEntry = 0;

void saveEntry(const char* title, const char* content) {
    if (currentEntry >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    strcpy(diary[currentEntry].title, title);
    strcpy(diary[currentEntry].content, content);
    diary[currentEntry].timestamp = time(NULL);

    currentEntry++;
}

void loadEntry(int index) {
    if (index < 0 || index >= currentEntry) {
        printf("Invalid entry index.\n");
        return;
    }

    printf("\nTitle: %s\n", diary[index].title);
    printf("Content:\n%s\n", diary[index].content);
    printf("Timestamp: %s\n", ctime(&diary[index].timestamp));
}

int main() {
    char title[128];
    char content[128];

    while (1) {
        printf("\nPeaceful Digital Diary\n");
        printf("-----------------------\n");
        printf("1. Write a new entry\n");
        printf("2. Read an entry\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^\n]s", content);
                saveEntry(title, content);
                printf("Entry saved.\n");
                break;

            case 2:
                printf("Enter entry index: ");
                int index;
                scanf("%d", &index);
                loadEntry(index);
                break;

            case 3:
                printf("Goodbye.\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}