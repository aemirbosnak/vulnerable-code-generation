//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char title[100];
    char content[1000];
    time_t timestamp;
} Entry;

void print_entry(Entry* entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %s", ctime(&entry->timestamp));
}

void add_entry(Entry* entry) {
    printf("Enter a title: ");
    scanf("%s", entry->title);
    printf("Enter some content: ");
    scanf("%s", entry->content);
    entry->timestamp = time(NULL);
}

void edit_entry(Entry* entry) {
    printf("Enter the title you want to edit: ");
    scanf("%s", entry->title);
    printf("Enter the new content: ");
    scanf("%s", entry->content);
}

void delete_entry(Entry* entry) {
    printf("Enter the title you want to delete: ");
    scanf("%s", entry->title);
}

void print_diary() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to your Digital Diary!\n");
    printf("Please enter the following commands:\n");
    printf("1. add - to add a new entry\n");
    printf("2. edit - to edit an existing entry\n");
    printf("3. delete - to delete an existing entry\n");
    printf("4. print - to print all entries\n");

    while (1) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            add_entry(&entries[num_entries]);
            num_entries++;
        } else if (strcmp(command, "edit") == 0) {
            edit_entry(&entries[num_entries - 1]);
        } else if (strcmp(command, "delete") == 0) {
            delete_entry(&entries[num_entries - 1]);
            num_entries--;
        } else if (strcmp(command, "print") == 0) {
            for (int i = 0; i < num_entries; i++) {
                print_entry(&entries[i]);
            }
        } else {
            printf("Invalid command\n");
        }
    }
}

int main() {
    print_diary();
    return 0;
}