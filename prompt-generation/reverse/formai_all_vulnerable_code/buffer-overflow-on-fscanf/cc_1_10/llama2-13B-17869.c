//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants and variables
#define DIARY_ENTRIES 50
#define MAX_NAME_LEN 20
#define MAX_TEXT_LEN 500

typedef struct {
    char name[MAX_NAME_LEN];
    char text[MAX_TEXT_LEN];
    time_t created;
} diary_entry_t;

diary_entry_t diary[DIARY_ENTRIES];
int curr_entry = 0;

// Function to read and write diary entries
void read_diary() {
    FILE *diary_file = fopen("diary.txt", "r");
    if (diary_file == NULL) {
        perror("Error opening diary file");
        return;
    }
    for (int i = 0; i < DIARY_ENTRIES; i++) {
        fscanf(diary_file, "%s %s %ld", diary[i].name, diary[i].text, &diary[i].created);
    }
    fclose(diary_file);
}

void write_diary() {
    FILE *diary_file = fopen("diary.txt", "w");
    if (diary_file == NULL) {
        perror("Error opening diary file");
        return;
    }
    for (int i = 0; i < DIARY_ENTRIES; i++) {
        fprintf(diary_file, "%s %s %ld\n", diary[i].name, diary[i].text, diary[i].created);
    }
    fclose(diary_file);
}

// Function to add a new diary entry
void add_entry() {
    // Get the current date and time
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(diary[curr_entry].name, MAX_NAME_LEN, "%d %B %Y", tm);
    strftime(diary[curr_entry].text, MAX_TEXT_LEN, "%I:%M %p", tm);
    diary[curr_entry].created = now;
    curr_entry++;
    if (curr_entry == DIARY_ENTRIES) {
        // If the diary is full, clear the oldest entry
        for (int i = 0; i < DIARY_ENTRIES; i++) {
            if (diary[i].created < diary[i + 1].created) {
                break;
            }
        }
        memmove(diary, diary + 1, (DIARY_ENTRIES - 1) * sizeof(diary_entry_t));
        curr_entry--;
    }
}

int main() {
    // Read the diary entries from the file
    read_diary();

    // Add a new diary entry
    add_entry();

    // Write the diary entries to the file
    write_diary();

    return 0;
}