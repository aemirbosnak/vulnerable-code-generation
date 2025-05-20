//FormAI DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_FILE "diary.txt"
#define MAX_ENTRY_LEN 500

void print_menu();
void add_entry();
void view_entries();
void search_entries();

int main() {
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
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

        printf("\n");
    } while (choice != 4);

    return 0;
}

void print_menu() {
    printf("Digital Diary\n");
    printf("=============\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entries\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void add_entry() {
    FILE *fptr;
    char entry[MAX_ENTRY_LEN];
    time_t t;

    printf("Enter your entry (max. %d characters):\n", MAX_ENTRY_LEN);
    getchar(); // Get rid of the previous newline character
    fgets(entry, MAX_ENTRY_LEN, stdin);

    time(&t);
    char *timestamp = ctime(&t);
    timestamp[strlen(timestamp)-1] = '\0'; // Removing the trailing newline character

    fptr = fopen(DIARY_FILE, "a");
    fprintf(fptr, "[%s]\n%s\n", timestamp, entry);
    fclose(fptr);

    printf("Entry added successfully.\n");
}

void view_entries() {
    FILE *fptr;
    char line[MAX_ENTRY_LEN];

    fptr = fopen(DIARY_FILE, "r");
    if (fptr == NULL) {
        printf("No entries found.\n");
        return;
    }

    while (fgets(line, MAX_ENTRY_LEN, fptr)) {
        printf("%s", line);
    }

    fclose(fptr);
}

void search_entries() {
    FILE *fptr;
    char search_text[MAX_ENTRY_LEN];
    char line[MAX_ENTRY_LEN];
    int found = 0;

    printf("Enter the text to search:\n");
    getchar(); // Get rid of the previous newline character
    fgets(search_text, MAX_ENTRY_LEN, stdin);

    fptr = fopen(DIARY_FILE, "r");
    if (fptr == NULL) {
        printf("No entries found.\n");
        return;
    }

    while (fgets(line, MAX_ENTRY_LEN, fptr)) {
        if (strstr(line, search_text)) {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found.\n");
    }

    fclose(fptr);
}