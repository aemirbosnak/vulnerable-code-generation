//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char date[11];
    char title[51];
    char content[1024];
} Entry;

Entry diary[100];
int num_entries = 0;

void add_entry() {
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", diary[num_entries].date);

    printf("Enter the title: ");
    scanf(" %[^\n]", diary[num_entries].title);

    printf("Enter the content: ");
    scanf(" %[^\n]", diary[num_entries].content);

    num_entries++;
}

void list_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].title);
    }
}

void view_entry() {
    char date[11];

    printf("Enter the date of the entry you want to view: ");
    scanf("%s", date);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("Date: %s\n", diary[i].date);
            printf("Title: %s\n", diary[i].title);
            printf("Content: %s\n", diary[i].content);
            return;
        }
    }

    printf("No entry found for the given date.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add a new entry\n");
        printf("2. List all entries\n");
        printf("3. View an existing entry\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                list_entries();
                break;
            case 3:
                view_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}