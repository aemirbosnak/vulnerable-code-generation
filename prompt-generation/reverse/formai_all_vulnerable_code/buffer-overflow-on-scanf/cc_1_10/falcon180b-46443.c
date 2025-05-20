//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\nEntry:\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                printf("Enter date (DD/MM/YYYY): ");
                char date[20];
                scanf("%s", date);
                printf("Enter entry:\n");
                char entry[MAX_ENTRY_LENGTH];
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = '\0'; // Remove newline character
                add_entry(date, entry);
                break;
            case '2':
                display_entries();
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '3');

    return 0;
}