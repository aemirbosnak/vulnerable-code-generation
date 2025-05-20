//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

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

void print_entries() {
    for(int i=0; i<num_entries; i++) {
        printf("%s:\n%s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    char entry[MAX_ENTRY_LENGTH];

    do {
        printf("Welcome to your digital diary!\n");
        printf("1. Add an entry\n2. View entries\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter your entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = '\0';
                add_entry(entries[num_entries].date, entry);
                break;
            case 2:
                print_entries();
                break;
            case 3:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 3);

    return 0;
}