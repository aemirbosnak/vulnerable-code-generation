//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_ENTRIES 10
#define ENTRY_LENGTH 256

// Structure to hold diary entries
typedef struct {
    char date[16];
    char entry[ENTRY_LENGTH];
} diary_entry_t;

// Global variable to store diary entries
diary_entry_t diary[DIARY_ENTRIES];

// Function to read and write diary entries
void read_diary() {
    int i;
    for (i = 0; i < DIARY_ENTRIES; i++) {
        printf("Enter entry for %s: ", diary[i].date);
        scanf("%s", diary[i].entry);
    }
}

void write_diary() {
    int i;
    for (i = 0; i < DIARY_ENTRIES; i++) {
        printf("%s\n", diary[i].entry);
    }
}

// Main function
int main() {
    // Set current date and time
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char date[16];
    strftime(date, sizeof(date), "%Y-%m-%d", tm);

    // Initialize diary entries
    for (int i = 0; i < DIARY_ENTRIES; i++) {
        strcpy(diary[i].date, date);
        diary[i].entry[0] = '\0';
    }

    // Read diary entries
    read_diary();

    // Write diary entries
    write_diary();

    return 0;
}