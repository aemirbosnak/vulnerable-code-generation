//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define TITLE_LENGTH 50
#define CONTENT_LENGTH 512

typedef struct {
    char title[TITLE_LENGTH];
    char content[CONTENT_LENGTH];
    time_t date;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void display_menu() {
    printf("================================\n");
    printf("  Welcome to the Medieval Diary  \n");
    printf("================================\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Search an entry by title\n");
    printf("4. Delete an entry\n");
    printf("5. Exit the program\n");
    printf("================================\n");
    printf("Choose thine fate (1-5): ");
}

void add_entry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Alas! The diary is full, and cannot hold more entries!\n");
        return;
    }

    DiaryEntry newEntry;
    printf("Enter the title of thine entry: ");
    scanf(" %[^\n]", newEntry.title);
    printf("Enter thine thoughts: ");
    scanf(" %[^\n]", newEntry.content);
    newEntry.date = time(NULL);

    diary[entryCount++] = newEntry;
    printf("Thy entry hath been added to the tome of memories.\n");
}

void view_entries() {
    if (entryCount == 0) {
        printf("The tome is empty! No tales to recount...\n");
        return;
    }

    printf("Behold! The entries in thy diary:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n", diary[i].content);
        printf("Date: %s", ctime(&diary[i].date));
        printf("--------------------------------\n");
    }
}

void search_entry() {
    char title[TITLE_LENGTH];
    printf("Enter the title of the entry ye seek: ");
    scanf(" %[^\n]", title);
    
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].title, title) == 0) {
            printf("Entry Found!\n");
            printf("Title: %s\n", diary[i].title);
            printf("Content: %s\n", diary[i].content);
            printf("Date: %s", ctime(&diary[i].date));
            return;
        }
    }

    printf("Alas! There be no entry with that title.\n");
}

void delete_entry() {
    char title[TITLE_LENGTH];
    printf("Enter the title of the entry to be purged: ");
    scanf(" %[^\n]", title);
    
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].title, title) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                diary[j] = diary[j + 1];
            }
            entryCount--;
            printf("The entry hath been vanquished from the tome.\n");
            return;
        }
    }

    printf("Alas! There be no entry bearing that title.\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("Farewell! Until we meet again.\n");
                exit(0);
            default:
                printf("Pray, choose a valid option!\n");
                break;
        }
    }

    return 0;
}