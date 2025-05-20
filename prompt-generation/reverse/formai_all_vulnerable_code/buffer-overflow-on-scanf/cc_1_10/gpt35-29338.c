//FormAI DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_SIZE 1000

struct DiaryEntry {
    char date[11];
    char text[MAX_ENTRY_SIZE];
    struct DiaryEntry *next;
};

struct Diary {
    struct DiaryEntry *head;
    struct DiaryEntry *tail;
};

void displayMenu() {
    printf("\nWelcome to your Digital Diary\n");
    printf("Select an option:\n");
    printf("1. Add an entry\n");
    printf("2. View all entries\n");
    printf("3. Delete an entry\n");
    printf("4. Exit\n");
}

void getDate(char *date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

void addEntry(struct Diary *diary) {
    char date[11];
    getDate(date);
    struct DiaryEntry *entry = malloc(sizeof(struct DiaryEntry));
    strcpy(entry->date, date);
    printf("Enter your diary entry (max %d characters):\n", MAX_ENTRY_SIZE-1);
    fgets(entry->text, MAX_ENTRY_SIZE, stdin);
    // remove trailing newline character
    entry->text[strcspn(entry->text, "\n")] = '\0';
    entry->next = NULL;
    if (diary->head == NULL) {
        diary->head = entry;
        diary->tail = entry;
    } else {
        diary->tail->next = entry;
        diary->tail = entry;
    }
    printf("Entry added successfully!\n");
}

void printEntry(struct DiaryEntry *entry) {
    printf("- Date: %s\n", entry->date);
    printf("- Entry: %s\n", entry->text);
}

void viewEntries(struct Diary *diary) {
    if (diary->head == NULL) {
        printf("Your diary is empty!\n");
    } else {
        printf("All entries in your diary:\n");
        struct DiaryEntry *current = diary->head;
        while (current != NULL) {
            printEntry(current);
            current = current->next;
        }
    }
}

void deleteEntry(struct Diary *diary) {
    if (diary->head == NULL) {
        printf("Your diary is empty!\n");
    } else {
        printf("Enter the date of the entry you want to delete (YYYY-MM-DD):\n");
        char date[11];
        fgets(date, 11, stdin);
        struct DiaryEntry *current = diary->head;
        struct DiaryEntry *previous = NULL;
        while (current != NULL && strcmp(current->date, date) != 0) {
            previous = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("No entry found for that date!\n");
        } else {
            if (previous == NULL) {
                diary->head = current->next;
            } else {
                previous->next = current->next;
            }
            if (current == diary->tail) {
                diary->tail = previous;
            }
            free(current);
            printf("Entry deleted successfully!\n");
        }
    }
}

int main() {
    struct Diary diary = { NULL, NULL };
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // remove trailing newline character
        switch (choice) {
            case 1:
                addEntry(&diary);
                break;
            case 2:
                viewEntries(&diary);
                break;
            case 3:
                deleteEntry(&diary);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}