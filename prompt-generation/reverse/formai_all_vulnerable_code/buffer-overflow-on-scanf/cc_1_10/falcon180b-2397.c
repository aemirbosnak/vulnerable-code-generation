//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[num_entries].date, 20, "%Y-%m-%d", t);
    strftime(diary[num_entries].time, 20, "%H:%M:%S", t);
    printf("Enter your entry:\n");
    fgets(diary[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    num_entries++;
}

void view_entries() {
    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].entry);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter a keyword to search for:\n");
    fgets(keyword, MAX_ENTRY_LENGTH, stdin);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].entry, keyword)!= NULL) {
            printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
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
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}