//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int num_entries = 0;
Entry diary[MAX_ENTRIES];

void add_entry() {
    if (num_entries == MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[num_entries].date, sizeof(diary[num_entries].date), "%Y-%m-%d %H:%M:%S", t);
    printf("Enter your diary entry:\n");
    fgets(diary[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    num_entries++;
    printf("Entry added.\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n", diary[i].date, diary[i].entry);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter keyword to search:\n");
    fgets(keyword, MAX_ENTRY_LENGTH, stdin);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].entry, keyword)!= NULL) {
            printf("%s\n%s\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}