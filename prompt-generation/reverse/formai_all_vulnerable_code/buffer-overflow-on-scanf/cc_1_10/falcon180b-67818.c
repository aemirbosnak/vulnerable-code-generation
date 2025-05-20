//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

diary_entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, you can only have %d entries.\n", MAX_ENTRIES);
        return;
    }
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(diary[num_entries].date, 20, "%Y-%m-%d", tm);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void read_entries() {
    if (num_entries == 0) {
        printf("You haven't written anything yet!\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    printf("Welcome to your digital diary!\n");
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. Read entries\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char entry[MAX_ENTRY_LENGTH];
                printf("Enter your entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                add_entry(entry);
                break;
            }
            case 2: {
                read_entries();
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }
    return 0;
}