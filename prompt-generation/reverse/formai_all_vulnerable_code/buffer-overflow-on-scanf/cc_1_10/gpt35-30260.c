//FormAI DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 1000

void add_entry(char *diary[]);
void view_entries(char *diary[]);
void search_entries(char *diary[]);

int main() {
    char *diary[MAX_ENTRIES];
    int menu_choice;

    while(1) {
        printf("\n\nDigital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entries\n");
        printf("4. Exit\n");
        printf("Enter menu choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1: add_entry(diary);
                    break;
            case 2: view_entries(diary);
                    break;
            case 3: search_entries(diary);
                    break;
            case 4: printf("Exiting program...\n");
                    exit(0);
            default: printf("Invalid menu choice!\n");
        }
    }

    return 0;
}

void add_entry(char *diary[]) {
    int i;
    char *entry = malloc(MAX_ENTRY_LEN);

    printf("Enter diary entry (maximum 1000 characters):\n");
    scanf(" %[^\n]s", entry);

    for (i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i] == NULL) {
            diary[i] = entry;
            printf("Entry added successfully.\n");
            break;
        }
    }

    if (i == MAX_ENTRIES)
        printf("Digital Diary is full. Cannot add any more entries.\n");
}

void view_entries(char *diary[]) {
    int i;

    printf("\n\nDigital Diary Entries\n");
    printf("----------------------\n");
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i] != NULL) {
            printf("%d. %s\n", i+1, diary[i]);
        }
    }
}

void search_entries(char *diary[]) {
    int i, j, found = 0;
    char search[MAX_ENTRY_LEN];

    printf("Enter search string:\n");
    scanf(" %[^\n]s", search);
    printf("\n\nSearch Results\n");
    printf("---------------\n");
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i] != NULL) {
            if (strstr(diary[i], search) != NULL) {
                printf("%d. %s\n", i+1, diary[i]);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No matching entries found.\n");
}