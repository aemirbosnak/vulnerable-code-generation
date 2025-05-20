//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

void add_entry(DiaryEntry* diary, int num_entries, char* new_entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    time(&diary[num_entries].timestamp);
    strcpy(diary[num_entries].entry, new_entry);
    num_entries++;
}

void print_entries(DiaryEntry* diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", ctime(&diary[i].timestamp), diary[i].entry);
    }
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("1. Add entry\n2. Print entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char new_entry[MAX_ENTRY_LENGTH];
                printf("Enter your new entry:\n");
                fgets(new_entry, MAX_ENTRY_LENGTH, stdin);
                add_entry(diary, num_entries, new_entry);
                break;
            }
            case 2: {
                print_entries(diary, num_entries);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}