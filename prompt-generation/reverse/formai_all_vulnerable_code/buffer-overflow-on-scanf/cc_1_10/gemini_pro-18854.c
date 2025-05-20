//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char title[50];
    char content[256];
    int date; // in the format YYYYMMDD
} Entry;

Entry entries[100];
int num_entries = 0;

void add_entry() {
    printf("Enter the title of your entry: ");
    scanf("%s", entries[num_entries].title);
    printf("Enter the content of your entry: ");
    scanf("%s", entries[num_entries].content);
    printf("Enter the date of your entry (YYYYMMDD): ");
    scanf("%d", &entries[num_entries].date);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Title: %s\n", entries[i].title);
        printf("Content: %s\n", entries[i].content);
        printf("Date: %d\n\n", entries[i].date);
    }
}

void search_entries() {
    char search_term[50];
    printf("Enter the search term: ");
    scanf("%s", search_term);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, search_term) != NULL || strstr(entries[i].content, search_term) != NULL) {
            printf("Title: %s\n", entries[i].title);
            printf("Content: %s\n", entries[i].content);
            printf("Date: %d\n\n", entries[i].date);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add an entry\n");
        printf("2. Print all entries\n");
        printf("3. Search entries\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                print_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}