//FormAI DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

// structure for diary entries
struct diary_entry {
    int day;
    int month;
    int year;
    char* content;
};

// function to add a new entry to the diary
void add_entry(struct diary_entry* entries, int* num_entries, char* content) {
    // get the current date and time
    time_t now = time(NULL);
    struct tm* tm_now = localtime(&now);
    
    // create a new diary entry
    struct diary_entry new_entry;
    new_entry.day = tm_now->tm_mday;
    new_entry.month = tm_now->tm_mon + 1;
    new_entry.year = tm_now->tm_year + 1900;
    new_entry.content = content;
    
    // add the new entry to the array of entries
    entries[*num_entries] = new_entry;
    (*num_entries)++;
    
    // print a confirmation message
    printf("Entry added to diary.\n");
}

// function to display all entries in the diary
void display_entries(struct diary_entry* entries, int num_entries) {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }
    
    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%02d/%02d/%d:\n%s\n", entries[i].day, entries[i].month, entries[i].year, entries[i].content);
        printf("---------------\n");
    }
}

int main() {
    // allocate memory for diary entries
    struct diary_entry* entries = (struct diary_entry*) malloc(sizeof(struct diary_entry) * MAX_ENTRIES);
    int num_entries = 0;
    
    // print a welcome message
    printf("Welcome to your digital diary!\n");
    
    // loop to get user input and execute commands
    char command[10];
    while (1) {
        printf("Enter a command (add, view, exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            // get user input for new entry
            char content[500];
            printf("Enter your diary entry: ");
            scanf(" %[^\n]s", content);
            
            // add the entry to the diary
            add_entry(entries, &num_entries, content);
        } else if (strcmp(command, "view") == 0) {
            // display all diary entries
            display_entries(entries, num_entries);
        } else if (strcmp(command, "exit") == 0) {
            // free memory and exit program
            free(entries);
            printf("Goodbye!\n");
            return 0;
        } else {
            // invalid command
            printf("Invalid command. Please try again.\n");
        }
    }
}