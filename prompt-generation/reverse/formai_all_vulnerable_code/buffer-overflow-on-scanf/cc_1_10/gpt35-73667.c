//FormAI DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10
#define MAX_ENTRY_SIZE 500

struct Entry {
    char date[20];
    char text[MAX_ENTRY_SIZE];
};

struct Diary {
    int count;
    struct Entry entries[MAX_ENTRIES];
};

void displayMenu() {
    printf("Digital Diary\n");
    printf("1. Add Entry\n");
    printf("2. Display All Entries\n");
    printf("3. Search for Entry\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void addEntry(struct Diary *diary) {
    if(diary->count == MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    struct Entry newEntry;
    time_t now = time(NULL);
    strftime(newEntry.date, sizeof(newEntry.date), "%Y-%m-%d %H:%M:%S", localtime(&now));
    printf("Enter your text (max %d characters): ", MAX_ENTRY_SIZE);
    fgets(newEntry.text, sizeof(newEntry.text), stdin);
    strtok(newEntry.text, "\n");
    diary->entries[diary->count++] = newEntry;
    printf("Entry added successfully!\n");
}

void displayAllEntries(struct Diary *diary) {
    if(diary->count == 0) {
        printf("Diary is empty!\n");
        return;
    }

    for(int i = 0; i < diary->count; i++) {
        printf("%s : %s\n", diary->entries[i].date, diary->entries[i].text);
    }
}

void searchEntry(struct Diary *diary) {
    if(diary->count == 0) {
        printf("Diary is empty!\n");
        return;
    }

    printf("Enter text to search: ");
    char searchQuery[MAX_ENTRY_SIZE];
    fgets(searchQuery, sizeof(searchQuery), stdin);
    strtok(searchQuery, "\n");

    int count = 0;
    for(int i = 0; i < diary->count; i++) {
        if(strstr(diary->entries[i].text, searchQuery) != NULL) {
            printf("%s : %s\n", diary->entries[i].date, diary->entries[i].text);
            count++;
        }
    }

    if(count == 0) {
        printf("No matching entries found!\n");
    }
}

int main() {
    struct Diary diary = {0};

    while(1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 1:
                addEntry(&diary);
                break;
            case 2:
                displayAllEntries(&diary);
                break;
            case 3:
                searchEntry(&diary);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}