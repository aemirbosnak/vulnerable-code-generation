//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char date[11];
    char title[51];
    char content[201];
};

void add_entry(struct entry entries[], int num_entries) {
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", entries[num_entries].date);

    printf("Enter the title: ");
    scanf("%s", entries[num_entries].title);

    printf("Enter the content:\n");
    fgets(entries[num_entries].content, 201, stdin);

    num_entries++;
}

void view_entries(struct entry entries[], int num_entries) {
    printf("Viewing entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n%s\n", entries[i].date, entries[i].title, entries[i].content);
    }
}

void search_entries(struct entry entries[], int num_entries) {
    char keyword[51];

    printf("Enter a keyword to search for: ");
    scanf("%s", keyword);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].content, keyword)) {
            printf("%s - %s\n%s\n", entries[i].date, entries[i].title, entries[i].content);
        }
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Maximum number of entries reached.\n");
                break;
            }
            add_entry(entries, num_entries);
            break;
        case 2:
            if (num_entries == 0) {
                printf("No entries found.\n");
                break;
            }
            view_entries(entries, num_entries);
            break;
        case 3:
            if (num_entries == 0) {
                printf("No entries found.\n");
                break;
            }
            search_entries(entries, num_entries);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}