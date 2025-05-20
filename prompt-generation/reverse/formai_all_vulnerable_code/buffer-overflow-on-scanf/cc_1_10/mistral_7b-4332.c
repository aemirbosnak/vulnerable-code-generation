//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 10

typedef struct DiaryEntry {
    char title[50];
    char content[200];
    time_t timestamp;
} DiaryEntry;

void saveEntry(DiaryEntry entries[DIARY_SIZE], int *count, char *title, char *content) {
    if (*count < DIARY_SIZE) {
        strcpy(entries[*count].title, title);
        strcpy(entries[*count].content, content);
        time(&entries[*count].timestamp);
        (*count)++;
    } else {
        printf("Diary is full.\n");
    }
}

void loadEntry(DiaryEntry entries[DIARY_SIZE], int index) {
    if (index >= 0 && index < DIARY_SIZE && entries[index].timestamp != 0) {
        printf("Title: %s\n", entries[index].title);
        printf("Content: %s\n", entries[index].content);
        printf("Timestamp: %s", ctime(&entries[index].timestamp));
    } else {
        printf("Invalid index.\n");
    }
}

void searchEntries(DiaryEntry entries[DIARY_SIZE], int count, char *keyword) {
    int i;
    for (i = 0; i < count; i++) {
        if (strstr(entries[i].title, keyword) != NULL || strstr(entries[i].content, keyword) != NULL) {
            loadEntry(entries, i);
        }
    }
    if (i == count) {
        printf("No entry found with the keyword: %s\n", keyword);
    }
}

int main() {
    DiaryEntry entries[DIARY_SIZE];
    int count = 0;
    char title[50], content[200], keyword[20];

    while (1) {
        printf("\n1. New Entry\n2. Show Latest Entry\n3. Search\n4. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^\n]", content);
                saveEntry(entries, &count, title, content);
                break;

            case 2:
                if (count > 0) {
                    loadEntry(entries, count - 1);
                } else {
                    printf("No entry yet.\n");
                }
                break;

            case 3:
                printf("Enter keyword: ");
                scanf("%s", keyword);
                searchEntries(entries, count, keyword);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}