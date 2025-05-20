//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char title[50];
    char entry[200];
} diary_entry;

typedef struct {
    diary_entry entries[MAX_ENTRIES];
    int num_entries;
} diary;

void add_entry(diary* diary, char* title, char* entry) {
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }
    
    diary_entry new_entry;
    strcpy(new_entry.title, title);
    strcpy(new_entry.entry, entry);
    
    diary->entries[diary->num_entries] = new_entry;
    diary->num_entries++;
}

void print_entries(diary* diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("---\n");
        printf("Title: %s\n", diary->entries[i].title);
        printf("Entry: %s\n", diary->entries[i].entry);
        printf("---\n");
    }
}

int main() {
    diary diary;
    diary.num_entries = 0;
    
    while (1) {
        printf("Enter title (or 'quit' to exit): ");
        char title[50];
        scanf("%s", title);
        
        if (strcmp(title, "quit") == 0) {
            break;
        }
        
        printf("Enter entry: ");
        char entry[200];
        scanf("%s", entry);
        
        add_entry(&diary, title, entry);
    }
    
    print_entries(&diary);
    
    return 0;
}