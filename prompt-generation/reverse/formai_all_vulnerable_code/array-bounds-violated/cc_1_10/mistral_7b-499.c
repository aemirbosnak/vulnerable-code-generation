//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_ENTRIES 10
#define MAX_CHAR 500

typedef struct {
    char title[50];
    char content[MAX_CHAR];
} DiaryEntry;

void displayMenu() {
    printf("\nDigital Diary Menu\n");
    printf("1. Create new entry\n");
    printf("2. Read entry\n");
    printf("3. Delete entry\n");
    printf("4. List entries\n");
    printf("5. Exit\n");
}

int getFreeIndex(DiaryEntry diary[]) {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i].title[0] == '\0') {
            return i;
        }
    }
    return -1;
}

bool isTitleValid(char title[]) {
    int len = strlen(title);
    if (len >= 1 && len <= 49) {
        for (int i = 0; i < len; i++) {
            if (!isalpha(title[i]) && title[i] != ' ') {
                return false;
            }
        }
        return true;
    }
    return false;
}

void createEntry(DiaryEntry diary[], int index) {
    printf("Enter title: ");
    scanf("%s", diary[index].title);
    printf("Enter content: ");
    scanf(" %[^\n]", diary[index].content);
}

void printEntry(DiaryEntry entry) {
    printf("\nTitle: %s\nContent:\n%s\n", entry.title, entry.content);
}

void listEntries(DiaryEntry diary[]) {
    printf("\nList of Entries:\n");
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i].title[0] != '\0') {
            printEntry(diary[i]);
        }
    }
}

void deleteEntry(DiaryEntry diary[], int index) {
    strcpy(diary[index].title, "");
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int choice, index;

    while (true) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                index = getFreeIndex(diary);
                if (index != -1) {
                    createEntry(diary, index);
                } else {
                    printf("No space left in the diary.\n");
                }
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                if (diary[index].title[0] != '\0') {
                    printEntry(diary[index]);
                } else {
                    printf("No such entry.\n");
                }
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &index);
                if (diary[index].title[0] != '\0') {
                    deleteEntry(diary, index);
                } else {
                    printf("No such entry.\n");
                }
                break;
            case 4:
                listEntries(diary);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}