//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 500
#define MAX_ENTRIES 50

typedef struct {
    char date[20];
    char entry[100];
} diary_entry_t;

diary_entry_t diary[MAX_ENTRIES];
int curr_entry = 0;

void init_diary() {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        strcpy(diary[i].date, "");
        strcpy(diary[i].entry, "");
    }
}

void add_entry(char *date, char *entry) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            strcpy(diary[i].entry, entry);
            return;
        }
    }
    if (curr_entry < MAX_ENTRIES) {
        strcpy(diary[curr_entry].date, date);
        strcpy(diary[curr_entry].entry, entry);
        curr_entry++;
    }
}

void display_diary() {
    int i;
    for (i = 0; i < curr_entry; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    init_diary();

    char date[20];
    char entry[100];

    // Example usage
    gets(date);
    gets(entry);
    add_entry(date, entry);

    display_diary();

    return 0;
}