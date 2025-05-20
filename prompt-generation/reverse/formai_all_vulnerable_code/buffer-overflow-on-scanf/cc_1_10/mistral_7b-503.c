//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 10

typedef struct {
    char title[50];
    char content[200];
    time_t timestamp;
} DiaryEntry;

void save_entry(DiaryEntry entries[DIARY_SIZE], int *index, const char *title, const char *content) {
    if (*index >= DIARY_SIZE) {
        printf("Diary is full.\n");
        return;
    }
    strcpy(entries[*index].title, title);
    strcpy(entries[*index].content, content);
    entries[*index].timestamp = time(NULL);
    (*index)++;
}

void load_entry(DiaryEntry entries[DIARY_SIZE], int index, char title[50], char content[200]) {
    if (index >= DIARY_SIZE || entries[index].timestamp == 0) {
        printf("Invalid index or empty entry.\n");
        return;
    }
    strcpy(title, entries[index].title);
    strcpy(content, entries[index].content);
}

void print_entry(const DiaryEntry entry) {
    printf("Title: %s\n", entry.title);
    printf("Content: %s\n", entry.content);
    printf("Timestamp: %s\n", ctime(&entry.timestamp));
}

int main(void) {
    DiaryEntry diary[DIARY_SIZE] = {0};
    int index = 0;
    char title[50], content[200];

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. New Entry\n");
        printf("2. Show Last Entry\n");
        printf("3. Show All Entries\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^\n]s", content);
                save_entry(diary, &index, title, content);
                break;
            case 2:
                if (index > 0) {
                    index--;
                    DiaryEntry last_entry = diary[index];
                    print_entry(last_entry);
                } else {
                    printf("No previous entry.\n");
                }
                break;
            case 3:
                if (index > 0) {
                    printf("Entries:\n");
                    for (int i = 0; i < index; i++) {
                        DiaryEntry entry = diary[i];
                        print_entry(entry);
                    }
                } else {
                    printf("No entries yet.\n");
                }
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}