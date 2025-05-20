//FormAI DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    time_t timestamp;
    char* content;
};

struct diary {
    struct entry entries[MAX_ENTRIES];
    int num_entries;
};

void print_entry(struct entry* e) {
    printf("%s", ctime(&(e->timestamp)));
    printf("%s\n", e->content);
}

void print_diary(struct diary* d) {
    for (int i = 0; i < d->num_entries; i++) {
        printf("\nEntry %d:\n", i+1);
        print_entry(&(d->entries[i]));
    }
}

void add_entry(struct diary* d, char* content) {
    if (d->num_entries >= MAX_ENTRIES) {
        printf("ERROR: diary is full\n");
        return;
    }
    struct entry new_entry;
    new_entry.timestamp = time(NULL);
    new_entry.content = content;
    d->entries[d->num_entries] = new_entry;
    d->num_entries++;
}

int main() {
    struct diary personal_diary;
    personal_diary.num_entries = 0;

    char input[100];
    int choice = -1;

    while (choice != 0) {
        printf("\n1. View entries\n");
        printf("2. Add an entry\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &choice);

        if (choice == 1) {
            if (personal_diary.num_entries == 0) {
                printf("No entries.\n");
            }
            else {
                printf("\n");
                print_diary(&personal_diary);
            }
        }
        else if (choice == 2) {
            char new_entry_content[1000];
            printf("\nEnter your entry:\n");
            fgets(new_entry_content, sizeof(new_entry_content), stdin);
            add_entry(&personal_diary, new_entry_content);
            printf("\nEntry added.\n");
        }
        else if (choice != 0) {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}