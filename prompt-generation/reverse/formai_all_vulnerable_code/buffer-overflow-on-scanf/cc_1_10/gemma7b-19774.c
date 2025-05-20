//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct DiaryEntry {
    char title[MAX_SIZE];
    char content[MAX_SIZE];
    struct DiaryEntry* next;
} DiaryEntry;

DiaryEntry* insertEntry(DiaryEntry* head) {
    DiaryEntry* newEntry = (DiaryEntry*)malloc(sizeof(DiaryEntry));
    newEntry->next = NULL;

    printf("Enter title: ");
    scanf("%s", newEntry->title);

    printf("Enter content: ");
    scanf("%s", newEntry->content);

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void displayEntries(DiaryEntry* head) {
    while (head) {
        printf("Title: %s\n", head->title);
        printf("Content: %s\n", head->content);
        printf("\n");
        head = head->next;
    }
}

int main() {
    DiaryEntry* head = NULL;

    while (1) {
        int choice;

        printf("1. Insert Entry\n");
        printf("2. Display Entries\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertEntry(head);
                break;
            case 2:
                displayEntries(head);
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}