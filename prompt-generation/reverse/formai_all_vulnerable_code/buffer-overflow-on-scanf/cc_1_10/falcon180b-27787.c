//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[num_entries].date);

    printf("Enter entry:\n");
    fgets(diary[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    diary[num_entries].entry[strcspn(diary[num_entries].entry, "\n")] = '\0';

    num_entries++;
}

void view_entries() {
    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];

    printf("Enter keyword to search for: ");
    scanf("%s", keyword);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].entry, keyword)) {
            printf("%s - %s\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    printf("Digital Diary\n");

    while (1) {
        printf("\n1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        int choice;
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
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}