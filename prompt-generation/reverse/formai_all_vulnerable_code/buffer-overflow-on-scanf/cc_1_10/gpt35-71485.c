//FormAI DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct entry {
    char title[50];
    char content[500];
    char date[20];
    struct entry *next;
};

struct entry *head = NULL, *tail = NULL;

void addEntry() {
    struct entry *newEntry = (struct entry*)malloc(sizeof(struct entry));

    printf("\nEnter title of the entry: ");
    scanf("%s", newEntry->title);
    fflush(stdin);

    printf("Enter the content of the entry: ");
    scanf("%[^\n]s", newEntry->content);
    fflush(stdin);

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(newEntry->date, "%02d/%02d/%04d", tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900);

    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
        tail = newEntry;
        printf("\nEntry added successfully!\n");
    } else {
        tail->next = newEntry;
        tail = newEntry;
        printf("\nEntry added successfully!\n");
    }
}

void viewAllEntries() {
    if (head == NULL) {
        printf("\nNo entries found!\n");
        return;
    }

    struct entry *current = head;

    while (current != NULL) {
        printf("\n\nTitle: %s\n", current->title);
        printf("Content: %s\n", current->content);
        printf("Date: %s\n", current->date);
        current = current->next;
    }
}

void searchEntry() {
    char query[50];
    struct entry *current = head;
    int found = 0;

    printf("\nEnter title to search for: ");
    scanf("%s", query);

    while (current != NULL) {
        if (strcmp(current->title, query) == 0) {
            printf("\nTitle: %s\n", current->title);
            printf("Content: %s\n", current->content);
            printf("Date: %s\n", current->date);
            found = 1;
        }

        current = current->next;
    }

    if (!found) {
        printf("\nNo entries found with that title!\n");
    }
}

void deleteEntry() {
    char query[50];
    struct entry *current = head, *prev = NULL;
    int found = 0;

    printf("\nEnter title of entry to delete: ");
    scanf("%s", query);

    while (current != NULL) {
        if (strcmp(current->title, query) == 0) {
            if (current == head) {
                head = head->next;
            } else if (current == tail) {
                tail = prev;
                prev->next = NULL;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("\nEntry deleted successfully!\n");
            found = 1;
            break;
        }

        prev = current;
        current = current->next;
    }

    if (!found) {
        printf("\nNo entries found with that title!\n");
    }
}

int main() {
    int option = 0;

    printf("Welcome to Sherlock Holmes' digital diary!\n");

    while (1) {
        printf("\n\nSelect an option:\n");
        printf("1. Add diary entry\n");
        printf("2. View all entries\n");
        printf("3. Search for a specific entry\n");
        printf("4. Delete an entry\n");
        printf("5. Exit\n\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                addEntry();
                break;
            case 2:
                viewAllEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid option!\n");
                break;
        }
    }

    return 0;
}