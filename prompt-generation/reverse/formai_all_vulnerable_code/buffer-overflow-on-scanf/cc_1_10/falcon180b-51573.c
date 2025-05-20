//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

int num_entries = 0;
diary_entry diary[MAX_ENTRIES];

void add_entry(char* date, char* entry) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
    char choice;

    do {
        printf("Digital Diary\n");
        printf("A - Add entry\n");
        printf("P - Print entries\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter date (yyyy-mm-dd): ");
                scanf("%s", date);
                printf("Enter entry: ");
                scanf("%[^\n]", entry);
                add_entry(date, entry);
                break;
            case 'P':
                print_entries();
                break;
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 'Q');

    return 0;
}