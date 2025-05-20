//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY 100

struct Entry {
    char title[50];
    char description[200];
    time_t timestamp;
};

void saveEntry(struct Entry* entries, int index) {
    struct Entry* entry = &entries[index];
    time_t rawtime;
    struct tm * timeinfo;

    printf("Enter title: ");
    fgets(entry->title, sizeof(entry->title), stdin);
    entry->title[strcspn(entry->title, "\n")] = '\0';

    printf("Enter description: ");
    fgets(entry->description, sizeof(entry->description), stdin);
    entry->description[strcspn(entry->description, "\n")] = '\0';

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    entry->timestamp = rawtime;
    strftime(entry->title + strlen(entry->title), sizeof(entry->title) - strlen(entry->title) - 1, "%Y-%m-%d %H:%M:%S", timeinfo);
}

void loadEntry(struct Entry* entries, int index) {
    printf("\nTitle: %s", entries[index].title);
    printf("\nDescription: %s", entries[index].description);
    printf("\nTimestamp: %s", ctime(&entries[index].timestamp));
}

int main() {
    struct Entry entries[MAX_ENTRY];
    int currentIndex = 0;
    int choice;

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. New Entry\n");
        printf("2. View Entry\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (currentIndex < MAX_ENTRY) {
                    saveEntry(entries, currentIndex);
                    currentIndex++;
                } else {
                    printf("Maximum entries reached.\n");
                }
                break;
            case 2:
                if (currentIndex > 0) {
                    loadEntry(entries, currentIndex - 1);
                } else {
                    printf("No previous entry.\n");
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}