//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Date: %s\nEntry:\n%s\n\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    char choice;
    int i;

    printf("Welcome to your digital diary!\n\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("A - Add an entry\n");
        printf("D - Display entries\n");
        printf("Q - Quit\n");
        printf("> ");
        scanf("%c", &choice);

        switch (choice) {
        case 'A':
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", diary[num_entries].date);
            printf("Enter your entry:\n");
            fgets(diary[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
            num_entries++;
            break;

        case 'D':
            display_entries();
            break;

        case 'Q':
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}