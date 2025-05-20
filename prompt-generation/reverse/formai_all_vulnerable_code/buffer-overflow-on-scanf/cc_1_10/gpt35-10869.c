//FormAI DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_NAME_LENGTH 50
#define MAX_ENTRIES 1000

typedef struct {
    char name[FILE_NAME_LENGTH];
    time_t time_modified;
} file_entry;

// function declarations
void add_entry(file_entry entries[], int* num_entries, char* name);
void print_entries(file_entry entries[], int num_entries);

int main() {
    file_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char file_name[FILE_NAME_LENGTH];

    printf("Welcome to Torvald's C File Backup System\n");

    while (1) {
        printf("\nEnter the name of the file you want to backup or 'quit' to exit: ");
        scanf("%s", file_name);

        if (strcmp(file_name, "quit") == 0) {
            printf("\nExiting program...\n");
            break;
        }

        add_entry(entries, &num_entries, file_name);
        print_entries(entries, num_entries);
    }

    return 0;
}

// function to add new file entry
void add_entry(file_entry entries[], int* num_entries, char* name) {
    if (*num_entries == MAX_ENTRIES) {
        printf("Cannot add any more entries. Maximum number of entries has been reached.\n");
        return;
    }

    file_entry new_entry;
    strcpy(new_entry.name, name);
    new_entry.time_modified = time(NULL);

    entries[*num_entries] = new_entry;
    (*num_entries)++;
}

// function to print all file entries
void print_entries(file_entry entries[], int num_entries) {
    printf("\nFile backups:\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%d. %s - backed up on %s", i+1, entries[i].name, ctime(&entries[i].time_modified));
    }
}