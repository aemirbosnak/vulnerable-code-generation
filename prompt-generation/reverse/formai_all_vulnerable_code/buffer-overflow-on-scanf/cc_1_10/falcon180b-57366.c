//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strncpy(diary[num_entries].date, date, 20);
    strncpy(diary[num_entries].entry, entry, MAX_ENTRY_LENGTH);
    num_entries++;
}

void print_entries() {
    printf("Digital Diary\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

void search_entries(char* keyword) {
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].entry, keyword)) {
            printf("%s - %s\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    char keyword[MAX_ENTRY_LENGTH];

    printf("Welcome to Digital Diary!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add entry\n");
        printf("2. Print entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");

        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("\nEnter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("\nEnter entry: ");
                scanf("%s", entry);
                add_entry(date, entry);
                printf("\nEntry added successfully!\n");
                break;
            case '2':
                printf("\nDigital Diary\n");
                print_entries();
                break;
            case '3':
                printf("\nEnter keyword: ");
                scanf("%s", keyword);
                search_entries(keyword);
                break;
            case '4':
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}