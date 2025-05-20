//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: portable
/// @file diary.c
/// @brief A portable C digital diary program
///
/// This program allows the user to enter and store entries in a digital diary.
/// The diary can be stored in a file or in memory, and the user can view and edit
/// the entries as needed.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTRY_MAX 256
#define DIARY_MAX 100

/// Structure to store an entry in the diary
typedef struct {
    char date[11];
    char time[9];
    char text[ENTRY_MAX];
} diary_entry;

/// Array to store the diary entries
static diary_entry diary[DIARY_MAX];

/// Number of entries in the diary
static int num_entries = 0;

/// File to store the diary
static FILE *diary_file = NULL;

/// Prompt the user for a date and time
void prompt_date_time(char *date, char *time) {
    printf("Enter date (YYYY-MM-DD): ");
    fgets(date, 11, stdin);
    date[strcspn(date, "\n")] = '\0';
    printf("Enter time (HH:MM): ");
    fgets(time, 9, stdin);
    time[strcspn(time, "\n")] = '\0';
}

/// Prompt the user for an entry
void prompt_entry(char *text) {
    printf("Enter entry: ");
    fgets(text, ENTRY_MAX, stdin);
    text[strcspn(text, "\n")] = '\0';
}

/// Display the diary
void display_diary() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s: %s\n", diary[i].date, diary[i].time, diary[i].text);
    }
}

/// Save the diary to a file
void save_diary() {
    if (diary_file == NULL) {
        diary_file = fopen("diary.txt", "w");
    }
    if (diary_file == NULL) {
        printf("Error: could not open diary file\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        fprintf(diary_file, "%s %s: %s\n", diary[i].date, diary[i].time, diary[i].text);
    }
    fclose(diary_file);
}

/// Load the diary from a file
void load_diary() {
    if (diary_file == NULL) {
        diary_file = fopen("diary.txt", "r");
    }
    if (diary_file == NULL) {
        printf("Error: could not open diary file\n");
        return;
    }
    char line[ENTRY_MAX + 11 + 9 + 2];
    while (fgets(line, ENTRY_MAX + 11 + 9 + 2, diary_file) != NULL) {
        diary_entry *entry = &diary[num_entries++];
        sscanf(line, "%s %s: %[^\n]", entry->date, entry->time, entry->text);
    }
    fclose(diary_file);
}

int main() {
    load_diary();
    char date[11], time[9], text[ENTRY_MAX];
    while (1) {
        prompt_date_time(date, time);
        prompt_entry(text);
        diary_entry *entry = &diary[num_entries++];
        strcpy(entry->date, date);
        strcpy(entry->time, time);
        strcpy(entry->text, text);
        save_diary();
        display_diary();
    }
    return 0;
}