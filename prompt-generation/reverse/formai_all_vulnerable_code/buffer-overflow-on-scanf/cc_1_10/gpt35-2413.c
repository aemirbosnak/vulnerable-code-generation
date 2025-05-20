//FormAI DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct DiaryEntry {
    char date[12];
    char title[50];
    char body[1000];
    struct DiaryEntry* next;
};

int isEmpty(struct DiaryEntry* diaryHead) {
    return diaryHead == NULL;
}

void printDiary(struct DiaryEntry* diaryHead) {
    if (diaryHead == NULL) {
        printf("Empty diary!\n");
    } else {
        struct DiaryEntry* currentEntry = diaryHead;
        while (currentEntry != NULL) {
            printf("Date: %s\nTitle: %s\nBody: %s\n", currentEntry->date, currentEntry->title, currentEntry->body);
            currentEntry = currentEntry->next;
            printf("----------------------------\n");
        }
    }
}

struct DiaryEntry* createEntry(struct DiaryEntry* diaryHead) {
    struct DiaryEntry* newEntry = malloc(sizeof(struct DiaryEntry));
    printf("Enter the date in the format MM/DD/YYYY: ");
    scanf("%s", newEntry->date);
    getchar(); // Capture the enter key
    printf("Enter the title of the entry: ");
    fgets(newEntry->title, 50, stdin);
    newEntry->title[strcspn(newEntry->title, "\n")] = '\0'; // Remove new line character from fgets input
    printf("Enter the body of the entry: ");
    fgets(newEntry->body, 1000, stdin);
    newEntry->body[strcspn(newEntry->body, "\n")] = '\0'; // Remove new line character from fgets input
    newEntry->next = diaryHead;
    diaryHead = newEntry;
    return diaryHead;
}

struct DiaryEntry* deleteEntry(struct DiaryEntry* diaryHead, char* date) {
    if (diaryHead == NULL) {
        printf("Empty diary, no entries to delete.\n");
        return diaryHead;
    } else if (strcmp(diaryHead->date, date) == 0) {
        struct DiaryEntry* temp = diaryHead;
        diaryHead = diaryHead->next;
        free(temp);
        printf("Entry with date %s has been deleted.\n", date);
        return diaryHead;
    } else {
        struct DiaryEntry* previous = diaryHead;
        struct DiaryEntry* current = diaryHead->next;
        while (current != NULL) {
            if (strcmp(current->date, date) == 0) {
                previous->next = current->next;
                free(current);
                printf("Entry with date %s has been deleted.\n", date);
                return diaryHead;
            } else {
                previous = current;
                current = current->next;
            }
        }
        printf("No entry found with date %s.\n", date);
        return diaryHead;
    }
}

void searchByDate(struct DiaryEntry* diaryHead, char* date) {
    if (diaryHead == NULL) {
        printf("Empty diary, no entries to search.\n");
    } else {
        struct DiaryEntry* currentEntry = diaryHead;
        int found = 0;
        while (currentEntry != NULL) {
            if (strcmp(currentEntry->date, date) == 0) {
                printf("Date: %s\nTitle: %s\nBody: %s\n", currentEntry->date, currentEntry->title, currentEntry->body);
                found = 1;
                break;
            }
            currentEntry = currentEntry->next;
        }
        if (!found) {
            printf("No entry found with date %s.\n", date);
        }
    }
}

int main() {
    struct DiaryEntry* diaryHead = NULL;
    printf("*** Welcome to Digital Diary ***\n\n");

    while (1) {
        printf("Enter your choice:\n1. Add new entry\n2. Delete entry\n3. Search by date\n4. Print all entries\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        getchar(); // Capture enter key after scanf input

        switch(choice) {
            case 1:
                diaryHead = createEntry(diaryHead);
                break;
            case 2:
                printf("Enter the date of the entry you want to delete: ");
                char inputDate[12];
                scanf("%s", inputDate);
                getchar(); // Capture enter key after scanf input
                diaryHead = deleteEntry(diaryHead, inputDate);
                break;
            case 3:
                printf("Enter the date of the entry you want to search: ");
                char searchDate[12];
                scanf("%s", searchDate);
                getchar(); // Capture enter key after scanf input
                searchByDate(diaryHead, searchDate);
                break;
            case 4:
                printDiary(diaryHead);
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid input, try again.\n");
        }
    }

    return 0;
}