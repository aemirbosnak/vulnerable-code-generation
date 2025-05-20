//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char title[50];
    char content[200];
    int created_at;
} Entry;

Entry entries[MAX_ENTRIES] = {{0}};

void add_entry() {
    entries[MAX_ENTRIES - 1].created_at = time(NULL);
    printf("Enter title: ");
    scanf("%s", entries[MAX_ENTRIES - 1].title);
    printf("Enter content: ");
    scanf("%s", entries[MAX_ENTRIES - 1].content);
}

void list_entries() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (entries[i].title[0] != '\0') {
            printf("%s - %s\n", entries[i].title, entries[i].content);
        }
    }
}

int main() {
    int option;

    printf("Digital Diary\n");
    printf("1. Add Entry\n");
    printf("2. List Entries\n");

    printf("Enter option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            add_entry();
            break;
        case 2:
            list_entries();
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}