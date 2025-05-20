//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct Entry {
    char title[MAX_CHAR];
    char content[MAX_CHAR];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
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

void displayEntries(Entry* head) {
    while (head) {
        printf("Title: %s\n", head->title);
        printf("Content: %s\n", head->content);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Entry* head = NULL;

    while (1) {
        char choice;

        printf("Enter 'a' to add an entry, 'd' to display entries, or 'q' to quit: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'a':
                head = insertEntry(head);
                break;
            case 'd':
                displayEntries(head);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}